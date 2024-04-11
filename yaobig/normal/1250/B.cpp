#include<bits/stdc++.h>
#define rep(i,a,n) for(int i=a;i<=n;i++)
#define per(i,a,n) for(int i=n;i>=a;i--)
#define pb push_back
#define mp make_pair
#define FI first
#define SE second
#define maxn 100000
#define mod 1000000007
#define inf 0x3f3f3f3f
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef double db;

vi e[maxn*2+5];
int dfn[maxn*2+5],low[maxn*2+5],cnt,tot;
int sta[maxn*2+5],top,scc[maxn*2+5];
int val[maxn+5];

void tarjan(int now)
{
	dfn[now]=low[now]=++cnt;
	sta[++top]=now;
	for(auto v: e[now])
	{
		if(dfn[v]==0)
		{
			tarjan(v);
			low[now]=min(low[now],low[v]);
		}
		else if(scc[v]==0) low[now]=min(low[now],dfn[v]);
	}
	if(low[now]==dfn[now])
	{
		tot++;
		while(sta[top]!=now) scc[sta[top--]]=tot;
		scc[sta[top--]]=tot;
	}
}

int a[maxn+5];
vi lst[maxn+5];

int main()
{
	int n,m; scanf("%d%d",&n,&m);
	rep(i,1,n) scanf("%d",&a[i]);
	rep(i,1,m)
	{
		int k; scanf("%d",&k);
		while(k--)
		{
			int x; scanf("%d",&x);
			lst[x].pb(i);
		}
	}
	rep(i,1,n)
	{
		assert(lst[i].size()==2);
		int x=lst[i][0]*2-1,nx=lst[i][0]*2;
		int y=lst[i][1]*2-1,ny=lst[i][1]*2;
		if(a[i]==0)
		{
			e[nx].pb(y);
			e[ny].pb(x);
			e[x].pb(ny);
			e[y].pb(nx);
		}
		else
		{
			e[x].pb(y);
			e[y].pb(x);
			e[nx].pb(ny);
			e[ny].pb(nx);
		}
	}

	rep(i,1,m*2) if(dfn[i]==0) tarjan(i);
	bool f=1;
	rep(i,1,m) if(scc[i*2-1]==scc[i*2]) f=0;
	puts(f?"YES":"NO");
	return 0;
}