#include<bits/stdc++.h>
using namespace std;
const int max_n=2e5+5;
int End[max_n<<1],Last[max_n],Next[max_n<<1],e;
inline void add_edge(int x,int y)
{
	End[++e]=y,Next[e]=Last[x],Last[x]=e;
	End[++e]=x,Next[e]=Last[y],Last[y]=e;
}
int a[max_n],dep[max_n],fath[max_n];
inline bool cmp(int x,int y)
{
	return a[x]<a[y];
}
int que[max_n],head,tail,l[max_n],r[max_n];
long long dp[max_n];
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		scanf("%d",&n);
		for(int i=1;i<=n;++i)
			Last[i]=l[i]=r[i]=0;
		e=0;
		for(int i=2;i<=n;++i)
		{
			int v;
			scanf("%d",&v);
			add_edge(i,v);
		}
		for(int i=2;i<=n;++i)
			scanf("%d",a+i);
		head=1,tail=0;
		que[++tail]=1;
		fath[1]=dep[1]=0;
		while(head<=tail)
		{
			int x=que[head++];
			for(int i=Last[x];i;i=Next[i])
			{
				int y=End[i];
				if(y!=fath[x])
				{
					que[++tail]=y;
					fath[y]=x;
					dep[y]=dep[x]+1;
				}
			}
		}
		assert(tail==n);
		for(int i=1;i<=n;++i)
		{
			if(!l[dep[que[i]]])
				l[dep[que[i]]]=i;
			r[dep[que[i]]]=i;
		}
		int d=dep[que[n]];
		for(int i=1;i<=d;++i)
		{
			sort(que+l[i],que+r[i]+1,cmp);
			for(int j=l[i];j<=r[i];++j)
			{
				int x=que[j];
				dp[x]=dp[fath[x]]+max(a[x]-a[que[l[i]]],a[que[r[i]]]-a[x]);
			}
			long long mx=-1e9;
			for(int j=l[i];j<=r[i];++j)
			{
				int x=que[j];
				dp[x]=max(dp[x],mx+a[x]);
				mx=max(mx,dp[fath[x]]-a[x]);
			}
			mx=0;
			for(int j=r[i];j>=l[i];--j)
			{
				int x=que[j];
				dp[x]=max(dp[x],mx-a[x]);
				mx=max(mx,dp[fath[x]]+a[x]);
			}
		}
		long long ans=0;
		for(int i=l[d];i<=r[d];++i)
			ans=max(ans,dp[que[i]]);
		printf("%lld\n",ans);
	}
	return 0;
}