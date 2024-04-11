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

void find_cycle(int R, auto & G, auto & par, auto & dep, bool & done) {
	int v_up = -1;
	for(auto v : G[R]) if(par[R] != v && par[v] != -1) {
		if(v_up == -1) v_up = v;
		if(dep[v] > dep[v_up]) v_up = v;
	}
	for(auto v : G[R]) if(v == v_up) {
		vector<bool> cyc(G.size(), false);
		cyc[v] = cyc[R] = true;
		for(int cur = R; cur != v; cur = par[cur]) cyc[cur] = true;
		int cnt = 0;
		for(int i = 0; i < (int)G.size(); i++) if(!cyc[i]) cnt++;
		if(cnt == 0 || cnt == (int)G.size()) cout << "No\n";
		else {
			cout << "Yes\n";
			cout << cnt << "\n";
			bool st = true;
			for(int i = 0; i < (int)G.size(); i++) if(!cyc[i]) {
				if(!st) cout << " ";
				st = false;
				cout << i+1;
			}
			cout << "\n";
		}
		done = true;
		return;
	}
	for(auto v : G[R]) if(par[v] == -1) {
		par[v] = R;
		dep[v] = dep[R]+1;
		find_cycle(v, G, par, dep, done);
		if(done) return;
	}
}

void find1(int R, auto & G, auto & par, auto & adj1, int adj_first, auto & G1, bool & done) {
	for(auto v : G[R]) if(par[v] == -1) {
		int adj_cur = -1;
		for(auto u : G1[v]) if(G1[u].size()%3 == 1 && u != adj_first) adj_cur = u;
		if(adj_cur != -1) {
			vector<bool> path(G.size(), false);
			path[v] = true;
			for(int cur = R; ; cur = par[cur]) {
				path[cur] = true;
				if(adj1[cur]) {
					path[adj_cur] = path[adj_first] = true;
					break;
				}
			}
			int cnt = 0;
			for(int i = 0; i < (int)G.size(); i++) if(!path[i]) cnt++;
			if(cnt == 0 || cnt == (int)G.size()) cout << "No\n";
			else {
				cout << "Yes\n";
				cout << cnt << "\n";
				bool st = true;
				for(int i = 0; i < (int)G.size(); i++) if(!path[i]) {
					if(!st) cout << " ";
					st = false;
					cout << i+1;
				}
				cout << "\n";
			}
			done = true;
			return;
		}
		par[v] = R;
		find1(v, G, par, adj1, adj_first, G1, done);
		if(done) return;
	}
}

void DFS(int R, auto & G, auto & par, auto & sum) {
	for(auto v : G[R]) if(par[v] == R) {
		DFS(v, G, par, sum);
		sum[R] += sum[v];
	}
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout << fixed << setprecision(10);
	int T;
	cin >> T;
	while(T--) {
		int N, M;
		cin >> N >> M;
		vector< vector<int> > G(N);
		for(int i = 0; i < M; i++) {
			int a, b;
			cin >> a >> b;
			G[--a].push_back(--b);
			G[b].push_back(a);
		}
		if(N <= 2) {
			cout << "No\n";
			continue;
		}
		bool done = false;
		for(int i = 0; i < N; i++) if(G[i].size()%3 == 0) {
			cout << "Yes\n" << N-1 << "\n";
			bool st = true;
			for(int j = 0; j < N; j++) if(j != i) {
				if(!st) cout << " ";
				st = false;
				cout << j+1;
			}
			cout << "\n";
			done = true;
			break;
		}
		if(done) continue;
		for(int i = 0; i < N; i++) for(auto v : G[i]) if(G[i].size()%3 == 1 && G[v].size()%3 == 1) {
			if(done) break;
			cout << "Yes\n" << N-2 << "\n";
			bool st = true;
			for(int j = 0; j < N; j++) if(j != i && j != v) {
				if(!st) cout << " ";
				st = false;
				cout << j+1;
			}
			cout << "\n";
			done = true;
			break;
		}
		if(done) continue;
		vector< vector<int> > G2(N);
		for(int i = 0; i < N; i++) if(G[i].size()%3 == 2)
			for(auto v : G[i]) if(G[v].size()%3 == 2)
				G2[i].push_back(v);
		vector<int> par(N, -1), dep(N, 0);
		int n_comp = 0;
		for(int i = 0; i < N; i++) if(par[i] == -1) {
			par[i] = i;
			n_comp++;
			find_cycle(i, G2, par, dep, done);
			if(done) break;
		}
		if(done) continue;
		vector<int> adj1(N, 0);
		int cnt1 = 0;
		for(int i = 0; i < N; i++) if(G[i].size()%3 == 1) {
			cnt1++;
			for(auto v : G[i]) if(G[v].size()%3 == 2) adj1[v]++;
		}
		if(cnt1 >= 2) {
			if(N == 3) {
				cout << "No\n";
				continue;
			}
			// always solvable
			for(int i = 0; i < N; i++) if(adj1[i] >= 2) {
				cout << "Yes\n" << N-3 << "\n";
				int n[2] = {-1, -1};
				for(auto v : G[i]) if(G[v].size()%3 == 1) {
					if(n[0] == -1) n[0] = v;
					else n[1] = v;
				}
				for(int j = 0; j < N; j++) if(i != j && n[0] != j && n[1] != j)
					cout << j+1 << ((j == N-1) ? "\n" : " ");
				done = true;
				break;
			}
			if(done) continue;
			par = vector<int>(N, -1);
			for(int i = 0; i < N; i++) if(adj1[i] && par[i] == -1) {
				par[i] = i;
				int adj_first = -1;
				for(auto v : G[i]) if(G[v].size()%3 == 1) adj_first = v;
				find1(i, G2, par, adj1, adj_first, G, done);
				if(done) break;
			}
			continue;
		}
		if(done) continue;
		if(n_comp == 1) {
			vector<int> high_deg(N, 0);
			for(int i = 0; i < N; i++)
				high_deg[i] = (G[i].size()%3 == 2 && G2[i].size() >= 3);
			int root = (G[0].size()%3 == 1) ? 1 : 0;
			DFS(root, G2, par, high_deg);
			int rm = -1;
			for(int i = 0; i < N; i++) if(G[i].size()%3 == 2) {
				int n_sons = 0;
				for(auto v : G[i]) if(par[v] == i && high_deg[v]) n_sons++;
				if(high_deg[root] > high_deg[i]) n_sons++;
				if(n_sons >= 2) rm = i;
			}
			assert(rm != -1);
			for(auto v : G[rm]) {
				for(int i = 0; i < (int)G[v].size(); i++) if(G[v][i] == rm) {
					swap(G[v][i], G[v].back());
					G[v].pop_back();
					break;
				}
			}
			for(auto v : G2[rm]) {
				for(int i = 0; i < (int)G2[v].size(); i++) if(G2[v][i] == rm) {
					swap(G2[v][i], G2[v].back());
					G2[v].pop_back();
					break;
				}
			}
			G[rm].clear();
			G2[rm].clear();
		}
		vector<bool> paths(N, false), blocked(N, false);
		for(int i = 0; i < N; i++)
			if(G[i].size()%3 == 1) paths[i] = blocked[i] = true;
		int n_paths = 0;
		for(int i = 0; i < N; i++) if((int)G2[i].size() == 1) {
			int cur = i;
			blocked[cur] = true;
			bool ok = true;
			vector<int> seq = {i};
			while(!(adj1[cur] && cur != i)) {
				int next = -1;
				for(auto v : G2[cur]) if(!blocked[v]) next = v;
				if(next == -1) {
					ok = false;
					break;
				}
				cur = next;
				seq.push_back(cur);
				blocked[cur] = true;
			}
			if(!ok) continue;
			for(auto u : seq) {
				paths[u] = true;
				for(auto v : G2[u]) blocked[v] = true;
			}
			if(++n_paths == 2) break;
		}
		int cnt = 0;
		for(int i = 0; i < N; i++) if(!paths[i]) cnt++;
		if(cnt == 0 || cnt == N) cout << "No\n";
		else {
			cout << "Yes\n";
			cout << cnt << "\n";
			bool st = true;
			for(int i = 0; i < N; i++) if(!paths[i]) {
				if(!st) cout << " ";
				st = false;
				cout << i+1;
			}
			cout << "\n";
		}
	}
	return 0;
}

// look at my code
// my code is amazing