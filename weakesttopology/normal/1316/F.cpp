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
    friend istream& operator>>(istream& in, Mint& a)
    {
        ll x;
        in >> x;
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
    Vector(initializer_list<T> lst) : Base()
    {
        int i = 0;
        for (const auto& x : lst) (*this)[i++] = x;
    }

    T& operator[](int i) { return Base::operator[](i)[0]; }
    const T& operator[](int i) const { return Base::operator[](i)[0]; }
};

template<typename T, int N, int M>
struct Affine
{
    Matrix<T, N, M> A;
    Vector<T, N> b;

    Affine(T value = T(0)) : A(value), b(T(0)) { }
    Affine(const Matrix<T, N, M>& A, const Vector<T, N>& b) : A(A), b(b) { }

    Affine operator+=(const Affine& rhs) { A += rhs.A, b += rhs.B; }
    Affine operator-=(const Affine& rhs) { A -= rhs.A, b -= rhs.B; }
    Affine operator+(const Affine& rhs) const { return Affine(*this) += rhs; };
    Affine operator-(const Affine& rhs) const { return Affine(*this) -= rhs; };

    T* operator[](int i) { return A[i]; }
    const T* operator[](int i) const { return A[i]; }

    template<int K> Affine<T, N, K> operator*(const Affine<T, M, K>& rhs) const
    {
        Affine<T, N, K> res;

        res.A = A * rhs.A;
        res.b = A * rhs.b + b;

        return res;
    }
    Vector<T, N> operator*(const Vector<T, M>& x) const
    {
        return A * x + b;
    }
};

template<typename T>
struct M1
{
    using Type = T;
    inline const static T Id = T(1);
    static T op(const T& x, const T& y) { return x * y; }
};

template<typename Monoid>
struct SegmentTree
{
private:
    using M = Monoid;
    using T = typename Monoid::Type;
    const int n;
    vector<T> st;
public:
    SegmentTree(int n) : n(n), st(2 * n, M::Id) { }
    SegmentTree(const vector<T>& a) : SegmentTree(size(a))
    {
        for (int i = 0; i < n; ++i) st[n + i] = a[i];
        for (int i = n - 1; i > 0; --i)
            st[i] = M::op(st[i << 1], st[i << 1 | 1]);
    }
    void modify(int p, T value)
    {
        for (st[p += n] = value; p > 1; p >>= 1)
            st[p >> 1] = M::op(st[p & ~1], st[p | 1]);
    }
    T query(int l, int r)
    {
        T resl = M::Id, resr = M::Id;
        for (l += n, r += n + 1; l < r; l >>= 1, r >>= 1)
        {
            if (l & 1) resl = M::op(resl, st[l++]);
            if (r & 1) resr = M::op(st[--r], resr);
        }
        return M::op(resl, resr);
    }
};

int main()
{ _
    constexpr ll mod = 1e9 + 7;
    using mint = Mint<mod>;
    using M = Affine<mint, 2, 2>;

    auto build = [&](mint x)
    {
        static const mint inv = 1 / mint(2);
        return M({{1, x*inv}, {0, inv}}, {0, x*inv});
    };

    int n;
    cin >> n;

    vector<int> p(n);
    for (auto& x : p) cin >> x;

    auto values = p;

    int q;
    cin >> q;

    vector<pair<int, int>> queries(q);

    for (auto& [i, x] : queries)
    {
        cin >> i >> x;
        --i;
        values.push_back(x);
    }

    sort(all(values)), values.erase(unique(all(values)), end(values));
    int N = size(values);

    map<int, int> pos, freq;
    for (int i = 0; i < N; ++i) pos[values[i]] = i;
    for (auto x : p) freq[x] += 1;

    vector<M> init(N, M(1));

    for (auto [x, i] : pos)
    {
        init[i] = templatepow(build(x), freq[x]);
    }

    SegmentTree<M1<M>> st(init);

    auto get = [&](){ return st.query(0, N - 1).b[0]; };

    cout << get() << endl;

    for (auto [i, x] : queries)
    {
        st.modify(pos[p[i]], templatepow(build(p[i]), --freq[p[i]]));
        p[i] = x;                                                    
        st.modify(pos[p[i]], templatepow(build(p[i]), ++freq[p[i]]));
        cout << get() << endl;
    }

    exit(0);
}