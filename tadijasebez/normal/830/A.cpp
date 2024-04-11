#include <stdio.h>
#include <algorithm>
using namespace std;
const int N=2005;
const int inf=2e9+1e7;
int a[N],b[N];
int max(int a, int b){ return a>b?a:b;}
int min(int a, int b){ return a>b?b:a;}
int dist(int x, int y){ return x>y?x-y:y-x;}
int main()
{
	int n,k,i,j,p;
	scanf("%i %i %i",&n,&k,&p);
	for(i=1;i<=n;i++) scanf("%i",&a[i]);sort(a+1,a+1+n);
	for(i=1;i<=k;i++) scanf("%i",&b[i]);sort(b+1,b+1+k);
	int sol=inf;
	for(j=1;j<=k-n+1;j++)
	{
		int ans=0;
		for(i=1;i<=n;i++) ans=max(ans,dist(a[i],b[j+i-1])+dist(b[j+i-1],p));
		sol=min(sol,ans);
	}
	printf("%i\n",sol);
	return 0;
}