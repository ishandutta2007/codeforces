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

const long long mod = 998244353;
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

ll bet[20][20];
ll dp[1<<18];

ll full[20][20];

int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int d,n,m;
    cin>>d>>n>>m;
    vi a(n);
    forn(i,0,n) cin>>a[i];
    srt(a);
    vi p(m);
    forn(i,0,m) cin>>p[i];
    p.pb(-d-1);
    p.pb(2*d+1);
    srt(p);
    forn(l,0,m+2) forn(r,l+1,m+2) {
        bet[l][r] = 1;
        forn(i,0,n) if(a[i] > p[l] && a[i] < p[r]) {
            int cant = min(a[i]-p[l], p[r]-a[i]);
            cant = min(cant, d+1);
            bet[l][r] = bet[l][r]*cant%mod;
        }
    }
    forn(mask,0,1<<m) {
        vi bad;
        bad.pb(0);
        forn(bit,0,m) if(mask&(1<<bit)) bad.pb(bit+1);
        bad.pb(m+1);
        dp[mask] = 1;
//        if(mask == 15) {
//            forn(i,1,bad.size()) cout<<bet[bad[i-1]][bad[i]]%mod<<'\n';;
//        }
        forn(i,1,bad.size()) dp[mask] = dp[mask]*bet[bad[i-1]][bad[i]]%mod;
    }
    forn(mask,0,1<<m) {
////        if(mask == 17) {
//            cout<<mask<<' '<<dp[mask]<<'\n';
////        }
    }
    forn(bit,0,m) {
        forn(mask,0,1<<m) if((mask&(1<<bit))==0) dp[mask] = (dp[mask] + mod - dp[mask|(1<<bit)])%mod;
    }
    forn(mask,0,1<<m) {
//        cout<<mask<<' '<<dp[mask]<<'\n';
        vi bad;
        forn(bit,0,m) if(mask&(1<<bit)) bad.pb(bit+1);
        if(!bad.empty()) full[bad[0]][bad.back()] = (full[bad[0]][bad.back()] + dp[mask])%mod;
//        if(!bad.empty()) cout<<bad[0]<<' '<<bad.back()<<' '<<dp[mask]<<'\n';
    }
    int q;
    cin>>q;
    ll dd = 1;
    forn(i,0,n+1) dd = dd*(d+1)%mod;
    dd += mod;
    while(q--) {
        int pos;
        cin>>pos;
        ll tot = 0;
        forn(l,1,m+1) forn(r,l,m+1) {
            int cant = max(abs(p[l]-pos), abs(p[r]-pos));
            tot = (tot + cant*full[l][r])%mod;
        }
        cout<< (dd - tot)%mod<<'\n';
    }
    
    
    
}