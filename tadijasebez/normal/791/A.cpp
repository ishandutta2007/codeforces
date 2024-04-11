#include <stdio.h>
int main()
{
    int a,b,i=0;
    scanf("%i%i",&a,&b);
    while(a<=b)
    {
        a*=3;
        b*=2;
        i++;
    }
    printf("%i",i);
    return 0;    
}