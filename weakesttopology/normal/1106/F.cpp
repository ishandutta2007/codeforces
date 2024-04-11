#include "bits/stdc++.h"

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define debug(x) cerr << #x << " == " << (x) << '\n';
#define all(X) begin(X), end(X)
#define size(X) (int)std::size(X)

using ll = long long;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fLL;

// assumes a and mod are coprime
// return -1 if not found

ll discrete_log(ll a, ll b, ll mod)
{
    a %= mod, b %= mod;

    ll n = (ll)sqrt(mod) + 1;
    ll apow = 1;

    for (int i = 0; i < n; ++i) (apow *= a) %= mod;

    vector<pair<ll, ll>> values;

    for (ll q = 0, cur = b; q <= n; ++q)
    {
        values.emplace_back(cur, q);
        (cur *= a) %= mod;
    }

    sort(all(values));

    for (ll p = 1, cur = 1; p <= n; ++p)
    {
        (cur *= apow) %= mod;
        auto iter = lower_bound(all(values), pair(cur, 0LL));
        if (iter != end(values) && iter->first == cur)
        {
            ll ans = n * p - iter->second;
            return ans;
        }
    }

    return -1;
}

ll modpow(ll x, ll p, ll mod)
{
    ll res = 1LL;
    for (; p; p >>= 1, (x *= x) %= mod) if (p & 1) (res *= x) %= mod;
    return res;
}

template<ll mod>
struct Mint
{
    ll x;
    Mint(ll x = 0) : x((x %= mod) < 0 ? x + mod : x) {  }
    Mint& operator+=(const Mint& rhs) { if ((x += rhs.x) >= mod) x -= mod; return *this; }
    Mint& operator-=(const Mint& rhs) { return *this += mod - rhs.x; }
    Mint& operator*=(const Mint& rhs) { (x *= rhs.x) %= mod; return *this; }
    Mint& operator/=(const Mint& rhs) { return *this *= modpow(rhs.x, mod - 2, mod); }
    Mint power(ll p) const { return Mint(modpow(x, p, mod)); }
    bool operator==(const Mint& rhs) const { return x == rhs.x; }
    bool operator<(const Mint& rhs) const { return x < rhs.x; }
    friend Mint operator+(const Mint& lhs, const Mint& rhs) { return Mint(lhs) += rhs; }
    friend Mint operator-(const Mint& lhs, const Mint& rhs) { return Mint(lhs) -= rhs; }
    friend Mint operator*(const Mint& lhs, const Mint& rhs) { return Mint(lhs) *= rhs; }
    friend Mint operator/(const Mint& lhs, const Mint& rhs) { return Mint(lhs) /= rhs; }
    friend ostream& operator<<(ostream& out, const Mint& a) { return out << a.x; }
    friend istream& operator>>(istream& in, Mint& a)
    {
        ll x; in >> x;
        a = Mint(x);
        return in;
    }
};

template<typename T>
T templatepow(T x, ll p)
{
    assert(p >= 0);
    T res(1);
    while (p > 0)
    {
        if (p & 1) res = res * x;
        x = x * x, p >>= 1;
    }
    return res;
}

template<typename T, int N, int M>
struct Matrix
{
    T A[N][M];
    int row[N];

    Matrix()
    {
        fill(&A[0][0], &A[0][0] + N * M, T(0));
        iota(all(row), 0);
    }
    Matrix(T value) : Matrix()
    {
        for (int i = 0; i < min(N, M); ++i) A[i][i] = value;
    }
    Matrix(initializer_list<initializer_list<T>> lst) : Matrix()
    {
        int i = 0, j = 0;
        for (const auto& v : lst)
        {
            for (const auto& x : v) A[i][j++] = x;
            i++, j = 0;
        }
    }

    T* operator[](int i) { return A[row[i]]; }
    const T* operator[](int i) const { return A[row[i]]; }

    void swap_rows(int i, int j) { swap(row[i], row[j]); }

    template<typename Op> Matrix& compose(const Matrix& rhs, Op&& op)
    {
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
    template<int K> Matrix<T, N, K> operator*(const Matrix<T, M, K>& rhs) const
    {
        const auto& lhs = *this;
        Matrix<T, N, K> res;
        for (int i = 0; i < N; ++i)
            for (int j = 0; j < K; ++j)
                for (int k = 0; k < M; ++k)
                    res[i][j] += lhs[i][k] * rhs[k][j];
        return res;
    }
    friend Matrix operator*(const T& alpha, Matrix A)
    {
        for (int i = 0; i < N; ++i)
            for (int j = 0; j < M; ++j)
                A[i][j] *= alpha;
        return A;
    }
};

template<typename T, int N>
struct Vector : public Matrix<T, N, 1>
{
    using Base = Matrix<T, N, 1>;

    Vector() : Base() { }
    Vector(const Base& v) : Base(v) { }

    T& operator[](int i) { return Base::operator[](i)[0]; }
    const T& operator[](int i) const { return Base::operator[](i)[0]; }
};

int main()
{ _
    constexpr ll mod = 998244353, primitive_root = 3;
    constexpr int kmax = 100;
    using mint = Mint<mod - 1>;

    int k;
    cin >> k;

    Matrix<mint, kmax, kmax> A;

    for (int j = 0; j < k; ++j) cin >> A[k - 1][k - 1 - j];
    for (int j = 0; j + 1 < k; ++j) A[j][j + 1] = 1;

    ll n, m;
    cin >> n >> m;

    Vector<mint, kmax> v;
    v[k - 1] = 1;

    v = templatepow(A, n - k) * v;

    ll f = modpow(primitive_root, v[k - 1].x, mod);
    ll g = discrete_log(f, m, mod);

    if (g == -1)
    {
        cout << -1 << endl;
    }
    else
    {
        assert(modpow(f, g, mod) == m);

        ll ans = modpow(primitive_root, g, mod);
        cout << ans << endl;
    }

    exit(0);
}