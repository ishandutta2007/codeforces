#include <stdio.h>
int main()
{
int n,i,a;
bool ok=false;
scanf("%i",&n);
for(i=0;i<n;i++)
{
scanf("%i",&a);
if(a==1) ok=true;
}
if(ok) printf("-1\n");
else printf("1\n");
return 0;
}