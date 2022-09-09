#include <stdio.h>
long long tmp=1;
int main()
{
int n,k,i;
scanf("%i %i",&n,&k);
for(i=0;i<k;i++) tmp*=10;
for(i=1;i<=tmp;i++)
{
if((1ll*n*i)%tmp==0)
{
printf("%lld\n",(1ll*n*i));
return 0;
}
}
return 0;
}