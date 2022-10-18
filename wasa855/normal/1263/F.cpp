#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define Fast_IO ios::sync_with_stdio(false);
#define fir first
#define sec second
inline int read()
{
	char ch=getchar(); int nega=1; while(!isdigit(ch)) {if(ch=='-') nega=-1; ch=getchar();}
	int ans=0; while(isdigit(ch)) {ans=ans*10+ch-48;ch=getchar();}
	if(nega==-1) return -ans;
	return ans;
}
typedef pair<int,int> pii;
#define N 2005
int n;
struct Tree
{
	vector<int> G[N];
	int a[N];
	int siz[N],son[N],dep[N],fa[N],top[N];
	int m;
	void get()
	{
		m=read();
//		cout<<"**"<<m<<endl;
		for(int i=2;i<=m;i++)
		{
			fa[i]=read();
			G[fa[i]].pb(i);
		}
		for(int i=1;i<=n;i++) a[i]=read();
		dfs1(1,1);
		dfs2(1,1);
	}
	void dfs1(int u,int de)
	{
		siz[u]=1,dep[u]=de;
		for(int v:G[u])
		{
			dfs1(v,de+1);
			siz[u]+=siz[v];
			if(siz[v]>siz[son[u]]) son[u]=v;
		}
	}
	void dfs2(int u,int topf)
	{
		top[u]=topf;
		if(!son[u]) return ;
		dfs2(son[u],topf);
		for(int v:G[u])
		{
			if(v!=son[u]) dfs2(v,v);
		}
	}
	int lca(int u,int v)
	{
		while(top[u]!=top[v])
		{
			if(dep[top[u]]<dep[top[v]]) v=fa[top[v]];
			else u=fa[top[u]];
		}
//		printf("%d %d\n",u,v);
		if(dep[u]>dep[v]) return v;
		return u;
	}
	int dis(int u,int v)
	{
		if(u==0) return dep[v]-1;
		return dep[v]-dep[lca(u,v)];
	}
};
Tree t[2];
int f[N][N][2];
signed main()
{
#ifdef __LOCAL__
	freopen("in.txt","r",stdin);
#endif
	n=read();
	t[0].get();
	t[1].get();
//	cout<<t[0].dis(0,3)<<endl;
//	return 0;
//	cout<<"Passed\n";
	for(int i=0;i<=n;i++)
	{
		for(int j=0;j<=n;j++)
		{
			for(int k=0;k<=1;k++) f[i][j][k]=1e6;
		}
	}
	f[0][0][0]=0;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<=i;j++)
		{
			for(int k=0;k<=1;k++)
			{
				int d[2]={k?j:i,k?i:j};
				for(int c=0;c<=1;c++)
				{
					int v=t[c].dis(t[c].a[d[c]],t[c].a[i+1])+f[i][j][k];
					if(v<f[i+1][d[c^1]][c]) f[i+1][d[c^1]][c]=v;
				}
			}
		}
	}
	int ans=1e6;
	for(int j=0;j<=n;j++)
	{
		for(int k=0;k<=1;k++)
		{
			if(f[n][j][k]<ans) ans=f[n][j][k];
		}
	}
	cout<<t[0].m+t[1].m-2-ans<<endl;
#ifdef __LOCAL__
	printf("Time Used : %d\n",clock());
#endif
	return 0;
}