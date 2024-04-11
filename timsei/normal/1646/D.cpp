#include <bits/stdc++.h>
using namespace std;


#define int long long
const int N = 1e6 + 5;

int n, s, t, A[N], fac[N], dep[N];
vector <int> G[N], C[N];
int x, y, cnt[N], du[N];
#define pii pair <int, int>

pii dp[N][2];
int pre[N];

#define mp make_pair
#define fi first
#define se second

pii operator + (pii a, pii b) {
	return mp(a.first + b.first, a.se + b.se);
}

void dfs(int x, int f) {
	dp[x][0] = mp(0, 1);
	dp[x][1] = mp(-1, du[x]);
	for(int i = 0; i < (int) G[x].size(); ++ i) {
		int V = G[x][i];
		if(V == f) continue;
		dfs(V, x);
		dp[x][0] = dp[x][0] + min(dp[V][0], dp[V][1]);
		dp[x][1] = dp[x][1] + dp[V][0];
	}
}

int ans[N];

void solve(int x, int p, int f) {
	ans[x] = (p) * (du[x] - 1) + 1;
	if(p == 1) {
		for(int i = 0; i < (int) G[x].size(); ++ i) {
			int V = G[x][i];
			if(V == f) continue;
			solve(V, 0, x);
		}
	} else {
		for(auto V : G[x]) {
			if(V == f) continue;
			if(dp[V][0] < dp[V][1]) solve(V, 0, x);
			else solve(V, 1, x);
		}
	}
}

main() {
	scanf("%lld", &n);
	for(int i = 1; i < n; ++ i) {
		scanf("%lld%lld", &x, &y);
		G[x].push_back(y);
		G[y].push_back(x);
		++ du[x], ++ du[y];
	}
	if(n == 2) {
		puts("2 2");
		puts("1 1");
		return 0;
	}
	dfs(1, 0);
	int x = 1;
	if(dp[x][0] < dp[x][1]) {
		cout << -dp[x][0].fi <<' ' << dp[x][0].se << endl;
		solve(1, 0, 0);
	} else cout << -dp[x][1].fi <<' ' << dp[x][1].se << endl, solve(1, 1, 0);
	for(int i = 1; i <= n; ++ i) printf("%lld ", ans[i]);
	puts("");
}