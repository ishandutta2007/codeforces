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

int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int ta;
    read(ta);
    forn(ifa,0,ta) {
        int m;
        cin>>m;
        int bad = 0;
        vvi ind(4);
        forn(i,0,m) {
            int x;
            cin>>x;
            if(x > 3) bad = 1;
            else ind[x].pb(i);
        }
        if(bad || ind[3].size() > 1 || (ind[3].size() > 0 && ind[2].size() > 0) || ind[2].size() > 2) {
            cout<<"-1\n";
            continue;
        }
        vvi ans;
        int n = 1;
        if(ind[3].size() == 1) {
            n*=4;
            forn(j,0,3) ans.pb(vi(m,0));
            ans[0][ind[3][0]] = 3;
            ans[1][ind[3][0]] = 1;
            ans[2][ind[3][0]] = 2;
        }
        else if(ind[2].size() == 1) {
            n*=3;
            forn(j,0,2) ans.pb(vi(m,0));
            ans[0][ind[2][0]] = 2;
            ans[1][ind[2][0]] = 1;
        }
        else if(ind[2].size() == 2) {
            n*=9;
            forn(j,0,8) ans.pb(vi(m,0));
            int i = ind[2][0];
            int j = ind[2][1];
            ans[0][i] = 2; ans[0][j] = 2;
            ans[1][i] = 1; ans[1][j] = 0;
            ans[2][i] = 2; ans[2][j] = 1;
            ans[3][i] = 0; ans[3][j] = 2;
            ans[4][i] = 1; ans[4][j] = 1;
            ans[5][i] = 2; ans[5][j] = 0;
            ans[6][i] = 1; ans[6][j] = 2;
            ans[7][i] = 0; ans[7][j] = 1;
        }
        else {
            n*=2;
            ans.pb(vi(m,0));
            ans[0][ind[1].back()] = 1;
            ind[1].pop_back();
        }
        auto nod = [&](const vi & a, const vi & b) {
            int ret = 0;
            forn(i,0,m) ret += min(a[i], b[i]);
            return ret;
        };
        while(!ind[1].empty()) {
            int k = ind[1].back();
            ind[1].pop_back();
            int pt = 0;
            while(nod(ans.back(), ans[pt])!=1) pt++;
            vvi nans;
            forn(i,0,pt+1) {
                nans.pb(ans[i]);
                nans.back()[k] = (i+pt)%2;
            }
            for(int i = ans.size() - 1; i>=0; i--) {
                nans.pb(ans[i]);
                nans.back()[k] = (i+pt+1)%2;
            }
            if(nans.back()[k] == 0) reverse(all(nans));
            nans.pb(vi(m,0));
            nans.back()[k] = 1;
            forn(i,pt+1,ans.size()) {
                nans.pb(ans[i]);
                nans.back()[k] = (i+pt)%2;
            }
            swap(ans,nans);
            n*=2;
        }
        
        forn(i,0,n-1) {
            forn(j,0,m) cout<<ans[i][j]<<' ';
            cout<<'\n';
        }

        
    }
    
    
}