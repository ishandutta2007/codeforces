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
#define abs(x) ((x < 0)?-(x):x)
#define uint unsigned int
#define dbl double
#define pi 3.14159265358979323846
using namespace std;
// mylittledoge

typedef long long cat;

#ifdef DONLINE_JUDGE
	// palindromic tree is better than splay tree!
	#define lld I64d
#endif

void DFS(int R, vector< vector<int> > &G, vector<int> &dep, vector< pair<int, int> > &I) {
	I[R].ss = I[R].ff+1;
	ALL_THE(G[R], it) {
		dep[*it] = dep[R] + 1;
		I[*it].ff = I[R].ss;
		DFS(*it, G, dep, I);
		I[R].ss = I[*it].ss;
	}
}

int LCA(int u, int v, auto &par, auto &dep) {
	if(dep[v] > dep[u]) swap(u, v);
	int dd = dep[u]-dep[v];
	if(dd != 0) for(int k = 0; k < 17; k++) if((dd>>k)&1) {
		u = par[k][u];
		dd -= (1<<k);
		if(dd == 0) break;
	}
	if(u == v) return v;
	for(int k = 16; k >= 0; k--) if(par[k][u] != par[k][v]) {
		u = par[k][u];
		v = par[k][v];
	}
	return par[0][v];
}

struct fin {
	vector<cat> T, Tc;
	cat sum;
	fin() {}
	fin(int N) {
		sum = 0;
		T.resize(N+10, 0);
		Tc.resize(N+10, 0);
	}

	int lastone(int x) {return x&(x^(x-1));}

	void put(int pos, int val) {
		sum += val;
		for(int i = pos+2; i < (int)T.size(); i += lastone(i)) {
			T[i] -= val;
			Tc[i] += 1LL*val*(pos+1);
		}
	}

	cat get(int pos) {
		cat ret = sum;
		for(int i = pos+1; i > 0; i -= lastone(i)) ret += T[i];
		ret *= pos+1;
		for(int i = pos+1; i > 0; i -= lastone(i)) ret += Tc[i];
		return ret;
	}
};

struct tree {
	int P;
	vector<int> path_id, path_index, path_sz, par, path_top;
	vector<fin> fpath;
	bool empty;

	tree() {empty = true;}
	tree(vector< vector<int> > &G, vector<int> par_) {
		empty = false;
		par = par_;
		int N = G.size();
		P = 0;
		path_id.resize(N);
		path_index.resize(N);
		DFS(0, G);
		fpath.resize(P);
		path_top.resize(P);
		for(int i = 0; i < P; i++) fpath[i] = fin(path_sz[i]);
		for(int i = 0; i < N; i++) {
			path_index[i] = path_sz[path_id[i]]-1-path_index[i];
			if(path_index[i] == 0) path_top[path_id[i]] = i;
		}
	}

	int DFS(int R, vector< vector<int> > &G) {
		int maxsz = 0, s = -1, sz = 1;
		ALL_THE(G[R], it) {
			int sz_add = DFS(*it, G);
			if(sz_add > maxsz) {
				maxsz = sz_add;
				s = *it;
			}
			sz += sz_add;
		}
		if(s == -1) {
			path_id[R] = P;
			path_index[R] = 0;
			path_sz.push_back(1);
			P++;
		}
		else {
			path_sz[path_id[s]]++;
			path_id[R] = path_id[s];
			path_index[R] = path_index[s]+1;
		}
		return sz;
	}

	void put(int v, int val) {
		while(true) {
			fpath[path_id[v]].put(path_index[v], val);
			v = path_top[path_id[v]];
			if(v == 0) break;
			v = par[v];
		}
	}

	cat get(int v) {
		cat ret = 0;
		while(true) {
			ret += fpath[path_id[v]].get(path_index[v]);
			v = path_top[path_id[v]];
			if(v == 0) break;
			v = par[v];
		}
		return ret;
	}
};

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout << fixed << setprecision(10);
	int N, M, Q;
	cat C;
	cin >> N >> M >> Q >> C;
	vector<int> T0(N);
	for(int i = 0; i < N; i++) {
		cin >> T0[i];
		T0[i]--;
	}

	vector< vector<int> > par(17, vector<int>(N, 0));
	vector< vector<int> > G(N);
	for(int i = 1; i < N; i++) {
		cin >> par[0][i];
		G[--par[0][i]].push_back(i);
	}
	vector<int> dep(N, 1);
	vector< pair<int, int> > I(N, make_pair(0, 0));
	DFS(0, G, dep, I);
	for(int i = 1; i < 17; i++)
		for(int j = 0; j < N; j++) par[i][j] = par[i-1][par[i-1][j]];

	vector<cat> c(M);
	for(int i = 0; i < M; i++) cin >> c[i];

	vector<int> cnt_occ(M, 0);
	vector< set<int> > list_occ(M);

	int X = 1000;
	vector<tree> F(M);

	vector<cat> sums(M, N*C*C);
	vector<int> T(N, -1);
	cat sum_cnt = 0;
	for(int i = 0; i < N; i++) {
		int v = i, k = T0[i];
		sums[k] += c[k] * (c[k] - 2 * C) * dep[v];

		sum_cnt = 0;
		if(cnt_occ[k] <= X) {
			ALL_THE(list_occ[k], it) {
				int lca = LCA(*it, v, par, dep);
				sum_cnt += dep[lca];
			}
		}
		else {
			sum_cnt += F[k].get(v);
		}
		if(!F[k].empty) F[k].put(v, 1);

		sums[k] += 2 * c[k] * c[k] * sum_cnt;
		cnt_occ[k]++;
		list_occ[k].insert(i);
		if(cnt_occ[k] > X && F[k].empty) {
			F[k] = tree(G, par[0]);
			ALL_THE(list_occ[k], it) F[k].put(*it, 1);
		}
		T[i] = k;
	}
	for(int q = 0; q < Q; q++) {
		int tp;
		cin >> tp;
		if(tp == 2) {
			int k;
			cin >> k;
			cout << dbl(sums[k-1])/N << "\n";
			continue;
		}
		int v, k;
		cin >> v >> k;
		v--, k--;
		int k0 = T[v];
		sums[k0] += c[k0] * (c[k0] + 2 * C) * dep[v];

		sum_cnt = 0;
		if(cnt_occ[k0] <= X) {
			ALL_THE(list_occ[k0], it) {
				int lca = LCA(*it, v, par, dep);
				sum_cnt += dep[lca];
			}
		}
		else {
			sum_cnt += F[k0].get(v);
		}
		if(!F[k0].empty) F[k0].put(v, -1);

		sums[k0] -= 2 * c[k0] * c[k0] * sum_cnt;
		cnt_occ[k0]--;
		list_occ[k0].erase(v);
		T[v] = -1;

		sums[k] += c[k] * (c[k] - 2 * C) * dep[v];

		sum_cnt = 0;
		if(cnt_occ[k] <= X) {
			ALL_THE(list_occ[k], it) {
				int lca = LCA(*it, v, par, dep);
				sum_cnt += dep[lca];
			}
		}
		else {
			sum_cnt += F[k].get(v);
		}
		if(!F[k].empty) F[k].put(v, 1);

		sums[k] += 2 * c[k] * c[k] * sum_cnt;
		cnt_occ[k]++;
		list_occ[k].insert(v);
		if(cnt_occ[k] > X && F[k].empty) {
			F[k] = tree(G, par[0]);
			ALL_THE(list_occ[k], it) F[k].put(*it, 1);
		}
		T[v] = k;
	}
	return 0;}

// look at my code
// my code is amazing