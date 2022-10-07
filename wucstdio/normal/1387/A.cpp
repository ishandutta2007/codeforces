#include<cstdio>
#include<algorithm>
#include<cstring>
#define ll long long
using namespace std;
struct Edge
{
	int to;
	int nxt;
	int len;
}e[400005];
int n,m,edgenum=1,head[100005],pa[100005],a[100005],b[100005];
bool vis[100005];
ll ans;
void add(int u,int v,int l)
{
	e[++edgenum].len=l;
	e[edgenum].to=v;
	e[edgenum].nxt=head[u];
	head[u]=edgenum;
}
bool flag;
int val;
int zero[100005],top;
void dfs(int node)
{
	vis[node]=1;
	for(int hd=head[node];hd;hd=e[hd].nxt)
	{
		int to=e[hd].to;
		if((hd>>1)==pa[node])continue;
		if(vis[to])
		{
			int aa=-a[node];
			int bb=e[hd].len-b[node];
			if(aa==a[to])
			{
				if(bb==b[to])continue;
				printf("NO\n");
				exit(0);
			}
			else
			{
				int cur=(bb-b[to])/(a[to]-aa);
				if(flag&&val!=cur)
				{
					printf("NO\n");
					exit(0);
				}
				flag=1;
				val=cur;
			}
		}
		else
		{
			a[to]=-a[node];
			b[to]=e[hd].len-b[node];
			pa[to]=(hd>>1);
			dfs(to);
		}
	}
}
void solve(int node)
{
	zero[++top]=-b[node]/a[node];
	for(int hd=head[node];hd;hd=e[hd].nxt)
	{
		int to=e[hd].to;
		if(pa[to]==(hd>>1))solve(to);
	}
}
void calc(int node)
{
	a[node]=a[node]*val+b[node];
	for(int hd=head[node];hd;hd=e[hd].nxt)
	{
		int to=e[hd].to;
		if(pa[to]==(hd>>1))calc(to);
	}
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
	{
		int u,v,l;
		scanf("%d%d%d",&u,&v,&l);
		l*=2;
		add(u,v,l);
		add(v,u,l);
	}
	for(int i=1;i<=n;i++)
	{
		if(vis[i])continue;
		val=flag=0;
		a[i]=1;
		dfs(i);
		if(!flag)
		{
			top=0;
			solve(i);
			sort(zero+1,zero+top+1);
			flag=1;
			val=zero[(top+1)/2];
		}
		calc(i);
	}
	printf("YES\n");
	for(int i=1;i<=n;i++)printf("%lf ",a[i]/2.0);
	printf("\n");
	return 0;
}