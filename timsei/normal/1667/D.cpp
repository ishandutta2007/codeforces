#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;

int t, n, m, x, y, dp[N][2], du[N], vis[N][2];

vector <int> G[N];

void dfs(int x, int f) {
	int t0 = 0, t1 = 0, t3 = 0;
	for(auto V : G[x]) {
		if(V == f) continue;
		dfs(V, x);
		if(dp[V][0] && dp[V][1]) ++ t3;
		else if(dp[V][0]) ++ t0;
		else if(dp[V][1]) ++ t1;
		else {
			return;
		}
	}
	dp[x][0] = dp[x][1] = 0;
	if(x == 1) return;
	int now = (du[x]), g0 = 0, g1 = 0;
	if(now == 1) {
		dp[x][0] = 0;
		dp[x][1] = 1;
		return;
	}
	// 0
	if(now % 2 == 0) g0 = (now + 1) / 2;
	else g0 = now / 2;
	g1 = now - g0;
	-- g0;
	if(t0 > g0 || t1 > g1 || g0 < 0) {
		dp[x][0] = 0;
	} else dp[x][0] = 1;
	++ g0;
	-- g1;
	if(t1 > g1 || t0 > g0 || g1 < 0) {
		dp[x][1] = 0;
	} else dp[x][1] = 1;
}

void output(int x, int f, int t) {
	int t0 = 0, t1 = 0, t3 = 0;
	vector <int> tr0, tr1, tr3;
	for(auto V : G[x]) {
		if(V == f) continue;
		if(dp[V][0] && dp[V][1]) ++ t3, tr3.push_back(V);
		else if(dp[V][0] == 1) ++ t0, tr0.push_back(V);
		else if(dp[V][1]) ++ t1, tr1.push_back(V);
		else {
			return;
		}
	}
	if(x == 1) return;
	int now = (du[x]), g0 = 0, g1 = 0;
	if(now % 2 == 0) g0 = (now + 1) / 2;
	else g0 = now / 2;
	g1 = now - g0;
	if(!t){	
		-- g0;
		for(auto V : tr3) {
			if(tr0.size() < g0) tr0.push_back(V);
			else tr1.push_back(V);
		}
		bool ok = 0;
		for(int i = now; i >= 1; -- i) {
			if(i % 2 == t) {
				if(!ok) {
					printf("%d %d\n", x, f);
					ok = 1;
					continue;
				}
			}
			if(i % 2) {
				//printf("%d %d\n", x, tr1.back());
				output(tr1.back(), x, 1);
				tr1.pop_back();
			} else {
				//printf("%d %d\n", x, tr0.back());
				output(tr0.back(), x, 0);
				tr0.pop_back();				
			}
		}
		++ g0;
		return;
	}
		-- g1;
		for(auto V : tr3) {
			if(tr0.size() < g0) tr0.push_back(V);
			else tr1.push_back(V);
		}
		bool ok = 0;
		for(int i = now; i >= 1; -- i) {
			if(i % 2 == t) {
				if(!ok) {
					printf("%d %d\n", x, f);
					ok = 1;
					continue;
				}
			}
			if(i % 2) {
				//printf("%d %d\n", x, tr1.back());
				output(tr1.back(), x, 1);
				tr1.pop_back();
			} else {
				//printf("%d %d\n", x, tr0.back());
				output(tr0.back(), x, 0);
				tr0.pop_back();				
			}
		}
		++ g1;
}

void rmain() {
	scanf("%d", &n);
	for(int i = 1; i <= n; ++ i) G[i].clear(), dp[i][0] = dp[i][1] = vis[i][0] = vis[i][1] = du[i] = 0;
	for(int i = 1; i < n; ++ i) scanf("%d%d", &x, &y), G[x].push_back(y), G[y].push_back(x), ++ du[x], ++ du[y];
	dfs(1, 0);
	int now = du[1];
	vector <int> g0, g1, g3;
	for(auto V : G[1]) {
		if(dp[V][0] && dp[V][1]) g3.push_back(V);
		else if(dp[V][0]) g0.push_back(V);
		else if(dp[V][1]) g1.push_back(V);
		else {
			puts("NO");
			return;
		}
	}
	int n0 = 0, n1 = 0;
	if(now & 1) {
		n1 = (now + 1) / 2;
	} else n1 = now / 2;
	n0 = now - n1;
	if(n0 < g0.size() || n1 < g1.size()) {
		puts("NO");
		return;
	}
	puts("YES");
	for(auto V : g3) {
		if(g0.size() < n0) g0.push_back(V);
		else g1.push_back(V);
	}
		for(int i = du[1]; i >= 1; -- i) {
			if(i % 2) {
				//printf("%d %d\n", x, g1.back());
				output(g1.back(), 1, 1);
				g1.pop_back();
			} else {
				//printf("%d %d\n", x, g0.back());
				output(g0.back(), 1, 0);
				g0.pop_back();				
			}
		}
}

int main() {
	for(cin >> t; t --;) {
		rmain();
	}
}