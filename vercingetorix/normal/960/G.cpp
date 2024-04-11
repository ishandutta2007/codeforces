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
    
    vector<int> multiply(vector<int> &a, vector<int> &b) {
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
        vector<int> res(need);
        for (int i = 0; i < need; i++) {
            res[i] = fa[i].x + 0.5;
        }
        return res;
    }
    
    vector<int> multiply_mod(vector<int> &a, vector<int> &b, int m, int eq = 0) {
        int need = a.size() + b.size() - 1;
        int nbase = 0;
        while ((1 << nbase) < need) nbase++;
        ensure_base(nbase);
        int sz = 1 << nbase;
        if (sz > (int) fa.size()) {
            fa.resize(sz);
        }
        for (int i = 0; i < (int) a.size(); i++) {
            int x = (a[i] % m + m) % m;
            fa[i] = num(x & ((1 << 15) - 1), x >> 15);
        }
        fill(fa.begin() + a.size(), fa.begin() + sz, num {0, 0});
        fft(fa, sz);
        if (sz > (int) fb.size()) {
            fb.resize(sz);
        }
        if (eq) {
            copy(fa.begin(), fa.begin() + sz, fb.begin());
        } else {
            for (int i = 0; i < (int) b.size(); i++) {
                int x = (b[i] % m + m) % m;
                fb[i] = num(x & ((1 << 15) - 1), x >> 15);
            }
            fill(fb.begin() + b.size(), fb.begin() + sz, num {0, 0});
            fft(fb, sz);
        }
        dbl ratio = 0.25 / sz;
        num r2(0, -1);
        num r3(ratio, 0);
        num r4(0, -ratio);
        num r5(0, 1);
        for (int i = 0; i <= (sz >> 1); i++) {
            int j = (sz - i) & (sz - 1);
            num a1 = (fa[i] + conj(fa[j]));
            num a2 = (fa[i] - conj(fa[j])) * r2;
            num b1 = (fb[i] + conj(fb[j])) * r3;
            num b2 = (fb[i] - conj(fb[j])) * r4;
            if (i != j) {
                num c1 = (fa[j] + conj(fa[i]));
                num c2 = (fa[j] - conj(fa[i])) * r2;
                num d1 = (fb[j] + conj(fb[i])) * r3;
                num d2 = (fb[j] - conj(fb[i])) * r4;
                fa[i] = c1 * d1 + c2 * d2 * r5;
                fb[i] = c1 * d2 + c2 * d1;
            }
            fa[j] = a1 * b1 + a2 * b2 * r5;
            fb[j] = a1 * b2 + a2 * b1;
        }
        fft(fa, sz);
        fft(fb, sz);
        vector<int> res(need);
        for (int i = 0; i < need; i++) {
            long long aa = fa[i].x + 0.5;
            long long bb = fb[i].x + 0.5;
            long long cc = fa[i].y + 0.5;
            res[i] = (aa + ((bb % m) << 15) + ((cc % m) << 30)) % m;
        }
        return res;
    }
    
    vector<int> square_mod(vector<int> &a, int m) {
        return multiply_mod(a, a, m, 1);
    }
};

class streefft {
public:
    vvi t;
    int s;
    void build (const vi & a, int v, int tl, int tr) {
        if(v==1) {
            t.resize(a.size() * 4);
        }
        if (tl == tr) {
            t[v] = vi({1,a[tl]});
        }
        else {
            int tm = (tl + tr) / 2;
            build (a, v*2, tl, tm);
            build (a, v*2+1, tm+1, tr);
            t[v] = fft::multiply_mod(t[v*2], t[v*2+1], mod);
        }
    }
};
#ifdef LOCAL
const int A = 100;
#else
const int A = 200500;
#endif
ll nfac[A];
ll ifac[A];
ll imod[A];

ll gcd (ll a, ll b, ll & x, ll & y) {
    if (a == 0) {
        x = 0; y = 1;
        return b;
    }
    ll x1, y1;
    ll d = gcd (b%a, a, x1, y1);
    x = y1 - (b / a) * x1;
    y = x1;
    return d;
}

ll invmod(ll a, ll modulo) {
    ll x, y;
    ll g = gcd (a, modulo, x, y);
    if (g != 1)
    {
        return -1;
    }
    else {
        x = (x % modulo + modulo) % modulo;
        return x;
    }
}

void initfac() {
    nfac[0] = 1;
    forn(i,1,A) nfac[i] = nfac[i-1]*i%mod;
    ifac[A-1] = invmod(nfac[A-1], mod);
    for(int i = A-1; i>=1; i--) ifac[i-1] = ifac[i]*i%mod;
    forn(i,1,A) imod[i] = ifac[i]*nfac[i-1]%mod;
}

int n;

void mulxa(vi & cur, ll a) {
    int mem = 0;
    forn(i,0,cur.size()) {
        swap(cur[i], mem);
        cur[i] = (cur[i]*a + mem)%mod;
    }
    cur.pb(mem*a%mod);
}

vll get(int k) {
    vll ret(n+2, 0);
    if(k == -1) return ret;
    if(k==0) {
        ret[0] = 1;
        return ret;
    }
    if(k==1) {
        forn(l,1,n) ret[l] = nfac[l-1];
        return ret;
    }
    vi a;
    forn(i,1,k) a.pb(imod[i]);
    streefft f;
    f.build(a, 1, 0, k-2);
    vi cur = f.t[1];
    int curn = k;
    ret[k] = 1;
    while(curn<n) {
        if(k<505) {
            mulxa(cur, imod[curn]);
            cur.pop_back();
            ret[curn+1] = cur.back()*nfac[curn]%mod;
            curn++;
            continue;
        }
        int st = min(n-curn, 500);
        vi curend;
        forn(i,k-st-3,k) curend.pb(cur[i]);
        vi nw(1,1);
        forn(i,curn,curn+st) {
            mulxa(curend, imod[i]);
            mulxa(nw, imod[i]);
            curend.pop_back();
            ret[i+1] = curend.back()*nfac[i]%mod;
        }
        cur = fft::multiply_mod(cur, nw, mod);
        forn(i,0,st) cur.pop_back();
        curn+=st;
    }
    return ret;
}

int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    initfac();
    int a,b;
    cin>>n>>a>>b;
    vll ra = get(a-1);
    vll rb = get(b-1);
    ll ans = 0;
    forn(l,0,n) {
        int r = n-1-l;
        ans += ra[l]*rb[r]%mod * nfac[n-1]%mod*ifac[l]%mod*ifac[r]%mod;
    }
    cout<<ans%mod;
    
}