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

void DFS(int R, auto & G, auto & par, auto & I, auto & dep) {
	I[R].ss = I[R].ff+1;
	for(auto s : G[R]) if(par[s] == -1) {
		par[s] = R;
		dep[s] = dep[R]+1;
		I[s].ff = I[R].ss;
		DFS(s, G, par, I, dep);
		I[R].ss = I[s].ss;
	}
}

void solve(int u, int v, auto & S, auto & par, auto & cnt, auto & down) {
	if(S[u][v] != -1) return;
	if(par[u] == v || par[v] == u) {
		S[u][v] = S[v][u] = cnt[u][v];
		return;
	}
	int prev_u = par[u], prev_v = par[v];
	if(down[u][v] != -1) prev_u = down[u][v];
	if(down[v][u] != -1) prev_v = down[v][u];
	solve(prev_u, v, S, par, cnt, down);
	solve(u, prev_v, S, par, cnt, down);
	S[u][v] = S[v][u] = max(S[u][v], max(S[prev_u][v], S[u][prev_v])+cnt[u][v]);
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout << fixed << setprecision(10);
	int N;
	cin >> N;
	vector< vector<int> > G(N);
	for(int i = 0; i < N-1; i++) {
		int u, v;
		cin >> u >> v;
		G[--u].push_back(--v);
		G[v].push_back(u);
	}
	vector<int> par(N, -1), dep(N, 0);
	vector< pair<int, int> > I(N, {0, 0});
	par[0] = 0;
	DFS(0, G, par, I, dep);
	vector< vector<int> > down(N, vector<int>(N, -1));
	for(int i = 0; i < N; i++) {
		int cur = i;
		while(cur) {
			down[par[cur]][i] = cur;
			cur = par[cur];
		}
	}
	vector< vector<cat> > cnt(N, vector<cat>(N, -1));
	for(int i = 0; i < N; i++) for(int j = 0; j < i; j++) {
		int sz1 = I[i].ss-I[i].ff, sz2 = I[j].ss-I[j].ff;
		if(down[i][j] != -1) sz1 = N-(I[down[i][j]].ss-I[down[i][j]].ff);
		if(down[j][i] != -1) sz2 = N-(I[down[j][i]].ss-I[down[j][i]].ff);
		cnt[i][j] = cnt[j][i] = sz1*sz2;
	}
	vector< vector<cat> > S(N, vector<cat>(N, -1));
	for(int i = 0; i < N; i++) for(int j = 0; j < i; j++)
		solve(i, j, S, par, cnt, down);
	cat ans = 0;
	for(int i = 0; i < N; i++) for(int j = 0; j < i; j++)
		ans = max(ans, S[i][j]);
	cout << ans << "\n";
	return 0;
}

// look at my code
// my code is amazing