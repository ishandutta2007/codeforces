#include <stdio.h>
int main()
{
    int n,a,b,c,sol,i;
    sol=0;
    scanf("%i",&n);
    for(i=0;i<n;i++)
    {
        scanf("%i%i%i",&a,&b,&c);
        if(a+b+c>1) sol++;
    }
    printf("%i",sol);
    return 0;
}