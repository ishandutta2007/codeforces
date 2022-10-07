#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
const int INF=2147483647;
struct Edge
{
	int to;
	int nxt;
	int flow;
	int cost;
}e[200005];
int n,m,s,t,edgenum=1,head[10005],a[10005],c[10005],from[10005];
char ss[2000005],tt[2000005];
int num[56][56];
queue<int>q;
void add(int u,int v,int f,int c)
{
	e[++edgenum].cost=c;
	e[edgenum].flow=f;
	e[edgenum].to=v;
	e[edgenum].nxt=head[u];
	head[u]=edgenum;
}
bool SPFA()
{
	while(!q.empty()) q.pop();
	memset(c,0x3f,sizeof(c));
	c[s]=0;
	a[s]=INF;
	q.push(s);
	while(!q.empty())
	{
		int node=q.front();
		q.pop();
		for(int hd=head[node];hd;hd=e[hd].nxt)
		{
			if(e[hd].flow==0)continue;
			int to=e[hd].to;
			if(c[to]>c[node]+e[hd].cost)
			{
				c[to]=c[node]+e[hd].cost;
				a[to]=min(a[node],e[hd].flow);
				from[to]=hd;
				q.push(to);
			}
		}
	}
	return c[t]<1000000000;
}
int solve()
{
	int ans=0;
	while(SPFA())
	{
		ans+=a[t]*c[t];
		int x=t;
		while(x)
		{
			int hd=from[x];
			e[hd].flow-=a[t];
			e[hd^1].flow+=a[t];
			x=e[hd^1].to;
		}
	}
	return ans;
}
int main()
{
	scanf("%d%d",&n,&m);
	scanf("%s%s",ss+1,tt+1);
	for(int i=1;i<=n;i++)
	{
		int x=ss[i]>='a'?ss[i]-'a'+1:ss[i]-'A'+27;
		int y=tt[i]>='a'?tt[i]-'a'+1:tt[i]-'A'+27;
		num[x][y]++;
	}
	s=2*m+1,t=2*m+2;
	for(int i=1;i<=m;i++)
	  for(int j=1;j<=m;j++)
	    add(i,j+m,1,-num[i][j]),add(j+m,i,0,num[i][j]);
	for(int i=1;i<=m;i++)
	{
		add(s,i,1,0);
		add(i,s,0,0);
		add(i+m,t,1,0);
		add(t,i+m,0,0);
	}
	printf("%d\n",-solve());
	for(int i=1;i<=m;i++)
	{
		int ans=0;
		for(int hd=head[i];hd;hd=e[hd].nxt)
		{
			if(e[hd].flow==0&&e[hd].to<=2*m)
			{
				ans=e[hd].to-m;
				break;
			}
		}
		putchar(ans<=26?ans+'a'-1:ans-26+'A'-1);
	}
	putchar('\n');
	return 0;
}