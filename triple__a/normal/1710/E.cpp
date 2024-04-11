// #pragma comment(linker, "/STACK:102400000,102400000")
#pragma GCC optimize("O3")
#pragma GCC optimize("O2")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx")
#pragma GCC optimize("trapv")
#include<bits/stdc++.h>
// #include <bits/extc++.h>
#define int long long
#define double long double
// #define i128 long long
// #define double long double
using namespace std;
 
#define rep(i,n) for (int i=0;i<(int)(n);++i)
#define rep1(i,n) for (int i=1;i<=(int)(n);++i)
#define range(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define pb push_back
#define F first
#define S second
 
typedef long long ll;
typedef unsigned long long ull;
// typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;
 
int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};
const int mod=998244353;
const double EPS=1e-9;
const double pi=acos(-1);
const int INF=1e18;
const int N=500007;
mt19937 rng(1235);


namespace internal {

// @param n `0 <= n`
// @return minimum non-negative `x` s.t. `n <= 2**x`
int ceil_pow2(int n) {
    int x = 0;
    while ((1U << x) < (unsigned int)(n)) x++;
    return x;
}

// @param n `1 <= n`
// @return minimum non-negative `x` s.t. `(n & (1 << x)) != 0`
constexpr int bsf_constexpr(unsigned int n) {
    int x = 0;
    while (!(n & (1 << x))) x++;
    return x;
}

// @param n `1 <= n`
// @return minimum non-negative `x` s.t. `(n & (1 << x)) != 0`
int bsf(unsigned int n) {
#ifdef _MSC_VER
    unsigned long index;
    _BitScanForward(&index, n);
    return index;
#else
    return __builtin_ctz(n);
#endif
}

}  // namespace internal

template <class S,
          S (*op)(S, S),
          S (*e)(),
          class F,
          S (*mapping)(F, S),
          F (*composition)(F, F),
          F (*id)()>
struct lazy_segtree {
  public:
    lazy_segtree() : lazy_segtree(0) {}
    explicit lazy_segtree(int n) : lazy_segtree(std::vector<S>(n, e())) {}
    explicit lazy_segtree(const std::vector<S>& v) : _n((int)(v.size())) {
        log = internal::ceil_pow2(_n);
        size = 1 << log;
        d = std::vector<S>(2 * size, e());
        lz = std::vector<F>(size, id());
        for (int i = 0; i < _n; i++) d[size + i] = v[i];
        for (int i = size - 1; i >= 1; i--) {
            update(i);
        }
    }

    void set(int p, S x) {
        assert(0 <= p && p < _n);
        p += size;
        for (int i = log; i >= 1; i--) push(p >> i);
        d[p] = x;
        for (int i = 1; i <= log; i++) update(p >> i);
    }

    S get(int p) {
        assert(0 <= p && p < _n);
        p += size;
        for (int i = log; i >= 1; i--) push(p >> i);
        return d[p];
    }

    S prod(int l, int r) {
        assert(0 <= l && l <= r && r <= _n);
        if (l == r) return e();

        l += size;
        r += size;

        for (int i = log; i >= 1; i--) {
            if (((l >> i) << i) != l) push(l >> i);
            if (((r >> i) << i) != r) push((r - 1) >> i);
        }

        S sml = e(), smr = e();
        while (l < r) {
            if (l & 1) sml = op(sml, d[l++]);
            if (r & 1) smr = op(d[--r], smr);
            l >>= 1;
            r >>= 1;
        }

        return op(sml, smr);
    }

    S all_prod() { return d[1]; }

    void apply(int p, F f) {
        assert(0 <= p && p < _n);
        p += size;
        for (int i = log; i >= 1; i--) push(p >> i);
        d[p] = mapping(f, d[p]);
        for (int i = 1; i <= log; i++) update(p >> i);
    }
    void apply(int l, int r, F f) {
        assert(0 <= l && l <= r && r <= _n);
        if (l == r) return;

        l += size;
        r += size;

        for (int i = log; i >= 1; i--) {
            if (((l >> i) << i) != l) push(l >> i);
            if (((r >> i) << i) != r) push((r - 1) >> i);
        }

        {
            int l2 = l, r2 = r;
            while (l < r) {
                if (l & 1) all_apply(l++, f);
                if (r & 1) all_apply(--r, f);
                l >>= 1;
                r >>= 1;
            }
            l = l2;
            r = r2;
        }

        for (int i = 1; i <= log; i++) {
            if (((l >> i) << i) != l) update(l >> i);
            if (((r >> i) << i) != r) update((r - 1) >> i);
        }
    }

    template <bool (*g)(S)> int max_right(int l) {
        return max_right(l, [](S x) { return g(x); });
    }
    template <class G> int max_right(int l, G g) {
        assert(0 <= l && l <= _n);
        assert(g(e()));
        if (l == _n) return _n;
        l += size;
        for (int i = log; i >= 1; i--) push(l >> i);
        S sm = e();
        do {
            while (l % 2 == 0) l >>= 1;
            if (!g(op(sm, d[l]))) {
                while (l < size) {
                    push(l);
                    l = (2 * l);
                    if (g(op(sm, d[l]))) {
                        sm = op(sm, d[l]);
                        l++;
                    }
                }
                return l - size;
            }
            sm = op(sm, d[l]);
            l++;
        } while ((l & -l) != l);
        return _n;
    }

    template <bool (*g)(S)> int min_left(int r) {
        return min_left(r, [](S x) { return g(x); });
    }
    template <class G> int min_left(int r, G g) {
        assert(0 <= r && r <= _n);
        assert(g(e()));
        if (r == 0) return 0;
        r += size;
        for (int i = log; i >= 1; i--) push((r - 1) >> i);
        S sm = e();
        do {
            r--;
            while (r > 1 && (r % 2)) r >>= 1;
            if (!g(op(d[r], sm))) {
                while (r < size) {
                    push(r);
                    r = (2 * r + 1);
                    if (g(op(d[r], sm))) {
                        sm = op(d[r], sm);
                        r--;
                    }
                }
                return r + 1 - size;
            }
            sm = op(d[r], sm);
        } while ((r & -r) != r);
        return 0;
    }

  private:
    int _n, size, log;
    std::vector<S> d;
    std::vector<F> lz;

    void update(int k) { d[k] = op(d[2 * k], d[2 * k + 1]); }
    void all_apply(int k, F f) {
        d[k] = mapping(f, d[k]);
        if (k < size) lz[k] = composition(f, lz[k]);
    }
    void push(int k) {
        all_apply(2 * k, lz[k]);
        all_apply(2 * k + 1, lz[k]);
        lz[k] = id();
    }
};

using S=int;
using F=int;
S op(S l,S r){return max(l,r);}
S e(){return -INF;}
S mapping(F l,S r){return l+r;}
F composition(F l,F r){return l+r;}
F id(){return 0;}

int n,m;
int a[N],b[N],sx[N],sy[N],px[N],py[N];
bool ok[N];
int tx,ty;
int xsum(int l,int r){return sx[r]-sx[l-1];}
int sum(int x,int y,bool cut)
{
    int res=0;
    if(px[x]<y)
    {
        if(cut)
        {
            if(tx>x && ty>y) res=1;
            if(tx<=x && ty<=y && ty<=px[tx]) res=1;
        }
        int l=py[y];
        return l*y+xsum(l+1,x)+(n-x)*(m-y)-res;
    }
    if(cut)
    {
        if(tx<=x && ty<=y) res=1;
        if(tx>x && ty>y && ty>px[tx]) res=1;
    }
    int r=py[y];
    return x*y+((r-x)*m-xsum(x+1,r))+(n-r)*(m-y)-res;
}
bool check(int x)
{
    px[0]=m;
    for(int i=1;i<=n;i++)
        for(px[i]=px[i-1];px[i] && a[i]+b[px[i]]>x;px[i]--);
    for(int i=1;i<=n;i++) sx[i]=sx[i-1]+px[i];
    py[0]=n;
    for(int i=1;i<=m;i++)
        for(py[i]=py[i-1];py[i] && a[py[i]]+b[i]>x;py[i]--);
    ll a0=max(xsum(1,n),1ll*n*m-xsum(1,n)),a1=max(xsum(1,n)-(ty<=px[tx]),n*m-xsum(1,n)-(ty>px[tx]));
    int p=1;
    for(int i=1;i<=n;i++)
    {
        while(p<m && sum(i,p,0)<=sum(i,p+1,0)) p++;
        a0=max(a0,sum(i,p,0));
    }
    p=1;
    for(int i=1;i<=n;i++)
    {
        while(p<m && sum(i,p,1)<=sum(i,p+1,1)) p++;
        a1=max(a1,sum(i,p,1));
    }
    return a0!=a1+1;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cout.precision(15);
    cin>>n>>m;
    rep1(i,n) cin>>a[i];
    rep1(i,m) cin>>b[i];
    tx=a[1],ty=b[1];
    sort(a+1,a+n+1), sort(b+1,b+m+1);
    tx=lower_bound(a+1,a+n+1,tx)-a, ty=lower_bound(b+1,b+m+1,ty)-b;
    int L=a[1]+b[1],R=a[tx]+b[ty],res=a[tx]+b[ty];
    while(L<=R){
        int mid=(L+R)>>1;
        if(check(mid)) R=mid-1,res=mid;
        else L=mid+1;
    }
    cout<<res<<"\n";
    return 0; 
}
/*
6
4 6 3
12 9 8
3 3 2
8 8
3 3 2
9 5
4 5 2
10 11
5 4 2
9 11
10 10 3
11 45 14

*/