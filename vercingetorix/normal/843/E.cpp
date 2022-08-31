#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <ctype.h>
#include <queue>
#include <cstring>
#include <set>
#include <bitset>
#include <cassert>
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
const int INF = 1e9;
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
        assert(0 <= u && u < V && 0 <= v && v < V);
        assert(capacity1 >= 0 && capacity2 >= 0);
        edge uv_edge(v, int(adj[v].size()) + (u == v ? 1 : 0), capacity1);
        edge vu_edge(u, int(adj[u].size()), capacity2);
        adj[u].push_back(uv_edge);
        adj[v].push_back(vu_edge);
    }
    
    void add_directional_edge(int u, int v, flow_t capacity) {
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
        assert(V >= 0);
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

vvpi g1,gr;
vi vis;

vi fw,cap;

bool dfsto(const vvpi & g, int v, int to) {
    vis[v] = 1;
    if(v==to) return true;
    for(auto u : g[v]) {
        if(vis[u.first]) continue;
        if(dfsto(g, u.first, to)) {
            fw[u.second]++;
            cap[u.second]++;
            return true;
        }
    }
    return false;
}

int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int n,m,s,t;
    scanf("%d %d %d %d", &n, &m, &s, &t);
    s--; t--;
    dinic<int> din(n);
    g1.resize(n);
    gr.resize(n);
    vpi e;
    vi f;
    fw = vi(m, 0);
    cap = vi(m, 0);
    forn(i,0,m) {
        int u,v,fl;
        scanf("%d %d %d", &u, &v, &fl);
        u--; v--;
        if(fl) {
            din.add_directional_edge(u, v, 1);
            din.add_directional_edge(v, u, 2000);
        }
        else din.add_directional_edge(u, v, 2000);
        e.pb(mp(u,v));
        f.pb(fl);
        if(fl) {
            g1[u].pb(mp(v,i));
            gr[v].pb(mp(u,i));
        }
    }
    printf("%d\n", din.flow(s, t));
    auto mc = din.min_cut(s);
    set<pi> full;
    for(auto x : mc) full.insert(x.second);
    forn(i,0,m) {
        if(f[i] == 1) {
            vis = vi(n,0);
            dfsto(g1, e[i].second, t);
            vis = vi(n,0);
            dfsto(gr, e[i].first, s);
            fw[i]++;
            cap[i]++;
            if(full.find(e[i]) == full.end()) cap[i]++;
        }
        else {
            cap[i]++;
        }
    }
    forn(i,0,m) printf("%d %d\n", fw[i], cap[i]);
    
}