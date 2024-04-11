#include "bits/stdc++.h"

using namespace std;

#define endl '\n'
#define debug(x) cerr << #x << " == " << (x) << '\n';
#define all(x) begin(x), end(x)

using ll = long long;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fLL;

template<typename T>
T templatepow(T x, ll p) {
    assert(p >= 0);
    T res(1);
    while (p > 0) {
        if (p & 1) res = res * x;
        x = x * x, p >>= 1;
    }
    return res;
}

template<typename T, int N, int M>
struct Matrix {
    T A[N][M];
    int row[N];

    Matrix() {
        fill(&A[0][0], &A[0][0] + N * M, T(0));
        iota(all(row), 0);
    }
    Matrix(T value) : Matrix() {
        for (int i = 0; i < min(N, M); ++i) A[i][i] = value;
    }
    Matrix(initializer_list<initializer_list<T>> lst) : Matrix() {
        int i = 0, j = 0;
        for (const auto& v : lst) {
            for (const auto& x : v) A[i][j++] = x;
            i++, j = 0;
        }
    }

    T* operator[](int i) { return A[row[i]]; }
    const T* operator[](int i) const { return A[row[i]]; }

    void swap_rows(int i, int j) { swap(row[i], row[j]); }

    template<typename Op> Matrix& compose(const Matrix& rhs, Op&& op) {
        auto& lhs = *this;
        for (int i = 0; i < N; ++i)
            for (int j = 0; j < M; ++j)
                lhs[i][j] = op(lhs[i][j], rhs[i][j]);
        return *this;
    }
    Matrix& operator+=(const Matrix& rhs) { return compose(rhs, std::plus<T>()); }
    Matrix& operator-=(const Matrix& rhs) { return compose(rhs, std::minus<T>()); }
    Matrix operator+(const Matrix& rhs) const { return Matrix(*this) += rhs; }
    Matrix operator-(const Matrix& rhs) const { return Matrix(*this) -= rhs; }
    template<int K> Matrix<T, N, K> operator*(const Matrix<T, M, K>& rhs) const {
        const auto& lhs = *this;
        Matrix<T, N, K> res;
        for (int i = 0; i < N; ++i)
            for (int j = 0; j < K; ++j)
                for (int k = 0; k < M; ++k)
                    res[i][j] += lhs[i][k] * rhs[k][j];
        return res;
    }
    friend Matrix operator*(const T& alpha, Matrix A) {
        for (int i = 0; i < N; ++i)
            for (int j = 0; j < M; ++j)
                A[i][j] *= alpha;
        return A;
    }
};

template<typename T, int N>
struct Vector : public Matrix<T, N, 1> {
    using Base = Matrix<T, N, 1>;

    Vector() : Base() { }
    Vector(const Base& v) : Base(v) { }
    Vector(initializer_list<T> lst) : Base() {
        int i = 0;
        for (const auto& x : lst) (*this)[i++] = x;
    }

    T& operator[](int i) { return Base::operator[](i)[0]; }
    const T& operator[](int i) const { return Base::operator[](i)[0]; }
};

ll modpow(ll x, ll p, ll mod) {
    ll res = 1LL;
    for (; p; p >>= 1, (x *= x) %= mod) if (p & 1) (res *= x) %= mod;
    return res;
}

template<ll mod>
struct Mint {
    ll x;
    Mint(ll x = 0) : x((x %= mod) < 0 ? x + mod : x) { }
    Mint& operator+=(Mint rhs) { if ((x += rhs.x) >= mod) x -= mod; return *this; }
    Mint& operator-=(Mint rhs) { return *this += mod - rhs.x; }
    Mint& operator*=(Mint rhs) { (x *= rhs.x) %= mod; return *this; }
    Mint& operator/=(Mint rhs) { return *this *= modpow(rhs.x, mod - 2, mod); }
    Mint power(ll p) const { return Mint(modpow(x, p, mod)); }
    bool operator==(Mint rhs) const { return x == rhs.x; }
    bool operator<(Mint rhs) const { return x < rhs.x; }
    friend Mint operator+(Mint lhs, Mint rhs) { return lhs += rhs; }
    friend Mint operator-(Mint lhs, Mint rhs) { return lhs -= rhs; }
    friend Mint operator*(Mint lhs, Mint rhs) { return lhs *= rhs; }
    friend Mint operator/(Mint lhs, Mint rhs) { return lhs /= rhs; }
    friend ostream& operator<<(ostream& out, Mint a) { return out << a.x; }
    friend istream& operator>>(istream& in, Mint& a) {
        ll x;
        in >> x;
        a = Mint(x);
        return in;
    }
};

constexpr ll mod = 998244353;
using mint = Mint<mod>;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<string> s(n);
    for (auto& x : s) cin >> x;
    vector<int> d(n);
    for (int i = 0; i < n; ++i) d[i] = (int)size(s[i]);

    constexpr int nmax = 8, maxsz = 5;

    auto Id = [&](int u, int j, int delay) { return u * maxsz * maxsz + j * maxsz + delay; };

    constexpr int N = nmax * maxsz * maxsz;
    Matrix<mint, N, N> A;

    for (int u = 0; u < n; ++u) {
        int k = (int)size(s[u]);
        for (int v = 0; v < n; ++v) {
            for (int i = 0; i < k; ++i) {
                int t = min(d[u] - i, d[v]);
                if (s[u].substr(i, t) != s[v].substr(0, t)) continue;

                if (i + t < k) A[Id(u, i + t, t - 1)][Id(u, i, 0)] += 1;
                else if (d[v] == k - i) {
                    for (int w = 0; w < n; ++w) {
                        A[Id(w, 0, t - 1)][Id(u, i, 0)] += 1;
                    }
                }
                else A[Id(v, t, t - 1)][Id(u, i, 0)] += 1;
            }
        }
        for (int t = 1; t < maxsz; ++t) {
            for (int i = 0; i < k; ++i) {
                A[Id(u, i, t - 1)][Id(u, i, t)] += 1;
            }
        }
    }

    Vector<mint, N> x;
    for (int u = 0; u < n; ++u) {
        x[Id(u, 0, 0)] = 1;
    }
    x = templatepow(A, m) * x;

    mint res = 0;
    for (int u = 0; u < n; ++u) {
        res += x[Id(u, 0, 0)];
    }
    res /= n;

    cout << res << endl;

    exit(0);
}