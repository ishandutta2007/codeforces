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

const int A = 10000;
bitset<A> full;
bitset<A> mask[17][31][16];
ll res[4];
int has[101];
const int md0 = 1754804011;
const int md1 = 1249792339;
const int md2 = 1787394631;
const int md3 = 588153930;
int ap[A][4];

int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    const int N = 100;
    vi mindiv(N+1, 0);
    vector<ll> pr;
    vi isp(N+1, 0);
    
    for (int i=2; i<=N; ++i) {
        if (mindiv[i] == 0) {
            mindiv[i] = i;
            pr.push_back (i);
            isp[i] = 1;
        }
        for (int j=0; j<(int)pr.size() && pr[j]<=mindiv[i] && i*pr[j]<=N; ++j)
            mindiv[i * pr[j]] = pr[j];
    }
    int pt = 0;
    reverse(all(pr));
    vll mmd;
    vvi cp;
    while(pt<pr.size()) {
        int done = 0;
        forn(i,0,mmd.size()) if(mmd[i] * pr[pt] < 2e9) {
            done = 1;
            cp[i].pb(pr[pt]);
            mmd[i] *= pr[pt++];
            break;
        }
        if(done == 0) {
            cp.pb(vi(1, pr[pt]));
            mmd.pb(pr[pt++]);
        }
    }
    int n;
    cin>>n;
    forn(i,0,n) full[i] = 1;
    vll a(n);
    forn(i,0,n) cin>>a[i];
    forn(i,0,n) {
        ap[i][0] = a[i]%md0;
        ap[i][1] = a[i]%md1;
        ap[i][2] = a[i]%md2;
        ap[i][3] = a[i]%md3;
    }
    forn(i,0,n) {
        forn(d,2,17) {
            ll m = i;
            forn(pos,0,30) {
                int cur = m%d;
                m/=d;
                mask[d][pos][cur][i] = 1;
            }
            if(m == 0) mask[d][30][0][i] = 1;
        }
    }
    int q;
    cin>>q;
    srt(pr);
//    forn(j,0,4) cout<<md[j]<<'\n';
    while(q--) {
        int d;
        ll c;
        string s;
        cin>>d>>s>>c;
        reverse(all(s));
        while(s.size() < 31) s.pb('0');
        bitset<A> cur = full;
        forn(pos,0,31) if(s[pos] != '?') {
            int dig;
            if(s[pos] >= 'A' && s[pos] <= 'F') {
                dig = (s[pos]-'A')+10;
            }
            else dig = s[pos]-'0';
            cur &= mask[d][pos][dig];
        }
        forn(i,0,4) res[i] = 1;
#ifdef LOCAL
        forn(i,0,n) if(cur[i]) {
#else
        for (int i = cur._Find_first();
             i < cur.size();
             i = cur._Find_next(i)) {
#endif
            res[0] = res[0]*ap[i][0]%md0;
            res[1] = res[1]*ap[i][1]%md1;
            res[2] = res[2]*ap[i][2]%md2;
            res[3] = res[3]*ap[i][3]%md3;
        }
        forn(j,0,4) res[j] += c;
        forn(j,0,4) {
            for(auto p : cp[j]) if(res[j]%p == 0) has[p] = 1;
        }
        int ans = -1;
        for(auto x : pr) if(has[x]) {
            ans = x;
            break;
        }
        printf("%d\n", ans);
        for(auto x : pr) has[x] = 0;
    }
    
    
}