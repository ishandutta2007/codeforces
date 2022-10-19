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
    if (v.empty()) cout << '\n';
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

template <typename S, typename T>
pair<S, T> operator+(const pair<S, T> &p, const pair<S, T> &q) {
    return make_pair(p.first + q.first, p.second + q.second);
}

template <typename S, typename T>
pair<S, T> operator-(const pair<S, T> &p, const pair<S, T> &q) {
    return make_pair(p.first - q.first, p.second - q.second);
}

template <typename S, typename T>
istream &operator>>(istream &is, pair<S, T> &p) {
    S a;
    T b;
    is >> a >> b;
    p = make_pair(a, b);
    return is;
}

template <typename S, typename T>
ostream &operator<<(ostream &os, const pair<S, T> &p) {
    return os << p.first << ' ' << p.second;
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

auto f = [](int a, int b) { return min(a, b); };
auto g = [](int a, int b) { return a + b; };
auto h = [](int a, int b) { return a + b; };
auto c = [](int a, int b) { return a <= b; };

pii solve(const vector<int> &a, int K) {
    int n = sz(a);

    map<int, int> mp;
    vector<int> pr(n + 1, n);
    rep3(i, n - 1, 0) {
        pr[i] = pr[i + 1];
        if (mp.count(a[i])) chmin(pr[i], mp[a[i]]);
        mp[a[i]] = i;
    }

    vector<int> v(n);
    rep(i, n) v[i] = -i;
    Lazy_Segment_Tree<int, int> seg(v, f, g, h, inf, 0);

    int l = -1, r = -1;
    stack<int> s1, s2;
    rep3(i, n - 1, 0) {
        vector<int> v1;
        while (!s1.empty() && a[i] >= a[s1.top()]) {
            v1.eb(s1.top());
            s1.pop();
        }
        v1.eb(s1.empty() ? n : s1.top());
        rep(j, sz(v1) - 1) seg.apply(v1[j], v1[j + 1], a[i] - a[v1[j]]);
        s1.emplace(i);

        vector<int> v2;
        while (!s2.empty() && a[i] <= a[s2.top()]) {
            v2.eb(s2.top());
            s2.pop();
        }
        v2.eb(s2.empty() ? n : s2.top());
        rep(j, sz(v2) - 1) seg.apply(v2[j], v2[j + 1], a[v2[j]] - a[i]);
        s2.emplace(i);

        int j = seg.find_last(pr[i], c, K - i) + 1;
        if (j - i >= r - l) l = i, r = j;
    }

    return pii(l, r);
}

int main() {
    int N, K, D;
    cin >> N >> K >> D;

    vector<int> a(N);
    rep(i, N) {
        cin >> a[i];
        a[i] += 1000000000;
    }

    if (D == 0) {
        int l = -1, r = -1;
        for (int i = 0; i < N;) {
            int j = 0;
            while (i + j < N && a[i + j] == a[i]) j++;
            if (j > r - l) l = i, r = i + j;
            i += j;
        }
        cout << l + 1 << ' ' << r << '\n';
        return 0;
    }

    int l = -1, r = -1;

    for (int i = 0; i < N;) {
        int j = 0;
        while (i + j < N && a[i + j] % D == a[i] % D) j++;
        vector<int> tmp;
        rep(k, j) tmp.eb(a[i + k] / D);
        auto [tl, tr] = solve(tmp, K);
        if (tr - tl > r - l) l = i + tl, r = i + tr;
        i += j;
    }

    cout << l + 1 << ' ' << r << '\n';
}