#include<bits/stdc++.h>
#define pii pair<int,int>
#define mp(a,b) make_pair(a,b)
#define maxn 300005 
#define ll long long
using namespace std;
int n,k;
ll a[maxn];
map<pii,ll> dp[maxn];
int main()
{
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;++i)scanf("%I64d",&a[i]);
	sort(a+1,a+n+1);
	int A=0,B=0,M=0;
	for(int s=1;s<=k;++s)
	{
		int cnt=0;
		for(int i=s;i<=n;i+=k)++cnt;
		M=max(M,cnt);
	}
	--M;
	for(int s=1;s<=k;++s)
	{
		int cnt=0;
		for(int i=s;i<=n;i+=k)++cnt;
		if(cnt==M)++A;
		if(cnt==M+1)++B;
	}
	dp[0][mp(0,0)]=0;
	map<pii,ll>::iterator it;
	for(int i=0;i<n;++i)
	{
		for(it=dp[i].begin();it!=dp[i].end();++it)
		{
			int x=(it->first).first,y=(it->first).second;
			if(x<A)
			{
				if(!dp[i+M].count(mp(x+1,y)))dp[i+M][mp(x+1,y)]=(it->second)+a[i+M]-a[i+1];
				else dp[i+M][mp(x+1,y)]=min(dp[i+M][mp(x+1,y)],(it->second)+a[i+M]-a[i+1]);
			}
			if(y<B)
			{
				if(!dp[i+M+1].count(mp(x,y+1)))dp[i+M+1][mp(x,y+1)]=(it->second)+a[i+M+1]-a[i+1];
				else dp[i+M+1][mp(x,y+1)]=min(dp[i+M+1][mp(x,y+1)],(it->second)+a[i+M+1]-a[i+1]);
			}
		}
	}
	printf("%I64d\n",dp[n][mp(A,B)]);
	return 0;
}