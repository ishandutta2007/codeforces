#include<bits/stdc++.h>
#define ll long long
#define maxn 100005
using namespace std;
int n,p,k;
struct Node
{
	int val;
	int s[9];
}a[maxn];
bool cmp(Node A,Node B){return A.val>B.val;}
ll dp[maxn][130];
int main()
{
	scanf("%d%d%d",&n,&p,&k);
	for(int i=1;i<=n;++i)scanf("%d",&a[i].val);
	for(int i=1;i<=n;++i)
		for(int j=0;j<p;++j)scanf("%d",&a[i].s[j]);
	sort(a+1,a+n+1,cmp);
	ll sum=0; 
	for(int i=1;i<=k;++i)sum+=a[i].val;
	dp[0][0]=sum;
	for(int i=1;i<=n;++i)
	{
		for(int S=0;S<(1<<p);++S)
		{
			dp[i][S]=max(dp[i][S],dp[i-1][S]);
			int num=0;
			for(int j=0;j<p;++j)if(S&(1<<j))num++;
			for(int j=0;j<p;++j)if(!(S&(1<<j)))
			{
				if(i<=k+num)dp[i][S|(1<<j)]=max(dp[i][S|(1<<j)],dp[i-1][S]-a[i].val+a[k+num+1].val+a[i].s[j]);
				else dp[i][S|(1<<j)]=max(dp[i][S|(1<<j)],dp[i-1][S]+a[i].s[j]);
			}
		}
	}
	ll ans=0;
	for(int S=0;S<(1<<p);++S)ans=max(ans,dp[n][S]);
	cout<<ans<<endl;
}