#include <bits/stdc++.h>

using namespace std;

#define u_map unordered_map
#define u_set unordered_set
#define u_multiset unordered_multiset

using ll = long long;
using vvi = vector<vector<int>>;
using vi = vector<int>;
using vvll = vector<vector<long long>>;
using vll = vector<long long>;
using vd = vector<double>;
using vvd = vector<vector<double>>;
using pii = pair<int, int>;
using vpii = vector<pair<int, int>>;

template<typename C> struct rge{C l, r;};
template<typename C> rge<C> range(C i, C j) { return rge<C>{i, j}; }
template<typename C> ostream& operator<<(ostream &os, rge<C> &r) { os << '{'; for(auto it = r.l; it != r.r; it++) os << "," + (it == r.l) << *it; os << '}'; return os; }
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '{' << p.first << "," << p.second << '}'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ","; return os << '}'; }
void dbg_out() { cerr << ']' << endl; }
template<typename A> void dbg_out(A H) { cerr << H; dbg_out(); }
template<typename A, typename B, typename... C> void dbg_out(A H, B G, C... T) { cerr << H << ","; dbg_out(G, T...); }
#ifdef DEBUG
#define debug(...) cerr << "[" << #__VA_ARGS__ << "] = [", dbg_out(__VA_ARGS__)
#else
#define debug(...)
#endif

// source: Atcoder Library https://github.com/atcoder/ac-library/blob/master/atcoder/lazysegtree.hpp
// docs: https://atcoder.github.io/ac-library/production/document_en/lazysegtree.html
namespace atcoder{

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
    explicit lazy_segtree(const std::vector<S>& v) : _n(int(v.size())) {
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
        debug("apply", l, r, f);
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

}

vvi factors; // (n)

void setup(int n){
    factors.resize(n+1);
    for(int i = 1; i <= n; i++){
        for(int j = 1; j * j <= i; j++){
            if(i % j == 0){
                factors[i].push_back(j);
            }
        }
        int last = factors[i][factors[i].size()-1];
        int start = factors[i].size() - 1 - (last * last == i ? 1 : 0);
        for(int j = start; j >= 0; j--){
            factors[i].push_back(i / factors[i][j]);
        }
    }
    // debug(factors);
}

// range add affine range sum
namespace sfuncs{
    struct S{
        int sz;
        ll grad;
        ll inter;
        S(int sz, ll grad, ll inter) : sz(sz), grad(grad), inter(inter) {}
        ll eval(ll x) {return inter + grad * x;}
    };
    ostream& operator<<(ostream &os, S &s) { return os << '{' << s.sz << ',' << s.grad << ',' << s.inter << '}'; }
    S op(S a, S b){
        return S(a.sz + b.sz, a.grad + b.grad, a.inter+b.inter);
    }
    S e(){
        return S(0, 0, 0);
    }
    struct F{
        ll grad;
        ll inter;
        F(ll grad, ll inter) : grad(grad), inter(inter) {}
    };
    ostream& operator<<(ostream &os, F &f) { return os << '{' << f.grad << ',' << f.inter << '}'; }
    S mapping(F f, S x){
        return S(x.sz, x.grad + f.grad * x.sz, x.inter + f.inter * x.sz);
    }

    F composition(F f, F g) { return F(f.grad + g.grad, f.inter + g.inter); }
    F id() { return F(0, 0); }
}

struct Query{
    int l, r, idx;
    Query(int l, int r, int idx) : l(l), r(r), idx(idx) {}
};

#define last(v) (v[v.size()-1])

void solve(){
    int n, q;
    cin >> n >> q;
    setup(n);
    vi v(n);
    vi pos(n+1, -100);
    for(int i = 0; i < n; i++){
        cin >> v[i];
        pos[v[i]] = i;
    }

    // sorted by r
    vector<vector<Query>> queries(n+1);
    for(int i = 0; i < q; i++){
        int l, r;
        cin >> l >> r;
        l--;
        queries[r].push_back(Query(l, r, i));
    }
    vll ans(q);

    vector<sfuncs::S> init(n, sfuncs::S(1, 0, 0));
    atcoder::lazy_segtree<sfuncs::S, sfuncs::op, sfuncs::e, sfuncs::F, sfuncs::mapping, sfuncs::composition, sfuncs::id> tree(init);

    vi maxima; // stack of positions
    vi leftmost_zero; // on or before maxima[i]
    for(int r = 1; r <= n; r++){
        debug(r);
        // consider intervals [l..r)
        // will push r-1 after everything
        int new_val = v[r-1];
        while(!maxima.empty() && v[last(maxima)] < new_val){
            maxima.pop_back();
            int seg_start = maxima.empty() ? 0 : last(maxima) + 1;
            tree.apply(seg_start, last(leftmost_zero), sfuncs::F(-1, r-1)); // set to 0
            leftmost_zero.pop_back();
        }
        debug(maxima, leftmost_zero);
        // update maxima before r
        for(int mult = 1; mult * new_val <= n; mult++){
            if(mult == new_val) continue;
            int cand_max = mult * new_val;
            if(pos[mult] >= r || pos[cand_max] >= r) continue;
            int cand_max_pos = lower_bound(maxima.begin(), maxima.end(), pos[cand_max]) - maxima.begin(); // O(nlog^2) - maybe optimize?
            if(cand_max_pos < maxima.size() && maxima[cand_max_pos] == pos[cand_max]){
                int mult_pos = lower_bound(maxima.begin(), maxima.end(), pos[mult]) - maxima.begin();
                debug(mult, mult_pos, cand_max_pos);
                if(mult_pos >= cand_max_pos){
                    // int seg_start = mult_pos == 0 ? 0 : maxima[mult_pos - 1] + 1;
                    int position = min(pos[mult], pos[cand_max]);
                    if(position + 1 > leftmost_zero[cand_max_pos]){
                        tree.apply(leftmost_zero[cand_max_pos], position + 1, sfuncs::F(1, -(r-1))); // set to 1
                        leftmost_zero[cand_max_pos] = position + 1;
                    }
                }
            }
        }
        // update rightmost segment
        int seg_start = maxima.size() == 0 ? 0 : last(maxima) + 1;
        int rightmost = seg_start - 1;
        for(int _fl = 0, _fr = factors[new_val].size() - 1; _fl < _fr; _fl++, _fr--){
            int fl = pos[factors[new_val][_fl]];
            int fr = pos[factors[new_val][_fr]];
            if(seg_start <= fl && fl < r && seg_start <= fr && fr < r){
                rightmost = max(rightmost, min(fl, fr));
            }
        }
        tree.apply(seg_start, rightmost + 1, sfuncs::F(1, -(r-1))); // set to 1

        maxima.push_back(r-1);
        leftmost_zero.push_back(rightmost + 1);

        for(Query query : queries[r]){
            ans[query.idx] = tree.prod(query.l, query.r).eval(r);
        }
    }

    for(ll i : ans) cout << i << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}