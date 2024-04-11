#include <stdio.h>
#include <cmath>
const double PI=acos(-1);
const double e=7e-7;
int main()
{
int n,R,r;
double a,b;
scanf("%i %i %i",&n,&R,&r);
if(r>R) 
{
if(n==0) printf("YES\n");
else printf("NO\n");
return 0;
}
if(r*2>R)
{
if(n==1) printf("YES\n");
else printf("NO\n");
return 0;
}
if(n==1)
{
printf("YES\n");
return 0;
}
b=2.00*r;
a=2.00*(R-r)*sin(PI/(double)n);
//if(n==6) printf("%.12llf",a);
if(a-b>-e) printf("YES\n");
else printf("NO\n");
return 0;
}