#include <bits/stdc++.h>
using namespace std;
int n,m,t;
const int Maxn=300005;
const int p=998244353;
long long fast_pow(long long x,long long y)
{
	long long ans=1,now=x;
	while(y)
	{
		if(y&1) ans=(ans*now)%p;
		now=(now*now)%p;
		y>>=1;
	}
	return ans;
}
int all,head[Maxn],cnt,ct,odd,sta[Maxn],top;
long long tot=1,ans[Maxn];
bool vis[Maxn],pnt[Maxn];
struct edg
{
	int nxt,to;
}edge[2*Maxn];
void add(int x,int y)
{
	edge[++cnt]=(edg){head[x],y};
	head[x]=cnt;
}
bool dfs(int u)
{
	if(!pnt[u]) odd++;
	vis[u]=true;
	all++;
	for(int i=head[u];i;i=edge[i].nxt)
	{
		int to=edge[i].to;
		if(vis[to]&&(!(pnt[to]^pnt[u]))) return false;
		if(vis[to]) continue;
		pnt[to]=pnt[u]^1;
		if(!dfs(to)) return false;
	}
	return true;
}
int main()
{
//	freopen("D.in","r",stdin);
	scanf("%d",&t);
	while(t--)
	{
		cnt=0;
		ct=0;
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;i++)
			head[i]=vis[i]=pnt[i]=0;
		for(int i=1;i<=m;i++)
		{
			int a,b;
			scanf("%d%d",&a,&b);
			add(a,b);
			add(b,a);
		}
		for(int i=1;i<=n;i++)
			if(!vis[i])
			{
				odd=0;
				all=0;
				vis[i]=true;
				ct++;
				pnt[i]=true;
				if(dfs(i))
					ans[ct]=((fast_pow(2,odd))+fast_pow(2,all-odd))%p;
				else ans[ct]=0;
			}
		for(int i=1;i<=ct;i++)
			tot=tot*ans[i]%p;
		printf("%lld\n",tot);
		tot=1;
	}
	return 0;
}