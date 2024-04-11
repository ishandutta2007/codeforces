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
#define dbl long double
#define pi 3.14159265358979323846
using namespace std;
// mylittledoge

using cat = long long;

#ifdef DONLINE_JUDGE
	// palindromic tree is better than splay tree!
	#define lld I64d
#endif

int lca(int u, int v, auto & dep, auto & par) {
	bool fl = false;
	if(u == 43 && v == 21) fl = true;
	if(u == 21 && v == 43) fl = true;
	if(dep[u] > dep[v]) swap(u, v);
	int d = dep[v]-dep[u];
	for(int k = 0; k < 20; k++) {
		if(d == 0) break; 
		if((d>>k)&1) v = par[k][v], d -= 1<<k;
	}
	if(v == u) return v;
	for(int k = 19; k >= 0; k--) if(par[k][v] != par[k][u])
		u = par[k][u], v = par[k][v];
	return par[0][u];
}

struct bus {
	int u, v, l;
	bus() {}
	bus(int u, int v, int l) : u(u), v(v), l(l) {}
};

void DFS(int R, auto & G, auto & I) {
	I[R].ss = I[R].ff+1;
	ALL_THE(G[R], it) {
		I[*it].ff = I[R].ss;
		DFS(*it, G, I);
		I[R].ss = I[*it].ss;
	}
}

struct intervalac {
	struct node {
		int z, k;
		int son[2];
		vector<int> I_add, I_rem;
	};
	vector<node> T;

	void constI(int akt) {
		node n = T[akt];
		if(n.z == n.k-1) return;
		for(int i = 0; i < 2; i++) {
			if(i == 0) n.k = (n.z+n.k)/2;
			else {n.z = n.k; n.k = T[akt].k;}
			T[akt].son[i] = T.size();
			T.push_back(n);
			constI(T[akt].son[i]);
		}
	}

	intervalac(int N) {
		node n;
		n.z = 0, n.k = N;
		n.son[0] = n.son[1] = -1;
		T.dibs(2*N);
		T.push_back(n);
		constI(0);
	}

	void add(int akt, int zac, int kon, int val) {
		node & n = T[akt];
		if(n.z >= kon || zac >= n.k) return;
		if(n.z == zac && n.k == kon) {
			n.I_add.push_back(val);
			return;
		}
		add(n.son[0], zac, min(kon, (n.z+n.k)/2), val);
		add(n.son[1], max(zac, (n.z+n.k)/2), kon, val);
	}

	void rem(int akt, int zac, int kon, int val) {
		node & n = T[akt];
		if(n.z >= kon || zac >= n.k) return;
		if(n.z == zac && n.k == kon) {
			n.I_rem.push_back(val);
			return;
		}
		rem(n.son[0], zac, min(kon, (n.z+n.k)/2), val);
		rem(n.son[1], max(zac, (n.z+n.k)/2), kon, val);
	}

	void proc(int akt, int pos, vector<bool> & res) {
		node & n = T[akt];
		sort(begin(n.I_add), end(n.I_add));
		sort(begin(n.I_rem), end(n.I_rem));
		int a = 0;
		for(int i = 0; i < (int)n.I_add.size(); i++) {
			while(a < (int)n.I_rem.size() && n.I_rem[a] < n.I_add[i]) a++;
			if(a == (int)n.I_rem.size() || n.I_rem[a] != n.I_add[i]) res[n.I_add[i]] = true;
		}
		n.I_add.clear();
		n.I_rem.clear();
		if(n.z == n.k-1) return;
		if(pos < (n.z+n.k)/2) proc(n.son[0], pos, res);
		else proc(n.son[1], pos, res);
	}

	void clear(int akt, int pos) {
		node & n = T[akt];
		n.I_add.clear();
		n.I_rem.clear();
		if(n.z == n.k-1) return;
		if(pos < (n.z+n.k)/2) clear(n.son[0], pos);
		else clear(n.son[1], pos);
	}
};

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout << fixed << setprecision(10);
	int N, M, Q;
	cin >> N;
	vector< vector<int> > G(N);
	vector< vector<int> > par(20, vector<int>(N, 0));
	vector<int> dep(N, 0);
	for(int i = 0; i < N-1; i++) {
		cin >> par[0][i+1];
		G[--par[0][i+1]].push_back(i+1);
		dep[i+1] = dep[par[0][i+1]]+1;
	}
	for(int i = 1; i < 20; i++)
		for(int j = 0; j < N; j++) par[i][j] = par[i-1][par[i-1][j]];
	vector< pair<int, int> > I(N, make_pair(0, 0));
	DFS(0, G, I);

	cin >> M;
	vector< vector<int> > mindep(20, vector<int>(N, N+1)); // min. height reachable by 2^k buses
	for(int i = 0; i < N; i++) mindep[0][i] = dep[i];
	vector< vector<int> > byl(N);
	vector<bus> B(M);
	for(int m = 0; m < M; m++) {
		int u, v;
		cin >> u >> v;
		u--, v--;
		int l = lca(u, v, dep, par);
		B[m] = bus(u, v, l);
		byl[l].push_back(m);
		mindep[0][u] = min(mindep[0][u], dep[l]);
		mindep[0][v] = min(mindep[0][v], dep[l]);
	}
	vector< vector<int> > mindep_pos(20, vector<int>(N));
	for(int i = N-1; i >= 0; i--) {
		// one bus
		mindep[0][par[0][i]] = min(mindep[0][par[0][i]], mindep[0][i]);
		int v = i, d = dep[i]-mindep[0][i];
		for(int j = 0; j < 20; j++) {
			if(d == 0) break;
			if((d>>j)&1) d -= 1<<j, v = par[j][v];
		}
		mindep_pos[0][i] = v;
	}
	for(int k = 1; k < 20; k++)
		for(int i = 0; i < N; i++) {
			mindep[k][i] = mindep[k-1][mindep_pos[k-1][i]];
			mindep_pos[k][i] = mindep_pos[k-1][mindep_pos[k-1][i]];
		}

	cin >> Q;
	vector<int> ans(Q, 0);
	vector<int> qu(Q, -1), qv(Q, -1);
	vector< vector<int> > proc(N);
	vector<bool> sub1(Q, false);
	for(int q = 0; q < Q; q++) {
		int u, v;
		cin >> u >> v;
		u--, v--;
		int l = lca(u, v, dep, par);
		if(mindep[19][u] > dep[l] || mindep[19][v] > dep[l]) {
			ans[q] = -1;
			continue;
		}
		if(dep[u] > dep[v]) swap(u, v);
		for(int k = 19; k >= 0; k--) {
			if(mindep[k][u] > dep[l]) ans[q] += 1<<k, u = mindep_pos[k][u];
			if(mindep[k][v] > dep[l]) ans[q] += 1<<k, v = mindep_pos[k][v];
		}
		if(u == v) continue;
		if(u == l || v == l) {
			ans[q]++;
			continue;
		}
		ans[q] += 2;
		// -1?
		qu[q] = u, qv[q] = v;
		proc[l].push_back(q);
	}

	intervalac It(N+1);

	vector< pair<int, int> > ivs(Q);
	for(int i = 0; i < N; i++) {
		vector< pair<int, int> > pts(byl[i].size());
		for(int j = 0; j < (int)byl[i].size(); j++) {
			pts[j].ff = I[B[byl[i][j]].u].ff;
			pts[j].ss = I[B[byl[i][j]].v].ff;
			if(pts[j].ff > pts[j].ss) swap(pts[j].ff, pts[j].ss);
		}
		sort(begin(pts), end(pts));
		vector< pair<int, int> > I_open(proc[i].size()), I_close(proc[i].size());
		for(int j = 0; j < (int)proc[i].size(); j++) {
			pair<int, int> ivs1 = I[qu[proc[i][j]]];
			pair<int, int> ivs2 = I[qv[proc[i][j]]];
			if(ivs1.ff > ivs2.ff) swap(ivs1, ivs2);
			ivs[proc[i][j]] = ivs2;
			I_open[j] = make_pair(ivs1.ff, proc[i][j]);
			I_close[j] = make_pair(ivs1.ss, proc[i][j]);
		}
		sort(begin(I_open), end(I_open));
		sort(begin(I_close), end(I_close));
		int a = 0, b = 0;
		for(int j = 0; j < (int)proc[i].size(); j++) {
			while(true) {
				int pos_a = N+1, pos_b = N+1;
				if(a < (int)proc[i].size() && I_open[a].ff < I_close[j].ff) pos_a = I_open[a].ff;
				if(b < (int)pts.size() && pts[b].ff < I_close[j].ff) pos_b = pts[b].ff;
				if(pos_b < pos_a) {
					It.proc(0, pts[b].ss, sub1);
					b++;
					continue;
				}
				if(pos_a <= pos_b && pos_a <= N) {
					It.add(0, ivs[I_open[a].ss].ff, ivs[I_open[a].ss].ss, I_open[a].ss);
					a++;
					continue;
				}
				break;
			}
			It.rem(0, ivs[I_close[j].ss].ff, ivs[I_close[j].ss].ss, I_close[j].ss);
		}
		ALL_THE(I_close, it) It.clear(0, i);
	}
	for(int i = 0; i < Q; i++) if(sub1[i]) ans[i]--;

	for(int i = 0; i < Q; i++) cout << ans[i] << "\n";
	return 0;}

// look at my code
// my code is amazing