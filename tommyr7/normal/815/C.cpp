#include <bits/stdc++.h>
#define Maxn 5007
#define Maxm 30007
#define inf 1e9+7
using namespace std;
int read()
{
	int x=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9'){if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
int last[Maxn],other[Maxm],pre[Maxm];
int d[Maxn],c[Maxn],size[Maxn];
int n,cnt=0,S;
int f[Maxn][Maxn][3];
int g1[Maxn],g2[Maxn],g3[Maxn];
void insert(int u,int v)
{
	other[++cnt]=v,pre[cnt]=last[u],last[u]=cnt;
}
void dfs(int u,int fa)
{
	size[u]=1;
	f[u][0][0]=0,f[u][0][1]=inf,f[u][0][2]=inf;
	f[u][1][0]=inf,f[u][1][1]=c[u],f[u][1][2]=c[u]-d[u];
	for (int q=last[u];q;q=pre[q])
	{
		int v=other[q];
		if (v!=fa)
		{
			dfs(v,u);
			for (int i=0;i<=n;i++) g1[i]=inf,g2[i]=inf,g3[i]=inf;
			for (int i=0;i<=size[u];i++)
				for (int j=0;j<=size[v];j++)
				{
					g1[i+j]=min(g1[i+j],f[u][i][0]+min(f[v][j][1],f[v][j][0]));
					g2[i+j]=min(g2[i+j],f[u][i][1]+min(f[v][j][0],f[v][j][1]));
					g3[i+j]=min(g3[i+j],f[u][i][2]+min(f[v][j][0],f[v][j][2]));
				}
			size[u]+=size[v];
			for (int i=0;i<=size[u];i++) f[u][i][0]=g1[i],f[u][i][1]=g2[i],f[u][i][2]=g3[i];
		}
	}
}
int main()
{
	n=read(),S=read();
	memset(last,0,sizeof(last));
	memset(size,0,sizeof(size));
	for (int i=1;i<=n;i++)
	{
		c[i]=read(),d[i]=read();
		if (i>1)
		{
			int x=read();
			insert(x,i),insert(i,x);
		}
	}
	dfs(1,-1);
	int ans=0;
	for (int i=1;i<=n;i++)
		if (f[1][i][0]<=S||f[1][i][1]<=S||f[1][i][2]<=S) ans=i;
	printf("%d\n",ans);
	return 0;
}