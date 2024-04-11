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

typedef struct {
	int tp, v;
} query;

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout << fixed << setprecision(10);
	int N, Q, X = 500;
	cin >> N >> Q;
	vector<int> par(N, 0);
	vector< vector<int> > G(N);
	for(int i = 1; i < N; i++) {
		cin >> par[i];
		G[--par[i]].push_back(i);
	}
	vector<bool> C(N, false), propagate(N, false);
	vector<int> used(N), cntw_up(N), cntb_up(N), par_reduced(N), seq;
	vector<int> top(N), lastw(N, -1), cntb(N, 0);
	vector< vector<int> > upd(N);
	for(int q = 0; q < Q; q += X) {
		int nq = min(Q, q+X) - q;
		vector<query> query(nq);
		for(int i = 0; i < N; i++) used[i] = 0;
		for(int i = 0; i < nq; i++) {
			cin >> query[i].tp >> query[i].v;
			used[--query[i].v] = 2;
		}
		for(int i = N-1; i > 0; i--) if(used[i] != 0) {
			int cnt = 0;
			ALL_THE(G[i], it) if(used[*it] != 0) cnt++;
			if(cnt > 1) used[i] = 2;
			if(used[par[i]] != 2) used[par[i]] = 1;
		}
		used[0] = 2;
		seq.clear();
		for(int i = 0; i < N; i++) if(used[i] == 2) {
			seq.push_back(i);
			seq.push_back(par[i]);
			cntw_up[i] = cntb_up[i] = 0;
			if(C[i]) cntb_up[i] = 1;
			else cntw_up[i] = 1;
			if(used[par[i]] != 2) {
				cntw_up[par[i]] = cntb_up[par[i]] = 0;
				int v = par[i];
				while(used[v] != 2) {
					if(C[v]) cntb_up[par[i]]++;
					else cntw_up[par[i]]++;
					v = par[v];
				}
				par_reduced[i] = par[i];
				par_reduced[par[i]] = v;
			}
			else par_reduced[i] = par[i];
		}
		sort(begin(seq), end(seq));
		for(int i = 0; i < nq; i++) {
			if(query[i].tp == 3) {
				if(cntw_up[query[i].v] == 1) cout << "white\n";
				else cout << "black\n";
				continue; 
			}
			propagate[query[i].v] = true;
			for(int j = 0; j < (int)seq.size(); j++) if(j == 0 || seq[j] != seq[j-1]) {
				int v = seq[j];
				if(propagate[par_reduced[v]]) propagate[v] = true;
				if(!propagate[v]) continue;
				if(query[i].tp == 2) {
					cntw_up[v] += cntb_up[v];
					cntb_up[v] = 0;
				}
				else {
					if(cntw_up[v] > 0) {
						cntw_up[v]--;
						cntb_up[v]++;
						propagate[v] = false;
					}
				}
			}
			for(int j = 0; j < (int)seq.size(); j++) propagate[seq[j]] = false;
		}
		for(int i = 0; i < nq; i++) {
			if(query[i].tp == 2) lastw[query[i].v] = i+q;
			if(query[i].tp == 1) upd[query[i].v].push_back(q+i);
		}
		for(int i = 0; i < N; i++) {
			lastw[i] = max(lastw[i], lastw[par[i]]);
			vector<int> w;
			ALL_THE(upd[i], it) if(*it > lastw[i]) w.push_back(*it);
			upd[i] = w;
		}
		for(int i = 0; i < N; i++) {
			if(used[i] == 2) {
				top[i] = i;
				cntb[i] = 0;
				if(i != 0) {
					vector<int> v, w = upd[i];
					for(int j = cntb[par[i]]; j < (int)upd[top[par[i]]].size(); j++)
						if(upd[top[par[i]]][j] > lastw[i]) v.push_back(upd[top[par[i]]][j]);
					upd[i].resize(v.size()+w.size());
					merge(begin(v), end(v), begin(w), end(w), begin(upd[i]));
				}
			}
			else top[i] = top[par[i]], cntb[i] = cntb[par[i]];
			if(lastw[i] >= q) C[i] = false;
			if(!C[i]) cntb[i]++;
			if(cntb[i] <= (int)upd[top[i]].size()) C[i] = true;
		}
		for(int i = 0; i < N; i++) upd[i].clear();
	}
	return 0;
}

// look at my code
// my code is amazing