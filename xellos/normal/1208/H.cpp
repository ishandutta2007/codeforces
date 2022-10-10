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

void DFS(int R, auto & G, auto & par, auto & DFS_order) {
	DFS_order.push_back(R);
	for(auto v : G[R]) if(par[v] == -1) {
		par[v] = R;
		DFS(v, G, par, DFS_order);
	}
}

struct query {
	int type, v, x;
};

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout << fixed << setprecision(10);
	int N, K;
	cin >> N >> K;
	vector< vector<int> > G(N);
	for(int i = 0; i < N-1; i++) {
		int u, v;
		cin >> u >> v;
		G[--u].push_back(--v);
		G[v].push_back(u);
	}
	vector<int> par(N, -1), DFS_order;
	par[0] = 0;
	DFS(0, G, par, DFS_order);
	vector<int> id_DFS(N), par_DFS(N);
	vector< vector<int> > sons_DFS(N);
	for(int i = 0; i < N; i++) id_DFS[DFS_order[i]] = i;
	for(int i = 1; i < N; i++) {
		par_DFS[id_DFS[i]] = id_DFS[par[i]];
		sons_DFS[id_DFS[par[i]]].push_back(id_DFS[i]);
	}
	vector<int> CL(N);
	for(int i = 0; i < N; i++) cin >> CL[id_DFS[i]];
	int B = 400;
	vector<char> compr(N, 0);
	vector<int> path(N, 0), under(N);
	vector<int> val[2] = {vector<int>(N), vector<int>(N)};
	vector< vector<int> > occ(N);
	for(int i = 0; i < N; i++) occ[i].resize(2*sons_DFS[i].size()+2, 0);
	vector< vector<int> > dif_occ(N), sons_compr(N);
	int Q;
	cin >> Q;
	for(int q = 0; q < Q; q += B) {
		memset(compr.data(), 0, N);
		memset(path.data(), 0, sizeof(int)*N);
		vector<query> qs(B);
		for(int i = q; i < min(Q, q+B); i++) {
			cin >> qs[i-q].type;
			if(qs[i-q].type != 2) cin >> qs[i-q].v;
			else cin >> qs[i-q].v >> qs[i-q].x;
			if(qs[i-q].type != 3) qs[i-q].v = id_DFS[qs[i-q].v-1];
			if(qs[i-q].type == 2) compr[qs[i-q].v] = 1;
		}
		for(int i = N-1; i > 0; i--) {
			if(path[i] >= 2) compr[i] = 1;
			if(path[i] || compr[i]) path[par_DFS[i]]++;
		}
		compr[0] = 1;
		// calculate values for fixed vertices
		for(int i = N-1; i >= 0; i--) if(path[i] == 0 && compr[i] == 0) {
			if(sons_DFS[i].empty()) {
				val[0][i] = CL[i] ? N+1 : -(N+1);
				continue;
			}
			int deg = sons_DFS[i].size();
			for(auto s : sons_DFS[i]) {
				if(val[0][s] < -deg-1) continue;
				occ[i][min(2*deg+1, deg+1+val[0][s])]++;
			}
			int sum = 0, x = deg+1;
			while(true) {
				x--;
				sum += occ[i][x+deg+1];
				if(sum >= (x+deg+1)/2) break;
			}
			val[0][i] = x;
			for(int j = 0; j < 2*(deg+1); j++) occ[i][j] = 0;
		}
		// find paths, calculate values for paths
		vector<int> V;
		for(int i = 0; i < N; i++) if(compr[i]) {
			V.push_back(i);
			under[i] = i;
			int cur = i;
			while(cur > 0 && compr[par_DFS[cur]] == 0) {
				cur = par_DFS[cur];
				under[cur] = i;
				int deg = sons_DFS[cur].size();
				for(int k = 0; k < 2; k++) {
					for(auto s : sons_DFS[cur]) {
						int val_cur;
						if(path[s] == 0 && compr[s] == 0) val_cur = val[0][s];
						else if(s == i) val_cur = k ? N+1 : -(N+1);
						else val_cur = val[k][s];
						if(val_cur >= -deg-1) occ[cur][min(2*deg+1, deg+1+val_cur)]++;
					}
					int sum = 0, x = deg+1;
					while(true) {
						x--;
						sum += occ[cur][x+deg+1];
						if(sum >= (x+deg+1)/2) break;
					}
					val[k][cur] = x;
					for(int j = 0; j < 2*(deg+1); j++) occ[cur][j] = 0;
				}
			}
			dif_occ[i] = vector<int>(2*sons_DFS[i].size()+2, 0);
			sons_compr[i].clear();
			int deg = sons_DFS[i].size(), dif0 = 0;
			for(auto s : sons_DFS[i]) {
				if(path[s] || compr[s]) sons_compr[i].push_back(s);
				else if(val[0][s] >= -deg-1) {
					occ[i][min(2*deg+1, deg+1+val[0][s])]++;
					dif0++;
				}
				else dif0--;
			}
			dif_occ[i][0] = dif0;
			for(int j = 1; j < 2*(deg+1); j++) dif_occ[i][j] = dif_occ[i][j-1]-2*occ[i][j-1];
			for(int j = 0; j < 2*(deg+1); j++) occ[i][j] = 0;
		}
		reverse(begin(V), end(V));
		for(int i = q; i < min(Q, q+B); i++) {
			if(qs[i-q].type == 3) {
				K = qs[i-q].v;
				continue;
			}
			if(qs[i-q].type == 2) {
				CL[qs[i-q].v] = qs[i-q].x;
				continue;
			}
			// recalculate colours
			for(auto v : V) {
				if(sons_DFS[v].empty()) continue;
				if(K > (int)sons_DFS[v].size()) {
					CL[v] = 0;
					continue;
				}
				if(K < -1-(int)sons_DFS[v].size()) {
					CL[v] = 1;
					continue;
				}
				int dif = dif_occ[v][K+1+sons_DFS[v].size()];
				for(auto s : sons_compr[v]) {
					if(compr[s]) {
						if(CL[s]) dif++;
						else dif--;
					}
					else if(compr[s] == 0 && path[s] == 0) {
						assert(false);
					}
					else {
						int u = under[s];
						int val_cur = val[CL[u]][u];
						if(val_cur >= K) dif++;
						else dif--;
					}
				}
				CL[v] = (dif >= K);
			}
			// find answer
			int u = under[qs[i-q].v];
			if(compr[qs[i-q].v]) cout << CL[u] << "\n"; // u == v
			else if(compr[qs[i-q].v] == 0 && path[qs[i-q].v] == 0) cout << (val[0][qs[i-q].v] >= K) << "\n";
			else cout << (val[CL[u]][qs[i-q].v] >= K) << "\n";
		}
	}
	return 0;
}

// look at my code
// my code is amazing