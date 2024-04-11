#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define forx(i, a, b) for (int i = (a); i < (b); i++)
#define rep(i, n) for (int i = 0; i < (n); i++)

ll MOD = 1e9 + 7;

struct Matrix
{
    vector<vector<long long>> val;
    Matrix(int n, int m, long long x = 0) : val(n, vector<long long>(m, x)) {}
    void init(int n, int m, long long x = 0) { val.assign(n, vector<long long>(m, x)); }
    size_t size() const { return val.size(); }
    inline vector<long long> &operator[](int i) { return val[i]; }
};

Matrix operator*(Matrix A, Matrix B)
{
    MOD--;
    Matrix R(A.size(), B[0].size());
    for (int i = 0; i < A.size(); ++i)
        for (int j = 0; j < B[0].size(); ++j)
            for (int k = 0; k < B.size(); ++k)
                R[i][j] = (R[i][j] + A[i][k] * B[k][j] % MOD) % MOD;
    MOD++;
    return R;
}

Matrix pow(Matrix A, long long n)
{
    Matrix R(A.size(), A.size());
    for (int i = 0; i < A.size(); ++i)
        R[i][i] = 1;
    while (n > 0)
    {
        if (n & 1)
            R = R * A;
        A = A * A;
        n >>= 1;
    }
    return R;
}

long long modpow(long long a, long long n)
{
    long long res = 1;
    while (n > 0)
    {
        if (n & 1)
            res = res * a % MOD;
        a = a * a % MOD;
        n >>= 1;
    }
    return res;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    ll n, f1, f2, f3, c;
    cin >> n >> f1 >> f2 >> f3 >> c;
    Matrix M(5, 5, 0);
    rep(i, 4) M[i][0] = 1;
    M[0][1] = M[1][2] = M[3][3] = M[4][4] = 1;
    M[4][3] = 2;

    M = pow(M, n - 3LL);
    ll ans = modpow(f3, M[0][0]);
    ans %= MOD;
    ans *= modpow(f2, M[1][0]);
    ans %= MOD;
    ans *= modpow(f1, M[2][0]);
    ans %= MOD;
    ans *= modpow(c, 2LL * M[3][0] + M[4][0]);
    ans %= MOD;

    cout << ans << endl;

    return 0;
}