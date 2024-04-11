#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <ctype.h>
#include <queue>
#include <cstring>
#include <set>
#include <array>
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

vpll split(ll l, ll r) {
    vpll ret;
    ll cur = l;
    ll d2 = 1;
    int deg = 0;
    r++;
    while(1) {
        while(cur%(2*d2) == 0 && cur + 2*d2 <= r) {
            d2*=2;
            deg++;
        }
        if(cur + d2 > r) break;
        ret.pb(mp(cur, deg));
        cur += d2;
    }
    while(deg > 0) {
        d2 /= 2;
        deg--;
        if(cur + d2 <= r) {
            
            ret.pb(mp(cur, deg));
            cur+=d2;
        }
    }
    return ret;
}

//#ifdef LOCAL
//const int A = 15000000;
//#else
//const int A = 5100500;
//#endif
const int A = 3500500;
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
//        cout<<a<<' '<<b<<'\n';
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

ll d2[51];
int n;

string tos(ll l, int deg) {
    ll lef = l >> deg;
    string ret;
    forn(i,0,n-deg) {
        ret.pb('0'+lef%2);
        lef/=2;
    }
    reverse(all(ret));
    ret +=  string(deg,'*');
    return ret;
}
int addr[60];
int tov(ll l, int deg) {
    ll lef = l >> deg;
    vi ret;
    forn(i,0,n-deg) {
        ret.pb(lef%2);
        lef/=2;
    }
    reverse(all(ret));
    forn(i,0,ret.size()) addr[i] = ret[i];
    return ret.size();
//    return ret;
}

int pt = 1;
set<pll> w;
struct node {
    node() : ch({-1,-1}), united(0), good(false) {};
    array<int, 2> ch;
    int united;
    bool good;
//    array<int, 2> ch = {-1, -1};
//    int united = -1;
//    bool good = 0;
};

node a[A];
int pta = 1;


void join(int v, int to) {
    if(a[v].united) union_sets(a[v].united, to);
    forn(bit,0,2) if(a[v].ch[bit] != -1) {
        join(a[v].ch[bit], to);
    }
}

void checkv(int len, int ind, ll l, ll r) {
    int cur = 0;
    int united = a[cur].united;
    int good = a[cur].good;
//    for(auto bit : addr) {
    forn(i,0,len) {
        cur = a[cur].ch[addr[i]];
        if(cur == -1) break;
        good |= a[cur].good;
        united = max(united, a[cur].united);
//        if(united == -1) united = a[cur].united;
    }
    if(cur != -1) good = 1;
    if(good == 0) return;
    if(united != 0) union_sets(united, ind);
    else if(cur != -1){
        a[cur].united = ind;
        join(cur, ind);
    }
}

void addv(int len, int ind) {
    int cur = 0;
//    for(auto bit : addr) {
    forn(i,0,len) {
        if(a[cur].ch[addr[i]] == -1) a[cur].ch[addr[i]] = pta++;
        cur = a[cur].ch[addr[i]];
        if(a[cur].united) union_sets(a[cur].united, ind);
    }
    a[cur].united = ind;
    a[cur].good = 1;
    
}

void add1(ll l, int deg) {
    int len = tov(l, deg);
    int ind = pt++;
    make_set(ind);
    w.insert(mp(l, ind));
//    cout<<ind<<' '<<tos(l,deg)<<'\n';
    forn(sw,0,len) {
        addr[sw]^=1;
        checkv(len, ind, l^d2[n-1-sw], l^d2[n-1-sw]+d2[deg]-1);
        addr[sw]^=1;
    }
    addv(len, ind);
}

void add(ll l, ll r) {
    for(auto x : split(l, r)) add1(x.first, x.second);
}

int check(ll a, ll b) {
    auto it1 = w.lower_bound(mp(a+1,0));
    auto it2 = w.lower_bound(mp(b+1,0));
    it1--;
    it2--;
    return find_set(it1->second) == find_set(it2->second);
}

int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int m;
    cin>>n>>m;
    forn(i,0,n+1) d2[i] = 1ll<<i;
    vll l(m), r(m);
    vi tp(m);
    vpll blocked;
    blocked.pb(mp(-1,-1));
    blocked.pb(mp(1ll<<n,1ll<<n));
    forn(i,0,m) {
        string s;
        cin>>s>>l[i]>>r[i];
//        if(i<m/2) s = "b";
//        else s = "a";
//        l[i] = gen()%d2[n];
//        r[i] = l[i];
        if(s[0] == 'a') tp[i] = 0;
        else {
            tp[i] = 1;
            blocked.pb(mp(l[i], r[i]));
        }
    }
    while(!tp.empty() && tp.back() == 1) {
        blocked.pop_back();
        tp.pop_back();
        l.pop_back();
        r.pop_back();
        m--;
    }
    srt(blocked);
    forn(i,1,blocked.size()) if(blocked[i].first - blocked[i-1].second > 1) {
        add(blocked[i-1].second + 1, blocked[i].first - 1);
    }
    vi ans;
    for(int i = m-1; i>=0; i--) {
        if(tp[i] == 0) ans.pb(check(l[i], r[i]));
        else add(l[i], r[i]);
    }
    reverse(all(ans));
    for(auto x : ans) cout<<x<<'\n';
//    cout<<a.size();
    
    
}