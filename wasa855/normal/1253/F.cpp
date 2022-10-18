#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define Fast_IO ios::sync_with_stdio(false);
#define fir first
#define sec second
#define mod 998244353
#define int long long
#define INF (int)(2e18)
inline int read()
{
	char ch=getchar(); int nega=1; while(!isdigit(ch)) {if(ch=='-') nega=-1; ch=getchar();}
	int ans=0; while(isdigit(ch)) {ans=ans*10+ch-48;ch=getchar();}
	if(nega==-1) return -ans;
	return ans;
}
typedef pair<int,int> pii;
int add(int x,int y){return x+y>mod?x+y-mod:x+y;}
int sub(int x,int y){return x-y<0?x-y+mod:x-y;}
int n,m,k,q;
#define N 300005
vector<pii> G[N],G2[N];
int dis[N];
struct Node
{
	int w,id;
	bool operator < (const Node &x) const
	{
		return w>x.w;
	}
};
void dij()
{
	priority_queue<Node> q;
	for(int i=1;i<=n;i++) dis[i]=INF;
	for(int i=1;i<=k;i++)
	{
		dis[i]=0,q.push((Node){0,i});
	}
	while(!q.empty())
	{
		Node t=q.top();
		q.pop();
		if(t.w!=dis[t.id]) continue;
		for(pii v:G[t.id])
		{
			if(dis[v.fir]>dis[t.id]+v.sec)
			{
				dis[v.fir]=dis[t.id]+v.sec;
				q.push((Node){dis[v.fir],v.fir});
			}
		}
	}
}
struct Edge
{
	int u,v,w;
};
Edge edge[N*2];
bool cmp(Edge x,Edge y)
{
	return x.w<y.w;
}
int fa[N][25],val[N][25];
int dep[N];
int Fa[N];
int find(int u)
{
	return u==Fa[u]?u:Fa[u]=find(Fa[u]);
}
void dfs(int u)
{
	for(pii v:G2[u])
	{
		if(v.fir==fa[u][0]) continue;
		fa[v.fir][0]=u,val[v.fir][0]=v.sec;
		dep[v.fir]=dep[u]+1;
		dfs(v.fir);
	}
}
int lca(int u,int v)
{
	int ans=0;
	if(dep[u]<dep[v]) swap(u,v);
	for(int i=20;i>=0;i--)
	{
		if(fa[u][i]!=0&&dep[fa[u][i]]>=dep[v])
		{
			ans=max(ans,val[u][i]);
			u=fa[u][i];
		}
	}
	if(u==v) return ans;
	for(int i=20;i>=0;i--)
	{
		if(fa[u][i]!=0&&fa[v][i]!=0)
		{
			if(fa[u][i]!=fa[v][i])
			{
				ans=max(ans,max(val[u][i],val[v][i]));
				u=fa[u][i],v=fa[v][i];
			}
		}
	}
	ans=max(ans,max(val[u][0],val[v][0]));
	return ans;
}
signed main()
{
#ifdef __LOCAL__
	freopen("in.txt","r",stdin);
#endif
	cin>>n>>m>>k>>q;
	for(int i=1;i<=m;i++)
	{
		int u=read(),v=read(),w=read();
		G[u].pb(mp(v,w)),G[v].pb(mp(u,w));
	}
	dij();
	int cnt=0;
	for(int i=1;i<=n;i++)
	{
		for(pii v:G[i])
		{
			edge[++cnt]=(Edge){i,v.fir,dis[i]+dis[v.fir]+v.sec};
		}
	}
	sort(edge+1,edge+cnt+1,cmp);
	for(int i=1;i<=n;i++) Fa[i]=i;
	for(int i=1;i<=cnt;i++)
	{
		int u=find(edge[i].u),v=find(edge[i].v);
		if(u!=v)
		{
			Fa[u]=v;
//			printf("%lld %lld %lld\n",edge[i].u,edge[i].v,edge[i].w);
			G2[edge[i].u].pb(mp(edge[i].v,edge[i].w));
			G2[edge[i].v].pb(mp(edge[i].u,edge[i].w));
		}
	}
	dep[1]=1;
	dfs(1);
//	cout<<"Passed\n";
//	for(int i=1;i<=n;i++)
//	{
//		for(int j=0;j<=4;j++) printf("%lld ",fa[i][j]); cout<<"\n";
//	}
//	cout<<"\n";
//	for(int i=1;i<=n;i++)
//	{
//		for(int j=0;j<=4;j++) printf("%lld ",val[i][j]); cout<<"\n";
//	}
//	cout<<"\n";
	for(int i=1;i<=20;i++)
	{
		for(int j=1;j<=n;j++)
		{
			fa[j][i]=fa[fa[j][i-1]][i-1];
			val[j][i]=max(val[j][i-1],val[fa[j][i-1]][i-1]);
		}
	}
//	for(int i=1;i<=n;i++)
//	{
//		for(int j=0;j<=4;j++) printf("%lld ",fa[i][j]); cout<<"\n";
//	}
//	cout<<"\n";
//	for(int i=1;i<=n;i++)
//	{
//		for(int j=0;j<=4;j++) printf("%lld ",val[i][j]); cout<<"\n";
//	}
//	cout<<"\n";
	for(int i=1;i<=q;i++)
	{
		int u=read(),v=read();
		printf("%lld\n",lca(u,v));
	}
#ifdef __LOCAL__
	cout<<"Time Used : "<<clock()<<endl;
#endif
	return 0;
}