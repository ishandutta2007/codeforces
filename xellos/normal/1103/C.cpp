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

void DFS(int R, vector< vector<int> > & G, vector<int> & dep, vector<int> & par) {
	ALL_THE(G[R], it) if(par[*it] == -1) {
		dep[*it] = dep[R]+1;
		par[*it] = R;
		DFS(*it, G, dep, par);
	}
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout << fixed << setprecision(10);
	int N, M, K;
	cin >> N >> M >> K;
	vector< vector<int> > G(N);
	for(int i = 0; i < M; i++) {
		int u, v;
		cin >> u >> v;
		G[--u].push_back(--v);
		G[v].push_back(u);
	}
	vector<int> dep(N, 0);
	vector<int> par(N, -1);
	par[0] = 0;
	DFS(0, G, dep, par);
	vector< vector<int> > dep_sort(N);
	for(int i = 0; i < N; i++) dep_sort[dep[i]].push_back(i);
	vector<int> in_cyc_mindep(N, N+1);
	vector< vector<int> > ans_cyc;
	for(int i = N-1; i >= 0; i--) ALL_THE(dep_sort[i], it) {
		int v = *it;
		if(in_cyc_mindep[v] < dep[v])
			in_cyc_mindep[par[v]] = min(in_cyc_mindep[par[v]], in_cyc_mindep[v]);
		if(in_cyc_mindep[v] <= dep[v]) continue;
		vector<int> new_cyc(1, v);
		vector<int> back_cand;
		ALL_THE(G[v], jt) if(dep[*jt] < dep[v] && *jt != par[v]) back_cand.push_back(*jt);
		ALL_THE(back_cand, jt) if((dep[v]-dep[*jt]+1)%3 != 0) {
			int w = v;
			while(w != *jt) {
				w = par[w];
				new_cyc.push_back(w);
			}
			in_cyc_mindep[v] = dep[*jt];
			in_cyc_mindep[par[v]] = min(in_cyc_mindep[par[v]], in_cyc_mindep[v]);
			break;
		}
		if((int)new_cyc.size() == 1) {
			if((int)back_cand.size() <= 1) continue;
			int u1 = back_cand[0], u2 = back_cand[1];
			if(dep[u1] > dep[u2]) swap(u1, u2);
			int w = u2;
			new_cyc.push_back(w);
			while(w != u1) {
				w = par[w];
				new_cyc.push_back(w);
			}
			in_cyc_mindep[u2] = min(in_cyc_mindep[u2], dep[u1]);
			in_cyc_mindep[par[u2]] = min(in_cyc_mindep[par[u2]], dep[u1]);
		}
		if((cat)new_cyc.size() * K >= N) {
			cout << "PATH\n" << new_cyc.size() << "\n";
			for(int j = 0; j < (int)new_cyc.size(); j++)
				cout << new_cyc[j]+1 << ((j+1 == (int)new_cyc.size()) ? "\n" : " ");
			return 0;
		}
		ans_cyc.push_back(new_cyc);
		if((int)ans_cyc.size() == K) {
			cout << "CYCLES\n";
			for(int i = 0; i < K; i++) {
				cout << ans_cyc[i].size() << "\n";
				for(int j = 0; j < (int)ans_cyc[i].size(); j++)
					cout << ans_cyc[i][j]+1 << ((j+1 == (int)ans_cyc[i].size()) ? "\n" : " ");
			}
			return 0;
		}
	}
}

// look at my code
// my code is amazing