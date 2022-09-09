#include <stdio.h>
int main()
{
    int n,i,x,a,sol;
    scanf("%i %i",&n,&x);
    sol=x;
    for(i=0;i<n;i++)
    {
        scanf("%i",&a);
        if(a==x) sol++;
        if(a<x) sol--;
    }
    printf("%i\n",sol);
    return 0;
}