#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define Fast_IO ios::sync_with_stdio(false);
#define int long long
inline int read()
{
	char ch=getchar(); int nega=1; while(!isdigit(ch)) {if(ch=='-') nega=-1; ch=getchar();}
	int ans=0; while(isdigit(ch)) {ans=ans*10+ch-48;ch=getchar();}
	if(nega==-1) return -ans;
	return ans;
}
#define N 300005
int n,lg[N],dep[N];
int w[N],st[N][25],g[N][25][2][2];
int f1[2],f2[2];
struct Edge
{
	int v,w1,w2;
};
vector<Edge> G[N];
void dfs1(int u,int fa)
{
	int v,w1,w2;
	st[u][0]=fa,dep[u]=dep[fa]+1;
	for(int i=0;i<G[u].size();i++)
	{
		v=G[u][i].v,w1=G[u][i].w1,w2=G[u][i].w2;
		if(v==fa) continue;
		dfs1(v,u);
		w[u]=min(w[u],w[v]+w1+w2);
	}
}
void dfs2(int u,int fa)
{
	int v,w1,w2;
	for(int i=0;i<G[u].size();i++)
	{
		v=G[u][i].v,w1=G[u][i].w1,w2=G[u][i].w2;
		if(v==fa) continue;
		w[v]=min(w[v],w[u]+w1+w2);
		dfs2(v,u);
	}
}
void dfs3(int u,int fa)
{
	int v,w1,w2;
	for(int i=0;i<G[u].size();i++)
	{
		v=G[u][i].v,w1=G[u][i].w1,w2=G[u][i].w2;
		if(v==fa) continue;
		dfs3(v,u);
		g[v][0][0][0]=min(w1,w[v]+w2+w[u]);
		g[v][0][1][1]=min(w2,w[v]+w1+w[u]);
		g[v][0][0][1]=min(w[v]+w2,w1+w[u]);
		g[v][0][1][0]=min(w1+w[v],w2+w[u]);
	}
}
int LCA(int u,int v)
{
	if(dep[u]<dep[v]) swap(u,v);
	for(int i=lg[n];i>=0;i--)
	{
		if(dep[st[u][i]]>=dep[v]) u=st[u][i];
	}
	if(u==v) return u;
	for(int i=lg[n];i>=0;i--)
	{
		if(st[u][i]!=st[v][i]) u=st[u][i],v=st[v][i];
	}
	return st[u][0];
}
int solve(int x,int y)
{
	int u=(x+1)/2,v=(y+1)/2;
	if(dep[u]<dep[v]) swap(u,v),swap(x,y);
	int lca=LCA(u,v);
	int t0,t1;
	f1[(x+1)&1]=0,f1[((x+1)&1)^1]=w[u];
	for(int i=lg[n];i>=0;i--)
	{
		if(dep[st[u][i]]>=dep[lca])
		{
			t0=f1[0],t1=f1[1];
			f1[0]=min(t0+g[u][i][0][0],t1+g[u][i][1][0]);
			f1[1]=min(t0+g[u][i][0][1],t1+g[u][i][1][1]);
			u=st[u][i];
		}
	}
	u=v;
	f2[(y+1)&1]=0,f2[((y+1)&1)^1]=w[u];
	for(int i=lg[n];i>=0;i--)
	{
		if(dep[st[u][i]]>=dep[lca])
		{
			t0=f2[0],t1=f2[1];
			f2[0]=min(t0+g[u][i][0][0],t1+g[u][i][1][0]);
			f2[1]=min(t0+g[u][i][0][1],t1+g[u][i][1][1]);
			u=st[u][i];
		}
	}
	return min(f1[0]+f2[0],f1[1]+f2[1]);
}
signed main()
{
#ifdef __LOCAL__
	freopen("in.txt","r",stdin);
#endif
	cin>>n;
	for(int i=2;i<=n;i++) lg[i]=lg[i/2]+1;
	for(int i=1;i<=n;i++) w[i]=read();
	int u,v,w1,w2;
	for(int i=1;i<n;i++)
	{
		u=read(),v=read(),w1=read(),w2=read();
		G[u].pb((Edge){v,w1,w2});
		G[v].pb((Edge){u,w1,w2});
	}
	memset(g,0x1f,sizeof(g));
	dfs1(1,0),dfs2(1,0),dfs3(1,0);
	for(int j=1;j<=lg[n];j++)
	{
		for(int i=1;i<=n;i++)
		{
			st[i][j]=st[st[i][j-1]][j-1];
			st[i][j]=st[st[i][j-1]][j-1];
			g[i][j][0][0]=min(g[i][j-1][0][0]+g[st[i][j-1]][j-1][0][0],g[i][j-1][0][1]+g[st[i][j-1]][j-1][1][0]);
            g[i][j][0][1]=min(g[i][j-1][0][0]+g[st[i][j-1]][j-1][0][1],g[i][j-1][0][1]+g[st[i][j-1]][j-1][1][1]);
            g[i][j][1][0]=min(g[i][j-1][1][0]+g[st[i][j-1]][j-1][0][0],g[i][j-1][1][1]+g[st[i][j-1]][j-1][1][0]);
            g[i][j][1][1]=min(g[i][j-1][1][0]+g[st[i][j-1]][j-1][0][1],g[i][j-1][1][1]+g[st[i][j-1]][j-1][1][1]);
		}
	}
	int m=read();
	for(int i=1;i<=m;i++)
	{
		u=read(),v=read();
		printf("%I64d\n",solve(u,v));
	}
#ifdef __LOCAL__
	printf("Time Used : %d\n",clock());
#endif
	return 0;
}