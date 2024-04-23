#include <stdio.h>
#include <stdlib.h>

void equacao();

int dia, mes, ano, dia_semana, formula; 

int main()
{
  
  char resposta[4] = "";
    
  while(strcmp(resposta, "nao") != 0)
  {
    system("clear");
    printf("A seguir, digite uma data do calendario Gregoriano para saber seu respectivo dia da semana. \n\n");
    printf("Dia: "); scanf("%d", &dia); printf("\n");
    printf("Mes: "); scanf("%d", &mes); printf("\n");
    printf("Ano: "); scanf("%d", &ano); printf("\n");
    
    // Verifica se é um ano Bissexto, se o dia está entre ( 01- 31 ) e o mês está entre ( 01 - 12 )
    if( (ano % 4 == 0 && (ano % 400 == 0 || ano % 100 != 0)) && (dia > 0 && dia <=31) && (mes >0 && mes <=12) ) 
    {    
       // Verifica se os meses de até 30 dias não estão corretos.
       if(mes == 2 && dia > 29 || mes == 4 && dia>30 || mes == 6 && dia>30 || mes == 9 && dia>30 || mes == 11 && dia>30 ) 
       {
       	 printf("A data %d/%d/%d nao existe no calendario Gregoriano. \n\n", dia, mes, ano);
       	 exit(0);
       }
       else equacao();  
    }
    
    // Verifica se não é um ano Bissexto, se o dia está entre ( 01- 31 ) e o mês está entre ( 01 - 12 )
    else if( !(ano % 4 == 0 && (ano % 400 == 0 || ano % 100 != 0)) && (dia > 0 && dia <=31) && (mes >0 && mes <=12) )
    {    
       // Verifica se os meses de até 30 dias não estão corretos.
       if(mes == 2 && dia > 28 || mes == 4 && dia>30 || mes == 6 && dia>30 || mes == 9 && dia>30 || mes == 11 && dia>30 ) 
       {
       	 printf("A data %d/%d/%d nao existe no calendario Gregoriano. \n\n", dia, mes, ano);
       	 exit(0);
       }
       else equacao();		
    }
    
    // Se a data não existir no calendário gregoriano.
    else printf("A data %d/%d/%d nao existe no calendario Gregoriano. \n\n", dia, mes, ano);
    
    
    printf("Quer tentar novamente?(sim/nao)\n"); scanf("%s", resposta);
  }  
  printf("Desenvolvedor do Programa: Bruno Werner\n\n");
  sleep(2);
  
  return 0;
  
}


void equacao()
{
   if(mes == 01 ) // mês de janeiro será o mês 13 do ano anterior.
   {
        mes = 13;
        ano = ano - 1;
   }
    
   if(mes == 02 ) // mês de favereiro será o mês 14 do ano anterior.
   {
       mes = 14;
        ano = ano - 1;
    
   } 
     
   formula = dia + 2*mes + (3*(mes+1)/5) + ano + ano/4 - ano/100 + ano/400 + 2;  // Formula para calcular o dia da semana.
   dia_semana = formula % 7;                                                     // Resto da divisão do valor encontrado na formula por 7.

   if (mes == 13) // Se for mês de Janeiro, coloca o valor certo do Mês e do Ano para mostrar na tela.
   {
        mes = 1;
        ano = ano+1;
   }
   if (mes == 14) // Se for mês de Fevereiro, coloca o valor certo do Mês e do Ano para mostrar na tela.
   {
        mes = 2;
        ano = ano +1;
   }
   
   
   switch(dia_semana)  // Switch case para saber qual dia da semana é.
   {
        case 0:
            printf("A data %d/%d/%d cai em um Sabado(Saturday)\n\n", dia, mes, ano); 
     break;
              
     case 1:
            printf("A data %d/%d/%d cai em um Domingo(Sunday)\n\n", dia, mes, ano);   
     break;
        
     case 2:
            printf("A data %d/%d/%d cai em uma Segunda-feira(Monday)\n\n", dia, mes, ano); 
     break;
        
     case 3:
            printf("A data %d/%d/%d cai em uma Terca-feira(Tuesday)\n\n", dia, mes, ano); 
     break;
        
     case 4:
         	printf("A data %d/%d/%d cai em uma Quarta-feira(Wednesday)\n\n", dia, mes, ano); 
     break;
        
     case 5:
            printf("A data %d/%d/%d cai em uma Quinta-feira(Thursday)\n\n", dia, mes, ano); 
     break;
        
     case 6:
           	printf("A data %d/%d/%d cai em uma Sexta-feira(Friday)\n\n", dia, mes, ano); 
     break;
            
   }
    
}