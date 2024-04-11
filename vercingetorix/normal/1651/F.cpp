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
#ifdef LOCAL
const int A = 200;
const int B = 4;
const int C = (A+B-1)/B;
#else
const int A = 200010;
const int B = 250;
const int C = (A+B-1)/B;
#endif
int c[A];
int rest[A];
int a[A];


pll d[C][2*B+1];
int ds[C];
// ll lin[C][A];
pll def[C][2*B+1];
int defs[C];

// void dix(int ind) {
//     int last = 0;
//     lin[ind][0] = 0;
//     ll lval = 0;
//     forn(i,1,defs[ind]) {
//         int nx = def[ind][i].first;
//         ll nval = def[ind][i].second;
//         ll step = (nval - lval)/(nx-last);
//         forn(j,last+1,nx+1) {
//             lin[ind][j] = lin[ind][j-1] + step;
//         }
//         lval = nval;
//         last = nx;
//     }
//     forn(j,last+1,A) {
//         lin[ind][j] = lin[ind][j-1];
//     }
// }

//ll hget(vpll & x, int t) {
//    auto it = lower_bound(all(x), mp(ll(t), 0ll));
//    if(it == x.end()) return x.back().second;
//    else if(it->first == t) return it->second;
//    else {
//        pll r = *it;
//        it --;
//        pll l = *it;
//        ll step = (r.second-l.second)/(r.first-l.first);
//        return it->second + step*(t-it->first);
//    }
//}

ll hget(pll * lt, pll * rt, int t) {
    int k = rt-lt;
    auto it = lower_bound(lt, rt, mp(ll(t), 0ll));
    // auto it = lt+1;
    if(it == rt) return (lt+k-1)->second;
    else if(it->first == t) return it->second;
    else {
        pll r = *it;
        it --;
        pll l = *it;
        ll step = (r.second-l.second)/(r.first-l.first);
        return it->second + step*(t-it->first);
    }
}
pi ev[A];
int pev;
ll megalen = 0;
class ccomp {
public:
    int l, r;
    int w;
    int zero = 0;
    int t0 = 0;
    
    void build_custom() {
        //        vpi ev;
        //        d[w].clear();
        ds[w] = 0;
        ll sum = 0;
        ll restsum = 0;
        int pev = 0;
        forn(i,l,r+1) {
            sum += a[i];
            restsum += rest[i];
            ev[pev++] = mp((c[i]-a[i])/rest[i], i);
            //            ev.pb(mp((c[i]-a[i])/rest[i], i));
        }
        d[w][ds[w]++] = mp(0, sum);
        //        d[w].pb(mp(0,sum));
        int k = r-l+1;
        
        //        srt(ev);
        megalen+=pev;
        sort(ev, ev+pev);
        int pt = 0;
        int last = 0;
        while(pt < pev) {
            int pr = pt+1;
            while(pr<pev && ev[pr].first == ev[pt].first) pr++;
            if(ev[pt].first > last) {
                sum += restsum*(ev[pt].first - last);
                d[w][ds[w]++] = mp(ev[pt].first, sum);
                //                d[w].pb(mp(ev[pt].first, sum));
            }
            forn(i,pt,pr) {
                int ind = ev[i].second;
                sum += (c[ind]-a[ind])-ev[i].first*rest[ind];
                restsum -= rest[ind];
            }
            sum += restsum;
            last = ev[pt].first + 1;
            pt = pr;
            d[w][ds[w]++] = mp(last, sum);
            //            d[w].pb(mp(last, sum));
            if(last > A) break;
        }
    }
    
    ll get(int t) {
        if(zero)return hget(def[w], def[w] + defs[w], t-t0);
        // if(zero) return lin[w][t-t0];
        else return hget(d[w], d[w] + ds[w], t-t0);
        //        if(zero) return hget(def[w], t-t0);
        //        else return hget(d[w], t-t0);
    }
    
    void remake(int t, ll h) {
        if(zero) forn(i,l,r+1) a[i] = 0;
        forn(i,l,r+1) {
            a[i] = min((ll)c[i], a[i] + ll(t-t0)*rest[i]);
            ll tk = min((ll)a[i], h);
            h-=tk;
            a[i] -= tk;
        }
        zero = 0;
        build_custom();
        t0 = t;
    }
};

ccomp comp[C];


int cnum = 0;

int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int n;
    //    read(n);
    cin>>n;
    forn(i,0,n) {
        
        // c[i] = 1+gen()%ll(1e9);
        // rest[i] = 1+gen()%c[i];
        cin>>c[i]>>rest[i];
        //        scanf("%d %d", &c[i], &rest[i]);
        //        a[i] = c[i];
    }
    for(int s = 0; s < n; s += B) {
        comp[cnum].l = s;
        comp[cnum].r = min(s+B-1, n-1);
        comp[cnum].w = cnum;
        cnum++;
    }
    forn(it,0,cnum) {
        comp[it].build_custom();
        defs[it] = ds[it];
        forn(i,0,ds[it]) def[it][i] = d[it][i];
        // dix(it);
        //        def[it] = d[it];
    }
    forn(i,0,n) a[i] = c[i];
    forn(it,0,cnum) comp[it].build_custom();
    int q;
    //    read(q);
    cin>>q;
    ll ans = 0;
    int curt = 1;
    // exit(0);
    while(q--) {
        int t;
        ll h;
        // t = curt++;
        // h = 1e10;
        // h = gen()%ll(1e12);
        cin>>t>>h;
        forn(it,0,cnum) {
            ll can = comp[it].get(t);
            if(can <= h) {
                h -= can;
                comp[it].zero = 1;
                comp[it].t0 = t;
            }
            else if(h>0) {
                comp[it].remake(t, h);
                h=0;
                break;
            }
        }
        ans += h;
    }
    cout<<ans;
}