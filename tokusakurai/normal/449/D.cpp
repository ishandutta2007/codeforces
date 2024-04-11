#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define per(i, n) for (int i = (n)-1; i >= 0; i--)
#define rep2(i, l, r) for (int i = (l); i < (r); i++)
#define per2(i, l, r) for (int i = (r)-1; i >= (l); i--)
#define each(e, v) for (auto &e : v)
#define MM << " " <<
#define pb push_back
#define eb emplace_back
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
#define sz(x) (int)x.size()
using ll = long long;
using pii = pair<int, int>;
using pil = pair<int, ll>;
using pli = pair<ll, int>;
using pll = pair<ll, ll>;

template <typename T>
using minheap = priority_queue<T, vector<T>, greater<T>>;

template <typename T>
using maxheap = priority_queue<T>;

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

template <int mod>
struct Mod_Int {
    int x;

    Mod_Int() : x(0) {}

    Mod_Int(long long y) : x(y >= 0 ? y % mod : (mod - (-y) % mod) % mod) {}

    static int get_mod() { return mod; }

    Mod_Int &operator+=(const Mod_Int &p) {
        if ((x += p.x) >= mod) x -= mod;
        return *this;
    }

    Mod_Int &operator-=(const Mod_Int &p) {
        if ((x += mod - p.x) >= mod) x -= mod;
        return *this;
    }

    Mod_Int &operator*=(const Mod_Int &p) {
        x = (int)(1LL * x * p.x % mod);
        return *this;
    }

    Mod_Int &operator/=(const Mod_Int &p) {
        *this *= p.inverse();
        return *this;
    }

    Mod_Int &operator++() { return *this += Mod_Int(1); }

    Mod_Int operator++(int) {
        Mod_Int tmp = *this;
        ++*this;
        return tmp;
    }

    Mod_Int &operator--() { return *this -= Mod_Int(1); }

    Mod_Int operator--(int) {
        Mod_Int tmp = *this;
        --*this;
        return tmp;
    }

    Mod_Int operator-() const { return Mod_Int(-x); }

    Mod_Int operator+(const Mod_Int &p) const { return Mod_Int(*this) += p; }

    Mod_Int operator-(const Mod_Int &p) const { return Mod_Int(*this) -= p; }

    Mod_Int operator*(const Mod_Int &p) const { return Mod_Int(*this) *= p; }

    Mod_Int operator/(const Mod_Int &p) const { return Mod_Int(*this) /= p; }

    bool operator==(const Mod_Int &p) const { return x == p.x; }

    bool operator!=(const Mod_Int &p) const { return x != p.x; }

    Mod_Int inverse() const {
        assert(*this != Mod_Int(0));
        return pow(mod - 2);
    }

    Mod_Int pow(long long k) const {
        Mod_Int now = *this, ret = 1;
        for (; k > 0; k >>= 1, now *= now) {
            if (k & 1) ret *= now;
        }
        return ret;
    }

    friend ostream &operator<<(ostream &os, const Mod_Int &p) { return os << p.x; }

    friend istream &operator>>(istream &is, Mod_Int &p) {
        long long a;
        is >> a;
        p = Mod_Int<mod>(a);
        return is;
    }
};

using mint = Mod_Int<MOD>;

template <typename T>
void fast_zeta_transform(vector<T> &a, bool upper) {
    int n = a.size();
    assert((n & (n - 1)) == 0);
    for (int i = 1; i < n; i <<= 1) {
        for (int j = 0; j < n; j++) {
            if (!(j & i)) {
                if (upper) {
                    a[j] += a[j | i];
                } else {
                    a[j | i] += a[j];
                }
            }
        }
    }
}

template <typename T>
void fast_mobius_transform(vector<T> &a, bool upper) {
    int n = a.size();
    assert((n & (n - 1)) == 0);
    for (int i = 1; i < n; i <<= 1) {
        for (int j = 0; j < n; j++) {
            if (!(j & i)) {
                if (upper) {
                    a[j] -= a[j | i];
                } else {
                    a[j | i] -= a[j];
                }
            }
        }
    }
}

template <typename T>
void fast_hadamard_transform(vector<T> &a, bool inverse = false) {
    int n = a.size();
    assert((n & (n - 1)) == 0);
    for (int i = 1; i < n; i <<= 1) {
        for (int j = 0; j < n; j++) {
            if (!(j & i)) {
                T x = a[j], y = a[j | i];
                a[j] = x + y, a[j | i] = x - y;
            }
        }
    }
    if (inverse) {
        T inv = T(1) / T(n);
        for (auto &e : a) e *= inv;
    }
}

template <typename T>
vector<T> bitwise_and_convolve(vector<T> a, vector<T> b) {
    int n = a.size();
    assert(b.size() == n && (n & (n - 1)) == 0);
    fast_zeta_transform(a, true), fast_zeta_transform(b, true);
    for (int i = 0; i < n; i++) a[i] *= b[i];
    fast_mobius_transform(a, true);
    return a;
}

template <typename T>
vector<T> bitwise_or_convolve(vector<T> a, vector<T> b) {
    int n = a.size();
    assert(b.size() == n && (n & (n - 1)) == 0);
    fast_zeta_transform(a, false), fast_zeta_transform(b, false);
    for (int i = 0; i < n; i++) a[i] *= b[i];
    fast_mobius_transform(a, false);
    return a;
}

template <typename T>
vector<T> bitwise_xor_convolve(vector<T> a, vector<T> b) {
    int n = a.size();
    assert(b.size() == n && (n & (n - 1)) == 0);
    fast_hadamard_transform(a), fast_hadamard_transform(b);
    for (int i = 0; i < n; i++) a[i] *= b[i];
    fast_hadamard_transform(a, true);
    return a;
}

template <typename T>
vector<T> subset_convolve(const vector<T> &a, const vector<T> &b) {
    int n = a.size();
    assert(b.size() == n && (n & (n - 1)) == 0);
    int k = __builtin_ctz(n);
    vector<vector<T>> A(k + 1, vector<T>(n, 0)), B(k + 1, vector<T>(n, 0)), C(k + 1, vector<T>(n, 0));
    for (int i = 0; i < n; i++) {
        int t = __builtin_popcount(i);
        A[t][i] = a[i], B[t][i] = b[i];
    }
    for (int i = 0; i <= k; i++) fast_zeta_transform(A[i], false), fast_zeta_transform(B[i], false);
    for (int i = 0; i <= k; i++) {
        for (int j = 0; j <= k - i; j++) {
            for (int l = 0; l < n; l++) C[i + j][l] += A[i][l] * B[j][l];
        }
    }
    for (int i = 0; i <= k; i++) fast_mobius_transform(C[i], false);
    vector<T> c(n);
    for (int i = 0; i < n; i++) c[i] = C[__builtin_popcount(i)][i];
    return c;
}

int main() {
    int N;
    cin >> N;

    vector<int> a(N);
    rep(i, N) cin >> a[i];

    int K = 20;
    vector<int> c(1 << K, 0);
    rep(i, N) c[a[i]]++;
    fast_zeta_transform(c, true);

    vector<mint> pw(N + 1, 1);
    rep(i, N) pw[i + 1] = pw[i] * 2;

    vector<mint> b(1 << K, 0);
    rep(i, 1 << K) b[i] = pw[c[i]];

    fast_mobius_transform(b, true);
    cout << b[0] << '\n';
}