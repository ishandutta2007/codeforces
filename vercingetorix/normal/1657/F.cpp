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
struct SCC {
    int V = 0;
    vector<vector<int>> adj;
    vector<int> tour_index, low_link;
    int tour;
    
    vector<int> stack;
    vector<bool> in_stack;
    
    vector<vector<int>> components;
    vector<int> which_component;
    
    SCC(int v = 0) {
        init(v);
    }
    
    SCC(const vector<vector<int>> &_adj) {
        init(_adj);
    }
    
    void init(int v) {
        V = v;
        adj.assign(V, {});
    }
    
    void init(const vector<vector<int>> &_adj) {
        adj = _adj;
        V = int(adj.size());
    }
    
    void add_edge(int a, int b) {
        adj[a].push_back(b);
    }
    
    // Tarjan's algorithm.
    void dfs(int node) {
        tour_index[node] = tour++;
        low_link[node] = tour_index[node];
        stack.push_back(node);
        in_stack[node] = true;
        
        for (int neighbor : adj[node])
            if (tour_index[neighbor] < 0) {
                // neighbor is part of our subtree.
                dfs(neighbor);
                low_link[node] = min(low_link[node], low_link[neighbor]);
            } else if (in_stack[neighbor]) {
                // neighbor is a candidate for low_link.
                low_link[node] = min(low_link[node], tour_index[neighbor]);
            }
        
        if (low_link[node] == tour_index[node]) {
            // node is the highest node in an SCC, which includes everything on the stack up to it.
            components.emplace_back();
            vector<int> &component = components.back();
            int x;
            
            do {
//                assert(!stack.empty());
                x = stack.back();
                stack.pop_back();
                in_stack[x] = false;
                which_component[x] = int(components.size()) - 1;
                component.push_back(x);
            } while (x != node);
        }
    }
    
    void build() {
        tour_index.assign(V, -1);
        low_link.resize(V);
        which_component.assign(V, -1);
        
        stack.clear();
        stack.reserve(V);
        in_stack.assign(V, false);
        tour = 0;
        
        // Note that Tarjan's algorithm provides the SCCs in reverse topological order.
        components = {};
        
        for (int i = 0; i < V; i++)
            if (tour_index[i] < 0)
                dfs(i);
    }
};
struct two_sat {
    int n = 0;
    vector<vector<int>> adj;
    vector<bool> assignment;
    SCC scc;
    
    int inv(int var) {
        return var ^ 1;
    }
    
    int new_var() {
        adj.emplace_back();
        adj.emplace_back();
        return 2 * n++;
    }
    
    void implies(int a, int b) {
        adj[a].push_back(b);
        adj[inv(b)].push_back(inv(a));
    }
    
    void either(int a, int b) {
        adj[inv(a)].push_back(b);
        adj[inv(b)].push_back(a);
    }
    
    void set_value(int a) {
        adj[inv(a)].push_back(a);
    }
    
    void equal(int a, int b) {
        implies(a, b);
        implies(inv(a), inv(b));
    }
    
    void unequal(int a, int b) {
        implies(a, inv(b));
        implies(inv(a), b);
    }
    
    // Warning: this only creates an implication in the negative direction. It is still possible for
    // a = b = true with and_var = false. In particular, it does not work to call set_value on inv(and_var).
    int create_and(int a, int b) {
        if (a < 0 || b < 0) return max(a, b);
        int result = new_var();
        implies(result, a);
        implies(result, b);
        return result;
    }
    
    // Warning: this only creates an implication in the positive direction. It is still possible for
    // a = b = false with or_var = true. In particular, it does not work to call set_value on or_var.
    int create_or(int a, int b) {
        if (a < 0 || b < 0) return max(a, b);
        int result = new_var();
        implies(a, result);
        implies(b, result);
        return result;
    }
    
    int create_at_most_one(int a, int b) {
        if (a < 0 || b < 0) return max(a, b);
        either(inv(a), inv(b));
        return create_or(a, b);
    }
    
    template<typename T_iterable>
    int create_at_most_one(const T_iterable &vars) {
        int aux = -1;
        
        for (int var : vars)
            aux = create_at_most_one(aux, var);
        
        return aux;
    }
    
    bool solve() {
        scc.init(adj);
        scc.build();
        
        for (int i = 0; i < n; i++)
            if (scc.which_component[2 * i] == scc.which_component[2 * i + 1])
                return false;
        
        assignment.resize(2 * n);
        vector<bool> done(n, false);
        
        // Tarjan's algorithm provides the SCCs in reverse topological order.
        for (auto &component : scc.components)
            for (int x : component) {
                assignment[x] = !done[x / 2];
                done[x / 2] = true;
            }
        
//        for (int i = 0; i < n; i++)
//            assert(assignment[2 * i] ^ assignment[2 * i + 1]);
        
        return true;
    }
};

int n;
const int A = 400500;
vi g[A];
int lev[A];
int par[A];
int curlev = 0;
void dfs(int v, int p) {
    lev[v] = curlev;
    for(auto u : g[v]) {
        if(u==p) continue;
        curlev++;
        par[u] = v;
        dfs(u, v);
        curlev--;
    }
}

vi getp(int a, int b) {
    vi l;
    vi r;
    while(lev[a] > lev[b]) {
        l.pb(a);
        a = par[a];
    }
    while(lev[a] < lev[b]) {
        r.pb(b);
        b = par[b];
    }
    while(1) {
        if(a==b) {
            l.pb(a);
            break;
        }
        l.pb(a);
        r.pb(b);
        a = par[a];
        b = par[b];
    }
    while(!r.empty()) {
        l.pb(r.back());
        r.pop_back();
    }
    return l;
}
string ans;
vector<pair<char, int>> cand[A];

int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int q;
    cin>>n>>q;
    ans = string(n,'a');
    forn(i,0,n-1) {
        int u,v;
        cin>>u>>v;
        u--; v--;
        g[u].pb(v);
        g[v].pb(u);
    }
    dfs(0,0);
    two_sat ts;
    vi w;
    forn(i,0,q) {
        int cur = ts.new_var();
        w.pb(cur);
        int u,v;
        string s;
        cin>>u>>v>>s;
        u--; v--;
        auto p = getp(u, v);
        forn(i,0,p.size()) {
            cand[p[i]].pb(mp(s[i], cur));
        }
        reverse(all(s));
        cur = ts.inv(cur);
        forn(i,0,p.size()) {
            cand[p[i]].pb(mp(s[i], cur));
        }
    }
    vector<pair<int, char>> fix;
    vi code;
    forn(i,0,n) {
        srt(cand[i]);
        int pt = 0;
        vi dif;
        while(pt < cand[i].size()) {
            int pr = pt+1;
            while(pr < cand[i].size() && cand[i][pt].first == cand[i][pr].first) pr++;
            int cur = ts.new_var();
            fix.pb(mp(i, cand[i][pt].first));
            code.pb(cur);
            dif.pb(cur);
            forn(j,pt,pr) {
//                cout<<cand[i][j].second <<' '<<cur<<'\n';
                ts.implies(cand[i][j].second, cur);
            }
            pt = pr;
        }
        if(!dif.empty()) {
//            cout<<"DIF ";
//            for(auto x : dif) cout<<' '<<x; cout<<'\n';
            ts.create_at_most_one(dif);
        }
    }
    if(ts.solve() == false) {
        cout<<"NO\n";
    }
    else {
        cout<<"YES\n";
        forn(i,0,code.size()) {
            if(ts.assignment[code[i]]) ans[fix[i].first] = fix[i].second;
        }
        cout<<ans;
    }
    
    
    
    
}