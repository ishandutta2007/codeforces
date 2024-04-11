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
#define readv(x, n) vi x(n); forn(i,0,n) scanf("%d", &a[i])

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
vi sx,sy;

long long gcd(long long a, long long b){
    if(a==0) return b;
    if(b==0) return a;
    if(a>b) return gcd(b, a%b);
    return gcd(a,b%a);
}

bool comp(pll x, pll y) {
    return x.first*y.second < x.second*y.first;
}
int t[2000000];
class stree {
public:
    int s;
    void build (int v, int tl, int tr) {
        if (tl == tr)
            t[v] = -1;
        else {
            int tm = (tl + tr) / 2;
            build (v*2, tl, tm);
            build (v*2+1, tm+1, tr);
            t[v] = -1;
        }
    }
    
    void set (int v, int tl, int tr, int pos, int val) {
        if (pos == tl && tr == pos) {
            t[v] = val;
        }
        else {
            int tm = (tl + tr) / 2;
            if(pos<=tm) set(v*2, tl, tm, pos, val);
            else set(v*2+1, tm+1, tr, pos, val);
            t[v] = max(t[v*2], t[v*2+1]);
        }
    }
    
    int get (int v, int tl, int tr, int l, int r) {
        if(l>r) return -1;
        if (tl == l && tr == r)
            return t[v];
        int tm = (tl + tr) / 2;
        return max(get (v*2, tl, tm, l, min(r,tm)), get(v*2+1, tm+1, tr, max(l,tm+1), r));
    }
};


const int N = 500000;  // limit for array size
int cl = 0;
//int t[2 * N];
stree st;
void build() {  // build the tree
    st.build(1, 0, cl-1);
    //    forn(i,0,2*N) t[i] = -1;
}

void modify(int p, int value) {  // set value at position p
    st.set(1, 0, cl-1, p, value);
    //    for (t[p += cl] = value; p > 1; p >>= 1) t[p>>1] = max(t[p], t[p^1]);
}

int get(int l, int r) {  // sum on interval [l, r)
    return st.get(1, 0, cl-1, l, r);
    //    int res = -1;
    //    for (l += cl, r += cl; l < r; l >>= 1, r >>= 1) {
    //        if (l&1) res = max(res,t[l++]);
    //        if (r&1) res = max(res,t[--r]);
    //    }
    //    return res;
}

set<int> bestl[500000];
//set<int> bestr[500000];
const int INF = 1e9;

//stree st;
int cr = 0;
void add(int il, int ir, bool real) {
    int mx = max(-*bestl[il].begin(), ir);
    if(real) bestl[il].insert(-ir);
    //    int mx = -*bestl[il].begin();
    //    st.set(1, 0, cl-1, il, mx);
    modify(il, mx);
}
void rem(int il, int ir, bool real) {
    auto it = bestl[il].begin();
    if(*it == -ir) it++;
    if(real) bestl[il].erase(-ir);
    int mx = -*it;
    //    st.set(1, 0, cl-1, il, mx);
    modify(il, mx);
}

void rem2(int il, int ir1, int ir2) {
    auto it = bestl[il].begin();
    if(*it == -ir2) {
        it++;
        if(*it == -ir1) it++;
    }
    //    st.set(1, 0, cl-1, il, -*it);
    modify(il, -*it);
}

void add2(int il, int ir1, int ir2) {
    int mx = max(-*bestl[il].begin(), ir2);
    //    st.set(1, 0, cl-1, il, mx);
    modify(il, mx);
}


int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int r,n;
    cin>>r>>n;
    vi q(n), x(n), y(n);
    vll xl,xr,yl,yr;
    vpll pl, pr;
    forn(i,0,n) {
        cin>>q[i];
        if(q[i] == 1) {
            cin>>x[i]>>y[i];
            sx.pb(x[i]); sy.pb(y[i]);
            int dl = gcd(y[i], abs(x[i]+r));
            int dr = gcd(y[i], abs(x[i]-r));
            pl.pb(mp((x[i]+r)/dl, y[i]/dl));
            pr.pb(mp((x[i]-r)/dr, y[i]/dr));
        }
        else if(q[i] == 2) cin>>x[i];
        else if(q[i] == 3) cin>>x[i]>>y[i];
    }
    vpll plwas = pl;
    vpll prwas = pr;
    sort(all(pl), comp);
    sort(all(pr), comp);
    map<pll, int> tol,tor;
    
    forn(i,0,pl.size()) if(i==0 || pl[i] != pl[i-1]) tol[pl[i]] = cl++;
    forn(i,0,pr.size()) if(i==0 || pr[i] != pr[i-1]) tor[pr[i]] = cr++;
    
    pl.resize(cl);
    pr.resize(cr);
    for(auto x : tol) pl[x.second] = x.first;
    for(auto x : tor) pr[x.second] = x.first;
    //    st.build(1, 0, cl-1);
    build();
    vi toli(plwas.size());
    vi tori(plwas.size());
    forn(i,0,plwas.size()) {
        toli[i] = tol[plwas[i]];
        tori[i] = tor[prwas[i]];
    }
    forn(i,0,cl) bestl[i].insert(1);
    //    forn(i,0,cr) bestr[i].insert(INF);
    int c1 = 0;
    forn(i,0,n) {
        if(q[i] == 1) {
            int il = toli[c1];
            int ir = tori[c1];
            c1++;
            add(il, ir, true);
            
        }
        else if(q[i] == 2) {
            int ind = x[i] - 1;
            int il = toli[ind];
            int ir = tori[ind];
            rem(il, ir, true);
        }
        else if(q[i] == 3) {
            int ind1 = x[i] - 1;
            int ind2 = y[i] - 1;
            int il1 = toli[ind1];
            int ir1 = tori[ind1];
            int il2 = toli[ind2];
            int ir2 = tori[ind2];
            int il = max(il1, il2);
            int ir = min(ir1, ir2);
            ll cosval = pl[il].first*pr[ir].first + pl[il].second*pr[ir].second;
            if(cosval < 0) cout<<"NO\n";
            else {
                if(il1 != il2) {
                    rem(il1, ir1, false);
                    rem(il2, ir2, false);
                    //                    if(st.get(1, 0, cl-1, 0, il) >= ir) printf("NO\n");
                    if(get(0, il) >= ir) cout<<"NO\n";
                    else cout<<"YES\n";
                    add(il1, ir1, false);
                    add(il2, ir2, false);
                }
                else {
                    if(ir1>ir2) swap(ir1,ir2);
                    rem2(il1, ir1, ir2);
                    //                    if(st.get(1, 0, cl-1, 0, il) >= ir) printf("NO\n");
                    if(get(0, il) >= ir) cout<<"NO\n";
                    else cout<<"YES\n";
                    add2(il1, ir1, ir2);
                }
            }
        }
    }
    
}