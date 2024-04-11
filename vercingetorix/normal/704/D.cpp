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
const ll INF = 1e15;
template<typename flow_t>
struct dinic {
    struct edge {
        int node, rev, ind;
        
        flow_t capacity;
        flow_t dcapacity;
        
        edge() {}
        
        edge(int _node, int _rev, flow_t _capacity, int ind) : node(_node), rev(_rev), capacity(_capacity), dcapacity(_capacity), ind(ind) {}
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
    
    void _add_edge(int u, int v, flow_t capacity1, flow_t capacity2, int ind) {
        //        assert(0 <= u && u < V && 0 <= v && v < V);
        //        assert(capacity1 >= 0 && capacity2 >= 0);
        edge uv_edge(v, int(adj[v].size()) + (u == v ? 1 : 0), capacity1, ind);
        edge vu_edge(u, int(adj[u].size()), capacity2, -1);
        adj[u].push_back(uv_edge);
        adj[v].push_back(vu_edge);
    }
    
    void add_directional_edge(int u, int v, flow_t capacity, int ind) {
        if(capacity == 0) return;
        _add_edge(u, v, capacity, 0, ind);
    }
    
//    void add_bidirectional_edge(int u, int v, flow_t capacity) {
//        _add_edge(u, v, capacity, capacity);
//    }
    
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
        dist.assign(V, 1e9);
        queue<int> q;
        bfs_check(q, source, 0);
        
        while (!q.empty()) {
            int top = q.front(); q.pop();
            
            for (edge &e : adj[top])
                if (e.capacity > 0)
                    bfs_check(q, e.node, dist[top] + 1);
        }
        
        return dist[sink] < 1e9;
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
        forn(v,0,V) {
            for(auto & ed : adj[v]) ed.capacity = ed.dcapacity;
        }
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
    int r,b;
    cin>>r>>b;
    vi x(n), y(n);
    forn(i,0,n) cin>>x[i]>>y[i];
    map<int, int> rx,ry,cx,cy;
    forn(i,0,n) {
        cx[x[i]]++;
        cy[y[i]]++;
    }
    forn(i,0,m) {
        int tp,l,d;
        cin>>tp>>l>>d;
        if(tp == 1) {
            if(rx.count(l)) rx[l] = min(rx[l], d);
            else rx[l] = d;
        }
        else {
            if(ry.count(l)) ry[l] = min(ry[l], d);
            else ry[l] = d;
        }
    }
    map<int, int> tox, toy;
    int pt = 0;
    for(auto v : rx) tox[v.first] = pt++;
    for(auto v : ry) toy[v.first] = pt++;
    dinic<ll> din(pt+4);
    int s = pt;
    int t = pt+1;
    int s2 = pt+2;
    int t2 = pt+3;
    ll need = 0;
    for(auto v : rx) {
        int k = cx[v.first];
        vi can;
        forn(i,0,k+1) if(abs(2*i-k) <= v.second) can.pb(i);
        if(can.empty()) {
            cout<<-1;
            exit(0);
        }
        din.add_directional_edge(s, t2, can[0],-1);
        din.add_directional_edge(s2, tox[v.first], can[0],-1);
        din.add_directional_edge(s, tox[v.first], can.back()-can[0],-1);
        need += can[0];
    }
    for(auto v : ry) {
        int k = cy[v.first];
        vi can;
        forn(i,0,k+1) if(abs(2*i-k) <= v.second) can.pb(i);
        if(can.empty()) {
            cout<<-1;
            exit(0);
        }
        din.add_directional_edge(s2, t, can[0],-1);
        din.add_directional_edge(toy[v.first], t2, can[0],-1);
        din.add_directional_edge(toy[v.first], t, can.back()-can[0],-1);
        need += can[0];
    }
    forn(i,0,n) {
        int u = s;
        int v = t;
        if(tox.count(x[i])) u = tox[x[i]];
        if(toy.count(y[i])) v = toy[y[i]];
        if(u!=s || v!=t) {
            din.add_directional_edge(u, v, 1, i);
        }
    }
//    din.add_directional_edge(t, s, INF,-1);
    auto go = [&](ll sat) {
        din.add_directional_edge(t, s, sat, -1);
        ll ret = din.flow(s2, t2);
        if(sat!=0) {
            din.adj[t].pop_back();
            din.adj[s].pop_back();
        }
        return ret;
    };
    if(go(n) < need) {
        cout<<-1;
        exit(0);
    }
    int pl = -1;
    int pr = n;
    while(pr-pl > 1) {
        int pm = (pl+pr)/2;
        if(go(pm) >= need) pr = pm;
        else pl = pm;
    }
    go(pr);
//    go(5);
//    go(3);
//    go(1);
//    go(2);
//    go(3);
//    go(2);
//    cout<<go(rr)<<'\n';
    map<pi, int> eind;
    forn(i,0,n) {
        int u = s;
        int v = t;
        if(tox.count(x[i])) u = tox[x[i]];
        if(toy.count(y[i])) v = toy[y[i]];
        eind[mp(u,v)] = i;
    }
    string ans(n,'r');
    forn(v,0,din.V) for(auto ed : din.adj[v]) {
        if(ed.ind != -1 && ed.capacity == 0) {
            ans[ed.ind] = 'b';
        }
    }
    if(b<r) {
        forn(i,0,n) {
            if(ans[i] == 'r') ans[i] = 'b';
            else ans[i] = 'r';
        }
    }
    ll sum = 0;
    for(auto x : ans) if(x=='r') sum+=r;
    else sum+=b;
    cout<<sum<<'\n';
    cout<<ans;
    
}