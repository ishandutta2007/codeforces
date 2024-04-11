#include<cstdio>
#include<algorithm>
#include<cstring>
#include<queue>
#define ll long long
using namespace std;
const ll MOD=998244353;
ll quick_pow(ll x,ll a)
{
	ll ans=1;
	while(a)
	{
		if(a&1)ans=ans*x%MOD;
		x=x*x%MOD;
		a>>=1;
	}
	return ans;
}
struct Edge
{
	int to;
	int next;
}e[600005];
int n,m,edgenum,head[300005],c[300005];
queue<int>q;
void add(int u,int v)
{
	e[++edgenum].to=v;
	e[edgenum].next=head[u];
	head[u]=edgenum;
}
int t;
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&m);
		edgenum=0;
		for(int i=1;i<=n;i++)head[i]=0,c[i]=-1;
		for(int i=1;i<=m;i++)
		{
			int u,v;
			scanf("%d%d",&u,&v);
			add(u,v);
			add(v,u);
		}
		int now=1;
		ll ans=1;
		bool flag=1;
		while(1)
		{
			int num1=0,num2=0;
			while(c[now]!=-1&&now<=n)now++;
			if(now>n)break;
			c[now]=1;
			q.push(now);
			while(!q.empty())
			{
				int node=q.front();
				q.pop();
				if(c[node]==0)num1++;
				else num2++;
				for(int hd=head[node];hd;hd=e[hd].next)
				{
					int to=e[hd].to;
					if(c[to]==c[node])
					{
						while(!q.empty())q.pop();
						flag=0;
						break;
					}
					if(c[to]==-1)
					{
						c[to]=!c[node];
						q.push(to);
					}
				}
			}
			if(!flag)break;
			if(num1+num2==1)ans=ans*3%MOD;
			else ans=ans*(quick_pow(2,num1)+quick_pow(2,num2))%MOD;
		}
		if(!flag)printf("0\n");
		else printf("%I64d\n",ans);
	}
	return 0;
}