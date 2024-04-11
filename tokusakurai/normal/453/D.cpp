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
// const int MOD = 1000000007;
const int MOD = 998244353;

struct Runtime_Mod_Int {
    int x;

    Runtime_Mod_Int() : x(0) {}

    Runtime_Mod_Int(long long y) {
        x = y % get_mod();
        if (x < 0) x += get_mod();
    }

    static inline int &get_mod() {
        static int mod = 0;
        return mod;
    }

    static void set_mod(int md) { get_mod() = md; }

    Runtime_Mod_Int &operator+=(const Runtime_Mod_Int &p) {
        if ((x += p.x) >= get_mod()) x -= get_mod();
        return *this;
    }

    Runtime_Mod_Int &operator-=(const Runtime_Mod_Int &p) {
        if ((x += get_mod() - p.x) >= get_mod()) x -= get_mod();
        return *this;
    }

    Runtime_Mod_Int &operator*=(const Runtime_Mod_Int &p) {
        x = (int)(1LL * x * p.x % get_mod());
        return *this;
    }

    Runtime_Mod_Int &operator/=(const Runtime_Mod_Int &p) {
        *this *= p.inverse();
        return *this;
    }

    Runtime_Mod_Int &operator++() { return *this += Runtime_Mod_Int(1); }

    Runtime_Mod_Int operator++(int) {
        Runtime_Mod_Int tmp = *this;
        ++*this;
        return tmp;
    }

    Runtime_Mod_Int &operator--() { return *this -= Runtime_Mod_Int(1); }

    Runtime_Mod_Int operator--(int) {
        Runtime_Mod_Int tmp = *this;
        --*this;
        return tmp;
    }

    Runtime_Mod_Int operator-() const { return Runtime_Mod_Int(-x); }

    Runtime_Mod_Int operator+(const Runtime_Mod_Int &p) const { return Runtime_Mod_Int(*this) += p; }

    Runtime_Mod_Int operator-(const Runtime_Mod_Int &p) const { return Runtime_Mod_Int(*this) -= p; }

    Runtime_Mod_Int operator*(const Runtime_Mod_Int &p) const { return Runtime_Mod_Int(*this) *= p; }

    Runtime_Mod_Int operator/(const Runtime_Mod_Int &p) const { return Runtime_Mod_Int(*this) /= p; }

    bool operator==(const Runtime_Mod_Int &p) const { return x == p.x; }

    bool operator!=(const Runtime_Mod_Int &p) const { return x != p.x; }

    Runtime_Mod_Int inverse() const {
        assert(*this != Runtime_Mod_Int(0));
        return pow(get_mod() - 2);
    }

    Runtime_Mod_Int pow(long long k) const {
        Runtime_Mod_Int now = *this, ret = 1;
        for (; k > 0; k >>= 1, now *= now) {
            if (k & 1) ret *= now;
        }
        return ret;
    }

    friend ostream &operator<<(ostream &os, const Runtime_Mod_Int &p) { return os << p.x; }

    friend istream &operator>>(istream &is, Runtime_Mod_Int &p) {
        long long a;
        is >> a;
        p = Runtime_Mod_Int(a);
        return is;
    }
};

using mint = Runtime_Mod_Int;

template <typename T>
struct Matrix {
    vector<vector<T>> A;

    Matrix(int m, int n) : A(m, vector<T>(n, 0)) {}

    int height() const { return A.size(); }

    int width() const { return A.front().size(); }

    inline const vector<T> &operator[](int k) const { return A[k]; }

    inline vector<T> &operator[](int k) { return A[k]; }

    static Matrix I(int l) {
        Matrix ret(l, l);
        for (int i = 0; i < l; i++) ret[i][i] = 1;
        return ret;
    }

    Matrix &operator*=(const Matrix &B) {
        int m = height(), n = width(), p = B.width();
        assert(n == B.height());
        Matrix ret(m, p);
        for (int i = 0; i < m; i++) {
            for (int k = 0; k < n; k++) {
                for (int j = 0; j < p; j++) ret[i][j] += A[i][k] * B[k][j];
            }
        }
        swap(A, ret.A);
        return *this;
    }

    Matrix operator*(const Matrix &B) const { return Matrix(*this) *= B; }

    Matrix pow(long long k) const {
        int m = height(), n = width();
        assert(m == n);
        Matrix now = *this, ret = I(n);
        for (; k > 0; k >>= 1, now *= now) {
            if (k & 1) ret *= now;
        }
        return ret;
    }

    bool eq(const T &a, const T &b) const {
        return a == b;
        // return abs(a-b) <= EPS;
    }

    // (rank, det) 
    pair<int, T> row_reduction(vector<T> &b) {
        int m = height(), n = width(), check = 0, rank = 0;
        T det = 1;
        assert(b.size() == m);
        for (int j = 0; j < n; j++) {
            int pivot = check;
            for (int i = check; i < m; i++) {
                if (A[i][j] != 0) pivot = i;
                // if(abs(A[i][j]) > abs(A[pivot][j])) pivot = i; // T 
            }
            if (check != pivot) det *= T(-1);
            swap(A[check], A[pivot]), swap(b[check], b[pivot]);
            if (eq(A[check][j], T(0))) {
                det = T(0);
                continue;
            }
            rank++;
            det *= A[check][j];
            T r = T(1) / A[check][j];
            for (int k = j + 1; k < n; k++) A[check][k] *= r;
            b[check] *= r;
            A[check][j] = T(1);
            for (int i = 0; i < m; i++) {
                if (i == check) continue;
                if (!eq(A[i][j], 0)) {
                    for (int k = j + 1; k < n; k++) A[i][k] -= A[i][j] * A[check][k];
                    b[i] -= A[i][j] * b[check];
                }
                A[i][j] = T(0);
            }
            if (++check == m) break;
        }
        return make_pair(rank, det);
    }

    pair<int, T> row_reduction() {
        vector<T> b(height(), T(0));
        return row_reduction(b);
    }

    // 
    Matrix inverse() {
        if (height() != width()) return Matrix(0, 0);
        int n = height();
        Matrix ret = I(n);
        for (int j = 0; j < n; j++) {
            int pivot = j;
            for (int i = j; i < n; i++) {
                if (A[i][j] != 0) pivot = i;
                // if(abs(A[i][j]) > abs(A[pivot][j])) pivot = i; // T 
            }
            swap(A[j], A[pivot]), swap(ret[j], ret[pivot]);
            if (eq(A[j][j], T(0))) return Matrix(0, 0);
            T r = T(1) / A[j][j];
            for (int k = j + 1; k < n; k++) A[j][k] *= r;
            for (int k = 0; k < n; k++) ret[j][k] *= r;
            A[j][j] = T(1);
            for (int i = 0; i < n; i++) {
                if (i == j) continue;
                if (!eq(A[i][j], T(0))) {
                    for (int k = j + 1; k < n; k++) A[i][k] -= A[i][j] * A[j][k];
                    for (int k = 0; k < n; k++) ret[i][k] -= A[i][j] * ret[j][k];
                }
                A[i][j] = T(0);
            }
        }
        return ret;
    }

    // Ax = b  1 
    vector<vector<T>> Gausiann_elimination(vector<T> b) {
        int m = height(), n = width();
        row_reduction(b);
        vector<vector<T>> ret;
        vector<int> p(m, n);
        vector<bool> is_zero(n, true);
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (!eq(A[i][j], T(0))) {
                    p[i] = j;
                    break;
                }
            }
            if (p[i] < n)
                is_zero[p[i]] = false;
            else if (!eq(b[i], T(0)))
                return {};
        }
        vector<T> x(n, T(0));
        for (int i = 0; i < m; i++) {
            if (p[i] < n) x[p[i]] = b[i];
        }
        ret.push_back(x);
        for (int j = 0; j < n; j++) {
            if (!is_zero[j]) continue;
            x[j] = T(1);
            for (int i = 0; i < m; i++) {
                if (p[i] < n) x[p[i]] = -A[i][j];
            }
            ret.push_back(x), x[j] = T(0);
        }
        return ret;
    }
};

using mat = Matrix<mint>;

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

const int m1 = 880803841; // 105*2^23 + 1
const int m2 = 897581057; // 107*2^23 + 1
const int m3 = 998244353; // 119*2^23 + 1

ll calc_comb(int n, int k) {
    ll ret = 1;
    rep(i, k) ret *= n - i, ret /= i + 1;
    return ret;
}

template <typename T>
void ff(vector<T> &a) {
    int n = sz(a);
    int t = __builtin_ctz(n);
    vector<T> c(t + 1);
    rep(i, t + 1) c[i] = T(calc_comb(t, i)).inverse();
    rep(i, n) a[i] *= c[__builtin_popcount(i)];
}

template <typename T>
vector<T> convolve(vector<T> a, vector<T> b) {
    using mint_1 = Mod_Int<m1>;
    using mint_2 = Mod_Int<m2>;
    using mint_3 = Mod_Int<m3>;
    int n = a.size(), m = b.size();
    vector<mint_1> a1(n), b1(m);
    vector<mint_2> a2(n), b2(m);
    vector<mint_3> a3(n), b3(m);
    for (int i = 0; i < n; i++) a1[i] = a[i].x, a2[i] = a[i].x, a3[i] = a[i].x;
    for (int i = 0; i < m; i++) b1[i] = b[i].x, b2[i] = b[i].x, b3[i] = b[i].x;
    // ff(b1), ff(b2), ff(b3);
    auto c1 = bitwise_xor_convolve(a1, b1);
    auto c2 = bitwise_xor_convolve(a2, b2);
    auto c3 = bitwise_xor_convolve(a3, b3);
    const mint_2 m1_inv_m2 = mint_2(m1).inverse();
    const mint_3 m1m2_inv_m3 = (mint_3(m1) * m2).inverse();
    vector<T> c(n);
    for (int i = 0; i < n; i++) {
        // cout << c1[i] << ' ' << c2[i] << ' ' << c3[i] << '\n';
        long long t1 = (m1_inv_m2 * (c2[i].x - c1[i].x)).x;
        long long t = (m1m2_inv_m3 * (c3[i].x - t1 * m1 - c1[i].x)).x;
        c[i] = T(t) * m1 * m2 + T(t1) * m1 + c1[i].x;
    }
    return c;
}

int main() {
    int K;
    ll N;
    int P;
    cin >> K >> N >> P;

    mint::set_mod(P);

    vector<mint> a(1 << K);
    rep(i, 1 << K) cin >> a[i];

    vector<mint> b(K + 1);
    rep(i, K + 1) cin >> b[i];

    vector<vector<mint>> c(K + 1, vector<mint>(K + 1));
    c[0][0] = 1;
    rep(i, K) {
        rep(j, i + 1) {
            c[i + 1][j] += c[i][j];
            c[i + 1][j + 1] += c[i][j];
        }
    }
    // rep(i, K + 1) print(c[i]);

    auto comb = [&](int n, int k) -> mint {
        if (n < k || k < 0) return 0;
        return c[n][k];
    };

    mat A(K + 1, K + 1);
    rep(i, K + 1) {
        rep(j, K + 1) {
            rep(k, j + 1) {
                if (k > j || i - k > K - j) continue;
                A[i][j] += comb(j, k) * comb(K - j, i - k) * b[j - k + i - k];
            }
        }
    }

    // rep(i, K + 1) print(A[i]);

    mat x(1, K + 1);
    x[0][0] = 1;
    x *= A.pow(N);

    // print(x[0]);

    vector<mint> f(1 << K);
    rep(i, 1 << K) f[i] = x[0][__builtin_popcount(i)];
    // print(a);
    // print(f);

    a = convolve(a, f);
    printn(a);
}