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
class CoordinateCompressor {
public:
    vpi xc;
    vpi xx;
    
    inline void add(pi x) {
        xx.pb(x);
    }
    
    void init() {
        xc.clear();
        srt(xx);
        forn(i,0,xx.size()) if(i==0 || xx[i] != xx[i-1]) xc.pb(xx[i]);
    }
    
    inline int comp(const pi x) {
        return lower_bound(all(xc), x) - xc.begin();
    }
    
    inline int len() {
        return xc.size();
    }
};

template <typename T>
class fenwick {
public:
    vector<T> fenw;
    int n;
    
    fenwick(int _n) : n(_n) {
        fenw.resize(n);
    }
    
    void modify(int x, T v) {
        while (x < n) {
            fenw[x] += v;
            x |= (x + 1);
        }
    }
    
    T get(int x) {
        T v{};
        while (x >= 0) {
            v += fenw[x];
            x = (x & (x + 1)) - 1;
        }
        return v;
    }
    
    T get(int l, int r) {
        T ret = get(r);
        if (l>0) ret -= get(l-1);
        return ret;
    }
};

class stree {
public:
    vll t;
    vll pp;
    void build (int n, int v, int tl, int tr) {
        t.resize(n * 4);
        pp = vll(n*4,1);
    }
    
    void push(int v, int tl, int tr) {
        if(pp[v] == 1) return;
        t[v] = t[v] * pp[v] % mod;
        if(tl != tr) {
            pp[2*v] = pp[v*2]*pp[v]%mod;
            pp[2*v+1] = pp[v*2+1]*pp[v]%mod;
        }
        pp[v] = 1;
    }
    
    void update (int v, int tl, int tr, int l, int r, ll val) {
        if (l == tl && tr == r) {
            pp[v] = pp[v]*val%mod;
            push(v,tl,tr);
            return;
        }
        if (l > r) {
            push(v, tl, tr);
            return;
        }
        else {
            push(v,tl,tr);
            int tm = (tl + tr) / 2;
            update (v*2, tl, tm, l, min(r,tm), val);
            update (v*2+1, tm+1, tr, max(l,tm+1), r, val);
            t[v] = (t[v*2] + t[v*2+1])%mod;
        }
    }
    
    void set (int v, int tl, int tr, int pos, ll val) {
        if (pos == tl && tr == pos) {
            pp[v] = 1;
            t[v] = val;
            return;
        }
        if (pos < tl || pos > tr) {
            push(v, tl, tr);
            return;
        }
        else {
            push(v,tl,tr);
            int tm = (tl + tr) / 2;
            set (v*2, tl, tm, pos, val);
            set (v*2+1, tm+1, tr, pos, val);
            t[v] = (t[v*2] + t[v*2+1])%mod;
        }
    }
    
    ll get (int v, int tl, int tr, int l, int r) {
        push(v, tl, tr);
        if (l>r) return 0;
        if (tl ==l && r== tr)
            return t[v];
        int tm = (tl + tr) / 2;
        ll ret =  (get(v*2, tl, tm, l, min(r,tm)) + get(v*2+1, tm+1, tr, max(l,tm+1), r)) % mod;
        t[v] = (t[v*2] + t[v*2+1])%mod;
        return ret;
    }
};

CoordinateCompressor comp;
ll cur = 0;
stree stl, str;
fenwick<int> fen(0);
int m;
const int A = 300500;
ll d2[A];
ll di2[A];
const ll i2 = (mod+1)/2;
const ll i4 = i2*i2%mod;
const ll i8 = i2*i4%mod;

void add(int pos, ll val) {
    int numl = fen.get(0, pos);
    ll kl = stl.get(1, 0, m-1, pos, m-1)*d2[numl]%mod;
    cur = (cur + kl*i4%mod*val)%mod;
    stl.update(1, 0, m-1, pos, m-1, i2);
    stl.set(1, 0, m-1, pos, val*di2[numl]%mod);
    int numr = fen.get(pos, m-1);
    ll kr = str.get(1, 0, m-1, 0 ,pos)*d2[numr]%mod;
    cur = (cur + kr*i4%mod*val)%mod;
    str.update(1, 0, m-1, 0, pos, i2);
    str.set(1, 0, m-1, pos, val*di2[numr]%mod);
    fen.modify(pos, 1);
    cur = (cur + mod - kl*kr%mod*i8%mod)%mod;
}

void rem(int pos, ll val) {
    fen.modify(pos, -1);
    int numl = fen.get(0, pos);
    stl.set(1, 0, m-1, pos, 0);
    stl.update(1, 0, m-1, pos, m-1, 2);
    ll kl = stl.get(1, 0, m-1, pos, m-1)*d2[numl]%mod;
    cur = (cur + mod - kl*i4%mod*val%mod)%mod;
    int numr = fen.get(pos, m-1);
    str.set(1, 0, m-1, pos, 0);
    str.update(1, 0, m-1, 0, pos, 2);
    ll kr = str.get(1, 0, m-1, 0 ,pos)*d2[numr]%mod;
    cur = (cur + mod - kr*i4%mod*val%mod)%mod;
    cur = (cur + mod + kl*kr%mod*i8%mod)%mod;
}

int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    d2[0] = 1;
    di2[0] = 1;
    forn(i,1,A) {
        d2[i] = d2[i-1] * 2 % mod;
        di2[i] = di2[i-1] * (mod+1)/2 % mod;
    }
    int n;
    cin>>n;
    vi a(n);
    forn(i,0,n) {
        cin >> a[i];
        comp.add(mp(a[i], i));
    }
    int qn;
    cin>>qn;
    vi qi(qn), qto(qn);
    forn(i,0,qn) {
        cin>>qi[i]>>qto[i];
        qi[i]--;
        comp.add(mp(qto[i], qi[i]));
    }
    comp.init();
    m = comp.len();
    stl.build(m, 1, 0, m-1);
    str.build(m, 1, 0, m-1);
    fen = fenwick<int>(m);
    forn(i,0,n) {
        int pos = comp.comp(mp(a[i], i));
        add(pos, a[i]);
    }
    cout<<cur<<'\n';
    forn(it,0,qn) {
        int i = qi[it];
        int to = qto[it];
        int pos = comp.comp(mp(a[i], i));
        rem(pos, a[i]);
        a[i] = to;
        pos = comp.comp(mp(a[i], i));
        add(pos, a[i]);
        cout<<cur<<'\n';
    }
    
    
}