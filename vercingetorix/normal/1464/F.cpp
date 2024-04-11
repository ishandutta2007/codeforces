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
#include <array>
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

const int A =  200500;
vi g[A];
int par[A];
int lev[A];
int a[A];
int b[A];
int tp[A];
int c[A];
vi ch[A];
int qhead[A];
int n;

int root;

int l;
vector<int> tin, tout;
int timer;
vector < vector<int> > up;

void dfsdumb (int v, int p = 0) {
    tin[v] = ++timer;
    up[v][0] = p;
    for (int i=1; i<=l; ++i)
        up[v][i] = up[up[v][i-1]][i-1];
    for (size_t i=0; i<g[v].size(); ++i) {
        int to = g[v][i];
        if (to != p)
            dfsdumb (to, v);
    }
    tout[v] = ++timer;
}

bool upper (int a, int b) {
    return tin[a] <= tin[b] && tout[a] >= tout[b];
}

int lca (int a, int b) {
    if (upper (a, b))  return a;
    if (upper (b, a))  return b;
    for (int i=l; i>=0; --i)
        if (! upper (up[a][i], b))
            a = up[a][i];
    return up[a][0];
}

void dfs0(int v, int  p) {
    for(auto u : g[v]) if(u!=p) {
        lev[u] = lev[v] + 1;
        par[u] = v;
        ch[v].pb(u);
        dfs0(u, v);
    }
}

int dist(int i, int j) {
//    if(max(i,j) == -1) return -2;
    if(i==-1||j==-1) return -1;
    if(lev[c[i]] < lev[c[j]]) swap(i, j);
    int cc = lca(c[i], c[j]);
    if(cc != c[j]) return -2*lev[cc] + lev[c[j]] + lev[c[i]];
    int ha = lca(c[i], a[j]);
    if(ha != c[j]) return -lev[ha] + lev[c[i]];
    int hb = lca(c[i], b[j]);
    if(hb != c[j]) return -lev[hb] + lev[c[i]];
    return -2*lev[cc] + lev[c[j]] + lev[c[i]];
}

struct path {
    path(int _a, int _b, int _c) : a(_a), b(_b), c(_c) {};
    int a,b,c;
    bool operator==(const path & other) {
        return a == other.a && b == other.b && c == other.c;
    }
};

bool onpath(int v, path p) {
    return lev[lca(v,p.a)] >= lev[p.c] || lev[lca(v,p.b)] >= lev[p.c];
}

path inter(path p, path q) {
    if(lev[p.c] < lev[q.c]) swap(p, q);
    if(lev[p.c] > lev[q.c]) {
        int down = q.a;
        if(lca(down, p.c) != p.c) down = q.b;
        int ato = lca(p.a, down);
        int bto = lca(p.b, down);
        if(lev[bto] > lev[ato]) ato = bto;
        return path(min(p.c,ato),max(p.c,ato),p.c);
    }
    int down = q.a;
    int ato = lca(p.a, down);
    int bto = lca(p.b, down);
    if(lev[bto] > lev[ato]) ato = bto;
    int e1 = ato;
    down = q.b;
    ato = lca(p.a, down);
    bto = lca(p.b, down);
    if(lev[bto] > lev[ato]) ato = bto;
    if(e1 > ato) swap(e1,ato);
    return path(e1,ato,p.c);
}

struct sega {
    sega() : ind({-1,-1,-1}), val(-1) {};
    sega(int i) : ind({i, -1, -1}), val(0) {if(i == -1) val = -1;};
    array<int, 3> ind;
    int val;
};

path getpath(int i) {
    return path(a[i], b[i], c[i]);
}

sega zerosega;

sega combine(const sega & a, const sega & b) {
    sega ret = a;
    if(b.val > a.val) ret = b;
    for(auto i : a.ind) for(auto j : b.ind) {
        int cand = dist(i,j);
        if(cand > ret.val) {
            ret.val = cand;
            ret.ind = {i,j,-1};
        }
    }
    if(ret.val == 0) {
        vi v;
        for(auto i : a.ind) if(i!=-1) v.pb(i);
        for(auto i : b.ind) if(i!=-1) v.pb(i);
        auto cur = getpath(v[0]);
        forn(i,1,v.size()) cur = inter(cur, getpath(v[i]));
        vector<path> p;
        for(auto i : v) p.pb(getpath(i));
        int done = 0;
        forn(i,0,v.size()) {
            if(done) break;
            path cand = p[i];
            if(cand == cur) {
                ret.ind = {v[i], -1, -1};
                break;
            }
            forn(j,i+1,v.size()) {
                if(done) break;
                path cand2 = inter(cand, p[j]);
                if(cand2 == cur) {
                    ret.ind = {v[i], v[j], -1};
                    done = 1;
                    break;
                }
                forn(k,j+1,v.size()) {
                    path cand3 = inter(cand2, p[k]);
                    if(cand3 == cur) {
                        ret.ind = {v[i], v[j], v[k]};
                        done = 1;
                        break;
                    }
                }
            }
        }
    }
    return ret;
}

class stree {
public:
    vector<sega> t;
    void build(int n) {
        t.resize(4*n);
    }
    
    void set(int v, int tl, int tr, int pos, int val) {
        if(tl == tr) {
            if(val == -1) t[v] = zerosega;
            else t[v] = sega(val);
        }
        else {
            int tm = (tl+tr)/2;
            if(pos <= tm) set(v*2,tl,tm,pos,val);
            else set(v*2+1,tm+1,tr,pos,val);
            t[v] = combine(t[v*2], t[v*2+1]);
        }
    }
};

int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int q;
    cin>>n>>q;
    vi to;
    forn(i,0,q) to.pb(i);
//    shuffle(all(to), gen);
//    to = {5,4,1,3,2,0};
//    root = gen()%n;
//    root = 1;
    forn(i,0,n-1) {
        int u, v;
        cin>>u>>v;
        --u; --v;
        g[u].pb(v);
        g[v].pb(u);
    }
    tin.resize (n),  tout.resize (n),  up.resize (n);
    l = 1;
    while ((1<<l) <= n)  ++l;
    for (int i=0; i<n; ++i)  up[i].resize (l+1);
    dfsdumb(root, root);
    dfs0(root, root);
    set<pair<pi, int>> cur;
    stree st;
    st.build(q);
    forn(i,0,q) {
        cin>>tp[i];
        if(tp[i] == 3) {
            cin>>c[i];
            if(st.t[1].val <= c[i]*2) cout<<"Yes\n";
            else {
                cout<<"No\n";
            }
        }
        else {
            cin>>a[i]>>b[i];
            --a[i]; --b[i];
            if(a[i] > b[i]) swap(a[i], b[i]);
            if(tp[i] == 1) {
                cur.insert(mp(mp(a[i], b[i]), i));
                c[i] = lca(a[i], b[i]);
                st.set(1, 0, q-1, to[i], i);
            }
            else {
                auto it = cur.lower_bound(mp(mp(a[i], b[i]), 0));
                int ind = it->second;
                c[i] = ind;
                cur.erase(it);
                st.set(1, 0, q-1, to[ind], -1);
            }
        }
    }
//    cout<<root<<'\n';
//    for(auto x : to) cout<<x<<' ';
    
}