#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)
#define rep2(i, x, n) for (int i = x; i <= n; i++)
#define rep3(i, x, n) for (int i = x; i >= n; i--)
#define each(e, v) for (auto &e : v)
#define pb push_back
#define eb emplace_back
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define sz(x) (int)x.size()
using ll = long long;
using pii = pair<int, int>;
using pil = pair<int, ll>;
using pli = pair<ll, int>;
using pll = pair<ll, ll>;

template <typename T>
bool chmax(T &x, const T &y) {
    return (x < y) ? (x = y, true) : false;
}

template <typename T>
bool chmin(T &x, const T &y) {
    return (x > y) ? (x = y, true) : false;
}

template <typename T>
int flg(T x, int i) {
    return (x >> i) & 1;
}

template <typename T>
void print(const vector<T> &v, T x = 0) {
    int n = v.size();
    for (int i = 0; i < n; i++) cout << v[i] + x << (i == n - 1 ? '\n' : ' ');
}

template <typename T>
void printn(const vector<T> &v, T x = 0) {
    int n = v.size();
    for (int i = 0; i < n; i++) cout << v[i] + x << '\n';
}

template <typename T>
int lb(const vector<T> &v, T x) {
    return lower_bound(begin(v), end(v), x) - begin(v);
}

template <typename T>
int ub(const vector<T> &v, T x) {
    return upper_bound(begin(v), end(v), x) - begin(v);
}

template <typename T>
void rearrange(vector<T> &v) {
    sort(begin(v), end(v));
    v.erase(unique(begin(v), end(v)), end(v));
}

template <typename T>
vector<int> id_sort(const vector<T> &v, bool greater = false) {
    int n = v.size();
    vector<int> ret(n);
    iota(begin(ret), end(ret), 0);
    sort(begin(ret), end(ret), [&](int i, int j) { return greater ? v[i] > v[j] : v[i] < v[j]; });
    return ret;
}

struct io_setup {
    io_setup() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout << fixed << setprecision(15);
    }
} io_setup;

const int inf = (1 << 30) - 1;
const ll INF = (1LL << 60) - 1;
const int MOD = 1000000007;
// const int MOD = 998244353;

template <typename Monoid, typename Operator_Monoid>
struct Lazy_Segment_Tree {
    using F = function<Monoid(Monoid, Monoid)>;
    using G = function<Monoid(Monoid, Operator_Monoid)>;
    using H = function<Operator_Monoid(Operator_Monoid, Operator_Monoid)>;
    int n, height;
    vector<Monoid> seg;
    vector<Operator_Monoid> lazy;
    const F f;
    const G g;
    const H h;
    const Monoid e1;
    const Operator_Monoid e2;

    // f(f(a,b),c) = f(a,f(b,c)), f(e1,a) = f(a,e1) = a
    // h(h(p,q),r) = h(p,h(q,r)), h(e2,p) = h(p,e2) = p
    // g(f(a,b),p) = f(g(a,p),g(b,p))
    // g(g(a,p),q) = g(a,h(p,q))

    Lazy_Segment_Tree(const vector<Monoid> &v, const F &f, const G &g, const H &h, const Monoid &e1, const Operator_Monoid &e2) : f(f), g(g), h(h), e1(e1), e2(e2) {
        int m = v.size();
        n = 1, height = 0;
        while (n < m) n <<= 1, height++;
        seg.assign(2 * n, e1), lazy.assign(2 * n, e2);
        copy(begin(v), end(v), seg.begin() + n);
        for (int i = n - 1; i > 0; i--) seg[i] = f(seg[2 * i], seg[2 * i + 1]);
    }

    Lazy_Segment_Tree(int m, const Monoid &x, const F &f, const G &g, const H &h, const Monoid &e1, const Operator_Monoid &e2) : f(f), g(g), h(h), e1(e1), e2(e2) {
        n = 1, height = 0;
        while (n < m) n <<= 1, height++;
        seg.assign(2 * n, e1), lazy.assign(2 * n, e2);
        vector<Monoid> v(m, x);
        copy(begin(v), end(v), seg.begin() + n);
        for (int i = n - 1; i > 0; i--) seg[i] = f(seg[2 * i], seg[2 * i + 1]);
    }

    inline Monoid reflect(int i) const { return (lazy[i] == e2 ? seg[i] : g(seg[i], lazy[i])); }

    inline void recalc(int i) {
        while (i >>= 1) seg[i] = f(reflect(2 * i), reflect(2 * i + 1));
    }

    inline void eval(int i) {
        if (i < n && lazy[i] != e2) {
            lazy[2 * i] = h(lazy[2 * i], lazy[i]);
            lazy[2 * i + 1] = h(lazy[2 * i + 1], lazy[i]);
            seg[i] = reflect(i), lazy[i] = e2;
        }
    }

    inline void thrust(int i) {
        for (int j = height; j > 0; j--) eval(i >> j);
    }

    void apply(int l, int r, const Operator_Monoid &x) {
        l = max(l, 0), r = min(r, n);
        if (l >= r) return;
        l += n, r += n;
        thrust(l), thrust(r - 1);
        int a = l, b = r;
        while (l < r) {
            if (l & 1) lazy[l] = h(lazy[l], x), l++;
            if (r & 1) r--, lazy[r] = h(lazy[r], x);
            l >>= 1, r >>= 1;
        }
        recalc(a), recalc(b - 1);
    }

    Monoid query(int l, int r) {
        l = max(l, 0), r = min(r, n);
        if (l >= r) return e1;
        l += n, r += n;
        thrust(l), thrust(r - 1);
        Monoid L = e1, R = e1;
        while (l < r) {
            if (l & 1) L = f(L, reflect(l++));
            if (r & 1) R = f(reflect(--r), R);
            l >>= 1, r >>= 1;
        }
        return f(L, R);
    }

    Monoid operator[](int i) { return query(i, i + 1); }

    template <typename C>
    int find_subtree(int i, const C &check, const Monoid &x, Monoid &M, bool type) {
        while (i < n) {
            eval(i);
            Monoid nxt = type ? f(reflect(2 * i + type), M) : f(M, reflect(2 * i + type));
            if (check(nxt, x)) {
                i = 2 * i + type;
            } else {
                M = nxt, i = 2 * i + (type ^ 1);
            }
        }
        return i - n;
    }

    template <typename C>
    int find_first(int l, const C &check, const Monoid &x) { // check(([l,r]), x)r
        Monoid L = e1;
        int a = l + n, b = n + n;
        thrust(a);
        while (a < b) {
            if (a & 1) {
                Monoid nxt = f(L, reflect(a));
                if (check(nxt, x)) return find_subtree(a, check, x, L, false);
                L = nxt, a++;
            }
            a >>= 1, b >>= 1;
        }
        return n;
    }

    template <typename C>
    int find_last(int r, const C &check, const Monoid &x) { // check(([l,r)), x)l
        Monoid R = e1;
        int a = n, b = r + n;
        thrust(b - 1);
        while (a < b) {
            if (b & 1 || a == 1) {
                Monoid nxt = f(reflect(--b), R);
                if (check(nxt, x)) return find_subtree(b, check, x, R, true);
                R = nxt;
            }
            a >>= 1, b >>= 1;
        }
        return -1;
    }
};

int main() {
    int N, D;
    cin >> N >> D;

    vector<pii> p;
    rep(i, N) {
        int s, a;
        cin >> s >> a;
        chmax(a, D);
        if (s >= D) p.eb(a, s);
    }

    N = sz(p);

    sort(all(p), [](pii a, pii b) {
        if (a.first != b.first) return a.first < b.first;
        return a.second > b.second;
    });

    auto f = [](int a, int b) { return max(a, b); };
    auto g = [](int a, int b) { return a + b; };
    auto h = [](int a, int b) { return a + b; };
    Lazy_Segment_Tree<int, int> seg(N + 1, 0, f, g, h, -inf, 0);

    vector<int> v(N);
    iota(all(v), 0);
    sort(all(v), [&](int i, int j) { return p[i].second < p[j].second; });
    vector<bool> used(N, false);
    int ptr = 0;

    vector<int> a(N);
    rep(i, N) a[i] = p[i].first;
    // rep(i, N) cout << p[i].first << ' ' << p[i].second << '\n';

    rep(i, N) {
        // cout << p[i].first << ' ' << p[i].second << '\n';
        while (ptr < N && p[v[ptr]].second < p[i].first) {
            if (used[v[ptr]]) {
                seg.apply(0, v[ptr] + 1, -1);
                used[v[ptr]] = false;
            }
            ptr++;
        }
        int id = ub(a, p[i].second);
        // cout << id << '\n';
        seg.apply(i + 1, i + 2, seg.query(0, id + 1) + 1);
        if (p[i].second >= p[i].first) {
            seg.apply(0, i + 1, 1);
            used[i] = true;
        }
    }

    cout << seg.query(0, N + 1) << '\n';
}