#include <stdio.h>
#define ll long long
const int N=1000050;
const ll inf=1e18;
ll dp[N*2];
int cnt[N*2],a[N];
int Cnt(int u, int v){ return cnt[v]-cnt[u-1];}
ll DP(int u, int v){ return dp[v]-dp[u-1];}
int max(int a, int b){ return a>b?a:b;}
ll sol=inf,ans;
ll min(ll a, ll b){ return a>b?b:a;}
int main()
{
	int n,x,y,i,j,p,g,sum,tmp;
	scanf("%i %i %i",&n,&x,&y);
	g=x/y;
	for(i=1;i<=n;i++) scanf("%i",&a[i]),cnt[a[i]]++;
	for(i=1;i<N*2;i++)
	{
		dp[i]=dp[i-1]+(ll)i*cnt[i];
		cnt[i]+=cnt[i-1];
	}
	for(i=2;i<N;i++)
	{
		p=0;sum=0;ans=0;
		for(j=i;j<N*2;j+=i)
		{
			tmp=Cnt(max(p+1,j-g),j);
			sum+=tmp;
			ans+=(ll)tmp*j-DP(max(p+1,j-g),j);
			p=j;
			if(j>N) break;
		}
		ans*=y;
		ans+=(ll)(n-sum)*x;
		sol=min(sol,ans);
	}
	printf("%lld\n",sol);
	return 0;
}