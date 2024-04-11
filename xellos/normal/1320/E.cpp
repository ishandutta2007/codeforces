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
#include <cassert>
// mylittledoge

using cat = long long;

#ifdef DONLINE_JUDGE
	// palindromic tree is better than splay tree!
	#define lld I64d
#endif

void DFS(int R, auto & G, auto & dep, auto & par, auto & I) {
	I[R].ss = I[R].ff+1;
	for(auto s : G[R]) if(par[s] == -1) {
		par[s] = R;
		dep[s] = dep[R]+1;
		I[s].ff = I[R].ss;
		DFS(s, G, dep, par, I);
		I[R].ss = I[s].ss;
	}
}

struct fin {
	vector<int> T;
	fin(int N) { T.resize(N+10, 0); }

	int lastone(int x) { return x & (x ^ (x-1)); }

	void put(int pos, int val) {
		for(int i = pos+1; i < (int)T.size(); i += lastone(i)) T[i] += val;
	}

	int get(int pos) {
		int ret = 0;
		for(int i = pos+1; i > 0; i -= lastone(i)) ret += T[i];
		return ret;
	}
};

struct virus {
	int v, id, step;

	bool operator<(const virus & A) const {
		if(step != A.step) return step > A.step;
		return id > A.id;
	}
};

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout << fixed << setprecision(10);
	int N, Q;
	cin >> N;
	vector< vector<int> > G(N);
	for(int i = 0; i < N-1; i++) {
		int u, v;
		cin >> u >> v;
		G[--u].push_back(--v);
		G[v].push_back(u);
	}
	cin >> Q;
	vector<int> dep(N, 0);
	vector< vector<int> > par(20, vector<int>(N, -1));
	par[0][0] = 0;
	vector< pair<int, int> > I(N, {0, 0});
	DFS(0, G, dep, par[0], I);
	for(int i = 1; i < 19; i++)
		for(int j = 0; j < N; j++)
			par[i][j] = par[i-1][par[i-1][j]];
	fin F(N);
	for(int q = 0; q < Q; q++) {
		int K, M;
		cin >> K >> M;
		vector<int> V(K), S(K), C(M);
		static priority_queue< pair<int, int> > q_compr;
		static vector<char> used(N, 0);
		for(int i = 0; i < K; i++) {
			cin >> V[i] >> S[i];
			used[--V[i]] = 1;
			q_compr.push({dep[V[i]], V[i]});
			F.put(I[V[i]].ff, 1);
		}
		for(int i = 0; i < M; i++) {
			cin >> C[i];
			used[--C[i]] = 1;
			q_compr.push({dep[C[i]], C[i]});
			F.put(I[C[i]].ff, 1);
		}
		q_compr.push({0, 0});
		static vector<int> compr, par_compr;
		compr.clear();
		par_compr.clear();
		while(!q_compr.empty()) {
			auto [d, v] = q_compr.top();
			q_compr.pop();
			if(!compr.empty() && compr.back() == v) continue;
			compr.push_back(v);
			if(!v) continue;
			int n = F.get(I[v].ss-1) - F.get(I[v].ff-1);
			for(int k = 18; k >= 0; k--) {
				int v_up = par[k][v];
				int n_up = F.get(I[v_up].ss-1) - F.get(I[v_up].ff-1);
				if(n_up == n) v = v_up;
			}
			if(v) v = par[0][v];
			par_compr.push_back(v);
			if(!used[v]) q_compr.push({dep[v], v});
			used[v] = 1;
		}
		par_compr.push_back(0);
		int N_compr = compr.size();
		static vector<int> id(N);
		for(int i = 0; i < N_compr; i++) id[compr[i]] = i;
		static vector< vector< pair<int, int> > > G_compr(N);
		for(int i = 0; i < N_compr; i++) G_compr[i].clear();
		for(int i = 0; i < N_compr-1; i++) {
			G_compr[id[par_compr[i]]].push_back({id[compr[i]], dep[compr[i]]-dep[par_compr[i]]});
			G_compr[id[compr[i]]].push_back({id[par_compr[i]], dep[compr[i]]-dep[par_compr[i]]});
		}
		vector<int> ans(N_compr, 0), min_step(N_compr, N+10), dist_orig(N_compr, 0);
		static priority_queue<virus> q_v;
		for(int i = 0; i < K; i++) {
			ans[id[V[i]]] = i+1;
			q_v.push({id[V[i]], i, 0});
			min_step[id[V[i]]] = 0;
		}
		while(!q_v.empty()) {
			auto [v, virus_id, step] = q_v.top();
			q_v.pop();
			if(step != min_step[v] || virus_id+1 != ans[v]) continue;
			for(auto [u, l] : G_compr[v]) {
				int next_step = (dist_orig[v] + l + S[virus_id]-1) / S[virus_id];
				if(next_step > min_step[u]) continue;
				if(next_step == min_step[u] && ans[u] < virus_id+1) continue;
				if(next_step == min_step[u] && ans[u] == virus_id+1) continue;
				min_step[u] = next_step;
				ans[u] = virus_id+1;
				dist_orig[u] = dist_orig[v] + l;
				q_v.push({u, virus_id, next_step});
			}
		}
		for(int i = 0; i < M; i++) cout << ans[id[C[i]]] << ((i == M-1) ? "\n" : " ");
		for(int i = 0; i < N_compr; i++) used[compr[i]] = 0;
		for(int i = 0; i < K; i++) F.put(I[V[i]].ff, -1);
		for(int i = 0; i < M; i++) F.put(I[C[i]].ff, -1);
	}
	return 0;
}

// look at my code
// my code is amazing