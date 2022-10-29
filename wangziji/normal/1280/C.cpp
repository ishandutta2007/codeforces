#include <iostream>
#include <cstdio>
#define int long long
using namespace std;
struct edge
{
	int v,n,w;
}e[1000005];
int head[500005],dp[500005],dp2[500005],cnt,sz[500005],ANS,n;
inline void add(int u,int v,int w)
{
	e[++cnt].v=v;
	e[cnt].n=head[u];
	e[cnt].w=w;
	head[u]=cnt;
}
inline void dfs(int u,int f)
{
	int cnt=0;
	for(int i=head[u];i;i=e[i].n)
	{
		if(e[i].v==f)
			continue;
		dfs(e[i].v,u);
		ANS+=min(sz[e[i].v],n-sz[e[i].v])*e[i].w;
		sz[u]+=sz[e[i].v];
		cnt+=dp2[e[i].v];
		dp[u]+=dp[e[i].v];
		dp[u]+=dp2[e[i].v]*e[i].w;
	}
	++sz[u];
	if(cnt%2==0) dp2[u]=1;
}
signed main(int argc, char** argv) {
	int T;
	cin >> T;
	while(T--)
	{
		cin >> n;
		ANS=0;
		n*=2;
		cnt=0;
		for(int i=1;i<=n;i++) head[i]=dp[i]=dp2[i]=0,sz[i]=0;
		for(int i=1;i<n;i++)
		{
			int u,v,w;
			scanf("%lld%lld%lld",&u,&v,&w);
			add(u,v,w);
			add(v,u,w);
		}
		dfs(1,0);
		cout << dp[1] << " " << ANS << endl;
	}
	return 0;
}