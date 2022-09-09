#include <stdio.h>
#include <algorithm>
using namespace std;
int x[100000];
int main()
{
int n,m,i;
scanf("%i %i",&n,&m);
for(i=0;i<m;i++) scanf("%i",&x[i]);
sort(x,x+m);
int sol=10000000;
for(i=n-1;i<m;i++)
{
int tr=x[i]-x[i-n+1];
if(tr<sol) sol=tr;
}
printf("%i\n",sol);
return 0;
}