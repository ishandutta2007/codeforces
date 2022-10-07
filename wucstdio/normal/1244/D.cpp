#include<cstdio>
#include<algorithm>
#include<cstring>
#define ll long long
using namespace std;
struct Edge
{
	int to;
	int nxt;
}e[200005];
ll n,c1[100005],c2[100005],c3[100005],s[3][4];
int edgenum,head[100005],d[100005],pa[100005],dep[100005];
void add(int u,int v)
{
	e[++edgenum].to=v;
	e[edgenum].nxt=head[u];
	head[u]=edgenum;
}
void dfs(int node)
{
	dep[node]=(dep[pa[node]]+1)%3;
	for(int hd=head[node];hd;hd=e[hd].nxt)
	{
		int to=e[hd].to;
		if(to==pa[node])continue;
		pa[to]=node;
		dfs(to);
	}
}
int main()
{
	scanf("%lld",&n);
	for(int i=1;i<=n;i++)scanf("%lld",&c1[i]);
	for(int i=1;i<=n;i++)scanf("%lld",&c2[i]);
	for(int i=1;i<=n;i++)scanf("%lld",&c3[i]);
	for(int i=1;i<n;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		add(u,v);
		add(v,u);
		d[u]++,d[v]++;
		if(d[u]>2||d[v]>2)
		{
			printf("-1\n");
			return 0;
		}
	}
	int st=0;
	for(int i=1;i<=n;i++)
	{
		if(d[i]==1)
		{
			st=i;
			break;
		}
	}
	dfs(st);
	for(int i=1;i<=n;i++)s[dep[i]][1]+=c1[i],s[dep[i]][2]+=c2[i],s[dep[i]][3]+=c3[i];
	ll ans=1e18;
	ans=min(ans,s[0][1]+s[1][2]+s[2][3]);
	ans=min(ans,s[0][1]+s[1][3]+s[2][2]);
	ans=min(ans,s[0][2]+s[1][1]+s[2][3]);
	ans=min(ans,s[0][2]+s[1][3]+s[2][1]);
	ans=min(ans,s[0][3]+s[1][1]+s[2][2]);
	ans=min(ans,s[0][3]+s[1][2]+s[2][1]);
	printf("%lld\n",ans);
	for(int i=1;i<=n;i++)
	{
		if(ans==s[0][1]+s[1][2]+s[2][3])
		{
			printf("%d ",dep[i]==0?1:dep[i]==1?2:3);
		}
		else if(ans==s[0][1]+s[1][3]+s[2][2])
		{
			printf("%d ",dep[i]==0?1:dep[i]==1?3:2);
		}
		else if(ans==s[0][2]+s[1][1]+s[2][3])
		{
			printf("%d ",dep[i]==0?2:dep[i]==1?1:3);
		}
		else if(ans==s[0][2]+s[1][3]+s[2][1])
		{
			printf("%d ",dep[i]==0?2:dep[i]==1?3:1);
		}
		else if(ans==s[0][3]+s[1][1]+s[2][2])
		{
			printf("%d ",dep[i]==0?3:dep[i]==1?1:2);
		}
		else
		{
			printf("%d ",dep[i]==0?3:dep[i]==1?2:1);
		}
	}
	return 0;
}