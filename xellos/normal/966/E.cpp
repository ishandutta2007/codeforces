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

void DFS(int R, vector< vector<int> > & son, vector<int> & seq) {
	seq.push_back(R);
	ALL_THE(son[R], it) DFS(*it, son, seq);
}

void make_unique(vector<int> & V) {
	sort(begin(V), end(V));
	auto it = unique(begin(V), end(V));
	int sz = it - begin(V);
	V.resize(sz);
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout << fixed << setprecision(10);
	int N, Q, X = 300;
	cin >> N >> Q;
	vector<int> par(N, 0), seq;
	vector< vector<int> > son(N);
	for(int i = 1; i < N; i++) {
		cin >> par[i];
		son[--par[i]].push_back(i);
	}
	DFS(0, son, seq);
	vector<int> V(N), V_nw(N);
	for(int i = 0; i < N; i++) cin >> V[i];
	vector< vector<int> > cnt(N);
	vector<int> add_cnt(N), top(N);
	vector<int> is_vac(N, false);
	int ans = 0;
	for(int q = 0; q < Q; q += X) {
		int nq = min(Q, q+X) - q;
		vector< pair<int, int> > query(nq);
		vector<int> used(N, 0), used_chg;
		used[0] = 1;
		for(int i = 0; i < nq; i++) {
			cin >> query[i].ff;
			if(query[i].ff > 0) query[i].ss = 1;
			else query[i].ss = 0, query[i].ff *= -1;
			int cur = --query[i].ff;
			used[cur] |= 2;
			while((used[cur]>>2) == 0) {
				used[cur] += 4;
				cur = par[cur];
			}
			used[cur] |= 1;
			used_chg.push_back(query[i].ff);
			V_nw[query[i].ff] = V[query[i].ff];
		}
		make_unique(used_chg);
		for(int i = 0; i < N; i++) if(used[i]&3) {
			add_cnt[i] = 0;
			cnt[i].resize(2*X, 0);
			int cur = i;
			while(true) {
				if(!is_vac[cur] && (used[cur]&2) == 0)
					if(V[cur] >= -X && V[cur] < X) cnt[i][V[cur]+X]++;
				cur = par[cur];
				if(used[cur]&1) break;
			}
			top[i] = cur;
		}
		vector<int> add(N, 0);
		for(int i = 0; i < nq; i++) {
			int cur = query[i].ff;
			ALL_THE(used_chg, it) if(V_nw[*it] < 0 && !is_vac[*it]) ans--;
			while(true) {
				if(used[cur]&2) V_nw[cur] += (query[i].ss) ? -1 : 1;
				if(query[i].ss) ans += cnt[cur][X+add_cnt[cur]];
				else ans -= cnt[cur][X+add_cnt[cur]-1];
				add_cnt[cur] += (query[i].ss) ? 1 : -1;
				if(cur == 0) break;
				cur = top[cur];
			}
			is_vac[query[i].ff] = !is_vac[query[i].ff];
			ALL_THE(used_chg, it) if(V_nw[*it] < 0 && !is_vac[*it]) ans++;
			add[query[i].ff] += (query[i].ss) ? -1 : 1;
			cout << ans << ((q+i+1 == Q) ? "\n" : " ");
		}
		for(int i = N-1; i >= 0; i--) {
			int v = seq[i];
			V[v] += add[v];
			add[par[v]] += add[v];
		}
		for(int i = 0; i < N; i++) if(used[i]&3) cnt[i] = vector<int>();
	}
	return 0;
}

// look at my code
// my code is amazing