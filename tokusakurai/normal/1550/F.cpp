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

template <typename Monoid>
struct Segment_Tree {
    using F = function<Monoid(Monoid, Monoid)>;
    int n;
    vector<Monoid> seg;
    const F f;
    const Monoid e1;

    Segment_Tree(const vector<Monoid> &v, const F &f, const Monoid &e1) : f(f), e1(e1) {
        int m = v.size();
        n = 1;
        while (n < m) n <<= 1;
        seg.assign(2 * n, e1);
        copy(begin(v), end(v), begin(seg) + n);
        for (int i = n - 1; i > 0; i--) seg[i] = f(seg[2 * i], seg[2 * i + 1]);
    }

    Segment_Tree(int m, const Monoid &x, const F &f, const Monoid &e1) : f(f), e1(e1) {
        n = 1;
        while (n < m) n <<= 1;
        seg.assign(2 * n, e1);
        vector<Monoid> v(m, x);
        copy(begin(v), end(v), begin(seg) + n);
        for (int i = n - 1; i > 0; i--) seg[i] = f(seg[2 * i], seg[2 * i + 1]);
    }

    void change(int i, const Monoid &x, bool update = true) {
        if (update)
            seg[i + n] = x;
        else
            seg[i + n] = f(seg[i + n], x);
        i += n;
        while (i >>= 1) { seg[i] = f(seg[2 * i], seg[2 * i + 1]); }
    }

    Monoid query(int l, int r) const {
        Monoid L = e1, R = e1;
        l += n, r += n;
        while (l < r) {
            if (l & 1) L = f(L, seg[l++]);
            if (r & 1) R = f(seg[--r], R);
            l >>= 1, r >>= 1;
        }
        return f(L, R);
    }

    Monoid operator[](int i) const { return seg[n + i]; }

    template <typename C>
    int find_subtree(int i, const C &check, const Monoid &x, Monoid &M, bool type) const {
        while (i < n) {
            Monoid nxt = type ? f(seg[2 * i + type], M) : f(M, seg[2 * i + type]);
            if (check(nxt, x))
                i = 2 * i + type;
            else
                M = nxt, i = 2 * i + (type ^ 1);
        }
        return i - n;
    }

    template <typename C>
    int find_first(int l, const C &check, const Monoid &x) const {
        Monoid L = e1;
        int a = l + n, b = n + n;
        while (a < b) {
            if (a & 1) {
                Monoid nxt = f(L, seg[a]);
                if (check(nxt, x)) return find_subtree(a, check, x, L, false);
                L = nxt, a++;
            }
            a >>= 1, b >>= 1;
        }
        return n;
    }

    template <typename C>
    int find_last(int r, const C &check, const Monoid &x) const {
        Monoid R = e1;
        int a = n, b = r + n;
        while (a < b) {
            if (b & 1 || a == 1) {
                Monoid nxt = f(seg[--b], R);
                if (check(nxt, x)) return find_subtree(b, check, x, R, true);
                R = nxt;
            }
            a >>= 1, b >>= 1;
        }
        return -1;
    }
};

struct Union_Find_Tree {
    vector<int> data;
    const int n;
    int cnt;

    Union_Find_Tree(int n) : data(n, -1), n(n), cnt(n) {}

    int root(int x) {
        if (data[x] < 0) return x;
        return data[x] = root(data[x]);
    }

    int operator[](int i) { return root(i); }

    bool unite(int x, int y) {
        x = root(x), y = root(y);
        if (x == y) return false;
        if (data[x] > data[y]) swap(x, y);
        data[x] += data[y], data[y] = x;
        cnt--;
        return true;
    }

    int size(int x) { return -data[root(x)]; }

    int count() { return cnt; };

    bool same(int x, int y) { return root(x) == root(y); }

    void clear() {
        cnt = n;
        fill(begin(data), end(data), -1);
    }
};

int main() {
    int N, Q, s, d;
    cin >> N >> Q >> s >> d;
    s--;

    vector<int> a(N);
    rep(i, N) cin >> a[i];

    vector<int> l(N), r(N);
    rep(i, N) {
        l[i] = lb(a, a[i] - d);
        r[i] = lb(a, a[i] + d);
    }

    vector<tuple<int, int, int>> qs;
    rep(i, Q) {
        int t, k;
        cin >> t >> k;
        t--;
        qs.eb(k, i, t);
    }
    sort(all(qs));

    vector<int> c(N);
    vector<vector<int>> ids(N);
    rep(i, N) {
        c[i] = i;
        ids[i].eb(i);
    }

    auto f1 = [](int a, int b) { return min(a, b); };
    auto f2 = [](int a, int b) { return max(a, b); };
    auto c1 = [](int a, int b) { return a < b; };
    auto c2 = [](int a, int b) { return a > b; };
    Segment_Tree<int> seg1(c, f1, inf), seg2(c, f2, -inf);

    int ptr = 0;
    vector<bool> ans(Q, true);
    vector<tuple<int, int, int>> es;

    while (true) {
        vector<tuple<int, int, int>> memo(N, make_tuple(inf, -1, -1));
        rep(i, N) {
            int l1 = max(seg1.find_last(l[i], c1, c[i]), seg2.find_last(l[i], c2, c[i]));
            int l2 = min(seg1.find_first(l[i], c1, c[i]), seg2.find_first(l[i], c2, c[i]));
            int r1 = max(seg1.find_last(r[i], c1, c[i]), seg2.find_last(r[i], c2, c[i]));
            int r2 = min(seg1.find_first(r[i], c1, c[i]), seg2.find_first(r[i], c2, c[i]));
            vector<int> v = {l1, l2, r1, r2};
            each(e, v) {
                if (e < 0 || e >= N) continue;
                if (e < i) {
                    chmin(memo[c[i]], make_tuple(abs(a[e] - (a[i] - d)), i, e));
                } else {
                    chmin(memo[c[i]], make_tuple(abs(a[e] - (a[i] + d)), i, e));
                }
            }
        }

        bool flag = true;

        each(e, memo) {
            auto [k, u, v] = e;
            if (k == inf || c[u] == c[v]) continue;
            flag = false;
            if (sz(ids[c[u]]) < sz(ids[c[v]])) swap(u, v);
            each(w, ids[c[v]]) {
                c[w] = c[u];
                seg1.change(w, c[u]), seg2.change(w, c[u]);
                ids[c[u]].eb(w);
            }
            es.eb(e);
        }

        if (flag) break;
    }

    sort(all(es));
    Union_Find_Tree uf(N);

    each(e, es) {
        auto [k, u, v] = e;
        // cout << k << ' ' << u << ' ' << v << '\n';
        while (ptr < Q && get<0>(qs[ptr]) < k) {
            auto [l, i, t] = qs[ptr++];
            ans[i] = uf.same(s, t);
        }
        uf.unite(u, v);
    }

    assert(uf.count() == 1);

    rep(i, Q) cout << (ans[i] ? "Yes\n" : "No\n");
}