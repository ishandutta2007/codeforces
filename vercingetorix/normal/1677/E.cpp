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

class stree {
public:
    vll t;
    vll pp;
    void build (int n) {
        t = vll(4*n, 0);
        pp = vll(4*n, 0);
    }
    
    void push(int v, int tl, int tr) {
        if(pp[v] == 0) return;
        t[v] += (tr-tl+1)*pp[v];
        if(tl != tr) {
            pp[2*v] += pp[v];
            pp[2*v+1] += pp[v];
        }
        pp[v] = 0;
    }
    
    void update (int v, int tl, int tr, int l, int r, ll val) {
        if (l == tl && tr == r) {
            pp[v] += val;
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
            t[v] = t[v*2] + t[v*2+1];
        }
    }
    
    ll get (int v, int tl, int tr, int l, int r) {
        push(v, tl, tr);
        if (l>r) return 0;
        if (tl ==l && r== tr)
            return t[v];
        int tm = (tl + tr) / 2;
        ll ret =  get(v*2, tl, tm, l, min(r,tm)) + get(v*2+1, tm+1, tr, max(l,tm+1), r);
        t[v] = t[v*2] + t[v*2+1];
        return ret;
    }
};

int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int n,q;
    set<int> ban;
    cin>>n>>q;
    vi a(n);
    forn(i,0,n) cin>>a[i];
    vi w(n+1);
    forn(i,0,n) w[a[i]] = i;
    ban.insert(-1);
    ban.insert(n);
    vector<pair<pi, pi>> rec;
    for(int mx = n; mx >= 1; mx--) {
        int m = w[mx];
        auto it = ban.lower_bound(m);
        int r = *it;
        it--;
        int l = *it;
        ban.insert(m);
        vpi cur;
        for(int d = 1; d * d < mx; d++) {
            if(mx % d == 0) {
                int p1 = w[d];
                int p2 = w[mx/d];
                if(p1 <=l || p2<=l || p1 >= r || p2 >= r) continue;
                if(p1 > p2) swap(p1, p2);
                if(p2 < m) p2 = m;
                if(p1 > m) p1 = m;
                cur.pb(mp(p1,p2));
            }
        }
        srt(cur);
        vpi ncur;
        for(auto x : cur) {
            while(!ncur.empty() && ncur.back().second >= x.second) ncur.pop_back();
            if(ncur.empty() || ncur.back().first < x.first) ncur.pb(x);
        }
        int last = l+1;
        for(auto x : ncur) {
            rec.pb(mp(mp(last,x.first), mp(x.second, r-1)));
            last = x.first + 1;
        }
    }
    stree stk, stb;
    stk.build(n);
    stb.build(n);
    vll ans(q,0);
    vector<vector<pair<pi, pi>>> eva(n+1);
    vector<vector<pair<int, pi>>> evr(n+1);
    forn(i,0,q) {
        int l,r;
        cin>>l>>r;
        l--;
        r--;
        eva[l].pb(mp(mp(i, -1), mp(l,r)));
        eva[r+1].pb(mp(mp(i, 1), mp(l,r)));
    }
    for(auto x : rec) {
        int l = x.first.first;
        int r = x.first.second;
        int d = x.second.first;
        int u = x.second.second;
        evr[d].pb(mp(1, mp(l,r)));
        evr[u+1].pb(mp(-1, mp(l,r)));
    }
    forn(i,0,n+1) {
        for(auto & x : eva[i]) {
            int l = x.second.first;
            int r = x.second.second;
            int caf = x.first.second;
            int ind = x.first.first;
            ll k = stk.get(1, 0, n-1, l, r);
            ll b = stb.get(1, 0, n-1, l, r);
            ans[ind] += caf*(k*(i-1)+b);
        }
        for(auto & x : evr[i]) {
            int l = x.second.first;
            int r = x.second.second;
            int caf = x.first;
            stb.update(1, 0, n-1, l, r, caf*(1-i));
            stk.update(1, 0, n-1, l, r, caf);
        }
    }
    forn(i,0,q) cout<<ans[i]<<'\n';
    
    
    
}