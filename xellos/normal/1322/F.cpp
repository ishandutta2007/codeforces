// iostream is too mainstream
#include <cstdio>
// bitch please
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <list>
#include <chrono>
#include <random>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cstring>
#include <iomanip>
#define dibs reserve
#define OVER9000 1234567890
#define tisic 47
#define soclose 1e-8
#define patkan 9
#define ff first
#define ss second
#define abs(x) (((x) < 0)?-(x):(x))
using uint = unsigned int;
using cat = long long;
using dbl = long double;
constexpr dbl pi = 3.14159265358979323846;
using namespace std;

#ifdef DONLINE_JUDGE
	// palindromic tree is better than splay tree!
	#define lld I64d
#endif

void DFS_LCA(int v, auto & G, auto & par, auto & dep, auto & seq) {
	seq.push_back(v);
	for(auto s : G[v]) if(par[s] == -1) {
		par[s] = v;
		dep[s] = dep[v]+1;
		DFS_LCA(s, G, par, dep, seq);
	}
}

void DFS_comp(int v, auto & G, auto & par, auto & dep, auto & up, auto & down,
		auto & comp, auto & comp_l) {
	for(auto s : G[v]) if(par[s] == v) {
		DFS_comp(s, G, par, dep, up, down, comp, comp_l);
		up[v] = min(up[v], up[s]);
	}
	static vector<int> sons;
	sons.clear();
	static vector<int> id(par.size());
	for(auto s : G[v]) if(par[s] == v) {
		id[s] = sons.size();
		sons.push_back(s);
	}

	int S = sons.size(), C = 0;
	comp[v].resize(S+1, 0);
	static vector< vector<int> > g(par.size());
	for(int i = 0; i <= S; i++) g[i].clear();
	for(auto p : down[v]) {
		g[id[p.ff]].push_back(id[p.ss]);
		g[id[p.ss]].push_back(id[p.ff]);
	}
	for(int i = 0; i < S; i++) if(up[sons[i]] < dep[v]) {
		g[S].push_back(i);
		g[i].push_back(S);
	}

	static queue<int> q;
	for(int i = 0; i <= S; i++) if(!comp[v][i]) {
		q.push(i);
		C++;
		comp[v][i] = C;
		comp_l[v].push_back({});
		while(!q.empty()) {
			comp_l[v].back().push_back(q.front());
			int c = comp[v][q.front()];
			for(auto r : g[q.front()]) {
				if(comp[v][r] && comp[v][r] == c) {
					cout << "-1\n";
					exit(0);
				}
				if(comp[v][r]) continue;
				comp[v][r] = -c;
				q.push(r);
			}
			q.pop();
		}
	}
}

void DFS_solve(int v, auto & G, auto & par, auto & dep, auto & up,
		auto & comp, auto & comp_l, auto & I_up, auto & I_dn, int A) {
	for(auto s : G[v]) if(par[s] == v)
		DFS_solve(s, G, par, dep, up, comp, comp_l, I_up, I_dn, A);
	static vector<int> sons;
	sons.clear();
	static vector<int> id(par.size());
	for(auto s : G[v]) if(par[s] == v) {
		id[s] = sons.size();
		sons.push_back(s);
	}

	int C = comp_l[v].size(), S = sons.size();

	static vector<int> i_up(par.size());
	for(int i = 0; i < S; i++) i_up[i] = I_up[sons[i]];
	static vector<int> i_dn(par.size());
	for(int i = 0; i < S; i++) i_dn[i] = I_dn[sons[i]];
	static vector<char> ud(par.size());
	for(int i = 0; i < S; i++) ud[i] = (up[sons[i]] <= dep[v]);

	I_up[v] = 0;
	I_dn[v] = A;
	static vector< pair<int, int> > bl;
	bl.clear();
	for(int i = 0; i < C; i++) {
		int up_min_val[2] = {0, 0};
		int dn_max_val[2] = {A, A};
		bool ok[2] = {1, 1};
		for(auto r : comp_l[v][i]) if(r != S) {
			int c = comp[v][r];
			int k = (c > 0) ? 0 : 1;
			if(i_up[r] != -1 && i_up[r] < A)
				up_min_val[1-k] = max(up_min_val[1-k], i_up[r]+1);
			else ok[1-k] = 0;
			if(i_dn[r] != -1 && i_dn[r] > 0)
				dn_max_val[k] = min(dn_max_val[k], i_dn[r]-1);
			else ok[k] = 0;
		}
		if((int)comp_l[v][i].size() == 1) {
			int r = comp_l[v][i][0];
			if(r != S && !ud[r]) {
				if(i_up[r] == -1 && i_dn[r] == -1) {
					I_up[v] = I_dn[v] = -1;
					return;
				}
				continue;
			}
		}
		if(!ok[0] && !ok[1]) {
			I_up[v] = I_dn[v] = -1;
			return;
		}
		if(comp[v][S] != i+1 && comp[v][S] != -i-1) {
			if(up_min_val[0] > dn_max_val[0]) ok[0] = 0;
			if(up_min_val[1] > dn_max_val[1]) ok[1] = 0;
			if(!ok[0]) {
				if(I_up[v] != -1) I_up[v] = max(I_up[v], up_min_val[1]);
				if(I_dn[v] != -1) I_dn[v] = min(I_dn[v], dn_max_val[1]);
			}
			else if(!ok[1]) {
				if(I_up[v] != -1) I_up[v] = max(I_up[v], up_min_val[0]);
				if(I_dn[v] != -1) I_dn[v] = min(I_dn[v], dn_max_val[0]);
			}
			else {
				if(I_up[v] != -1) I_up[v] = max(I_up[v], min(up_min_val[0], up_min_val[1]));
				if(I_dn[v] != -1) I_dn[v] = min(I_dn[v], max(dn_max_val[0], dn_max_val[1]));
				if(up_min_val[0] > dn_max_val[1]+1) bl.push_back({dn_max_val[1]+1, up_min_val[0]-1});
				if(up_min_val[1] > dn_max_val[0]+1) bl.push_back({dn_max_val[0]+1, up_min_val[1]-1});
			}
			continue;
		}
		if(comp[v][S] == i+1) {
			if(I_up[v] != -1) I_up[v] = max(I_up[v], up_min_val[0]);
			if(I_dn[v] != -1) I_dn[v] = min(I_dn[v], dn_max_val[1]);
		}
		else { // comp[S] == -i-1
			if(I_up[v] != -1) I_up[v] = max(I_up[v], up_min_val[1]);
			if(I_dn[v] != -1) I_dn[v] = min(I_dn[v], dn_max_val[0]);
		}
	}

	sort(begin(bl), end(bl));
	pair<int, int> cur = {-1, -1};
	for(auto & p : bl) {
		if(cur.ff == -1) cur = p;
		if(cur.ss < p.ff-1) continue;
		cur.ss = max(cur.ss, p.ss);
		p = cur;
	}
	if(I_up[v] != -1) for(auto p : bl) {
		if(p.ff > I_up[v] || I_up[v] > p.ss) continue;
		I_up[v] = max(I_up[v], p.ss+1);
		if(I_up[v] > A) {
			I_up[v] = -1;
			break;
		}
	}
	if(I_dn[v] != -1) for(auto p : bl) {
		if(p.ff > I_dn[v] || I_dn[v] > p.ss) continue;
		I_dn[v] = min(I_dn[v], p.ff-1);
		if(I_dn[v] < 0) {
			I_dn[v] = -1;
			break;
		}
	}

	// check if valid
	static vector<char> state_up(par.size()+1);
	static vector<char> state_dn(par.size()+1);
	for(int i = 0; i <= C; i++) state_up[i] = state_dn[i] = 3;
	for(int i = 0; i < S; i++) if(ud[i]) {
		if(comp[v][S] == -comp[v][i]) {
			if(i_up[i] >= I_up[v]) I_up[v] = -1;
			if(i_dn[i] <= I_dn[v]) I_dn[v] = -1;
			continue;
		}
		if(comp[v][S] == comp[v][i]) {
			if(i_up[i] >= I_dn[v]) I_dn[v] = -1;
			if(i_dn[i] <= I_up[v]) I_up[v] = -1;
			continue;
		}
		int k = (comp[v][i] < 0), c = (comp[v][i] < 0) ? -comp[v][i] : comp[v][i];
		if(i_dn[i] <= I_up[v]) state_up[c] &= 1<<k;
		if(i_up[i] >= I_up[v]) state_up[c] &= 1<<(1-k);
		if(i_dn[i] <= I_dn[v]) state_dn[c] &= 1<<(1-k);
		if(i_up[i] >= I_dn[v]) state_dn[c] &= 1<<k;
	}
	for(int i = 1; i <= C; i++) if(state_up[i] == 0) I_up[v] = -1;
	for(int i = 1; i <= C; i++) if(state_dn[i] == 0) I_dn[v] = -1;
}

void DFS_reconstruct(int v, auto & G, auto & par, auto & dep,
		auto & up, auto & down, auto & I_up, auto & I_dn, auto & ans, int dir) {
	ans[v] = (dir == 0) ? I_up[v] : I_dn[v];
	vector<int> sons;
	sons.dibs(G[v].size());
	static vector<int> id(par.size());
	for(auto s : G[v]) if(par[s] == v) {
		id[s] = sons.size();
		sons.push_back(s);
	}
	int S = sons.size(), C = 0;
	static vector<int> comp(par.size());
	static vector< vector<int> > g(par.size());
	for(int i = 0; i <= S; i++) g[i].clear(), comp[i] = 0;
	for(auto p : down[v]) {
		g[id[p.ff]].push_back(id[p.ss]);
		g[id[p.ss]].push_back(id[p.ff]);
	}
	for(int i = 0; i < S; i++) if(up[sons[i]] < dep[v]) {
		g[S].push_back(id[sons[i]]);
		g[id[sons[i]]].push_back(S);
	}

	static queue<int> q;
	static vector<int> dirs(par.size());
	for(int i = 0; i <= S; i++) if(!comp[i]) {
		bool ok_dir[2] = {true, true};
		q.push(i);
		C++;
		comp[i] = C;
		static vector<int> V;
		V.clear();
		while(!q.empty()) {
			V.push_back(q.front());
			int c = comp[q.front()];
			if(q.front() != S) {
				int k = (c < 0);
				if(I_dn[sons[q.front()]] == -1) ok_dir[k] = false;
				if(I_dn[sons[q.front()]] < ans[v]+1) ok_dir[k] = false;
				if(I_up[sons[q.front()]] == -1) ok_dir[1-k] = false;
				if(I_up[sons[q.front()]] > ans[v]-1) ok_dir[1-k] = false;
			}
			for(auto r : g[q.front()]) if(!comp[r]) {
				comp[r] = -c;
				q.push(r);
			}
			q.pop();
		}
		if(i != S && up[sons[i]] >= dep[sons[i]]) {
			if(I_up[sons[i]] != -1 && I_up[sons[i]] < ans[v])
				ans[sons[i]] = I_up[sons[i]], dirs[sons[i]] = 0;
			else
				ans[sons[i]] = I_dn[sons[i]], dirs[sons[i]] = 1;
			continue;
		}
		if(comp[S] != C && comp[S] != -C) {
			int dir_k = ok_dir[1];
			for(auto s : V) if(s != S) {
				int k = (comp[s] < 0);
				dirs[sons[s]] = (k == dir_k);
			}
			continue;
		}
		for(auto s : V) if(s != S) {
			if(comp[s] != comp[S]) dirs[sons[s]] = dir;
			else dirs[sons[s]] = 1-dir;
		}
	}

	for(auto s : G[v]) if(par[s] == v)
		DFS_reconstruct(s, G, par, dep, up, down, I_up, I_dn, ans, dirs[s]);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cout << fixed << setprecision(10);
	int N, M;
	cin >> N >> M;
	vector< vector<int> > G(N);
	for(int i = 0; i < N-1; i++) {
		int u, v;
		cin >> u >> v;
		G[--u].push_back(--v);
		G[v].push_back(u);
	}

	vector<int> dep(N, 0);
	vector< vector<int> > par(20, vector<int>(N, -1));
	par[0][0] = 0;
	vector<int> DFS_seq, DFS_id(N);
	DFS_LCA(0, G, par[0], dep, DFS_seq);
	for(int i = 0; i < N; i++) DFS_id[DFS_seq[i]] = i;
	vector< vector<int> > G_reordered(N);
	for(int i = 0; i < N; i++)
		for(auto v : G[i])
			G_reordered[DFS_id[i]].push_back(DFS_id[v]);
	G = G_reordered;
	vector<int> dep_reordered(N), par_reordered(N);
	for(int i = 0; i < N; i++) dep_reordered[DFS_id[i]] = dep[i];
	for(int i = 0; i < N; i++) par_reordered[DFS_id[i]] = DFS_id[par[0][i]];
	dep = dep_reordered, par[0] = par_reordered;
	for(int k = 1; k < 20; k++)
		for(int i = 0; i < N; i++)
			par[k][i] = par[k-1][par[k-1][i]];

	vector<int> up(N, N);
	vector< vector< pair<int, int> > > down(N);
	for(int i = 0; i < M; i++) {
		int u, v;
		cin >> u >> v;
		u--, v--;
		u = DFS_id[u], v = DFS_id[v];
		if(dep[u] > dep[v]) swap(u, v);
		int d = dep[v]-dep[u], a = v;
		for(int k = 0; d; k++, d /= 2) if(d&1) a = par[k][a];
		if(a == u) {
			up[v] = min(up[v], dep[u]);
			continue;
		}
		int b = u;
		for(int k = 19; k >= 0; k--)
			if(par[k][a] != par[k][b])
				a = par[k][a], b = par[k][b];
		int l = par[0][a];
		up[u] = min(up[u], dep[l]);
		up[v] = min(up[v], dep[l]);
		down[l].push_back({a, b});
	}
	vector< vector<int> > comp(N);
	vector< vector< vector<int> > > comp_l(N);
	DFS_comp(0, G, par[0], dep, up, down, comp, comp_l);

	int ans_min = 0, ans_max = N+1;
	vector<int> I_up_ans, I_dn_ans;
	while(ans_max-ans_min > 1) {
		int A = (ans_min + ans_max) / 2;
		static vector<int> I_up(N), I_dn(N);
		DFS_solve(0, G, par[0], dep, up, comp, comp_l, I_up, I_dn, A);
		if(I_up[0] != -1 || I_dn[0] != -1) {
			ans_max = A;
			I_up_ans = I_up;
			I_dn_ans = I_dn;
		}
		else ans_min = A;
	}

	if(ans_max == N+1) {
		cout << "-1\n";
		return 0;
	}
	cout << ans_max+1 << "\n";
	// reconstruct
	vector<int> ans(N);
	if(I_up_ans[0] != -1)
		DFS_reconstruct(0, G, par[0], dep, up, down, I_up_ans, I_dn_ans, ans, 0);
	else
		DFS_reconstruct(0, G, par[0], dep, up, down, I_up_ans, I_dn_ans, ans, 1);
	for(int i = 0; i < N; i++) cout << ans[DFS_id[i]]+1 << ((i == N-1) ? "\n" : " ");
	return 0;
}

// look at my code
// my code is amazing