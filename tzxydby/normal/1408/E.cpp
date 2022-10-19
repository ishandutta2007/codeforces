#include<bits/stdc++.h>
using namespace std;
const int N=200005;
int n,m,s[N],t,a[N],b[N];
struct UnionFind
{
	int parent[N],rnk[N];
	void init(int n)
	{
		for(int i=1;i<=n;i++)
			parent[i]=i,rnk[i]=1;
	}
	int root(int x)
	{
		if(parent[x]!=x)
			parent[x]=root(parent[x]);
		return parent[x];
	}
	int connect(int x,int y)
	{
		int rx=root(x),ry=root(y);
		if(rx==ry)
			return 0;
		if(rnk[rx]>rnk[ry])
		{
			parent[ry]=rx;
			rnk[rx]+=rnk[ry];
		}
		else
		{
			parent[rx]=ry;
			rnk[ry]+=rnk[rx];
		}
		return 1;
	}
}uf;
struct edge
{
	int u,v,c;
	bool operator<(const edge k)const
	{
		return c<k.c;
	}
}e[N];
long long ans;
int main()
{
	scanf("%d%d",&m,&n);
	for(int i=1;i<=m;i++)
		scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)
		scanf("%d",&b[i]);
	for(int i=1;i<=m;i++)
	{
		scanf("%d",&s[i]);
		for(int j=1;j<=s[i];j++)
		{
			int x;
			scanf("%d",&x);
			t++;
			e[t].u=i,e[t].v=m+x,e[t].c=-a[i]-b[x];
		}
	}
	uf.init(n+m);
	sort(e+1,e+t+1);
	for(int i=1;i<=t;i++)
		if(!uf.connect(e[i].u,e[i].v))
			ans-=e[i].c;
	printf("%lld\n",ans);
	return 0;
}