#include <bits/stdc++.h>
#define Maxn 207
using namespace std;
int n,root;
int last[Maxn],other[Maxn],pre[Maxn],cnt=0;
int fa[Maxn],size[Maxn];
double f[Maxn][Maxn],g[Maxn][Maxn];
void insert(int u,int v)
{
	other[++cnt]=v,pre[cnt]=last[u],last[u]=cnt;
}
void pre_dfs(int u,int f)
{
	fa[u]=f;
	size[u]=1;
	for (int q=last[u];q;q=pre[q])
	{
		int v=other[q];
		if (v!=f)
		{
			pre_dfs(v,u);
			size[u]+=size[v];
		}
	}
}
void dfs(int u,int ff)
{
	g[u][0]=1.0;
	int now=0;
	for (int q=last[u];q;q=pre[q])
	{
		int v=other[q];
		if (v!=ff)
		{
			dfs(v,u);
			for (int i=now;i>=0;i--)
			{
				double tmp=1.0*g[u][i];
				g[u][i]=0.0;
				for (int j=0;j<=size[v];j++)
					g[u][i+j]+=1.0*tmp*f[v][j];
			}
			now+=size[v];
		}
	}
	for (int i=0;i<size[u];i++)
	{
		double tmp=1.0;
		for (int j=0;j<=i;j++)
		{
			f[u][i-j]+=0.5*tmp*g[u][i];
			tmp*=(double)(1.0*(i-j))/(1.0*(size[u]-i+j));
		}
	}
	for (int i=0;i<size[u];i++)
		f[u][i]=(double)(1.0*f[u][i]/(1.0*(size[u]-i)));
	for (int i=0;i<size[u];i++)
		f[u][i+1]+=g[u][i];
}
int main()
{
	scanf("%d",&n);
	for (int i=1;i<n;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		insert(u,v),insert(v,u);
	}
	for (int i=1;i<=n;i++)
	{
		root=i;
		memset(f,0,sizeof(f));
		memset(g,0,sizeof(g));
		memset(size,0,sizeof(size));
		memset(fa,0,sizeof(fa));
		pre_dfs(root,0);
		dfs(root,0);
		double ans=1.0;
		for (int q=last[root];q;q=pre[q])
		{
			int v=other[q];
			ans*=1.0*f[v][0];
		}
		printf("%.10lf\n",ans);
	}
	return 0;
}