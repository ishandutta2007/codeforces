#include <bits/stdc++.h>
// iostream is too mainstream
#include <cstdio>
// bitch please
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <list>
#include <cmath>
#include <iomanip>
#include <time.h>
#define dibs reserve
#define OVER9000 1234567890
#define ALL_THE(CAKE,LIE) for(auto LIE =CAKE.begin(); LIE != CAKE.end(); LIE++)
#define tisic 47
#define soclose 1e-8
#define chocolate win
// so much chocolate
#define patkan 9
#define ff first
#define ss second
#define abs(x) (((x) < 0)?-(x):(x))
#define uint unsigned int
#define dbl long double
#define pi 3.14159265358979323846
using namespace std;
// mylittledoge

using cat = long long;

#ifdef DONLINE_JUDGE
	// palindromic tree is better than splay tree!
	#define lld I64d
#endif

cat mod = 1000000007;

void DFS(int R, auto & E, auto & G, auto & par, auto & dep, auto & cyc_min, auto & cyc_max, auto & adj) {
	for(auto id : G[R]) {
		if(id == par[R]) continue;
		int s = E[id];
		if(par[s] == -1) {
			par[s] = id^1;
			dep[s] = dep[R]+1;
			DFS(s, E, G, par, dep, cyc_min, cyc_max, adj);
		}
		else if(dep[s] < dep[R]) {
			int mi = id/2, mx = id/2, cur = R;
			vector<int> e = {id/2};
			while(cur != E[id]) {
				mi = min(mi, par[cur]/2);
				mx = max(mx, par[cur]/2);
				e.push_back(par[cur]/2);
				cur = E[par[cur]];
			}
			bool inc = true;
			for(int i = 0; i < (int)e.size(); i++) if(e[i] == mi) {
				for(int j = 0; j < (int)e.size(); j++) {
					cur = (i+j)%e.size();
					int nxt = (i+j+1)%e.size();
					if(e[nxt] == mx) break;
					if(e[nxt] < e[cur]) inc = false;
				}
				for(int j = 0; j < (int)e.size(); j++) {
					cur = (i-j+e.size())%e.size();
					int nxt = (i-j-1+e.size())%e.size();
					if(e[nxt] == mx) break;
					if(e[nxt] < e[cur]) inc = false;
				}
			}
			if(inc) for(auto x : e) cyc_min[x] = mi, cyc_max[x] = mx;
			cur = R;
			for(int i = 0; i < (int)e.size(); i++) {
				int e1 = 2*e[i], e2 = 2*e[(i+1)%e.size()];
				if(E[e1] != cur) e1++;
				if(E[e2] == cur) e2++;
				adj[e1] = e2;
				adj[e2^1] = e1^1;
				if(i+1 < (int)e.size()) cur = E[par[cur]];
			}
		}
	}
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout << fixed << setprecision(10);
	int N, M;
	cin >> N >> M;
	vector<int> E(2*M);
	vector< vector<int> > G(N);
	for(int i = M-1; i >= 0; i--) {
		int a, b;
		cin >> a >> b;
		G[--a].push_back(2*i+1);
		G[--b].push_back(2*i);
		E[2*i] = a, E[2*i+1] = b;
	}
	vector<int> cyc_min(M, M), cyc_max(M, -1), par(N, -1), dep(N, 0), adj(2*M);
	par[0] = -2;
	DFS(0, E, G, par, dep, cyc_min, cyc_max, adj);
	vector<cat> dp[2] = {vector<cat>(2*M, 0), vector<cat>(2*M, 0)};
	vector< vector<cat> > dp_v[2];
	for(int k = 0; k < 2; k++) {
		dp_v[k].resize(N);
		for(int i = 0; i < N; i++) dp_v[k][i].resize(G[i].size()+1, 0);
	}
	vector<int> cur_e(N, 0);
	for(int i = 0; i < N; i++) sort(begin(G[i]), end(G[i]));
	for(int i = 0; i < M; i++) {
		for(int k = 0; k < 2; k++) {
			// E[2*i+1-k] -> E[2*i+k]
			int v = E[2*i+1-k];
			auto it = lower_bound(begin(G[v]), end(G[v]), 2*min(i, cyc_min[i]));
			int s0 = dp_v[0][v][it-begin(G[v])];
			int s1 = dp_v[1][v][it-begin(G[v])];
			int min_adj_pos = (cyc_min[i] != M) && (E[2*cyc_min[i]] == v || E[2*cyc_min[i]+1] == v);
			if(cyc_min[i] == i) min_adj_pos = 1;
			if(min_adj_pos) {
				if(i != cyc_max[i]) {
					dp[1][2*i+k] += s0;
					if(dp[1][2*i+k] >= mod) dp[1][2*i+k] -= mod;
					dp[1][2*i+k] += s1;
					if(dp[1][2*i+k] >= mod) dp[1][2*i+k] -= mod;
				}
			}
			else {
				dp[0][2*i+k] += s0;
				if(dp[0][2*i+k] >= mod) dp[0][2*i+k] -= mod;
				dp[0][2*i+k] += s1;
				if(dp[0][2*i+k] >= mod) dp[0][2*i+k] -= mod;
			}
			{
				dp[0][2*i+k] += dp_v[0][v][cur_e[v]]-s0;
				if(dp[0][2*i+k] >= mod) dp[0][2*i+k] -= mod;
				if(dp[0][2*i+k] < 0) dp[0][2*i+k] += 0;
				dp[0][2*i+k] += dp_v[1][v][cur_e[v]]-s1;
				if(dp[0][2*i+k] >= mod) dp[0][2*i+k] -= mod;
				if(dp[0][2*i+k] < 0) dp[0][2*i+k] += 0;
			}
			if(cyc_min[i] != M && adj[2*i+1-k]/2 < i) {
				int e = adj[2*i+1-k];
				// undo wrong
				int l = (e/2 < cyc_min[i] && cyc_min[i] != M);
				if(l && E[2*cyc_min[i]] != v && E[2*cyc_min[i]+1] != v) l = 0;
				if(cyc_min[i] == i) l = 1;
				if(l == 0 || i != cyc_max[i]) {
					dp[l][2*i+k] -= dp[0][e^1];
					if(dp[l][2*i+k] < 0) dp[l][2*i+k] += mod;
					dp[l][2*i+k] -= dp[1][e^1];
					if(dp[l][2*i+k] < 0) dp[l][2*i+k] += mod;
				}
				// add correct
				dp[0][2*i+k] += dp[0][e^1];
				if(dp[0][2*i+k] >= mod) dp[0][2*i+k] -= mod;
				if(cyc_max[i] != i) {
					dp[1][2*i+k] += dp[1][e^1];
					if(dp[1][2*i+k] >= mod) dp[1][2*i+k] -= mod;
				}
			}
			// first edge
			int l = (cyc_min[i] != M);
			if(l)
				if(E[2*cyc_min[i]] != v && E[2*cyc_min[i]+1] != v) l = 0;
			if(!l || i != cyc_max[i]) {
				dp[l][2*i+k] += 1;
				if(dp[l][2*i+k] >= mod) dp[l][2*i+k] -= mod;
			}
		}
		int v = E[2*i];
		dp_v[0][v][cur_e[v]+1] = dp_v[0][v][cur_e[v]]+dp[0][2*i];
		if(dp_v[0][v][cur_e[v]+1] >= mod) dp_v[0][v][cur_e[v]+1] -= mod;
		dp_v[1][v][cur_e[v]+1] = dp_v[1][v][cur_e[v]]+dp[1][2*i];
		if(dp_v[1][v][cur_e[v]+1] >= mod) dp_v[1][v][cur_e[v]+1] -= mod;
		cur_e[v]++;
		v = E[2*i+1];
		dp_v[0][v][cur_e[v]+1] = dp_v[0][v][cur_e[v]]+dp[0][2*i+1];
		if(dp_v[0][v][cur_e[v]+1] >= mod) dp_v[0][v][cur_e[v]+1] -= mod;
		dp_v[1][v][cur_e[v]+1] = dp_v[1][v][cur_e[v]]+dp[1][2*i+1];
		if(dp_v[1][v][cur_e[v]+1] >= mod) dp_v[1][v][cur_e[v]+1] -= mod;
		cur_e[v]++;
	}
	vector<int> ans(N, 0);
	for(int i = 0; i < 2*M; i++) {
		ans[E[i]] += dp[0][i];
		if(ans[E[i]] >= mod) ans[E[i]] -= mod;
		ans[E[i]] += dp[1][i];
		if(ans[E[i]] >= mod) ans[E[i]] -= mod;
	}
	for(int i = 0; i < N; i++)
		cout << ans[i] << ((i == N-1) ? "\n" : " ");
	return 0;
}

// look at my code
// my code is amazing