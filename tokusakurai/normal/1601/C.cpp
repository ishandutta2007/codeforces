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

template <typename T>
struct Binary_Indexed_Tree {
    vector<T> bit;
    const int n;

    Binary_Indexed_Tree(const vector<T> &v) : n((int)v.size()) {
        bit.resize(n + 1);
        copy(begin(v), end(v), begin(bit) + 1);
        for (int a = 2; a <= n; a <<= 1) {
            for (int b = a; b <= n; b += a) bit[b] += bit[b - a / 2];
        }
    }

    Binary_Indexed_Tree(int n, const T &x) : n(n) {
        bit.resize(n + 1);
        vector<T> v(n, x);
        copy(begin(v), end(v), begin(bit) + 1);
        for (int a = 2; a <= n; a <<= 1) {
            for (int b = a; b <= n; b += a) bit[b] += bit[b - a / 2];
        }
    }

    void add(int i, const T &x) {
        for (i++; i <= n; i += (i & -i)) bit[i] += x;
    }

    void change(int i, const T &x) { add(i, x - query(i, i + 1)); }

    T sum(int i) const {
        T ret = 0;
        for (; i > 0; i -= (i & -i)) ret += bit[i];
        return ret;
    }

    T query(int l, int r) const { return sum(r) - sum(l); }

    T operator[](int i) const { return query(i, i + 1); }

    int lower_bound(T x) const {
        int ret = 0;
        for (int k = 31 - __builtin_clz(n); k >= 0; k--) {
            if (ret + (1 << k) <= n && bit[ret + (1 << k)] < x) x -= bit[ret += (1 << k)];
        }
        return ret;
    }

    int upper_bound(T x) const {
        int ret = 0;
        for (int k = 31 - __builtin_clz(n); k >= 0; k--) {
            if (ret + (1 << k) <= n && bit[ret + (1 << k)] <= x) x -= bit[ret += (1 << k)];
        }
        return ret;
    }
};

template <typename T>
long long inversion_number(const vector<T> &a) {
    int n = a.size();
    vector<int> v(n);
    iota(begin(v), end(v), 0);
    sort(begin(v), end(v), [&](int i, int j) {
        if (a[i] != a[j]) return a[i] < a[j];
        return i < j;
    });
    Binary_Indexed_Tree<int> bit(n, 0);
    long long ret = 0;
    for (int i = 0; i < n; i++) {
        ret += bit.query(v[i] + 1, n);
        bit.add(v[i], 1);
    }
    return ret;
}

template <typename T>
long long inversion_number(const vector<T> &a, const vector<T> &b) { // ab
    int n = a.size();
    assert(b.size() == n);
    vector<int> u(n), v(n);
    iota(begin(u), end(u), 0);
    sort(begin(u), end(u), [&](int i, int j) {
        if (a[i] != a[j]) return a[i] < a[j];
        return i < j;
    });
    iota(begin(v), end(v), 0);
    sort(begin(v), end(v), [&](int i, int j) {
        if (b[i] != b[j]) return b[i] < b[j];
        return i < j;
    });
    vector<int> w(n);
    for (int i = 0; i < n; i++) {
        if (a[u[i]] != b[v[i]]) return -1;
        w[v[i]] = u[i];
    }
    Binary_Indexed_Tree<int> bit(n, 0);
    long long ret = 0;
    for (int i = 0; i < n; i++) {
        ret += bit.query(w[i] + 1, n);
        bit.add(w[i], 1);
    }
    return ret;
}

int main() {
    int T;
    cin >> T;

    while (T--) {
        int N, M;
        cin >> N >> M;

        vector<int> a(N), b(M);
        rep(i, N) cin >> a[i];
        rep(i, M) cin >> b[i];

        sort(all(b));
        vector<int> p(M, -1);

        function<void(int, int, int, int)> rec = [&](int li, int ri, int lj, int rj) {
            if (li == ri) return;
            int mi = (li + ri) / 2;
            int mj = lj, tmp = 0, s = 0;
            rep2(i, lj, rj - 1) {
                s += (a[i] > b[mi] ? 1 : a[i] < b[mi] ? -1 : 0);
                if (chmin(tmp, s)) mj = i + 1;
            }
            p[mi] = mj;
            rec(li, mi, lj, mj);
            rec(mi + 1, ri, mj, rj);
        };

        rec(0, M, 0, N);
        // print(p);

        ll ans = inversion_number(a);
        vector<int> v = id_sort(a);
        int ptr = 0;
        Binary_Indexed_Tree<int> bit(N, 0);

        rep(i, M) {
            while (ptr < N && a[v[ptr]] < b[i]) {
                bit.add(v[ptr], 1);
                ptr++;
            }
            ans += bit.query(p[i], N);
        }
        while (ptr < N) bit.add(v[ptr++], 1);

        ptr = 0;
        rep(i, M) {
            while (ptr < N && a[v[ptr]] <= b[i]) {
                bit.add(v[ptr], -1);
                ptr++;
            }
            ans += bit.query(0, p[i]);
        }

        cout << ans << '\n';
    }
}