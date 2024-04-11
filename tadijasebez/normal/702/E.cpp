#include <stdio.h>
#define ll long long
const int N=100050;
const int L=35;
const int inf=1e9+7;
int min(int a, int b){ return a>b?b:a;}
int par[N][L],Min[N][L];
ll sum[N][L];
int main()
{
	int n,i,j;
	ll k;
	scanf("%i %lld",&n,&k);
	for(i=0;i<n;i++) scanf("%i",&par[i][0]);
	for(i=0;i<n;i++) scanf("%i",&Min[i][0]),sum[i][0]=Min[i][0];
	for(j=1;j<L;j++)
	{
		for(i=0;i<n;i++)
		{
			par[i][j]=par[par[i][j-1]][j-1];
			Min[i][j]=min(Min[i][j-1],Min[par[i][j-1]][j-1]);
			sum[i][j]=sum[i][j-1]+sum[par[i][j-1]][j-1];
		}
	}
	for(i=0;i<n;i++)
	{
		int u=i;
		ll sol=0;
		int ans=inf;
		for(j=L-1;~j;j--) if((k>>j)&1)
		{
			sol+=sum[u][j];
			ans=min(ans,Min[u][j]);
			u=par[u][j];
		}
		printf("%lld %i\n",sol,ans);
	}
	return 0;
}