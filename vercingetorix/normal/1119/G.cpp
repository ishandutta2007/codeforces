#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <ctype.h>
#include <deque>
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
const unsigned gen_seed = std::chrono::system_clock::now().time_since_epoch().count();
std::mt19937_64 gen(gen_seed);

#define all(c) (c).begin(),(c).end()
#define forn(i, a, b) for(int i = a; i < b; i++)
#define read(x) scanf("%d", &x)
#define readv(x, n) vi x(n); forn(i,0,n) scanf("%d", &x[i])
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

#define pb push_back
#define mp make_pair
vi ans;
vvi a;
vi hp;
vi pind;
vi ind2, ind0, ind1;
//int pta;
const int A = 1000500;
int touch[A];
int ptt;
pi last[A];

void reset() {
    forn(i,0,ptt) last[touch[i]] = mp(-1,-1);
    ptt = 0;
}

void go(int il, int ir, int n, int l, int skip = 0) {
//    shuffle(pind.begin()+il, pind.begin()+ir, gen);
    if(l == 1) {
        forn(i,il,ir) {
            ans[i] = hp[pind[i]];
            a[0][i] = pind[i];
        }
        return;
    }
    
    if(l == 0 || n == 0 || il == ir) return;
    int sum = 0;
    
//    if(l >= ir-il && skip == 0)
    while(ll(ir-il)*(n-1) < ll(n)*l || ll(ir-il)*l > ll(n)*l) {
//    while(1) {
        int improve = 0;
        forn(ind,il,ir) {
            int i = pind[ind];
            if(hp[i] <= l) {
                reset();
                int w = il;
                ans[w] = 1;
                swap(pind[il], pind[ind]);
                int left = l;
                while(left>0) {
                    while(hp[pind[il]] == 0) il++;
                    hp[pind[il]]--;
                    left--;
                    a[left][w] = pind[il];
                }
                while(il < ir && hp[pind[il]] == 0) il++;
//                ind--;
                ind = max(il, ind) - 1;
                n--;
                if(n==0) return;
                improve = 1;
                continue;
            }
            if(hp[i] >= n) {
                hp[i] -= n;
                l--;
                forn(j,il,ir) a[l][j] = i;
                if(l == 1) {
                    go(il, ir, n, l);
                    return;
                }
                if(l == 0) return;
                if(hp[i] == 0) {
                    swap(pind[ind], pind[il++]);
                    if(il == ir) return;
                }
                else ind--;
                improve = 1;
            }
//            else i--;
        }
//        if(improve ==0 ) break;
    }
    last[0] = mp(il, 0);
    int pta = il;
    forn(ind,il,ir) {
        int i = pind[ind];
        if(hp[i] <= l) {
            reset();
            ans[pta] = 1;
            swap(pind[il], pind[ind]);
            int left = l;
            while(left>0) {
                while(hp[pind[il]] == 0) il++;
                hp[pind[il]]--;
                left--;
                a[left][pta] = pind[il];
            }
            while(il < ir && hp[pind[il]] == 0) il++;
            go(il, ir, n-1, l);
            return;
        }
        sum += hp[i];
        int sumw = sum%l;
        if(last[sumw].first != -1) {
            int indl = last[sumw].first;
            int sumwas = last[sumw].second;
            int cnt = ind - indl + 1;
            forn(i,0,cnt) if(ind - i >= il + cnt) {
                swap(pind[il+i], pind[ind-i]);
            }
            int suml = sum - sumwas;
            int sumr = n*l-suml;
            reset();
            go(il, il+cnt, suml/l, l);
            go(il+cnt,ir,sumr/l,l,1);
            return;
        }
        else {
            last[sumw] = mp(ind+1, sum);
            touch[ptt++] = sumw;
        }
    }
    go(il,ir,sum,l,0);
    
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    forn(i,0,A) last[i] = mp(-1,-1);
    int n,m;
    cin>>n>>m;
    hp.resize(m);
    forn(i,0,m) cin>>hp[i];
    int sum =0;
    forn(i,0,m) sum+=hp[i];
    if(sum%n != 0) {
        hp[0] += n-sum%n;
        sum += n-sum%n;
    }
    int t = sum/n;
    printf("%d\n", t);
    ans = vi(m, 0);
    a = vvi(t, vi(m,0));
    forn(i,0,m) pind.pb(i);
    
    go(0, m, n, t);
    forn(i,0,m) cout<<ans[i]<<' '; cout<<'\n';
    forn(i,0,t) {
        forn(j,0,m) cout<<a[i][j]+1<<' '; cout<<'\n';
    }
    
    
}