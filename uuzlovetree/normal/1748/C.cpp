#include<bits/stdc++.h>
#define maxn 200005
using namespace std;
typedef long long ll;
const int inf = 1000000000;
int T,n;
ll a[maxn],s[maxn];
map<ll,int> mx;
int dp[maxn],g[maxn];
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;++i)scanf("%lld",&a[i]);
		for(int i=1;i<=n;++i)s[i]=s[i-1]+a[i];
		mx.clear();
		mx[0]=0;
		int lst=0,ans=0;
		for(int i=1;i<=n;++i)
		{
			dp[i]=-inf;
			if(!a[i])lst=i;
			if(mx.count(s[i]))dp[i]=max(dp[i],mx[s[i]]+1);
			if(lst)dp[i]=max(dp[i],g[lst-1]+1);
			g[i]=max(g[i-1],dp[i]);
			if(mx.count(s[i]))mx[s[i]]=max(mx[s[i]],dp[i]);
			else mx[s[i]]=dp[i];
			ans=max(ans,dp[i]);
		}
		printf("%d\n",ans);
	}
}