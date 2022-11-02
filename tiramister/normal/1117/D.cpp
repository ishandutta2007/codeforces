#include <iostream>
#include <numeric>
#include <vector>

using namespace std;
using ll = long long;

const ll MOD = 1000000007;
int M;

vector<vector<ll>> matmul(const vector<vector<ll>>& a, const vector<vector<ll>>& b) {
    vector<vector<ll>> c(M + 1, vector<ll>(M + 1, 0));
    for (int i = 0; i < M + 1; ++i) {
        for (int j = 0; j < M + 1; ++j) {
            for (int k = 0; k < M + 1; ++k) {
                c[i][j] += a[i][k] * b[k][j] % MOD;
            }
            c[i][j] %= MOD;
        }
    }
    return c;
}

vector<vector<ll>> matpow(const vector<vector<ll>>& b, ll n) {
    if (n == 0) {
        vector<vector<ll>> e(M + 1, vector<ll>(M + 1, 0));
        for (int i = 0; i < M + 1; ++i) e[i][i] = 1;
        return e;
    }

    if (n == 1) return b;
    if (n % 2 == 0) {
        return matpow(matmul(b, b), n / 2);
    } else {
        return matmul(matpow(b, n - 1), b);
    }
}

int main() {
    ll N;
    cin >> N >> M;

    vector<vector<ll>> A(M + 1, vector<ll>(M + 1, 0));
    for (int i = 0; i < M - 1; ++i) {
        A[i][i + 1] = 1;
    }
    A[M - 1][0] = A[M - 1][M - 1] = A[M - 1][M] = A[M][M] = 1;

    A = matpow(A, N - 1);
    vector<ll> v(M + 1);
    iota(v.begin(), v.begin() + M, 1LL);
    v[M] = 1;

    ll s[2] = {0, 0};
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < M + 1; ++j) {
            s[i] += A[i][j] * v[j] % MOD;
        }
        s[i] %= MOD;
    }

    cout << (s[1] - s[0] + MOD) % MOD << endl;
    return 0;
}