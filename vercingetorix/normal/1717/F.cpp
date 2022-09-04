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
        //        assert(0 <= u && u < V && 0 <= v && v < V);
        //        assert(capacity1 >= 0 && capacity2 >= 0);
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
    int n,m;
    scanf("%d %d", &n, &m);
    readv(s,n);
    readv(a,n);
    vvi g(n);
    vpi e;
    forn(i,0,m) {
        int u,v;
        scanf("%d %d", &u, &v);
        --u; --v;
        g[u].pb(v);
        g[v].pb(u);
        if(v<u) swap(v,u);
        e.pb(mp(u,v));
    }
    forn(i,0,n) if(s[i]==1 && (abs(a[i])%2!=g[i].size()%2 || g[i].size() < abs(a[i]))) {
        cout<<"NO\n";
        exit(0);
    }
    dinic<int> din(n+4);
    int st = n;
    int t= n+1;
    int st2 = n+2;
    int t2 = n+3;
    const int A = 20000;
    int sp = 0, sn = 0;
    forn(i,0,n) {
        if(s[i] == 0) {
            din.add_directional_edge(st, i, A);
            din.add_directional_edge(i,t, A);
        }
        else {
            if(a[i] > 0) {
                din.add_directional_edge(st2, i, a[i]);
                sp+=a[i];
            }
            else if(a[i] < 0) {
                din.add_directional_edge(i, t2, -a[i]);
                sn-=a[i];
            }
        }
    }
    din.add_directional_edge(t, st, A);
    din.add_directional_edge(st, t2, sp);
    din.add_directional_edge(st2, t, sn);
    forn(i,0,m) din.add_bidirectional_edge(e[i].first, e[i].second, 1);
//    cout<<din.flow(st2, t2)<<' '<<sp+sn<<'\n';
    set<pi> done;
    if(din.flow(st2, t2) == sp + sn) {
        printf("YES\n");
        forn(v,0,n) for(auto ed : din.adj[v]) {
            if(ed.node<n && ed.capacity == 0) {
                int u = ed.node;
                printf("%d %d\n", u+1, v+1);
                done.insert(mp(min(u,v), max(u,v)));
            }
        }
//        printf("FRES\n");
        vector<set<int>> g2(n);
        forn(i,0,m) if(done.find(e[i]) == done.end()) {
//            printf("%d %d\n", e[i].first+1, e[i].second+1);
            g2[e[i].first].insert(e[i].second);
            g2[e[i].second].insert(e[i].first);
        }
        forn(i,0,n) {
            while(!g2[i].empty()) {
                st = i;
                int nx = *g2[i].begin();
                printf("%d %d\n", st+1, nx+1);
                g2[i].erase(nx);
                g2[nx].erase(i);
                while(nx != st && s[nx] == 1) {
                    int nx2 = *g2[nx].begin();
                    g2[nx].erase(nx2);
                    g2[nx2].erase(nx);
                    printf("%d %d\n", nx+1,nx2+1);
                    nx = nx2;
                }
                if(nx != st && s[st]==1) {
                    nx = *g2[i].begin();
                    printf("%d %d\n", nx+1, st+1);
                    g2[i].erase(nx);
                    g2[nx].erase(i);
                    while(s[nx] == 1) {
                        int nx2 = *g2[nx].begin();
                        g2[nx].erase(nx2);
                        g2[nx2].erase(nx);
                        printf("%d %d\n", nx2+1,nx+1);
                        nx = nx2;
                    }
                }
            }
        }
        
    }
    else cout<<"NO\n";
    
}