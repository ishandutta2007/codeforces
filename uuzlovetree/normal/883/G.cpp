#include<bits/stdc++.h>
#define maxn 300005
using namespace std;
int n,m,s;
int U[maxn],V[maxn];
vector< pair<int,int> > g[maxn];
char Ans[maxn];
int dis[maxn];
void bfs(int s)
{
	queue<int> q;
	q.push(s);dis[s]=1;
	while(!q.empty())
	{
		int u=q.front();q.pop();
		for(auto p:g[u])
		{
			int v=p.first,id=p.second;
			if(dis[v])continue;
			dis[v]=dis[u]+1;q.push(v);
		}
	}
}
void bfs2(int s)
{
	memset(dis,0,sizeof(dis));
	queue<int> q;
	q.push(s);dis[s]=1;
	while(!q.empty())
	{
		int u=q.front();q.pop();
		for(auto p:g[u])
		{
			int v=p.first,id=p.second;
			if(dis[v])continue;
			if(id)continue;
			dis[v]=dis[u]+1;q.push(v);
		}
	}
}
int main()
{
	scanf("%d%d%d",&n,&m,&s);
	int tot=0;
	for(int i=1;i<=m;++i)
	{
		int tp,u,v;
		scanf("%d%d%d",&tp,&u,&v);
		if(tp==1)
		{
			g[u].push_back(make_pair(v,0));
		}
		else
		{
			++tot;
			U[tot]=u;V[tot]=v;
			g[u].push_back(make_pair(v,tot));
			g[v].push_back(make_pair(u,tot));
		}
	}
	bfs(s);
	int ans=0;
	for(int i=1;i<=n;++i)if(dis[i])ans++;
	for(int i=1;i<=tot;++i)
	{
		if(dis[U[i]]<dis[V[i]])Ans[i]='+';
		else Ans[i]='-';
	}
	printf("%d\n",ans);
	printf("%s\n",Ans+1);
	bfs2(s);
	ans=0;
	for(int i=1;i<=n;++i)if(dis[i])ans++;
	printf("%d\n",ans);
	for(int i=1;i<=tot;++i)
	{
		if(dis[U[i]]&&(!dis[V[i]]))Ans[i]='-';
		else Ans[i]='+';
	}
	printf("%s\n",Ans+1);
}