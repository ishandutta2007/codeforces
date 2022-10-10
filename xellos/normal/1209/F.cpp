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

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout << fixed << setprecision(10);
	int N, M;
	cin >> N >> M;
	vector< pair<int, int> > VI(M+1, {0, 0});
	int V = 0;
	for(int i = 1; i <= M; i++) {
		int d = 0, x = i;
		while(x) x /= 10, d++;
		VI[i] = {VI[i-1].ss, VI[i-1].ss+d-1};
		V += d-1;
	}
	vector< pair<int, int> > E(M);
	vector< vector< pair<int, int> > > G(N);
	for(int i = 0; i < M; i++) {
		int u, v;
		cin >> u >> v;
		E[i] = {--u, --v};
		int x = i+1, l = 0;
		while(x) x /= 10, l++;
		G[u].push_back({v, l});
		G[v].push_back({u, l});
	}
	priority_queue< pair<int, int>, vector< pair<int, int> >, greater< pair<int, int> > > q;
	vector<int> L(N, OVER9000), seq;
	q.push({0, 0});
	L[0] = 0;
	while(!q.empty()) {
		auto p = q.top();
		q.pop();
		if(p.ff != L[p.ss]) continue;
		seq.push_back(p.ss);
		for(auto r : G[p.ss]) if(L[r.ff] > p.ff+r.ss) {
			L[r.ff] = p.ff+r.ss;
			q.push({p.ff+r.ss, r.ff});
		}
	}

	vector< vector< pair<int, int> > > Gi(N+V);
	vector< vector<int> > seq2(N);
	int Vc = 0;
	for(int i = 0; i < M; i++) {
		int u = E[i].ff, v = E[i].ss;
		if(L[u] == L[v]) continue;
		if(L[u] > L[v]) swap(u, v);
		int d = 0, x = i+1;
		while(x) d++, x /= 10;
		if(L[u]+d != L[v]) continue;
		x = i+1;
		int cur = v, prev = N+Vc;
		while(x) {
			if(cur >= N) seq2[v].push_back(cur);
			int val = x%10;
			x /= 10;
			if(x == 0) prev = u;
			Gi[cur].push_back({prev, val});
			cur = prev;
			prev++;
		}
		Vc += d-1;
	}
	vector<int> seq3;
	for(int i = 0; i < N; i++) {
		reverse(begin(seq2[seq[i]]), end(seq2[seq[i]]));
		for(auto x : seq2[seq[i]]) seq3.push_back(x);
		seq3.push_back(seq[i]);
	}
	seq = seq3;

	vector< vector<int> > prev_v(N+V, vector<int>(30, 0));
	vector< pair<cat, cat> > H(N+V, {0, 0});
	vector<int> val(N+V, 0);
	cat mod1 = mod, mod2 = 1000000009;

	vector<cat> ans(N+V, 0);
	for(auto v : seq) {
		int opt = -1, opt_v;
		for(auto e : Gi[v]) {
			if(opt == -1) {
				opt = e.ff;
				opt_v = e.ss;
				continue;
			}
			// compare strings
			int cur = e.ff, cur_opt = opt;
			bool better = false;
			if(H[cur] == H[cur_opt]) {
				if(e.ss < opt_v) better = true;
			}
			else {
				for(int k = 28; k >= 0; k--) while(true) {
					int a = prev_v[cur][k], b = prev_v[cur_opt][k];
					if(H[a] == H[b]) break;
					cur = a;
					cur_opt = b;
				}
				if(val[cur] < val[cur_opt]) better = true;
			}
			if(better) {
				opt = e.ff;
				opt_v = e.ss;
			}
		}
		if(opt == -1) continue;

		ans[v] = (ans[opt] * 10 + opt_v) % mod;
		prev_v[v][0] = opt;
		for(int k = 1; k <= 28; k++) prev_v[v][k] = prev_v[prev_v[v][k-1]][k-1];
		val[v] = opt_v;
		H[v].ff = (H[opt].ff * 999983 + opt_v + 1) % mod1;
		H[v].ss = (H[opt].ss * 999983 + opt_v + 1) % mod2;
	}

	for(auto v : seq) if(ans[v] < 0) ans[v] += mod;
	for(int i = 1; i < N; i++) cout << ans[i] << "\n";
	return 0;
}

// look at my code
// my code is amazing