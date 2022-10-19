#include<bits/stdc++.h>
using namespace std;
const int N=100005;
int n,q,l;
vector<pair<int,int>>e[N];
struct task
{
	int rt,mu,md[N],d[N],fa[N][17],mx[N],tp[N],len[N],ans[N],c[N],s[N],k;
	vector<int>a[N];
	void dfs0(int u,int f,int t)
	{
		if(t)
		{
			fa[u][0]=f;
			for(int j=1;j<=16;j++)
				fa[u][j]=fa[fa[u][j-1]][j-1];
		}
		md[u]=d[u];
		if(!t&&d[mu]<d[u])
			mu=u;
		for(auto i:e[u])
		{
			int v=i.first,w=i.second;
			if(v==f)
				continue;
			d[v]=d[u]+w;
			dfs0(v,u,t);
			md[u]=max(md[u],md[v]);
			if(t&&md[mx[u]]<md[v])
				mx[u]=v;
		}
	}
	void dfs1(int u,int t)
	{
		a[tp[u]=t].push_back(u);
		if(mx[u])
			dfs1(mx[u],t);
		for(auto i:e[u])
		{
			int v=i.first;
			if(v==fa[u][0]||v==mx[u])
				continue;
			dfs1(v,v);
			len[v]=md[v]-d[u];
		}
	}
	bool cmp(int x,int y){return len[x]>len[y];}
	int init(int x)
	{
		dfs0(x,0,0);
		rt=mu,d[rt]=0;
		dfs0(rt,0,1);
		dfs1(rt,rt);
		len[rt]=md[rt];
		for(int i=1;i<=n;i++)
			if(tp[i]==i)
				s[++k]=i;
		sort(s+1,s+k+1,[&](int i,int j){return len[i]>len[j];});
		for(int i=1;i<=k;i++)
		{
			ans[i]=ans[i-1]+len[s[i]];
			for(int u=s[i];u;u=mx[u])
				c[u]=i;
		}
		return rt;
	}
	int sol(int x,int y,int *b)
	{
		int u=x;
		for(int i=16;i>=0;i--)
			if(c[fa[u][i]]>y)
				u=fa[u][i];
		u=fa[u][0];
		return ans[y]+md[x]-b[u];
	}
	int ask(int x,int y)
	{
		y=2*y-1;
		if(y>=k)
			return ans[k];
		if(c[x]<=y)
			return ans[y];
		return max(sol(x,y-1,d),sol(x,y,md));
	}
}t1,t2;
int main()
{
	scanf("%d%d",&n,&q);
	for(int i=1;i<n;i++)
	{
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		e[u].emplace_back(v,w);
		e[v].emplace_back(u,w);
	}
	t2.init(t1.init(1));
	while(q--)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		x=(x+l-1)%n+1;
		y=(y+l-1)%n+1;
		int ans=max(t1.ask(x,y),t2.ask(x,y));
		printf("%d\n",ans);
		l=ans;
	}
	return 0;
}