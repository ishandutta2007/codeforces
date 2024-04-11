#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define ff first
#define ss second
using namespace std;

int K;
struct tree_node_info {
	vector<int> adj;
	int par = -1, sz = 1, top, dep, dist, dist_down_rest, id_down_rest, up;
	char bl = 0, rest = 0;
};
vector<tree_node_info> G;
vector< vector<int> > V_dep;
vector<char> ans;
int max_dep;

void DFS(int R, auto & comp) {
	comp.push_back(R);
	for(auto s : G[R].adj) if(!G[s].bl && G[s].par == -1) {
		G[s].par = R;
		G[s].dep = G[R].dep+1;
		if(G[R].par != R) G[s].top = G[R].top;
		DFS(s, comp);
		G[R].sz += G[s].sz;
		G[R].dist_down_rest = min(G[R].dist_down_rest, G[s].dist_down_rest+1);
		if(G[s].dist_down_rest+1 == G[R].dist_down_rest) G[R].id_down_rest = G[s].id_down_rest;
	}
}

struct itree {
	vector< vector< pair<int, int> > > items;
	vector<int> T;
	int b;

	itree() = default;
	itree(int N) {
		b = 1;
		while(b < N) b *= 2;
		items.resize(2*b, {{1000000, 0}});
		T.resize(2*b, 1000000);
	}

	void insert(int key, int val, int id) {
		if(val < items[key].back().ff) {
			put(key, val, 1, 0, b);
			items[key].push_back({val, id});
		}
		else items[key].push_back(items[key].back());
	}

	void erase(int key) {
		if(items[key][items[key].size()-1] != items[key][items[key].size()-2]) {
			items[key].pop_back();
			put(key, items[key].back().ff, 1, 0, b);
		}
		else items[key].pop_back();
	}

	pair<int, int> get(int key) {
		// [<= key], min val
		int best_val = 1000000, best_cur = 1;
		get_internal(0, key+1, best_val, best_cur, 1, 0, b);
		if(best_val == 1000000) return {best_val, 0};
		while(best_cur < b) {
			if(T[2*best_cur] == best_val) best_cur *= 2;
			else best_cur = 2*best_cur+1;
		}
		return items[best_cur-b].back();
	}

	void get_internal(int key_l, int key_r, int & best_val, int & best_cur, int cur, int l, int r) {
		key_l = max(key_l, l);
		key_r = min(key_r, r);
		if(key_l >= r || l >= key_r || best_val <= T[cur]) return;
		if(key_l == l && key_r == r) {
			best_val = T[cur];
			best_cur = cur;
			return;
		}
		get_internal(key_l, key_r, best_val, best_cur, 2*cur, l, (l+r)/2);
		get_internal(key_l, key_r, best_val, best_cur, 2*cur+1, (l+r)/2, r);
	}

	void put(int key, int val, int cur, int l, int r) {
		if(l == key && r == key+1) {
			T[cur] = val;
			return;
		}
		if((l+r)/2 > key) put(key, val, 2*cur, l, (l+r)/2);
		else put(key, val, 2*cur+1, (l+r)/2, r);
		T[cur] = min(T[2*cur], T[2*cur+1]);
	}
} I;

void DFS_calc_up(int R) {
	auto [d, id] = I.get(K+max_dep-G[R].dep);
	if(d <= K+max_dep && G[id].dep < G[R].dep) G[R].up = id;
	else G[R].up = -1;
	if(G[R].dist_down_rest <= K)
		I.insert(G[R].dist_down_rest+max_dep-G[R].dep, G[R].dep+G[R].dist_down_rest, G[R].id_down_rest);
	for(auto s : G[R].adj) if(!G[s].bl && G[s].par == R) DFS_calc_up(s);
	if(G[R].dist_down_rest <= K)
		I.erase(G[R].dist_down_rest+max_dep-G[R].dep);
}

struct query {
	int u, v, id;
};

void solve(int R, auto & qv) {
	static vector<int> comp;
	comp.clear();
	G[R].par = R;
	DFS(R, comp);

	int C = R;
	for(auto c : comp) if(2*(G[R].sz-G[c].sz) <= G[R].sz) {
		bool ok = true;
		for(auto s : G[c].adj) if(!G[s].bl && G[s].sz < G[c].sz && G[s].sz*2 > G[R].sz) {
			ok = false;
			break;
		}
		if(!ok) continue;
		C = c;
		break;
	}

	for(auto c : comp) G[c].par = -1, G[c].sz = 1, G[c].dist_down_rest = G[c].dist = K+1;
	for(auto c : comp) if(G[c].rest) G[c].dist_down_rest = 0, G[c].id_down_rest = c;
	comp.clear();
	G[C].par = C;
	G[C].top = -1;
	int E = 0;
	for(int i = 0; i < (int)G[C].adj.size(); i++) if(!G[G[C].adj[i]].bl) G[G[C].adj[i]].top = E++;
	G[C].dep = 0;
	DFS(C, comp);

	max_dep = 0;
	for(auto c : comp) {
		V_dep[G[c].dep].clear();
		max_dep = max(max_dep, G[c].dep);
	}
	DFS_calc_up(C);
	G[C].dist = 0;
	for(auto c : comp) V_dep[G[c].dep].push_back(c);
	for(int i = 0; i <= max_dep; i++) for(auto v : V_dep[i]) {
		G[v].dist = i;
		if(G[v].up != -1) G[v].dist = min(i, G[G[v].up].dist);
	}

	vector< vector<query> > qs(E);
	for(auto q : qv) {
		if(G[q.u].dist+G[q.v].dist <= K) ans[q.id] = 1;
		if(!ans[q.id] && G[q.u].top == G[q.v].top) qs[G[q.u].top].push_back(q);
	}

	for(auto c : comp) G[c].par = -1, G[c].sz = 1, G[c].dist_down_rest = G[c].dist = K+1;
	G[C].bl = 1;
	for(int i = 0; i < (int)G[C].adj.size(); i++)
		if(!G[G[C].adj[i]].bl) solve(G[C].adj[i], qs[G[G[C].adj[i]].top]);
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	int N, R;
	cin >> N >> K >> R;
	G.resize(N);
	for(int i = 0; i < N-1; i++) {
		int u, v;
		cin >> u >> v;
		G[--u].adj.push_back(--v);
		G[v].adj.push_back(u);
	}
	for(int i = 0; i < R; i++) {
		int a;
		cin >> a;
		G[--a].rest = 1;
	}
	int Q;
	cin >> Q;
	vector<query> qv(Q);
	for(int i = 0; i < Q; i++) {
		int u, v;
		cin >> u >> v;
		qv[i] = {--u, --v, i};
	}
	ans.resize(Q, 0);
	for(int i = 0; i < N; i++) G[i].dist = K+1;
	I = itree(N+K);
	V_dep.resize(N);
	solve(0, qv);
	for(int i = 0; i < Q; i++) cout << (ans[i] ? "YES\n" : "NO\n");
}