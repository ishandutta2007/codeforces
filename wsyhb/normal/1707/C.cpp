#include<bits/stdc++.h>
using namespace std;
const int max_n=1e5+5;
int End[max_n<<1],Last[max_n],Next[max_n<<1],E;
inline void add_edge(int x,int y)
{
	End[++E]=y,Next[E]=Last[x],Last[x]=E;
	End[++E]=x,Next[E]=Last[y],Last[y]=E;
}
int fa[max_n];
int get_fa(int x)
{
	return fa[x]!=x?fa[x]=get_fa(fa[x]):x;
}
inline bool merge(int x,int y)
{
	x=get_fa(x),y=get_fa(y);
	if(x!=y)
	{
		fa[x]=y;
		return true;
	}
	return false;
}
int dfn[max_n][2],Time,dep[max_n],Log[max_n],f[max_n][20];
void dfs(int x,int fa)
{
	dfn[x][0]=++Time;
	dep[x]=dep[fa]+1;
	f[x][0]=fa;
	for(int i=1;i<=Log[dep[x]-1];++i)
		f[x][i]=f[f[x][i-1]][i-1];
	for(int i=Last[x];i;i=Next[i])
	{
		int y=End[i];
		if(y!=fa)
			dfs(y,x); 
	}
	dfn[x][1]=Time;
}
inline bool check(int x,int y)
{
	return dfn[x][0]<=dfn[y][0]&&dfn[y][0]<=dfn[x][1];
}
inline int jump(int x,int d)
{
	while(d>0)
	{
		int k=d&(-d);
		x=f[x][Log[k]];
		d^=k;
	}
	return x;
}
int val[max_n];
const int max_m=2e5+5;
int u[max_m],v[max_m];
bool used[max_m];
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	Log[0]=-1;
	for(int i=1;i<=n;++i)
		Log[i]=Log[i>>1]+1;
	for(int i=1;i<=n;++i)
		fa[i]=i;
	for(int i=1;i<=m;++i)
	{
		scanf("%d%d",u+i,v+i);
		if(merge(u[i],v[i]))
		{
			used[i]=true;
			add_edge(u[i],v[i]);
		}
	}
	dfs(1,0);
	for(int i=1;i<=m;++i)
	{
		if(used[i])
			continue;
		int x=u[i],y=v[i];
		if(dfn[x][0]>dfn[y][0])
			swap(x,y);
		if(check(x,y))
		{
			int z=jump(y,dep[y]-dep[x]-1);
			++val[1];
			--val[dfn[z][0]],++val[dfn[z][1]+1];
			++val[dfn[y][0]],--val[dfn[y][1]+1];
		}
		else
		{
			++val[dfn[x][0]],--val[dfn[x][1]+1];
			++val[dfn[y][0]],--val[dfn[y][1]+1];
		}
	}
	for(int i=1;i<=n;++i)
		val[i]+=val[i-1];
	for(int i=1;i<=n;++i)
		putchar((val[dfn[i][0]]==m-n+1)^'0');
	putchar('\n');
	return 0;
}