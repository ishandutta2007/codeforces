#include <stdio.h>
#include <algorithm>
using namespace std;
int max(int a, int b)
{
if(a>b) return a;
else return b;
}
int main()
{
int a[4],i;
int sol=0;
for(i=0;i<4;i++) scanf("%i",&a[i]);
sort(a,a+4);
for(i=2;i<4;i++)
{
if(a[i-1]+a[i-2]==a[i]) sol=max(sol,1);
if(a[i-1]+a[i-2]>a[i]) sol=max(sol,2);
}
if(sol==2) printf("TRIANGLE\n");
if(sol==1) printf("SEGMENT\n");
if(sol==0) printf("IMPOSSIBLE\n");
return 0;
}