#include <cstdio>
#include <algorithm>
#include <cstring>
#include <utility>
#include <vector>
#include <queue>
#include <stack>
#include <functional>
#include <string>
#include <iostream>
#include <set>

using namespace std;
typedef long long lli;
typedef pair<int,int> pii;
typedef pair<lli,lli> pll;
typedef pair<lli,int> pli;

const lli mod = 1e9+7;

int n;
lli cost[200001],sum[200001],cnt[200001],ans=0;
vector<int> adj[200001];

void dfs(int cur,int p) {
	cnt[cur]++;
	for(auto &it:adj[cur]) {
		if(it==p) continue;
		dfs(it,cur);
		sum[cur] = (sum[cur] - sum[it]) % mod;
		sum[cur] = (sum[cur] + cnt[it] * cost[cur] % mod) % mod; 
		cnt[cur] += cnt[it];
	}
	sum[cur] = (sum[cur] + cost[cur]) % mod;
}
void check(int cur,int p,lli cs, lli c) {
	lli ss = (sum[cur] - cs) % mod;
	ss = (ss + cost[cur] * c % mod) % mod;

	ans = (ans + ss) % mod;

	for(auto &it:adj[cur]) {
		if(it==p) continue;
		
		lli tcs = (ss + sum[it] - cost[cur] * cnt[it] % mod) % mod;
		lli tc = n - cnt[it];
		check(it,cur, tcs, tc);
	}
}
int main() {
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%lld",cost+i);
	for(int i=1;i<n;i++) {
		int a,b;
		scanf("%d%d",&a,&b);
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	dfs(1,0);
	check(1,0,0,0);
	ans %= mod;
	if(ans < 0) ans += mod;
	printf("%lld\n",ans);
	
	return 0;
}