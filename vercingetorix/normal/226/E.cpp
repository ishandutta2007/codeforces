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

const int A = 100010;
int tt[2*A];
class stree {
public:
    int n;
    void build (const vi & a) {
        n = a.size();
        forn(i,0,n) tt[i] = 0;
        forn(i,0,n) tt[n+i] = a[i];
//        for (int i = n - 1; i > 0; --i) tt[i] = tt[i<<1] + tt[i<<1|1];
    }
    
    void update(int l, int r, int value) {
        r++;
        for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
            if (l&1) tt[l++] += value;
            if (r&1) tt[--r] += value;
        }
    }
    
    int get(int pos) {
        int res = 0;
        for (pos += n; pos > 0; pos >>= 1) res += tt[pos];
        return res;
    }
};

int l;
vector<int> tin, tout;
vi tl, tr;
int timer,timer2;
vector < vector<int> > up;

vi ch[A];
int dep[A];

void dfs1 (int v, int p = 0) {
    tl[v] = timer2++;
    tin[v] = ++timer;
    up[v][0] = p;
    for (int i=1; i<=l; ++i)
        up[v][i] = up[up[v][i-1]][i-1];
    for(auto to : ch[v]) {
        dep[to] = dep[v] + 1;
        dfs1 (to, v);
    }
    tout[v] = ++timer;
    tr[v] = timer2-1;
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

const int B = 222;
const int C = A/B+2;
//stree st[C];
int par[A];
stree st;
int n;
int get(int v, int k) {
    int need = st.get(tl[v]) - k + 1;
    for (int i=l; i>=0; --i) if(st.get(tl[up[v][i]]) >= need) v = up[v][i];
    return v;
};

vvi gp;
void reroot(int v, int p) {
    par[v] = p;
    for(auto u : gp[v]) if(u != p) reroot(u, v);
}

int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
//    stree s;
//    s.build({0,1,2,3});
//    cout<<s.get(1);
//    exit(0);
    
    cin>>n;
    forn(i,0,n) cin>>par[i];
//    gp.resize(n);
    forn(i,0,n) par[i]--;
//    forn(i,0,n) if(par[i] != -1) {
//        gp[par[i]].pb(i);
//        gp[i].pb(par[i]);
//    }
//    reroot(gen()%n, -1);
//
    int root = 0;
    forn(i,0,n) {
        if(par[i] == -1) root = i;
        else ch[par[i]].pb(i);
    }
    tin.resize (n),  tout.resize (n),  up.resize (n);
    tl.resize(n), tr.resize(n);
    l = 1;
    while ((1<<l) <= n)  ++l;
    for (int i=0; i<n; ++i)  up[i].resize (l+1);
    
    dfs1 (root, root);
    vi def(n);
    forn(i,0,n) def[tl[i]] = dep[i]+1;
//    forn(i,0,C) st[i].build(def, 1, 0, n-1);
    int q;
    cin>>q;
    
    
    int num;
    vi tp(q);
    vi qv(q);
    vi qa(q), qb(q), qk(q), qy(q);
    vpi raid;
    vi numto(q);
    vpi t1;
    vvi proc(C);
    forn(t, 0, q) {
        cin>>tp[t];
        if(tp[t] == 1) {
            cin>>qv[t];
            qv[t]--;
            raid.pb(mp(t, qv[t]));
        }
        else {
            cin>>qa[t]>>qb[t]>>qk[t]>>qy[t];
            qa[t]--;
            qb[t]--;
            qy[t]--;
            int y = qy[t];
            int num = y/B+1;
            int done = num*B;
            auto pts = lower_bound(all(raid), mp(y+1,0)) - raid.begin();
            int pt = pts;
            while(pt<raid.size() && raid[pt].first < done) pt++;
            int high = pt-pts;
            pt = pts-1;
            while(pt>=0 && raid[pt].first > done - B) pt--;
            int low = pts -1 - pt;
//            low  = -1;
            if(low < high) {
                numto[t] = num-1;
            }
            else numto[t] = num;
            proc[numto[t]].pb(t);
        }
            
    }
    vi res(q);
    vi barb(n,-1);
    forn(num,0,C) {
        if(proc[num].empty()) continue;
        forn(i,0,n) barb[i] = -1;
        st.build(def);
        int tpt = 0;
        for(auto t : proc[num]) {
            while(tpt < raid.size() && raid[tpt].first < t) {
                int v = raid[tpt].second;
                if(num * B <= raid[tpt].first) st.update(tl[v], tr[v], -1);
                barb[v] = raid[tpt++].first;
            }
            int a = qa[t];
            int b = qb[t];
            int k = qk[t];
            int y = qy[t];
//            if(y/B+1 != num) continue;
            int curnum = y/B+1;
            //                num = y/B+1;
            int done = num*B;
            auto pts = lower_bound(all(raid), mp(y+1,0)) - raid.begin();
            int pt;
            if(num == curnum) {
                pt = pts;
                while(pt<raid.size() && raid[pt].first < min(t,done)) {
                    int v = raid[pt++].second;
                    st.update(tl[v], tr[v], -1);
                }
            }
            else {
                pt = pts-1;
                while(pt>=0 && raid[pt].first >= done) {
                    int v = raid[pt--].second;
                    st.update(tl[v], tr[v], 1);
                }
            }
            for(auto v : {a,b}) if(barb[v] <= y) st.update(tl[v], tr[v], -1);
            int c = lca(a, b);
            int sta = st.get(tl[a]);
            int stb = st.get(tl[b]);
            int stpc = 0;
            if(c != root) stpc = st.get(tl[par[c]]);
            int full = sta+stb-2*stpc;
            if(c!=a && c!=b && barb[c] <= y) full--;
            int ans = -2;
            if(full >= k) {
                if(sta - stpc >= k) ans = get(a, k);
                else ans = get(b, full + 1 - k);
            }
            //            printf("%d\n", ans+1);
            //                cout<<ans+1<<'\n';
            res[t] = ans+1;
            for(auto v : {a,b}) if(barb[v] <= y) st.update(tl[v], tr[v], 1);
            if(num == curnum) {
                pt = pts;
                while(pt<raid.size() && raid[pt].first < min(t,done)) {
                    int v = raid[pt++].second;
                    st.update(tl[v], tr[v], 1);
                }
            }
            else {
                pt = pts-1;
                while(pt>=0 && raid[pt].first >= done) {
                    int v = raid[pt--].second;
                    st.update(tl[v], tr[v], -1);
                }
            }
        }
    }
    forn(i,0,q) if(tp[i] == 2) cout<<res[i] <<'\n';
    
    
}