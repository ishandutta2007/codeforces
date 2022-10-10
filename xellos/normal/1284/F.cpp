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

int P = 0;
vector<int> par, dep, path_pos, in_path;
vector<int> par_up[20];
vector< vector<int> > paths;

void DFS(int R, auto & G, auto & sz) {
	int best_son = -1, best_sz = 0;
	for(auto s : G[R]) if(par[R] != s) {
		par[s] = R;
		dep[s] = dep[R]+1;
		DFS(s, G, sz);
		sz[R] += sz[s];
		if(sz[s] > best_sz) best_sz = sz[s], best_son = s;
	}
	if(best_son == -1) {
		paths.push_back({R});
		in_path[R] = P++;
	}
	else {
		in_path[R] = in_path[best_son];
		paths[in_path[R]].push_back(R);
	}
}

vector<int> used_pt;
vector< set<int> > used_p;

vector< pair< pair<int, int>, pair<int, int> > > ans;

void solve(int R, int par2, auto & G) {
	for(auto s : G[R]) if(par2 != s) solve(s, R, G);
	if(R == par2) return;
	int u = R, v = par2;
	if(dep[u] > dep[v]) swap(u, v);
	for(int k = 19; k >= 0; k--) while(dep[v]-dep[u] >= (1<<k))
		v = par_up[k][v];
	for(int k = 19; k >= 0; k--) if(par_up[k][u] != par_up[k][v]) {
		u = par_up[k][u];
		v = par_up[k][v];
	}
	int l = (u == v) ? u : par[u];
	u = R, v = par2;
	bool found = false;
	while(!found && u != l) {
		int p = in_path[u];
		int r = path_pos[u], ll = 1;
		if(in_path[l] == p) ll = 1+path_pos[l];
		auto it = used_p[p].upper_bound(r);
		if(it != begin(used_p[p])) {
			it--;
			if(*it >= ll) {
				ans.push_back({{paths[p][*it], paths[p][(*it)-1]}, {R, par2}});
				used_p[p].erase(it);
				found = true;
				break;
			}
		}
		if(in_path[l] == p) break;
		u = paths[p][0];
		if(!used_pt[p]) {
			ans.push_back({{u, par[u]}, {R, par2}});
			used_pt[p] = 1;
			found = true;
		}
		u = par[u];
	}
	vector< pair<int, pair<int, int> > > path_seq;
	while(!found && v != l) {
		int p = in_path[v];
		int r = path_pos[v], ll = 1;
		if(in_path[l] == p) ll = 1+path_pos[l];
		path_seq.push_back({p, {ll, r}});
		if(in_path[l] == p) break;
		path_seq.push_back({p, {0, 0}});
		v = paths[p][0];
		v = par[v];
	}
	reverse(begin(path_seq), end(path_seq));
	if(!found) for(auto pp : path_seq) {
		int p = pp.ff;
		if(!pp.ss.ff) {
			if(!used_pt[p]) {
				ans.push_back({{paths[p][0], par[paths[p][0]]}, {R, par2}});
				used_pt[p] = 1;
				found = true;
				break;
			}
			continue;
		}
		auto it = used_p[p].lower_bound(pp.ss.ff);
		if(it != end(used_p[p])) {
			if(*it <= pp.ss.ss) {
				ans.push_back({{paths[p][*it], paths[p][(*it)-1]}, {R, par2}});
				used_p[p].erase(it);
				found = true;
				break;
			}
		}
	}
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout << fixed << setprecision(10);
	int N;
	cin >> N;
	vector< vector<int> > G(N), G2(N);
	for(int i = 0; i < N-1; i++) {
		int u, v;
		cin >> u >> v;
		G[--u].push_back(--v);
		G[v].push_back(u);
	}
	for(int i = 0; i < N-1; i++) {
		int u, v;
		cin >> u >> v;
		G2[--u].push_back(--v);
		G2[v].push_back(u);
	}
	vector<int> sz(N, 1);
	par.resize(N, -1);
	in_path.resize(N);
	path_pos.resize(N);
	dep.resize(N, 0);
	par[0] = 0;
	DFS(0, G, sz);
	for(int i = 0; i < P; i++) {
		reverse(begin(paths[i]), end(paths[i]));
		for(int j = 0; j < (int)paths[i].size(); j++) path_pos[paths[i][j]] = j;
	}
	par_up[0] = par;
	for(int k = 1; k < 20; k++) {
		par_up[k].resize(N);
		for(int i = 0; i < N; i++) par_up[k][i] = par_up[k-1][par_up[k-1][i]];
	}
	used_pt.resize(P, 0);
	used_pt[in_path[0]] = 1;
	used_p.resize(P);
	for(int i = 0; i < P; i++)
		for(int j = 0; j < (int)paths[i].size()-1; j++) used_p[i].insert(j+1);
	solve(0, 0, G2);
	cout << ans.size() << "\n";
	for(int i = 0; i < (int)ans.size(); i++)
		cout << ans[i].ff.ff+1 << " " << ans[i].ff.ss+1 << " " << ans[i].ss.ff+1 << " " << ans[i].ss.ss+1 << "\n";
	return 0;
}

// look at my code
// my code is amazing