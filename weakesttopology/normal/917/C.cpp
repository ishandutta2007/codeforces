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

template<typename T>
T templatepow(T x, ll p)
{
    assert(p >= 0);
    T res(0);
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

    inline static const T inf = numeric_limits<T>::max();

    Matrix()
    {
        fill(&A[0][0], &A[0][0] + N * M, inf);
        iota(all(row), 0);
    }
    Matrix(T value) : Matrix()
    {
        for (int i = 0; i < min(N, M); ++i) A[i][i] = value;
    }

    T* operator[](int i) { return A[row[i]]; }
    const T* operator[](int i) const { return A[row[i]]; }

    void swap_rows(int i, int j) { swap(row[i], row[j]); }

    template<int K> Matrix<T, N, K> operator*(const Matrix<T, M, K>& rhs) const
    {
        const auto& lhs = *this;
        Matrix<T, N, K> res;

        for (int i = 0; i < N; ++i)
            for (int j = 0; j < K; ++j)
                for (int k = 0; k < M; ++k)
                    if (max(lhs[i][k], rhs[k][j]) < inf)
                        res[i][j] = min(res[i][j], lhs[i][k] + rhs[k][j]);

        return res;
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
    int x, k, n, q;
    cin >> x >> k >> n >> q;

    vector<ll> c(k);
    for (int j = 0; j < k; ++j) cin >> c[j];

    map<int, ll> cost;
    vector<int> checkpoints;

    for (int z = 0; z < q; ++z)
    {
        int p, w;
        cin >> p >> w;
        --p;
        cost[p] = w;

        if (p < n - x) checkpoints.push_back(p);
    }

    checkpoints.push_back(n - x);
    sort(all(checkpoints));

    vector<int> hamming_weight(1 << k, 0);

    vector<int> states;
    map<int, int> Id;

    for (int mask = 1, ptr = 0; mask < (1 << k); ++mask)
    {
        int lsb = mask & -mask;
        hamming_weight[mask] = 1 + hamming_weight[mask ^ lsb];

        if (hamming_weight[mask] == x)
        {
            states.push_back(mask);
            Id[mask] = ptr++;
        }
    }

    int num_states = size(states);
    vector<vector<tuple<int, int, ll>>> E(num_states);

    for (int t = 0; t < num_states; ++t)
    {
        int mask = states[t];
        int lsb = mask & -mask;

        int offset = __builtin_ctz(lsb);

        for (int shift = 1; shift <= k && (lsb << shift) <= (1 << k); ++shift)
        {
            if (mask & (lsb << shift)) continue;
            int newmask = (mask ^ (lsb << shift) ^ lsb) >> 1;
            E[t].emplace_back(Id[newmask], shift + offset, c[shift - 1]);
        }

        if (not (mask & 1)) E[t].emplace_back(Id[mask >> 1], -1, 0LL);
    }

    constexpr int matrix_size = 70;
    assert(num_states <= matrix_size);

    Matrix<ll, matrix_size, matrix_size> A;
    Vector<ll, matrix_size> dp;

    for (int t = 0; t < num_states; ++t)
    {
        for (auto [s, offset, w] : E[t]) A[s][t] = w;
    }

    dp[0] = 0;

    int pos = 0;

    for (const auto p : checkpoints)
    {
        if (pos + k < p)
        {
            dp = templatepow(A, p - (pos + k)) * dp;
            pos = p - k;
        }

        for (; pos < p; ++pos)
        {
            Vector<ll, matrix_size> dpnxt;

            for (int t = 0; t < num_states; ++t) if (dp[t] < LINF)
            {
                for (auto [s, offset, w] : E[t])
                {
                    ll newcost = dp[t] + w + (offset != -1 ? cost[pos + offset] : 0);
                    dpnxt[s] = min(dpnxt[s], newcost);
                }
            }

            swap(dp, dpnxt);
        }
    }

    ll ans = dp[0];

    cout << ans << endl;

    exit(0);
}