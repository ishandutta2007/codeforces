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

template <typename T>
struct Segment_Tree_2D {
    using F = function<T(T, T)>;
    int n;
    vector<vector<int>> ids;
    vector<Segment_Tree<T>> segs;
    const F f;
    const T e1;

    Segment_Tree_2D(int m, const F &f, const T &e1) : f(f), e1(e1) {
        n = 1;
        while (n < m) n <<= 1;
        ids.resize(2 * n);
    }

    void insert(int x, int y) { // 
        x += n;
        while (x) {
            ids[x].push_back(y);
            x >>= 1;
        }
    }

    void build() {
        for (int i = 0; i < 2 * n; i++) {
            sort(begin(ids[i]), end(ids[i]));
            ids[i].erase(unique(begin(ids[i]), end(ids[i])), end(ids[i]));
            segs.emplace_back((int)ids[i].size(), e1, f, e1);
        }
    }

    void change(int x, int y, const T &a) {
        x += n;
        while (x) {
            segs[x].change(lower_bound(begin(ids[x]), end(ids[x]), y) - begin(ids[x]), a, false);
            x >>= 1;
        }
    }

    T query(int lx, int rx, int ly, int ry) const {
        T L = e1, R = e1;
        lx += n, rx += n;
        while (lx < rx) {
            if (lx & 1) {
                int l = lower_bound(begin(ids[lx]), end(ids[lx]), ly) - begin(ids[lx]);
                int r = lower_bound(begin(ids[lx]), end(ids[lx]), ry) - begin(ids[lx]);
                L = f(L, segs[lx].query(l, r));
                lx++;
            }
            if (rx & 1) {
                rx--;
                int l = lower_bound(begin(ids[rx]), end(ids[rx]), ly) - begin(ids[rx]);
                int r = lower_bound(begin(ids[rx]), end(ids[rx]), ry) - begin(ids[rx]);
                R = f(segs[rx].query(l, r), R);
            }
            lx >>= 1, rx >>= 1;
        }
        return f(L, R);
    }
};

int main() {
    int N;
    cin >> N;

    vector<int> a(N + 1);
    a[0] = 0;
    rep2(i, 1, N) cin >> a[i];

    rep(i, N + 1) a[i] += N - i;

    vector<int> xs, ys;
    rep(i, N + 1) xs.eb(-a[i]), ys.eb(a[i] + i);
    rearrange(xs), rearrange(ys);

    int K = sz(xs);
    auto f = [](int a, int b) { return max(a, b); };

    Segment_Tree_2D<int> seg(K, f, -inf);
    rep(i, N + 1) seg.insert(lb(xs, -a[i]), lb(ys, a[i] + i));
    seg.build();

    seg.change(lb(xs, -a[0]), lb(ys, a[0] + 0), 0);
    int ans = 0;

    // print(a);

    rep2(i, 1, N) {
        int x = seg.query(0, lb(xs, -a[i] + 1), 0, lb(ys, a[i] + i)) + 1;
        seg.change(lb(xs, -a[i]), lb(ys, a[i] + i), x);
        chmax(ans, x);
    }

    cout << ans << '\n';
}