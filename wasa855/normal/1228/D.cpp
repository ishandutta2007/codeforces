#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define Fast_IO ios::sync_with_stdio(false);
inline int read()
{
	char ch=getchar(); int nega=1; while(!isdigit(ch)) {if(ch=='-') nega=-1; ch=getchar();}
	int ans=0; while(isdigit(ch)) {ans=ans*10+ch-48;ch=getchar();}
	if(nega==-1) return -ans;
	return ans;
}
#define N 300005
vector<int> G[N];
int n,m;
int ans[N];
bool vis[N];
int cnt[5];
signed main()
{
#ifdef __LOCAL__
	freopen("in.txt","r",stdin);
#endif
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		int u=read(),v=read();
		G[u].pb(v),G[v].pb(u);
	}
	int sum=1;
	queue<int> q;
	while(!q.empty()) q.pop();
	memset(vis,0,sizeof(vis));
	for(int i=1;i<=n;++i)
	{
		if(!ans[i])
		{
			q.push(i);
		}
	}
	while(!q.empty())
	{
		int x=q.front();
		q.pop();
		while(!q.empty()&&vis[x])
		{
			x=q.front();
			q.pop();
		}
		if(vis[x]) break;
		ans[x]=sum;
		int tx=G[x].size();
		for(int i=0;i<tx;i++)
		{
			vis[G[x][i]]=1;
		}
	}
	sum++;
	while(!q.empty()) q.pop();
	memset(vis,0,sizeof(vis));
	for(int i=1;i<=n;++i)
	{
		if(!ans[i])
		{
			q.push(i);
		}
	}
	while(!q.empty())
	{
		int x=q.front();
		q.pop();
		while(!q.empty()&&vis[x])
		{
			x=q.front();
			q.pop();
		}
		if(vis[x]) break;
		ans[x]=sum;
		int tx=G[x].size();
		for(int i=0;i<tx;i++)
		{
			vis[G[x][i]]=1;
		}
	}
	sum++;
	while(!q.empty()) q.pop();
	memset(vis,0,sizeof(vis));
	for(int i=1;i<=n;++i)
	{
		if(!ans[i])
		{
			q.push(i);
		}
	}
	while(!q.empty())
	{
		int x=q.front();
		q.pop();
		while(!q.empty()&&vis[x])
		{
			x=q.front();
			q.pop();
		}
		if(vis[x]) break;
		ans[x]=sum;
		int tx=G[x].size();
		for(int i=0;i<tx;i++)
		{
			vis[G[x][i]]=1;
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(!ans[i])
		{
			cout<<"-1\n";
			return 0;
		}
	}
	for(int i=1;i<=n;i++)
	{
		cnt[ans[i]]++;
	}
	if(!cnt[1]||!cnt[2]||!cnt[3])
	{
		printf("-1\n");
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		int tx=G[i].size();
		for(int j=0;j<tx;j++)
		{
			int to=G[i][j];
			if(ans[i]==ans[to])
			{
				printf("-1\n");
				return 0;
			}
		}
		if(tx!=n-cnt[ans[i]])
		{
			printf("-1\n");
			return 0;
		}
	}
	for(int i=1;i<=n;i++) printf("%d ",ans[i]);
	cout<<"\n";
#ifdef __LOCAL__
	printf("Time used : %d\n",clock());
#endif
	return 0;
}