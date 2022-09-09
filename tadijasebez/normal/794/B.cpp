#include <stdio.h>
#include <cmath>
int main()
{
int n,h,i;
double p,sol;
scanf("%i %i",&n,&h);
p=0.5*h/n;
for(i=1;i<n;i++)
{
sol=sqrt(2.0*h*p*i);
printf("%.12llf ",sol);
}
printf("\n");
return 0;
}