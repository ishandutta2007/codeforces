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
    vi t;
    int s;
    void build (const vi & a, int v, int tl, int tr) {
        if(v==1) {
            t.resize(a.size() * 4);
        }
        if (tl == tr)
            t[v] = a[tl];
        else {
            int tm = (tl + tr) / 2;
            build (a, v*2, tl, tm);
            build (a, v*2+1, tm+1, tr);
            t[v] = max(t[v*2], t[v*2+1]);
        }
    }
    
    int get (int v, int tl, int tr, int l, int r) {
        if (l > r)
            return 0;
        if (l == tl && r == tr)
            return t[v];
        int tm = (tl + tr) / 2;
        return  max(
                    get (v*2, tl, tm, l, min(r,tm)),
                    get (v*2+1, tm+1, tr, max(l,tm+1), r)
                    );
    }
    
    void update (int v, int tl, int tr, int pos, ll new_val) {
        if (tl == tr)
            t[v] = new_val;
        else {
            int tm = (tl + tr) / 2;
            if (pos <= tm)
                update (v*2, tl, tm, pos, new_val);
            else
                update (v*2+1, tm+1, tr, pos, new_val);
            t[v] =  max(t[v*2], t[v*2+1]);
        }
    }
};

int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int ta;
    cin>>ta;
    const int INF = 1e9;
    forn(ifa,0,ta) {
        int n,qn;
        cin>>n>>qn;
        vi  p(n), a(n);
        forn(i,0,n) cin>>p[i];
        forn(i,0,n) cin>>a[i];
        stree st;
        st.build(a, 1, 0, n-1);
        vpi ord;
        forn(i,0,n) ord.pb(mp(p[i],i));
        srtrev(ord);
        set<int> b;
        b.insert(-1);
        b.insert(n);
        vi u(n, INF);
        vi d(n, 0);
        vpi e;
        int bad = 0;
        int k = 0;
        forn(i,0,n) k += (a[i]==0);
        for(auto xx : ord) {
            int i = xx.second;
            auto it = b.lower_bound(i);
            int r =  *it;
            it--;
            int l = *it;
            b.insert(i);
            int mx = 1e9;
            if(l != -1) mx = min(mx, u[l]);
            if(r != n) mx = min(mx, u[r]);
            int mn = st.get(1, 0, n-1, l+1, r-1);
            if(a[i] != 0) {
                if(a[i] > mx  || a[i] < mn) {
                    bad = 1;
                    break;
                }
                mx = a[i];
                mn = a[i];
            }
            else {
                e.pb(mp(mn, mx));
            }
            d[i] = mn;
            u[i] = mx;
        }
        vi s(k-1);
        forn(i,0,k-1) cin>>s[i];
        vi q(qn);
        forn(i,0,qn) cin>>q[i];
        int al = 0;
        int ar = INF;
        vpi ev;
        forn(i,0,e.size()) {
            ev.pb(mp(e[i].first, -i-2));
            ev.pb(mp(e[i].second, i+2));
        }
        for(auto x : q) ev.pb(mp(x,0));
        for(auto x : s) ev.pb(mp(x,-1));
        srt(ev);
        set<pi> rend;
        int done = 0;
        vi taken(e.size(), 0);
        for(auto x : ev) {
//            cout<<x.first<<' '<<x.second<<'\n';
            if(x.second == 0) {
                if(done == 0 && rend.empty()) {
                    al = min(al, x.first+1);
                }
            }
            else if(x.second == -1) {
                if(rend.empty()) {
                    bad = 1;
                    break;
                };
                taken[rend.begin()->second] = 1;
                rend.erase(rend.begin());
            }
            else if(x.second < 0) {
                int i = -2-x.second;
                rend.insert(mp(e[i].second, i));
            }
            else {
                int i = x.second - 2;
                if(taken[i]) continue;
                if(done) {
                    bad = 1;
                    break;
                }
                done = 1;
                ar = min(ar, x.first);
                rend.erase(rend.find(mp(e[i].second, i)));
            }
        }
//        ev.clear();
        rend.clear();
        taken = vi(e.size(), 0);
        reverse(all(ev));
        done = 0;
        for(auto x : ev) {
            if(x.second == 0) {
                if(done == 0 && rend.empty()) {
                    ar = min(ar, x.first-1);
                }
            }
            else if(x.second == -1) {
                if(rend.empty()) {
                    bad = 1;
                    break;
                };
                taken[rend.begin()->second] = 1;
                rend.erase(rend.begin());
            }
            else if(x.second > 0) {
                int i = -2+x.second;
                rend.insert(mp(-e[i].first, i));
            }
            else {
                int i = -x.second - 2;
                if(taken[i]) continue;
                if(done) {
                    bad = 1;
                    break;
                }
                done = 1;
                al = max(al, x.first);
                rend.erase(rend.find(mp(-e[i].first, i)));
            }
        }
        forn(i,0,qn) {
            if(bad || q[i] < al || q[i] > ar) cout<<"NO\n";
            else cout<<"YES\n";
        }
        
    }
    
    
}