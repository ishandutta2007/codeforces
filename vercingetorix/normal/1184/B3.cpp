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
static struct FastInput {
    static constexpr int BUF_SIZE = 1 << 20;
    char buf[BUF_SIZE];
    size_t chars_read = 0;
    size_t buf_pos = 0;
    FILE *in = stdin;
    char cur = 0;
    
    inline char get_char() {
        if (buf_pos >= chars_read) {
            chars_read = fread(buf, 1, BUF_SIZE, in);
            buf_pos = 0;
            buf[0] = (chars_read == 0 ? -1 : buf[0]);
        }
        return cur = buf[buf_pos++];
    }
    
    inline void tie(int) {}
    
    inline explicit operator bool() {
        return cur != -1;
    }
    
    inline static bool is_blank(char c) {
        return c <= ' ';
    }
    
    inline bool skip_blanks() {
        while (is_blank(cur) && cur != -1) {
            get_char();
        }
        return cur != -1;
    }
    
    inline FastInput& operator>>(char& c) {
        skip_blanks();
        c = cur;
        return *this;
    }
    
    inline FastInput& operator>>(string& s) {
        if (skip_blanks()) {
            s.clear();
            do {
                s += cur;
            } while (!is_blank(get_char()));
        }
        return *this;
    }
    
    template <typename T>
    inline FastInput& read_integer(T& n) {
        // unsafe, doesn't check that characters are actually digits
        n = 0;
        if (skip_blanks()) {
            int sign = +1;
            if (cur == '-') {
                sign = -1;
                get_char();
            }
            do {
                n += n + (n << 3) + cur - '0';
            } while (!is_blank(get_char()));
            n *= sign;
        }
        return *this;
    }
    
    template <typename T>
    inline typename enable_if<is_integral<T>::value, FastInput&>::type operator>>(T& n) {
        return read_integer(n);
    }
    
#if !defined(_WIN32) || defined(_WIN64)
    inline FastInput& operator>>(__int128& n) {
        return read_integer(n);
    }
#endif
    
    template <typename T>
    inline typename enable_if<is_floating_point<T>::value, FastInput&>::type operator>>(T& n) {
        // not sure if really fast, for compatibility only
        n = 0;
        if (skip_blanks()) {
            string s;
            (*this) >> s;
            sscanf(s.c_str(), "%lf", &n);
        }
        return *this;
    }
} fast_input;

#define cin fast_input

static struct FastOutput {
    static constexpr int BUF_SIZE = 1 << 20;
    char buf[BUF_SIZE];
    size_t buf_pos = 0;
    static constexpr int TMP_SIZE = 1 << 20;
    char tmp[TMP_SIZE];
    FILE *out = stdout;
    
    inline void put_char(char c) {
        buf[buf_pos++] = c;
        if (buf_pos == BUF_SIZE) {
            fwrite(buf, 1, buf_pos, out);
            buf_pos = 0;
        }
    }
    
    ~FastOutput() {
        fwrite(buf, 1, buf_pos, out);
    }
    
    inline FastOutput& operator<<(char c) {
        put_char(c);
        return *this;
    }
    
    inline FastOutput& operator<<(const char* s) {
        while (*s) {
            put_char(*s++);
        }
        return *this;
    }
    
    inline FastOutput& operator<<(const string& s) {
        for (int i = 0; i < (int) s.size(); i++) {
            put_char(s[i]);
        }
        return *this;
    }
    
    template <typename T>
    inline char* integer_to_string(T n) {
        // beware of TMP_SIZE
        char* p = tmp + TMP_SIZE - 1;
        if (n == 0) {
            *--p = '0';
        } else {
            bool is_negative = false;
            if (n < 0) {
                is_negative = true;
                n = -n;
            }
            while (n > 0) {
                *--p = (char) ('0' + n % 10);
                n /= 10;
            }
            if (is_negative) {
                *--p = '-';
            }
        }
        return p;
    }
    
    template <typename T>
    inline typename enable_if<is_integral<T>::value, char*>::type stringify(T n) {
        return integer_to_string(n);
    }
    
#if !defined(_WIN32) || defined(_WIN64)
    inline char* stringify(__int128 n) {
        return integer_to_string(n);
    }
#endif
    
    template <typename T>
    inline typename enable_if<is_floating_point<T>::value, char*>::type stringify(T n) {
        sprintf(tmp, "%.17f", n);
        return tmp;
    }
    
    template <typename T>
    inline FastOutput& operator<<(const T& n) {
        auto p = stringify(n);
        for (; *p != 0; p++) {
            put_char(*p);
        }
        return *this;
    }
} fast_output;

#define cout fast_output

int d[100][100];
const int A = 100500;
vpi basegold[A];
int parent[A];
int rk[A];
void make_set (int v) {
    parent[v] = v;
    rk[v] = 0;
}

int find_set (int v) {
    if (v == parent[v])
        return v;
    return parent[v] = find_set (parent[v]);
}

void union_sets (int a, int b) {
    a = find_set (a);
    b = find_set (b);
    if (a != b) {
        if (rk[a] < rk[b])
            swap (a, b);
        parent[b] = a;
        if (rk[a] == rk[b])
            ++rk[a];
    }
}

int loc[A];
const ll INF = 1e14;
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
    vector<ll> dist;
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
    
    void bfs_check(queue<int> &q, int node, ll new_dist) {
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
    cin>>n>>m;
    forn(i,0,n) forn(j,0,n) d[i][j] = n;
    forn(i,0,n) d[i][i] = 0;
    forn(i,0,m) {
        int u,v;
        cin>>u>>v;
        --u; --v;
        if(u == v) continue;
        d[u][v] = 1; d[v][u] = 1;
    }
    for (int k=0; k<n; ++k)
        for (int i=0; i<n; ++i)
            for (int j=0; j<n; ++j)
                d[i][j] = min (d[i][j], d[i][k] + d[k][j]);
    forn(i,0,n) forn(j,0,n) if(d[i][j] == n) d[i][j] = 2e9;
    int sn,bn,k;
    cin>>sn>>bn>>k;
    vi sx(sn), a(sn), f(sn), sp(sn);
    forn(i,0,sn) cin>>sx[i]>>a[i]>>f[i]>>sp[i];
    forn(i,0,sn) sx[i]--;
    vi bx(bn), def(bn), gold(bn);
    forn(i,0,bn) cin>>bx[i]>>def[i]>>gold[i];
    forn(i,0,bn) bx[i]--;
    forn(i,0,bn) {
        basegold[bx[i]].pb(mp(def[i], gold[i]));
    }
    forn(i,0,n) {
        srt(basegold[i]);
        forn(j,1,basegold[i].size()) basegold[i][j].second = max(basegold[i][j-1].second, basegold[i][j].second);
    }
    vll prof(sn,-INF);
    forn(i,0,sn) {
        forn(to,0,n) if(d[sx[i]][to] <= f[i]) {
            auto bi = lower_bound(all(basegold[to]), mp(a[i]+1,0)) - basegold[to].begin();
            if(bi > 0) prof[i] = max(prof[i], (ll)basegold[to][bi-1].second);
        }
        prof[i] -= sp[i];
//        cout<<prof[i] << '\n';
    }
    vi s1(k), s2(k);
    forn(i,0,sn) make_set(i);
    vvi gs(sn);
    forn(i,0,k) {
        cin>>s1[i]>>s2[i];
        s1[i]--; s2[i]--;
        if(s1[i] == s2[i]) continue;
        union_sets(s1[i], s2[i]);
        gs[s1[i]].pb(s2[i]);
    }
    vvi w(sn);
    forn(i,0,sn) w[find_set(i)].pb(i);
    ll ans = 0;
    forn(it,0,sn) {
        if(w[it].size() == 1) {
            ans += max(0ll, prof[w[it][0]]);
        }
        else if(w[it].size() > 0) {
            int l = w[it].size();
            forn(j,0,l) loc[w[it][j]] = j;
            
            dinic<ll> din(l+2);
            int dins = l;
            int dint = l+1;
            ll cur = 0;
            forn(i,0,l) {
                for(auto to : gs[w[it][i]]) {
                    int j = loc[to];
                    din.add_directional_edge(i, j, INF);
//                    cout<<"DI " <<i <<' '<<j<<' '<<INF<<'\n';
                }
                if(prof[w[it][i]] > 0) {
                    cur += prof[w[it][i]];
                    din.add_directional_edge(dins, i, prof[w[it][i]]);
//                    cout<<"DI "<<dins<<' '<<i<<' '<<prof[w[it][i]]<<'\n';
                }
                else if(prof[w[it][i]] < 0) {
                    din.add_directional_edge(i, dint, -prof[w[it][i]]);
//                    cout<<"DI "<<i<<' '<<dint<<' '<<-prof[w[it][i]]<<'\n';
                }
            }
            ans += cur - din.flow(dins, dint);
        }
    }
    cout<<ans;
}