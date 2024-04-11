
#include <iostream>
#include <cmath>
using namespace std;
char first[100001], second[100001], zero[100001];
int number1[10], number2[10];
int just_zero()
{
     char *p1=first, *p2=second;
     while ( number1[0]-- )
           *p1++=*p2++='0';
     return p1-first;
}
int summary_ten (int count)
{
     int min_rez=-1;
     int t=0;
     for ( int i=1; i<6; i++ )
     {
         if ( number1[i]&&number2[10-i] )
         {
              int now_rez=min(number1[i], number2[9-i])+min(number2[10-i], number1[i-1])-min(number1[i]-1, number2[9-i])-min(number2[10-i]-1, number1[i-1]);
              if ( now_rez<min_rez||min_rez==-1 )
              {
                 t=i;
                 min_rez=now_rez;
              }
         }
     } 
     if ( t )
     {
          number1[t]--;
          number2[10-t]--;
          first[count]=t+'0';
          second[count]=(10-t)+'0';
          return count+1;
     }
     return count;
}
int summary_nine(int count)
{
     char *p1=&first[count], *p2=&second[count];
     for ( int i=0; i<10; i++ )
     {
         int t1=number1[9-i];
         int t2=number2[i];
         while ( t1*t2 )
         {
               *p1++=(9-i)+'0';
               *p2++=i+'0';
               t1--;
               t2--;
               number1[9-i]--;
               number2[i]--;
         }    
     }
     return p1-first;
}
int what_else ( int count )
{
     char *zero_p=zero;
     while ( number1[0]*number2[0] )
     {
           *zero_p++='0';
           number1[0]--;
           number2[0]--;
     } 
     char *p1=&first[count], *p2=&second[count];
     for ( int i=0; i<10; i++ )
     {
         while ( number1[i] )
         {
               *p1++=i+'0';
               number1[i]--;
         }
         while ( number2[i] )
         {
               *p2++=i+'0';
               number2[i]--;
         }
     } 
     return p1-first;
}
void print_screen ( int count )
{
     char *p1=first+count, *p2=second+count;
     while ( true )
     {
           printf("%c", *p1);
           if ( p1==first )
              break;
           *p1--;
     }
     printf("%s\n", zero);
     while ( true )
     {
           printf("%c", *p2);
           if ( p2==second )
              break;
           *p2--;
     }
     printf("%s", zero);
     return;
}
void maximum_sum ()
{
     int count1=summary_ten(0);
     int count2=count1;
     if ( count1 )
        count2=summary_nine(count1);
     int count3=what_else(count2);
     print_screen(count3-1);
     return;
} 
int main()
{
    char str[100001];
    scanf("%s", &str);
    char *p=&str[0];
    while ( *p )
    {
          number2[*p-'0']++;          
          number1[(*p++)-'0']++;
    }
    maximum_sum();
    scanf("%s", &str);
    return 0;
}