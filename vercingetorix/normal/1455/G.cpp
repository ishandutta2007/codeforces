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
    int n,s;
    cin>>n>>s;
    vi tp(n+2,0);
    tp[n+1] = 1;
    vi to(n+2,0);
    vi cost(n+2,0);
    forn(i,1,n+1) {
        string stp;
        cin>>stp;
        if(stp == "set") {
            tp[i] = 2;
            cin>>to[i]>>cost[i];
        }
        else if(stp == "if") cin>>to[i];
        else if(stp == "end") tp[i] = 1;
    }
    to[0] = 0;
    n+=2;
    vi st;
    vi rto(n), lto(n);
    forn(i,0,n) {
        if(tp[i] == 0) st.pb(i);
        else if(tp[i] == 1) {
            int prev = st.back();
            st.pop_back();
            rto[prev] = i;
            lto[i] = prev;
        }
    }
    vector<map<int, ll>> a(n);
    vector<multiset<ll>> aac(n);
    vector<ll> aadd(n,0);
    for(int i = n-1; i>=0; i--) if(tp[i] == 0) {
//        map<int, ll> cur;
        auto & cur = a[i];
        auto & add = aadd[i];
        auto & ac = aac[i];
        ac.insert(0);
        cur[to[i]] = 0;
        int pos = i+1;
        while(pos < rto[i]) {
            if(tp[pos] == 2) {
                add += cost[pos];
                if(to[pos] != s) {
                    ll best = *ac.begin()+add;
                    if(cur.count(to[pos])) {
                        ac.erase(ac.find(cur[to[pos]]));
                        cur[to[pos]] = min(cur[to[pos]], best - add - cost[pos]);
                    }
                    else cur[to[pos]] = best - add - cost[pos];
                    ac.insert(cur[to[pos]]);
                }
                pos++;
            }
            else if(tp[pos] == 0) {
                if(cur.count(to[pos])) {
                    ll was = cur[to[pos]];
                    ac.erase(ac.find(cur[to[pos]]));
                    cur.erase(to[pos]);
                    if(a[pos].size() < cur.size()) {
                        for(auto x : a[pos]) {
                            if(cur.count(x.first)) {
                                ac.erase(ac.find(cur[x.first]));
                                cur[x.first] = min(cur[x.first], x.second+aadd[pos]+was);
                            }
                            else cur[x.first] = x.second + aadd[pos] + was;
                            ac.insert(cur[x.first]);
                        }
                    }
                    else {
                        aadd[pos] += was + aadd[i];
                        for(auto x : cur) {
                            if(a[pos].count(x.first)) {
                                aac[pos].erase(aac[pos].find(a[pos][x.first]));
                                a[pos][x.first] = min(a[pos][x.first], x.second - aadd[pos] + aadd[i]);
                            }
                            else a[pos][x.first] = x.second - aadd[pos] + aadd[i];
                            aac[pos].insert(a[pos][x.first]);
                        }
                        swap(aadd[pos], aadd[i]);
                        swap(a[pos], a[i]);
                        swap(aac[pos], aac[i]);
                    }
                }
                pos = rto[pos] + 1;
            }
        }
//        for(auto x : cur) a[i][x.first] = x.second+add;
        if(i == 0) cout<<*ac.begin()+add;
    }
    
    
    
}