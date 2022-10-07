#include<cstdio>
#include<algorithm>
#include<cstring>
#define ll long long
using namespace std;
const ll MOD=1000000007;
struct Edge
{
	int to;
	int nxt;
	int opt;
}e[400005];
ll f[100005][2][2][2];
int n,m,edgenum=1,head[100005],d[100005],c1[100005],c0[100005],pa[100005];
bool vis[100005],ban[400005];
void add(int u,int v,int t)
{
	e[++edgenum].opt=t;
	e[edgenum].to=v;
	e[edgenum].nxt=head[u];
	head[u]=edgenum;
}
void DP(int node)
{
	vis[node]=1;
	bool flag=0;
	for(int hd=head[node];hd;hd=e[hd].nxt)
	{
		if(ban[hd>>1])continue;
		int to=e[hd].to;
		if(to==pa[node])continue;
		pa[to]=node;
		DP(to);
		flag=1;
		int u=e[hd].opt,v=e[hd^1].opt;
		f[node][0][0][0]=(f[node][0][0][0]+f[to][0][u|v][0]+f[to][1][(u^1)|v][0])%MOD;
		f[node][0][0][1]=(f[node][0][0][1]+f[to][0][u|v][1]+f[to][1][(u^1)|v][1])%MOD;
		f[node][0][1][0]=(f[node][0][1][0]+f[to][0][1^(u|v)][0]+f[to][1][1^((u^1)|v)][0])%MOD;
		f[node][0][1][1]=(f[node][0][1][1]+f[to][0][1^(u|v)][1]+f[to][1][1^((u^1)|v)][1])%MOD;
		f[node][1][0][0]=(f[node][1][0][0]+f[to][0][u|(v^1)][0]+f[to][1][(u^1)|(v^1)][0])%MOD;
		f[node][1][0][1]=(f[node][1][0][1]+f[to][0][u|(v^1)][1]+f[to][1][(u^1)|(v^1)][1])%MOD;
		f[node][1][1][0]=(f[node][1][1][0]+f[to][0][1^(u|(v^1))][0]+f[to][1][1^((u^1)|(v^1))][0])%MOD;
		f[node][1][1][1]=(f[node][1][1][1]+f[to][0][1^(u|(v^1))][1]+f[to][1][1^((u^1)|(v^1))][1])%MOD;
	}
	if(!flag)
	{
		f[node][1][c1[node]][1]=1;
		f[node][0][c0[node]][0]=1;
	}
}
int main()
{
	scanf("%d%d",&n,&m);
	bool cnt=0;
	for(int i=1;i<=n;i++)
	{
		int k,x,y;
		scanf("%d",&k);
		if(k==1)
		{
			scanf("%d",&x);
			if(x>0)c1[x]^=1;
			else c0[-x]^=1;
		}
		else
		{
			scanf("%d%d",&x,&y);
			if(x==y)
			{
				if(x<0)c0[-x]^=1;
				else c1[x]^=1;
			}
			else if(x+y==0)cnt^=1;
			else
			{
				add(abs(x),abs(y),y<0);
				add(abs(y),abs(x),x<0);
				d[abs(x)]++,d[abs(y)]++;
			}
		}
	}
	ll ans0=1,ans1=0;
	if(cnt)swap(ans0,ans1);
	for(int i=1;i<=m;i++)
	{
		if(d[i]==1&&!vis[i])
		{
			DP(i);
			ll v0=0,v1=0;
			v0+=ans0*(f[i][0][c0[i]][0]+f[i][0][c0[i]][1])%MOD;
			v0+=ans0*(f[i][1][c1[i]][0]+f[i][1][c1[i]][1])%MOD;
			v0+=ans1*(f[i][0][c0[i]^1][0]+f[i][0][c0[i]^1][1])%MOD;
			v0+=ans1*(f[i][1][c1[i]^1][0]+f[i][1][c1[i]^1][1])%MOD;
			v1+=ans0*(f[i][0][c0[i]^1][0]+f[i][0][c0[i]^1][1])%MOD;
			v1+=ans0*(f[i][1][c1[i]^1][0]+f[i][1][c1[i]^1][1])%MOD;
			v1+=ans1*(f[i][0][c0[i]][0]+f[i][0][c0[i]][1])%MOD;
			v1+=ans1*(f[i][1][c1[i]][0]+f[i][1][c1[i]][1])%MOD;
			ans0=v0%MOD,ans1=v1%MOD;
		}
		if(d[i]==0&&!vis[i])
		{
			vis[i]=1;
			f[i][1][0][1]=1;
			f[i][0][0][0]=1;
			ll v0=0,v1=0;
			v0+=ans0*(f[i][0][c0[i]][0]+f[i][1][c1[i]][1])%MOD;
			v0+=ans1*(f[i][0][c0[i]^1][0]+f[i][1][c1[i]^1][1])%MOD;
			v1+=ans0*(f[i][0][c0[i]^1][0]+f[i][1][c1[i]^1][1])%MOD;
			v1+=ans1*(f[i][0][c0[i]][0]+f[i][1][c1[i]][1])%MOD;
			ans0=v0%MOD,ans1=v1%MOD;
		}
	}
	for(int i=1;i<=m;i++)
	{
		if(!vis[i])
		{
			ban[head[i]>>1]=1;
			DP(i);
			int u=e[head[i]].opt;
			int v=e[head[i]^1].opt;
			ll v0=0,v1=0;
			v0+=ans0*(f[i][0][c0[i]^((u^0)|(v^0))][0]+f[i][0][c0[i]^((u^1)|(v^0))][1])%MOD;
			v0+=ans0*(f[i][1][c1[i]^((u^0)|(v^1))][0]+f[i][1][c1[i]^((u^1)|(v^1))][1])%MOD;
			v0+=ans1*(f[i][0][c0[i]^1^((u^0)|(v^0))][0]+f[i][0][c0[i]^1^((u^1)|(v^0))][1])%MOD;
			v0+=ans1*(f[i][1][c1[i]^1^((u^0)|(v^1))][0]+f[i][1][c1[i]^1^((u^1)|(v^1))][1])%MOD;
			v1+=ans0*(f[i][0][c0[i]^1^((u^0)|(v^0))][0]+f[i][0][c0[i]^1^((u^1)|(v^0))][1])%MOD;
			v1+=ans0*(f[i][1][c1[i]^1^((u^0)|(v^1))][0]+f[i][1][c1[i]^1^((u^1)|(v^1))][1])%MOD;
			v1+=ans1*(f[i][0][c0[i]^((u^0)|(v^0))][0]+f[i][0][c0[i]^((u^1)|(v^0))][1])%MOD;
			v1+=ans1*(f[i][1][c1[i]^((u^0)|(v^1))][0]+f[i][1][c1[i]^((u^1)|(v^1))][1])%MOD;
			ans0=v0%MOD,ans1=v1%MOD;
		}
	}
	printf("%lld\n",ans1);
	return 0;
}