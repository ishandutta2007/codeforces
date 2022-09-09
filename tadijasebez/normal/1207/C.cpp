#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair
const int N=200050;
char s[N];
bool h[N];
ll dp[N][2];
void ckmn(ll &a, ll b){ a=min(a,b);}
int main()
{
	int t;
	scanf("%i",&t);
	while(t--)
	{
		int n,a,b;
		scanf("%i %i %i",&n,&a,&b);
		scanf("%s",s+1);
		for(int i=0;i<=n;i++) h[i]=0,dp[i][0]=dp[i][1]=9e18;
		for(int i=1;i<=n;i++) if(s[i]=='1') h[i-1]=h[i]=1;
		dp[0][0]=b;
		for(int i=1;i<=n;i++)
		{
			ckmn(dp[i][1],min(dp[i-1][1]+b*2+a,dp[i-1][0]+b*2+a*2));
			if(!h[i]) ckmn(dp[i][0],min(dp[i-1][0]+b+a,dp[i-1][1]+b+a*2));
		}
		ll ans=dp[n][0];
		printf("%lld\n",ans);
	}
	return 0;
}