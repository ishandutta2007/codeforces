#include<bits/stdc++.h>
const int N=100010;
typedef struct edge
{
	long long next,to;
};
typedef struct point
{
	double total,ans;
	long long first,sum;
};
long long e=0;
edge edg[N];
point poi[N];
void addedge(long long u,long long v)
{
	edg[++e].to=v;
	edg[e].next=poi[u].first;
	poi[u].first=e;
}
void dfs1(int i)
{
	long long j,sum=1;
	for (j=poi[i].first;j;j=edg[j].next)
	{
		dfs1(edg[j].to);
		sum+=poi[edg[j].to].sum;
	}
	poi[i].sum=sum;
}
void dfs2(long long i)
{
	long long j;
	poi[i].ans=poi[i].total/poi[i].sum-(poi[i].sum-1)/2.0;
	for (j=poi[i].first;j;j=edg[j].next)
	{
		poi[edg[j].to].total=(poi[i].total-poi[i].ans)*poi[edg[j].to].sum/(poi[i].sum-1);
		dfs2(edg[j].to);
	}
}
int main()
{
	long long n,p,i;
	memset(edg,0,sizeof(edg));
	memset(poi,0,sizeof(poi));
	scanf("%I64d",&n);
	for (i=2;i<=n;i++)
	{
		scanf("%I64d",&p);
		addedge(p,i);
	}
	dfs1(1);
	poi[1].total=n*(n+1)/2;
	dfs2(1);
	for (i=1;i<=n;i++)
		printf("%lf ",poi[i].ans);
	return 0;
}