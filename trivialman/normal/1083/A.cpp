#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define repr(i,a,b) for(int i=(a);i>=(b);--i)
#define PB push_back
#define MP make_pair
#define PII pair<int, int>
typedef long long LL;
const LL MOD = 998244353;
const int INF = 0x3fffffff;
const int N = 300010;

vector<PII> g[N];
int n, w[N];
bool vis[N];
LL dp[N], ans=0;

void dfs(int x){
	bool leaf=true;
	LL m1=0ll,m2=0ll;
	vis[x] = true;
	for(auto u:g[x]){
		int to=u.first, len=u.second;
		if(!vis[to]){
			dfs(to);
			leaf = false;
			//cout<<dp[to]-len<<endl;
			if(dp[to]-len>m1){
				m2 = m1;
				m1 = dp[to] - len;
			}else if(dp[to]-len>m2){
				m2 = dp[to] - len;
			}
		}
	}
	if(leaf){
		dp[x] = w[x];
		ans = max(ans, dp[x]);
	}else{
		dp[x] = w[x] + max(m1, 0ll);
		ans = max(ans, w[x] + max(m1,0ll) + max(m2,0ll));
	}
}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("test.in","r",stdin);
	#endif
	scanf("%d",&n);
	rep(i,1,n)scanf("%d",w+i);
	rep(i,1,n-1){
		int u,v,c;
		scanf("%d%d%d",&u,&v,&c);
		g[u].PB(MP(v,c));
		g[v].PB(MP(u,c));
	}
	memset(vis,0,sizeof vis);
	memset(dp,0,sizeof dp);
	dfs(1);
	//rep(i,1,n)cout<<dp[i]<<(i==n?'\n':' ');
	printf("%lld\n",ans);
	return 0;
}