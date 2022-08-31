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
namespace fft {
    typedef double dbl;
    
    struct num {
        dbl x, y;
        num() { x = y = 0; }
        num(dbl x, dbl y) : x(x), y(y) { }
    };
    
    inline num operator+(num a, num b) { return num(a.x + b.x, a.y + b.y); }
    inline num operator-(num a, num b) { return num(a.x - b.x, a.y - b.y); }
    inline num operator*(num a, num b) { return num(a.x * b.x - a.y * b.y, a.x * b.y + a.y * b.x); }
    inline num conj(num a) { return num(a.x, -a.y); }
    
    int base = 1;
    vector<num> roots = {{0, 0}, {1, 0}};
    vector<int> rev = {0, 1};
    
    const dbl PI = acosl(-1.0);
    
    void ensure_base(int nbase) {
        if (nbase <= base) {
            return;
        }
        rev.resize(1 << nbase);
        for (int i = 0; i < (1 << nbase); i++) {
            rev[i] = (rev[i >> 1] >> 1) + ((i & 1) << (nbase - 1));
        }
        roots.resize(1 << nbase);
        while (base < nbase) {
            dbl angle = 2 * PI / (1 << (base + 1));
            //      num z(cos(angle), sin(angle));
            for (int i = 1 << (base - 1); i < (1 << base); i++) {
                roots[i << 1] = roots[i];
                //        roots[(i << 1) + 1] = roots[i] * z;
                dbl angle_i = angle * (2 * i + 1 - (1 << base));
                roots[(i << 1) + 1] = num(cos(angle_i), sin(angle_i));
            }
            base++;
        }
    }
    
    void fft(vector<num> &a, int n = -1) {
        if (n == -1) {
            n = a.size();
        }
        //        assert((n & (n - 1)) == 0);
        int zeros = __builtin_ctz(n);
        ensure_base(zeros);
        int shift = base - zeros;
        for (int i = 0; i < n; i++) {
            if (i < (rev[i] >> shift)) {
                swap(a[i], a[rev[i] >> shift]);
            }
        }
        for (int k = 1; k < n; k <<= 1) {
            for (int i = 0; i < n; i += 2 * k) {
                for (int j = 0; j < k; j++) {
                    num z = a[i + j + k] * roots[j + k];
                    a[i + j + k] = a[i + j] - z;
                    a[i + j] = a[i + j] + z;
                }
            }
        }
        /*    for (int len = 1; len < n; len <<= 1) {
         for (int i = 0; i < n; i += 2 * len) {
         for (int j = i, k = i + len; j < i + len; j++, k++) {
         num z = a[k] * roots[k - i];
         a[k] = a[j] - z;
         a[j] = a[j] + z;
         }
         }
         }*/
    }
    
    vector<num> fa, fb;
    
    vector<ll> multiply(vector<ll> &a, vector<ll> &b) {
        int need = a.size() + b.size() - 1;
        int nbase = 0;
        while ((1 << nbase) < need) nbase++;
        ensure_base(nbase);
        int sz = 1 << nbase;
        if (sz > (int) fa.size()) {
            fa.resize(sz);
        }
        for (int i = 0; i < sz; i++) {
            int x = (i < (int) a.size() ? a[i] : 0);
            int y = (i < (int) b.size() ? b[i] : 0);
            fa[i] = num(x, y);
        }
        fft(fa, sz);
        num r(0, -0.25 / sz);
        for (int i = 0; i <= (sz >> 1); i++) {
            int j = (sz - i) & (sz - 1);
            num z = (fa[j] * fa[j] - conj(fa[i] * fa[i])) * r;
            if (i != j) {
                fa[j] = (fa[i] * fa[i] - conj(fa[j] * fa[j])) * r;
            }
            fa[i] = z;
        }
        fft(fa, sz);
        vector<ll> res(need);
        for (int i = 0; i < need; i++) {
            res[i] = fa[i].x + 0.5;
        }
        return res;
    }
};

void add(vll & to, vll & f) {
    if(f.size() > to.size()) swap(f,to);
    forn(i,0,f.size()) to[i] += f[i];
}

class stree {
public:
    vvll p;
    vvll pl;
    vvll pr;
    
    int s;
    void build (const vi & a, int v, int tl, int tr) {
        if(v==1) {
            p.resize(a.size() * 4);
            pr.resize(a.size() * 4);
            pl.resize(a.size() * 4);
        }
        if (tl == tr) {
            if(a[tl] == 0) {
                p[v] = vll({1});
            }
            else {
                p[v] = vll({0, 1});
            }
            pl[v] = p[v];
            pr[v] = p[v];
        }
        else {
            int tm = (tl + tr) / 2;
            build (a, v*2, tl, tm);
            build (a, v*2+1, tm+1, tr);
            add(p[v], p[v*2]);
            add(p[v], p[v*2+1]);
            vll c = fft::multiply(pr[v*2], pl[v*2+1]);
            add(p[v], c);
            swap(pl[v], pl[v*2]);
            pl[v].back() += pl[v*2+1][0];
            forn(i,1,pl[v*2+1].size()) pl[v].pb(pl[v*2+1][i]);
            
            swap(pr[v], pr[v*2+1]);
            pr[v].back() += pr[v*2][0];
            forn(i,1,pr[v*2].size()) pr[v].pb(pr[v*2][i]);
        }
    }
};


int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int n,x;
    scanf("%d %d", &n, &x);
    readv(a,n);
    forn(i,0,n) if(a[i] < x) a[i] = 1;
    else a[i] = 0;
    stree st;
    st.build(a, 1, 0, n-1);
    while(st.p[1].size() < n+1) st.p[1].pb(0);
    forn(i,0,n+1) printf("%lld ", st.p[1][i]);
    
    
    
}