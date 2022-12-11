#include<bits/stdc++.h>
#define ll long long
#define pii pair<ll,int>
#define mp(a,b) make_pair(a,b)
#define maxn 5005
using namespace std;
int n,k,x;
struct Que
{
	int l,r;
	pii a[maxn];
	void init(){l=r=0;}
	bool empty(){return l==r;}
	void push(pii x)
	{
		while(!empty()&&a[r]<x)r--;
		a[++r]=x;
	}
	pii top(){return a[l+1];}
	void pop(){l++;}
}q;
int a[maxn];
ll dp[maxn][maxn];
int main()
{
	scanf("%d%d%d",&n,&k,&x);
	for(int i=1;i<=n;++i)scanf("%d",&a[i]);
	if(n>=(x+1)*k)
	{
		puts("-1");exit(0);
	}
	for(int i=0;i<=n;++i)
		for(int j=0;j<=x;++j)dp[i][j]=-(ll)1e17;
	dp[0][0]=0;
	for(int j=1;j<=x;++j)
	{
		q.init();
		q.push(mp(0,0));
		for(int i=1;i<=n;++i)
		{
			while(!q.empty()&&q.top().second<i-k)q.pop();
			int t=q.top().second;
			if(dp[t][j-1]>=0)dp[i][j]=dp[t][j-1]+a[i];
			q.push(mp(dp[i][j-1],i));
		}
	}
	ll ans=0;
	for(int i=n-k+1;i<=n;++i)ans=max(ans,dp[i][x]);
	printf("%I64d\n",ans);
	return 0;
}