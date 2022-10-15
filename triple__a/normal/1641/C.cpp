// #pragma comment(linker, "/STACK:102400000,102400000")
#pragma GCC optimize("O3")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx")
// #pragma GCC optimize("trapv")
#include<bits/stdc++.h>
 
// #define int long long
#define double long double
using namespace std;


// namespace std {
 
// template<class Fun>
// class y_combinator_result {
// 	Fun fun_;
// public:
// 	template<class T>
// 	explicit y_combinator_result(T &&fun): fun_(std::forward<T>(fun)) {}
 
// 	template<class ...Args>
// 	decltype(auto) operator()(Args &&...args) {
// 		return fun_(std::ref(*this), std::forward<Args>(args)...);
// 	}
// };
 
// template<class Fun>
// decltype(auto) y_combinator(Fun &&fun) {
// 	return y_combinator_result<std::decay_t<Fun>>(std::forward<Fun>(fun));
// }
 
// } // namespace std
 
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
 
int dx[]={0,1,0,-1,1,-1};
int dy[]={1,0,-1,0,1,-1};
// const int mod=998244353;
const int INF=LLONG_MAX/4;
const double EPS=1e-9;
const int N=200007;
const int K=10;

mt19937 rng(1234);


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
    lazy_segtree(int n) : lazy_segtree(std::vector<S>(n, e())) {}
    lazy_segtree(const std::vector<S>& v) : _n(int(v.size())) {
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
            if (((r >> i) << i) != r) push(r >> i);
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

using S=pii;
using F=int;
S op(S l,S r){return make_pair(l.F+r.F,l.S+r.S);}
S e(){return make_pair(0,0);}
F id(){return -1;}
S mapping(F l,S r){
    if (l==-1) return r;
    return make_pair(r.F,r.F*l);
}
F composition(F l,F r){
    if (l==-1) return r;
    return l;
}

using S2=pii;
using F2=int;
S2 op2(S2 l,S2 r){if (l.F<r.F||(l.F==r.F&&l.S<r.S)) return l; else return r;}
S2 e2(){return make_pair((int)(1e9),0);}
F2 id2(){return 0;}
S2 mapping2(F2 l,S2 r){return r;}
F2 composition2(F2 l,F2 r){return 0;}
int n,q;
int cnt[N];
signed main(){
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cout.precision(15), cerr.precision(15);
    cin>>n>>q;
    rep(i,n) cnt[i]=N+7;
    lazy_segtree<S,op,e,F,mapping,composition,id> seg(vector<pii>(N,make_pair(1,0)));
    lazy_segtree<S2,op2,e2,F2,mapping2,composition2,id2> seg2(N);
    while (q--){
        int op,l,r,x;
        cin>>op;
        if (op==0){
            cin>>l>>r>>x;
            l--;
            if (x==0) seg.apply(l,r,1);
            else {
                if (cnt[l]>r) cnt[l]=r, seg2.set(l,{r,l});
            }
        }
        else{
            cin>>x;
            x--;
            if (seg.prod(x,x+1).S==1){
                cout<<"NO\n";
                continue;
            }
            int lb=seg.min_left(x,[&](S g){return g.S==g.F;});
            auto mn=seg2.prod(lb,x+1);
            int posl=mn.S, posr=mn.F;
            if (posl<N&&posr<N&&seg.prod(posl,posr).S==posr-posl-1){
                cout<<"YES\n";
            } 
            else{
                cout<<"N/A\n";
            }
        }
    }
    return 0;
}

/*
0 0 1 1 0 1 
0 0 1 0 1 0
1 1 0 1 0 0
1 0 1 0 0 0
0 1 0 0 0 0
1 0 0 0 0 0
*/