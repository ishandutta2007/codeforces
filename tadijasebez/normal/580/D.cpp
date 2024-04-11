#include <stdio.h>
#include <algorithm>
using namespace std;
#define ll long long
const int N=18;
const int M=1<<N;
ll dp[M][N];
int dist[N][N],a[N];
int main()
{
	int n,m,q,u,v,w,i,j,k,mask;
	scanf("%i %i %i",&n,&m,&q);
	for(i=0;i<n;i++) scanf("%i",&a[i]);
	while(q--) scanf("%i %i %i",&u,&v,&w),dist[u-1][v-1]=w;
	for(mask=1;mask<(1<<n);mask++)
	{
		for(j=0;j<n;j++)
		{
			if((mask>>j)&1)
			{
				for(i=0;i<n;i++)
				{
					if(i!=j && (mask>>i)&1)
					{
						dp[mask][j]=max(dp[mask][j],dp[mask^(1<<j)][i]+dist[i][j]);
					}
				}
				dp[mask][j]+=a[j];
			}
		}
	}
	ll sol=0;
	for(mask=1;mask<(1<<n);mask++)
	{
		if(__builtin_popcount(mask)==m)
		{
			for(j=0;j<n;j++) sol=max(sol,dp[mask][j]);
		}
	}
	printf("%lld\n",sol);
	return 0;
}