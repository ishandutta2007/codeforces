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

//typedef long long ll;
typedef int ll;
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
const int INF = 1e9;
struct Line {
    mutable ll k, m, p;
    bool operator<(const Line& o) const { return k < o.k; }
    bool operator<(ll x) const { return p < x; }
    ll get(int x) {return k*x+m;};
    Line() : k(0), m(-INF) {}
    Line(int a, int b, int p = 0) : k(a), m(b), p(p) {}
};



struct LineContainer : multiset<Line, less<>> {
    // (for doubles, use inf = 1/.0, div(a,b) = a/b)
    static const ll inf = 1e9;
    ll div(ll a, ll b) { // floored division
        return a / b - ((a ^ b) < 0 && a % b); }
    bool isect(iterator x, iterator y) {
        if (y == end()) return x->p = inf, 0;
        if (x->k == y->k) x->p = x->m > y->m ? inf : -inf;
        else x->p = div(y->m - x->m, x->k - y->k);
        return x->p >= y->p;
    }
    void add(ll k, ll m) {
        auto z = insert({k, m, 0}), y = z++, x = y;
        while (isect(y, z)) z = erase(z);
        if (x != begin() && isect(--x, y)) isect(x, y = erase(y));
        while ((y = x) != begin() && (--x)->p >= y->p)
            isect(x, erase(y));
    }
    int query(ll x) {
        //        assert(!empty());
        if(empty()) return -INF;
        auto l = *lower_bound(x);
        return l.k * x + l.m;
    }
};

LineContainer t1[80000];
LineContainer t2[80000];

class stree {
public:
    LineContainer * t;
    //    vector<LineContainer> t;
    void build (int n) {
        //        t.clear();
        //        t.resize(4*n);
        forn(i,0,4*n) t[i].clear();
    }
    
    void update (int v, int tl, int tr, int l, int r, ll k, ll m) {
        //        if(v==1) cout<<l<<' '<<r<<' '<<k<<' '<<m<<'\n';
        if (l > r)
            return;
        if (l == tl && tr == r)
            t[v].add(k, m);
        else {
            int tm = (tl + tr) / 2;
            update (v*2, tl, tm, l, min(r,tm), k, m);
            update (v*2+1, tm+1, tr, max(l,tm+1), r, k, m);
        }
    }
    
    int get (int v, int tl, int tr, int pos, int x) {
        if (tl == tr)
            return t[v].query(x);
        int tm = (tl + tr) / 2;
        if (pos <= tm)
            return max(t[v].query(x), get (v*2, tl, tm, pos, x));
        else
            return max(t[v].query(x), get (v*2+1, tm+1, tr, pos, x));
    }
};
struct Node {
    Line line;
    Node *lc = nullptr;
    Node *rc = nullptr;
    void clear() {
        lc = nullptr;
        rc = nullptr;
        line = Line();
    }
};
auto *root = new Node[80000];
int sz;
class LiChao {
public:
    void InsertLineKnowingly(Node* &n, int tl, int tr, Line x) {
        if (n == nullptr) n = new Node();
        if (n->line.get(tl) < x.get(tl)) swap(n->line, x);
        if (n->line.get(tr) >= x.get(tr)) return;
        if (tl == tr) return;
        int mid = (tl + tr) / 2;
        if (n->line.get(mid) > x.get(mid)) {
            InsertLineKnowingly(n->rc, mid + 1, tr, x);
        } else {
            swap(n->line, x);
            InsertLineKnowingly(n->lc, tl, mid, x);
        }
    }
    
    void InsertLine(Node* &n, int tl, int tr, int l, int r, Line x) {
        if (tr < l || r < tl || tl > tr || l > r) return;
        if (n == nullptr) n = new Node();
        if (l <= tl && tr <= r) return InsertLineKnowingly(n, tl, tr, x);
        int mid = (tl + tr) / 2;
        InsertLine(n->lc, tl, mid, l, r, x);
        InsertLine(n->rc, mid + 1, tr, l, r, x);
    }
    
    int Query(Node* &n, int tl, int tr, int x) {
        if (n == nullptr) return -INF;
        if (tl == tr) return n->line.get(x);
        int res = n->line.get(x);
        int mid = (tl + tr) / 2;
        if (x <= mid) {
            res = max(res, Query(n->lc, tl, mid, x));
        } else {
            res = max(res, Query(n->rc, mid + 1, tr, x));
        }
        return res;
    }
    
    void InsertLine(int l, int r, Line x) {
        return InsertLine(root, 0, sz - 1, l, r, x);
    }
    
    int Query(int x) {
        return Query(root, 0, sz - 1, x);
    }
    
    void build(int n) {
        forn(i,0,4*n) root[i].clear();
    }
};


int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int n,k;
    //    scanf("%d %d", &n, &k);
    cin>>n>>k;
    sz = n;
    vi a(n);
    forn(i,0,n) cin>>a[i];
    //    forn(i,0,n) a[i] = n-i;
    //    readv(a,n);
    vi tor(n, n);
    vi tol(n,-1);
    vi big;
    forn(i,0,n) {
        while(!big.empty() && a[big.back()] <= a[i]) big.pop_back();
        if(!big.empty()) tol[i] = big.back();
        big.pb(i);
    }
    big.clear();
    for(int i = n-1; i>=0; i--) {
        while(!big.empty() && a[big.back()] <= a[i]) big.pop_back();
        if(!big.empty()) tor[i] = big.back();
        big.pb(i);
    }
    vi pref(1,0);
    forn(i,0,n) pref.pb(pref.back() + a[i]);
    stree st2;
//    st1.t = t1;
    st2.t = t2;
    //    stree st;
    int mx = 0;
    LiChao st1;
    
    vi cur(n, INF);
    forn(i,0,n) {
        if(a[i] >= mx) cur[i] = a[i]*(i+1)-pref[i+1];
        mx = max(mx, a[i]);
    }
    forn(imp, 0, k-1) {
        st1.build(n);
        st2.build(n);
        //        st1.update(1, 0, n-1, 0, n-1, 0, -INF);
        //        st2.update(1, 0, n-1, 0, n-1, 0, -INF);
        //        vi ncur;
        forn(p,0,n) {
            int q = tor[p] - 1;
            int f = cur[p];
            int up = p*a[p]-pref[p+1] - st2.get(1, 0, n-1, tol[p]+1, a[p]);
            if(tol[p] >= 0) {
//                up = min(up, -pref[p+1] + (p-tol[p])*a[p] - st1.get(1, 0, n-1, tol[p], tol[p]));
                up = min(up, -pref[p+1] + (p-tol[p])*a[p] - st1.Query(root, 0, n-1, tol[p]));
            }
            cur[p] = up;
            //            ncur.pb(up);
            if(f<=INF) {
//                st1.update(1, 0, n-1, 0, q, -a[p], a[p]*p-f-pref[p+1]);
                st1.InsertLine(root, 0, n-1, 0, q, Line(-a[p], a[p]*p-f-pref[p+1]));
                st2.update(1, 0, n-1, 0, p, q, -pref[p+1]-f-(q-p)*a[p]);
            }
        }
        //        swap(cur,ncur);
    }
    int ans = INF;
    forn(i,0,n) if(tor[i] == n) {
        ans = min(ans, cur[i]+(n-i)*a[i]-pref[n]+pref[i]);
    }
    for(auto x : a) ans+=x;
    cout<<ans;
    
    
}