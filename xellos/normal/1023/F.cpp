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

void DFS(int R, vector< vector< pair<int, int> > > & G, vector<int> & par, vector<int> & dep) {
	ALL_THE(G[R], it) if(par[it->ff] == -1) {
		par[it->ff] = R;
		dep[it->ff] = dep[R]+1;
		DFS(it->ff, G, par, dep);
	}
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout << fixed << setprecision(10);
	int N, K, M;
	cin >> N >> K >> M;
	vector< pair<int, int> > E(K);
	for(int i = 0; i < K; i++) {
		cin >> E[i].ff >> E[i].ss;
		E[i].ff--, E[i].ss--;
	}
	vector<int> in_comp(N);
	vector< vector<int> > comp(N);
	for(int i = 0; i < N; i++) {
		in_comp[i] = i;
		comp[i] = {i};
	}
	vector< vector< pair<int, int> > > G(N);
	for(int i = 0; i < K; i++) {
		int u = E[i].ff, v = E[i].ss;
		if(in_comp[u] == in_comp[v]) continue;
		G[u].push_back({v, i});
		G[v].push_back({u, i});
		u = in_comp[u], v = in_comp[v];
		if(comp[u].size() > comp[v].size()) swap(u, v);
		ALL_THE(comp[u], it) {
			in_comp[*it] = v;
			comp[v].push_back(*it);
		}
	}
	vector< pair<int, pair<int, int> > > Eo(M);
	for(int i = 0; i < M; i++) {
		int u, v, c;
		cin >> u >> v >> c;
		u--, v--;
		Eo.push_back({c, {u, v}});
		if(in_comp[u] == in_comp[v]) continue;
		G[u].push_back({v, -1});
		G[v].push_back({u, -1});
		u = in_comp[u], v = in_comp[v];
		if(comp[u].size() > comp[v].size()) swap(u, v);
		ALL_THE(comp[u], it) {
			in_comp[*it] = v;
			comp[v].push_back(*it);
		}
	}
	vector< vector<int> > par(20, vector<int>(N, -1));
	par[0][0] = 0;
	vector<int> dep(N, 0);
	DFS(0, G, par[0], dep);
	for(int k = 1; k < 20; k++) for(int i = 0; i < N; i++)
		par[k][i] = par[k-1][par[k-1][i]];
	vector< vector<int> > mxc(20, vector<int>(N, OVER9000));
	for(int i = 0; i < (int)Eo.size(); i++) {
		int u = Eo[i].ss.ff, v = Eo[i].ss.ss;
		if(dep[u] > dep[v]) swap(u, v);
		int u0 = u, v0 = v;
		for(int k = 0; k < 20; k++) {
			if(dep[u] == dep[v]) break;
			if((((dep[v]-dep[u])>>k)&1) == 0) continue;
			v = par[k][v];
		}
		if(u != v) {
			for(int k = 19; k >= 0; k--) if(par[k][u] != par[k][v]) {
				u = par[k][u];
				v = par[k][v];
			}
			u = par[0][u], v = par[0][v];
		}
		int l = u;
		u = u0, v = v0;
		int d = dep[u]-dep[l];
		for(int k = 0; k < 20; k++) if((d>>k)&1) {
			mxc[k][u] = min(mxc[k][u], Eo[i].ff);
			u = par[k][u];
		}
		d = dep[v]-dep[l];
		for(int k = 0; k < 20; k++) if((d>>k)&1) {
			mxc[k][v] = min(mxc[k][v], Eo[i].ff);
			v = par[k][v];
		}
	}
	for(int k = 19; k > 0; k--) for(int i = 0; i < N; i++) {
		mxc[k-1][i] = min(mxc[k-1][i], mxc[k][i]);
		mxc[k-1][par[k-1][i]] = min(mxc[k-1][par[k-1][i]], mxc[k][i]);
	}
	cat ans = 0;
	for(int i = 1; i < N; i++) ALL_THE(G[i], it) if(par[0][i] == it->ff && it->ss != -1) {
		if(mxc[0][i] == OVER9000) {
			cout << "-1\n";
			return 0;
		}
		ans += mxc[0][i];
	}
	cout << ans << "\n";
	return 0;
}

// look at my code
// my code is amazing