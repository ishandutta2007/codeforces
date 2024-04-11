#include<bits/stdc++.h>
using namespace std;
#define int long long
#define mod 1000000007LL
struct Edge
{
	int to;
	int nxt;
};
Edge edge[400005];
int fir[200005];
int ss;
void add(int u,int v)
{
	ss++;
	edge[ss].to=v;
	edge[ss].nxt=fir[u];
	fir[u]=ss;
}
int dep[200005];
int vis[200005];
int ring[200005];
int sum;
void dfs(int now,int depth)
{
	vis[now]=1;
	dep[now]=depth;
	for(int i=fir[now];i!=0;i=edge[i].nxt)
	{
		int to=edge[i].to;
		if(vis[to]==0)
		{
			dfs(to,depth+1);
		}
		if(vis[to]==1)
		{
			ring[++sum]=dep[now]-dep[to]+1;
		}
	}
	vis[now]=2;
}
int kasumi(int a,int b)
{
	int ans=1;
	while(b>0)
	{
		if(b%2==1)
		{
			ans=ans*a%mod;
		}
		b/=2;
		a=a*a%mod;
	}
	return ans;
}
signed main()
{
	int n;
	cin>>n;
	int u;
	for(int i=1;i<=n;i++)
	{
		scanf("%I64d",&u);
		add(i,u);
	}
	int tot=0;
	for(int i=1;i<=n;i++)
	{
		if(dep[i]==0)
		{
			dfs(i,1);
		}
	}
	for(int i=1;i<=sum;i++)
	{
//		printf("%I64d ",ring[i]);
		tot+=ring[i];
	}
//	cout<<"\n";
	int ans=kasumi(2,n-tot);
//	cout<<(4LL*(4LL-2LL+mod)%mod)<<endl;
//	cout<<ans*(kasumi(2,ring[1])-2+mod)%mod<<endl;
	for(int i=1;i<=sum;i++)
	{
//		cout<<"ans:"<<ans<<endl;
//		cout<<ans*(kasumi(2LL,ring[i])-2LL+mod)%mod<<endl;
		ans=ans*(kasumi(2LL,ring[i])-2LL+mod)%mod;
//		cout<<ans<<endl;
	}
	cout<<ans<<endl;
	return 0;
}