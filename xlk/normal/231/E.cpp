#include<stdio.h>
#include<iostream>
#include<vector>
#define fe(i,a) for(__typeof(a.begin()) i=a.begin();i!=a.end();i++)
using namespace std;
int n,m,x,y,z,q,cnt,p=1000000007;
vector<int>a[100020];
int f[100020][17];
int dfn[100020];
int low[100020];
int d[100020];
int c[100020];
int r[100020];
int s[100020],ss;
void mk(int x)
{
	c[x]+=c[f[x][0]];
	fe(i,a[x])
		if(f[*i][0]==x)
			mk(*i);
}
void dfs(int x,int y)
{
	d[x]=d[y]+1;
	f[x][0]=y;
	s[ss++]=x;
	dfn[x]=low[x]=++cnt;
	for(int i=1;i<17;i++)
		f[x][i]=f[f[x][i-1]][i-1];
	fe(i,a[x])
		if(*i!=y)
		{
			if(dfn[*i])
				low[x]=min(low[x],dfn[*i]);
			else
				dfs(*i,x),low[x]=min(low[x],low[*i]);
		}
	if(low[x]==dfn[x])
	{
		int o=0;
		do
			r[s[--ss]]=x,o++;
		while(s[ss]!=x);
		if(o>2)
			c[x]=1;
	}
}
int lca(int x,int y)
{
	if(d[x]<d[y])
		swap(x,y);
	int w=d[x]-d[y];
	for(int i=17;i--;)
		if(w>>i&1)
			x=f[x][i];
	if(x==y)
		return x;
	for(int i=17;i--;)
		if(f[x][i]!=f[y][i])
			x=f[x][i],y=f[y][i];
	return f[x][0];
}
int cal(int y)
{
	long long _=1,x=2;
	for(;y;y>>=1,x=x*x%p)
		y&1?_=_*x%p:0;
	return _;
}
int main()
{
	scanf("%d %d",&n,&m);
	for(int i=0;i<m;i++)
		scanf("%d %d",&x,&y),a[x].push_back(y),a[y].push_back(x);
	dfs(1,0);
	mk(1);
	for(scanf("%d",&q);q--;)
	{
		scanf("%d %d",&x,&y);
		z=lca(x,y);

		printf("%d\n",cal(c[x]+c[y]-2*c[z]+c[r[z]]-c[f[r[z]][0]]));
	}
	return 0;
}