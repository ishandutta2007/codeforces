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

void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}

template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifdef DEBUG
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif



#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()

const ll INF = (ll) 4e18 + 123;

struct Node{
    int x, y, t;
    ll w;
    Node(int _x, int _y, ll _w) : x(_x), y(_y), w(_w) {
        t = x & 1 ? (y & 1 ? 3 : 0) : (y & 1 ? 2 : 1);
    }
};

// kactl
template<class T> T edmondsKarp(vector<unordered_map<int, T>>& graph, int source, int sink) {
	assert(source != sink);
	T flow = 0;
	vi par(sz(graph)), q = par;

	for (;;) {
		fill(all(par), -1);
		par[source] = 0;
		int ptr = 1;
		q[0] = source;

		rep(i,0,ptr) {
			int x = q[i];
			for (auto e : graph[x]) {
				if (par[e.first] == -1 && e.second > 0) {
					par[e.first] = x;
					q[ptr++] = e.first;
					if (e.first == sink) goto out;
				}
			}
		}
		return flow;
out:
		T inc = numeric_limits<T>::max();
		for (int y = sink; y != source; y = par[y])
			inc = min(inc, graph[par[y]][y]);

		flow += inc;
		for (int y = sink; y != source; y = par[y]) {
			int p = par[y];
			if ((graph[p][y] -= inc) <= 0) graph[p].erase(y);
			graph[y][p] += inc;
		}
	}
}

void solve(){
    int n;
    cin >> n;
    vector<Node> nodes;
    ll tot = 0;
    for(int i = 0; i < n; i++){
        int x, y;
        ll w;
        cin >> x >> y >> w;
        nodes.push_back(Node(x, y, w)); 
        tot += w;
        debug(nodes[i].t);
    }
    vector<u_map<int, ll>> adj(2 * n + 2);
    int s = 2 * n;
    int t = 2 * n + 1;
    for(int i = 0; i < n; i++){
        adj[i * 2][i * 2 + 1] = nodes[i].w;
        if(nodes[i].t == 0){
            adj[s][i * 2] = INF;
        }
        else if(nodes[i].t == 3){
            adj[i * 2 + 1][t] = INF;
        }
        for(int j = 0; j < n; j++){
            if(abs(nodes[i].x-nodes[j].x) <= 1 && abs(nodes[i].y-nodes[j].y) <= 1 && nodes[i].t + 1 == nodes[j].t){
                debug(i, j);
                adj[i * 2 + 1][j * 2] = INF;
            }
        }
    }
    debug(adj);
    ll ans = edmondsKarp(adj, s, t);
    cout << tot - ans << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}