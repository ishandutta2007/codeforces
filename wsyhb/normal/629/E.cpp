#include<bits/stdc++.h>
using namespace std;
int n,m;
const int max_n=1e5+5;
int End[max_n<<1],Last[max_n],Next[max_n<<1],E=1;
inline void add_edge(int x,int y)
{
	End[++E]=y,Next[E]=Last[x],Last[x]=E;
	End[++E]=x,Next[E]=Last[y],Last[y]=E;
}
long long sum_in[max_n];
int sz[max_n];
void dfs1(int x,int fa)
{
	sz[x]=1;
	for(int i=Last[x];i;i=Next[i])
	{
		int y=End[i];
		if(y!=fa)
		{
			dfs1(y,x);
			sz[x]+=sz[y];
			sum_in[x]+=sum_in[y]+sz[y];
		}
	}
}
long long sum_all[max_n];
void dfs2(int x,int fa)
{
	sum_all[x]=sum_in[x];
	if(fa)
		sum_all[x]+=(sum_all[fa]-sum_in[x]-sz[x])+(n-sz[x]);
	for(int i=Last[x];i;i=Next[i])
	{
		int y=End[i];
		if(y!=fa)
			dfs2(y,x);
	}
}
int dep[max_n],f[max_n][17],Log[max_n];
void dfs3(int x,int fa)
{
	dep[x]=dep[fa]+1;
	f[x][0]=fa;
	for(int i=1;i<=Log[dep[x]-1];++i)
		f[x][i]=f[f[x][i-1]][i-1];
	for(int i=Last[x];i;i=Next[i])
	{
		int y=End[i];
		if(y!=fa)
			dfs3(y,x);
	}
}
inline int jump(int x,int d)
{
	while(d>0)
	{
		int k=Log[d];
		x=f[x][k];
		d^=1<<k;
	}
	return x;
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n-1;++i)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		add_edge(a,b);
	}
	Log[0]=-1;
	for(int i=1;i<=n;++i)
		Log[i]=Log[i>>1]+1;
	dfs1(1,0),dfs2(1,0),dfs3(1,0);
	while(m--)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		if(dep[u]>dep[v])
			swap(u,v);
		int key=jump(v,dep[v]-dep[u]-1);
//		fprintf(stderr,"key=%d\n",key);
		double ans;
		if(f[key][0]!=u)
		{
			int x=u,y=(dep[v]==dep[u]?v:f[key][0]);
			for(int i=Log[dep[u]-1];i>=0;--i)
			{
				if(f[x][i]!=f[y][i])
					x=f[x][i],y=f[y][i];
			}
			ans=(dep[u]+dep[v]-(dep[x]<<1)+2)+1.0*sum_in[u]/sz[u]+1.0*sum_in[v]/sz[v];
		}
		else
			ans=(dep[v]-dep[u])+1.0*(sum_all[u]-sum_in[key]-sz[key])/(n-sz[key])+1.0*sum_in[v]/sz[v];
		printf("%.8lf\n",ans+1);
	}
	return 0;
}