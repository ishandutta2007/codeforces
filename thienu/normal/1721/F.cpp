#include <bits/stdc++.h>

using namespace std;

#define u_map unordered_map
#define u_set unordered_set
#define u_multiset unordered_multiset

using ll = long long;
using vvi = vector<vector<int>>;
using vi = vector<int>;
using vvll = vector<vector<long long>>;
using vll = vector<long long>;
using vd = vector<double>;
using vvd = vector<vector<double>>;
using pii = pair<int, int>;
using vpii = vector<pair<int, int>>;

template<typename C> struct rge{C l, r;};
template<typename C> rge<C> range(C i, C j) { return rge<C>{i, j}; }
template<typename C> ostream& operator<<(ostream &os, rge<C> &r) { os << '{'; for(auto it = r.l; it != r.r; it++) os << "," + (it == r.l) << *it; os << '}'; return os; }
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '{' << p.first << "," << p.second << '}'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ","; return os << '}'; }
void dbg_out() { cerr << ']' << endl; }
template<typename A> void dbg_out(A H) { cerr << H; dbg_out(); }
template<typename A, typename B, typename... C> void dbg_out(A H, B G, C... T) { cerr << H << ","; dbg_out(G, T...); }
#ifdef DEBUG
#define debug(...) cerr << "[" << #__VA_ARGS__ << "] = [", dbg_out(__VA_ARGS__)
#else
#define debug(...)
#endif

#define sz(x) ((int) x.size())

// kactl
struct Dinic {
	struct Edge {
		int to, rev;
        int id;
		ll c, oc;
		ll flow() { return max(oc - c, 0LL); } // if you need flows
	};
	vi lvl, ptr, q;
	vector<vector<Edge>> adj;
	Dinic(int n) : lvl(n), ptr(n), q(n), adj(n) {}
	void addEdge(int a, int b, int id, ll c, ll rcap = 0) {
		adj[a].push_back({b, sz(adj[b]), id, c, c});
		adj[b].push_back({a, sz(adj[a]) - 1, id, rcap, rcap});
	}
	ll dfs(int v, int t, ll f) {
		if (v == t || !f) return f;
		for (int& i = ptr[v]; i < sz(adj[v]); i++) {
			Edge& e = adj[v][i];
			if (lvl[e.to] == lvl[v] + 1)
				if (ll p = dfs(e.to, t, min(f, e.c))) {
					e.c -= p, adj[e.to][e.rev].c += p;
					return p;
				}
		}
		return 0;
	}
	ll calc(int s, int t) {
		ll flow = 0; q[0] = s;
		for(int L = 0; L < 31; L++) do { // 'int L=30' maybe faster for random data
			lvl = ptr = vi(sz(q));
			int qi = 0, qe = lvl[s] = 1;
			while (qi < qe && !lvl[t]) {
				int v = q[qi++];
				for (Edge e : adj[v])
					if (!lvl[e.to] && e.c >> (30 - L))
						q[qe++] = e.to, lvl[e.to] = lvl[v] + 1;
			}
			while (ll p = dfs(s, t, LLONG_MAX)) flow += p;
		} while (lvl[t]);
		return flow;
	}
	bool leftOfMinCut(int a) { return lvl[a] != 0; }
};

int edge_idx(int x, int n1){
    if(x >= n1) return n1 - x - 1;
    return x + 1; 
}

void solve(){
    int n1, n2, m, q;
    cin >> n1 >> n2 >> m >> q;
    
    int s = n1 + n2;
    int t = s + 1;
    
    Dinic dinic(n1 + n2 + 2);
    for(int i = 0; i < n1; i++) dinic.addEdge(s, i, -1, 1);
    for(int i = 0; i < n2; i++) dinic.addEdge(i + n1, t, -1, 1);
    for(int i = 0; i < m; i++){
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        dinic.addEdge(x, y + n1, i+1, 1);
    }

    int flow = dinic.calc(s, t);
    
    // find some matching
    // pairs: {edge, vertex}
    vector<pair<int, int>> edges;
    ll edge_sum = 0;
    for(int u = 0; u < n1; u++){
        for(Dinic::Edge e : dinic.adj[u]){
            if(e.flow() > 0){
                edge_sum += e.id;
                int rep;
                if(dinic.leftOfMinCut(u)){
                    rep = e.to;
                }else{
                    rep = u;
                }
                edges.push_back({e.id, rep});
            }
        }
    }
    debug(edges, edge_sum);

    assert(edges.size() == flow);

    int removed = 0;
    while(q--){
        int type;
        cin >> type;
        if(type == 1){
            edge_sum -= edges[removed].first;
            cout << 1 << endl << edge_idx(edges[removed].second, n1) << endl << edge_sum << endl;
            removed++;
        }else{
            cout << flow - removed << endl;
            for(int i = removed; i < flow; i++){
                cout << edges[i].first << ' ';
            }
            cout << endl;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}