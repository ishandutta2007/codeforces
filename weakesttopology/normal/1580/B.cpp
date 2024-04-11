#include <bits/stdc++.h>
using namespace std;
struct Z {
    inline static long long P;
    long long x;
    Z() : x(0) {}
    Z(long long x_) {
        x = x_ % P;
        if (x < 0) x += P;
    }
    Z& operator+=(Z rhs) {
        x += rhs.x;
        if (x >= P) x -= P;
        return *this;
    }
    Z& operator-=(Z rhs) {
        x -= rhs.x;
        if (x < 0) x += P;
        return *this;
    }
    Z& operator*=(Z rhs) {
        x = x * rhs.x % P;
        return *this;
    }
    Z& operator/=(Z rhs) {
        return *this *= rhs.power(-1);
    }
    Z power(long long p) const {
        p %= P - 1;
        if (p < 0) p += P - 1;
        Z res = 1;
        for (Z y = *this; p; p >>= 1, y *= y) if (p & 1) res *= y;
        return res;
    }
    Z operator-() const {
        return Z() - *this;
    }
    bool operator==(Z rhs) const {
        return x == rhs.x;
    }
    bool operator!=(Z rhs) const {
        return x != rhs.x;
    }
    bool operator<(Z rhs) const {
        return x < rhs.x;
    }
    friend Z operator+(Z lhs, Z rhs) {
        return lhs += rhs;
    }
    friend Z operator-(Z lhs, Z rhs) {
        return lhs -= rhs;
    }
    friend Z operator*(Z lhs, Z rhs) {
        return lhs *= rhs;
    }
    friend Z operator/(Z lhs, Z rhs) {
        return lhs /= rhs;
    }
    friend ostream& operator<<(ostream& out, Z a) {
        return out << a.x;
    }
    friend istream& operator>>(istream& in, Z& a) {
        long long x;
        in >> x;
        a = Z(x);
        return in;
    }
};
const int Nmax = 100;
Z dp[Nmax + 1][Nmax + 1][Nmax + 1], C[Nmax + 1][Nmax + 1], f[Nmax + 1];
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int N, M, K;
    cin >> N >> M >> K >> Z::P;
    f[0] = C[0][0] = 1;
    for (int n = 1; n <= N; ++n) {
        f[n] = n * f[n - 1];
        C[n][0] = 1;
        for (int k = 1; k <= n; ++k) {
            C[n][k] = C[n - 1][k - 1] + C[n - 1][k];
        }
    }
    for (int m = 0; m <= N; ++m) {
        dp[0][m][0] = 1;
    }
    for (int n = 1; n <= N; ++n) {
        for (int m = 1; m <= n; ++m) {
            for (int i = 0; i < n; ++i) {
                for (int k = 0; k + (k ? m - 2 : 0) <= i; ++k) {
                    for (int l = 0; l + (l ? m - 2 : 0) <= n - (i + 1); ++l) {
                        dp[n][m][k + l + (m == 1)] += C[n - 1][i] * dp[i][m - 1][k] * dp[n - (i + 1)][m - 1][l];
                    }
                }
            }
        }
        dp[n][0][0] = f[n];
        for (int m = n + 1; m <= N; ++m){
            dp[n][m][0] = f[n];
        }
    }
    cout << dp[N][M][K] << '\n';
    exit(0);
}