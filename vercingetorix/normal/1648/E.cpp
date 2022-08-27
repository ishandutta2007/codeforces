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

const int A = 200500;
int pars[A];
vi vers[A];

int parent[A];
vi ver[A];
set<int> ch[A];
void make_set (int v) {
    parent[v] = v;
    ch[v].insert(v);
    pars[v]= v;
    vers[v].pb(v);
    ver[v].pb(v);
}
int ans[A];
map<pi, int> ed;
set<pi> g[A];
int curc;

int find_set (int v) {
    return parent[v];
}

void union_s8 (int a, int b) {
    a = pars[a];
    b = pars[b];
    if(a == b) return;
    pi ts = mp(a,b);
    if(a>b) ts = mp(b,a);
    if(ed[ts] == ll(vers[a].size())*vers[b].size()) return;
    if(g[b].size() + vers[b].size() > g[a].size() + vers[a].size()) swap(a,b);
    for(auto x : g[b]) {
        if(x.first == a) {
            g[a].erase(mp(b, x.second));
            ans[x.second] = curc;
        }
        else {
            int c = x.first;
            pi cur = mp(a,c);
            if(a > c) cur = mp(c,a);
            ed[cur]++;
            g[a].insert(mp(c, x.second));
            g[c].erase(mp(b, x.second));
            g[c].insert(mp(a, x.second));
        }
    }
    for(auto v : vers[b]) {
        vers[a].pb(v);
        pars[v] = a;
    }
    vers[b].clear();
}

void union_ber(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if(a == b) return;
    if(ver[a].size() < ver[b].size()) swap(a,b);
    for(auto x : ch[a]) for(auto y : ch[b]) {
        union_s8(x, y);
    }
    set<int> nch;
    for(auto x : ch[a]) nch.insert(pars[x]);
    for(auto x : ch[b]) nch.insert(pars[x]);
    ch[b].clear();
    for(auto x : ver[b]) {
        parent[x] = a;
        ver[a].pb(x);
    }
    swap(ch[a], nch);
}



int n,m;
void clean() {
    ed.clear();
    forn(i,0,n) {
        vers[i].clear();
        ch[i].clear();
        g[i].clear();
        ver[i].clear();
    }
}

int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int ta;
    read(ta);
    forn(ifa,0,ta) {
        cin>>n>>m;
        vector<pi> ev;
        vi a(m), b(m), c(m);;
        forn(i,0,n) make_set(i);
        forn(i,0,m) {
            cin>>a[i]>>b[i]>>c[i];
            a[i]--;
            b[i]--;
            if(a[i] > b[i]) swap(a[i], b[i]);
            ed[mp(a[i],b[i])]++;
            ev.pb(mp(c[i], i));
            g[a[i]].insert(mp(b[i],i));
            g[b[i]].insert(mp(a[i],i));
        }
        srt(ev);
        for(auto xx : ev) {
            curc = xx.first;
            int ind = xx.second;
            int u = a[ind];
            int v = b[ind];
            if(find_set(u) == find_set(v))  continue;
            union_ber(u, v);
        }
        clean();
        forn(i,0,m) cout<<ans[i]<<' ';
        cout<<'\n';
    }
    
    
}