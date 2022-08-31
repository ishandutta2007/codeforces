#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <ctype.h>
#include <queue>
#include <cstring>
#include <set>
#include <bitset>
#include <map>
#include <chrono>
#include <random>
#include <unordered_map>
#include <stdio.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef std::vector<int> vi;
typedef std::vector<bool> vb;
typedef std::vector<string> vs;
typedef std::vector<double> vd;
typedef std::vector<long long> vll;
typedef std::vector<std::vector<int> > vvi;
typedef vector<vll> vvll;
typedef std::vector<std::pair<int, int> > vpi;
typedef vector<vpi> vvpi;
typedef std::pair<int, int> pi;
typedef std::pair<ll, ll> pll;
typedef std::vector<pll> vpll;

const long long mod = 1000000007;
ll gcd (ll a, ll b) {return b==0 ? a : gcd(b, a%b);}
const unsigned gen_seed = std::chrono::system_clock::now().time_since_epoch().count();
std::mt19937_64 gen(gen_seed);

#define all(c) (c).begin(),(c).end()
#define srt(c) sort(all(c))
#define srtrev(c) sort(all(c)); reverse(all(c))
#define forn(i, a, b) for(int i = a; i < b; i++)
#define read(x) scanf("%d", &x)
#define readv(x, n) vi x(n); forn(i,0,n) scanf("%d", &x[i])

#define pb push_back
#define mp make_pair
vvpi g,gr;

int n;
vb used;
vector<int> ts;

void dfs (int v) {
    used[v] = true;
    for (size_t i=0; i<g[v].size(); ++i) {
        int to = g[v][i].first;
        if (!used[to])
            dfs (to);
    }
    ts.push_back (v);
}

void topological_sort() {
    used.resize(n);
    for (int i=0; i<n; ++i)
        used[i] = false;
    ts.clear();
    for (int i=0; i<n; ++i)
        if (!used[i])
            dfs (i);
    reverse (ts.begin(), ts.end());
}
const int INF = 2e9;
template<typename flow_t>
struct dinic {
    struct edge {
        int node, rev;
        flow_t capacity;
        
        edge() {}
        
        edge(int _node, int _rev, flow_t _capacity) : node(_node), rev(_rev), capacity(_capacity) {}
    };
    
    int V = -1;
    vector<vector<edge>> adj;
    vector<int> dist;
    vector<int> edge_index;
    bool flow_called;
    
    dinic(int vertices = -1) {
        if (vertices >= 0)
            init(vertices);
    }
    
    void init(int vertices) {
        V = vertices;
        adj.assign(V, {});
        dist.resize(V);
        edge_index.resize(V);
        flow_called = false;
    }
    
    void _add_edge(int u, int v, flow_t capacity1, flow_t capacity2) {
        //        assert(0 <= u && u < V && 0 <= v && v < V);
        //        assert(capacity1 >= 0 && capacity2 >= 0);
        edge uv_edge(v, int(adj[v].size()) + (u == v ? 1 : 0), capacity1);
        edge vu_edge(u, int(adj[u].size()), capacity2);
        adj[u].push_back(uv_edge);
        adj[v].push_back(vu_edge);
    }
    
    void add_directional_edge(int u, int v, flow_t capacity) {
//        cout<<u<<' '<<v<<' '<<capacity<<endl;
        _add_edge(u, v, capacity, 0);
    }
    
    void add_bidirectional_edge(int u, int v, flow_t capacity) {
        _add_edge(u, v, capacity, capacity);
    }
    
    edge &reverse_edge(const edge &e) {
        return adj[e.node][e.rev];
    }
    
    void bfs_check(queue<int> &q, int node, int new_dist) {
        if (new_dist < dist[node]) {
            dist[node] = new_dist;
            q.push(node);
        }
    }
    
    bool bfs(int source, int sink) {
        dist.assign(V, INF);
        queue<int> q;
        bfs_check(q, source, 0);
        
        while (!q.empty()) {
            int top = q.front(); q.pop();
            
            for (edge &e : adj[top])
                if (e.capacity > 0)
                    bfs_check(q, e.node, dist[top] + 1);
        }
        
        return dist[sink] < INF;
    }
    
    flow_t dfs(int node, flow_t path_cap, int sink) {
        if (node == sink)
            return path_cap;
        
        if (dist[node] >= dist[sink])
            return 0;
        
        flow_t total_flow = 0;
        
        // Because we are only performing DFS in increasing order of dist, we don't have to revisit fully searched edges
        // again later.
        while (edge_index[node] < int(adj[node].size())) {
            edge &e = adj[node][edge_index[node]];
            
            if (e.capacity > 0 && dist[node] + 1 == dist[e.node]) {
                flow_t path = dfs(e.node, min(path_cap, e.capacity), sink);
                path_cap -= path;
                e.capacity -= path;
                reverse_edge(e).capacity += path;
                total_flow += path;
            }
            
            // If path_cap is 0, we don't want to increment edge_index[node] as this edge may not be fully searched yet.
            if (path_cap == 0)
                break;
            
            edge_index[node]++;
        }
        
        return total_flow;
    }
    
    flow_t flow(int source, int sink) {
        //        assert(V >= 0);
        flow_t total_flow = 0;
        
        while (bfs(source, sink)) {
            edge_index.assign(V, 0);
            total_flow += dfs(source, numeric_limits<flow_t>::max(), sink);
        }
        
        flow_called = true;
        return total_flow;
    }
    
    vector<bool> reachable;
    
    void reachable_dfs(int node) {
        reachable[node] = true;
        
        for (edge &e : adj[node])
            if (e.capacity > 0 && !reachable[e.node])
                reachable_dfs(e.node);
    }
    
    // Returns a list of {capacity, {from_node, to_node}} representing edges in the min cut.
    // TODO: for bidirectional edges, divide the resulting capacities by two.
    vector<pair<flow_t, pair<int, int>>> min_cut(int source) {
        //        assert(flow_called);
        reachable.assign(V, false);
        reachable_dfs(source);
        vector<pair<flow_t, pair<int, int>>> cut;
        
        for (int node = 0; node < V; node++)
            if (reachable[node])
                for (edge &e : adj[node])
                    if (!reachable[e.node])
                        cut.emplace_back(reverse_edge(e).capacity, make_pair(node, e.node));
        
        return cut;
    }
};

int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int m;
    scanf("%d %d", &n, &m);
    g.resize(n);
    gr.resize(n);
    forn(i,0,m) {
        int u,v,w;
        scanf("%d %d %d", &u, &v, &w);
        u--; v--;
        g[u].pb(mp(v,w));
        gr[v].pb(mp(u,w));
    }
    int mx = 17;
    dinic<int> din(2+n*(mx+2));
    int s = n*(mx+2);
    int t = s+1;
    
    int ans = 0;
    int A = mx+2;
    forn(i,0,n) din.add_directional_edge(s, i*A, INF);
    forn(i,0,n) din.add_directional_edge(i*A+A-1, t, INF);
    vi tos(n,0);
    vi tot(n,0);
    forn(v,0,n) {
        for(auto u2 : g[v]) {
            int u = u2.first;
            tos[v] += u2.second;
            tot[u] += u2.second;
            ans -= A*u2.second;
            forn(add,0,mx+1) din.add_directional_edge(v*A+add, u*A+add+1, INF);
        }
    }
    forn(i,0,n) forn(j,0,mx+2) {
        din.add_directional_edge(i*A+j, t, tot[i]);
        din.add_directional_edge(s, i*A+j, tos[i]);
    }
    din.flow(s, t);
//    cout<<ans + din.flow(s, t);
    auto x = din.min_cut(s);
    vi res(n,mx);
    forn(v,0,n) {
        int cur = v*A+1;
        while(din.reachable[cur]) {
            res[v]--;
            cur++;
        }
        printf("%d ", res[v]);
    }
    
////    vi force(n,0);
////    forn(i,0,n) force[i] = 1<<i;
////    for(auto v : ts) {
////        for(auto u : gr[v]) force[v] |= force[u.first];
////    }
//    forn(i,0,n) cout<<l[i]<<' '<<r[i]<<'\n';
    
    
}