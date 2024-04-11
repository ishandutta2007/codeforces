#include <bits/stdc++.h>
using namespace std;
template<long long P>
struct Z {
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
    bool operator==(Z rhs) const { return x == rhs.x; }
    bool operator!=(Z rhs) const { return x != rhs.x; }
    bool operator<(Z rhs) const { return x < rhs.x; }
    friend Z operator+(Z lhs, Z rhs) { return lhs += rhs; }
    friend Z operator-(Z lhs, Z rhs) { return lhs -= rhs; }
    friend Z operator*(Z lhs, Z rhs) { return lhs *= rhs; }
    friend Z operator/(Z lhs, Z rhs) { return lhs /= rhs; }
    friend ostream& operator<<(ostream& out, Z a) { return out << a.x; }
    friend istream& operator>>(istream& in, Z& a) {
        long long x;
        in >> x;
        a = Z(x);
        return in;
    }
    inline static const Z X = [](){
        uniform_int_distribution<long long> unif(1, P - 1);
        mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
        return unif(rng);
    }(), Xinv = 1 / X;
};
using Zp = Z<(int)1e9 + 7>;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int N;
    cin >> N;
    vector<Zp> a(N);
    for (int i = 0; i < N; ++i) {
        cin >> a[i];
    }
    vector<vector<Zp>> p(N, vector<Zp>(1 << N, 1)), q(N, vector<Zp>(1 << N, 1));
    vector<int> inv(1 << N);
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (i == j) continue;
            p[i][1 << j] = (a[i] + a[j]) / a[i];
            q[i][1 << j] = a[j] / (a[i] + a[j]);
        }
        for (int mask = 1; mask < (1 << N); ++mask) {
            int lsb = mask & -mask;
            p[i][mask] = p[i][mask ^ lsb] * p[i][lsb];
            q[i][mask] = q[i][mask ^ lsb] * q[i][lsb];
        }
        inv[1 << i] = i;
    }
    vector<Zp> dp(1 << N), aux(1 << N);
    vector<int> popcount(1 << N);
    Zp ans = 0;
    for (int mask = 1; mask < (1 << N); ++mask) {
        int lsb = mask & -mask;
        popcount[mask] = 1 + popcount[mask ^ lsb];
        dp[mask] = aux[mask] = 1;
        for (int submask = mask & (mask - 1); submask > 0; submask = (submask - 1) & mask) {
            int complement = mask ^ submask, lsb = complement & -complement;
            aux[submask] = aux[submask ^ lsb] * p[inv[lsb]][complement] * q[inv[lsb]][submask];
            dp[mask] -= dp[submask] * aux[submask];
        }
        Zp coef = dp[mask];
        for (int i = 0; i < N; ++i) {
            if (~mask >> i & 1) {
                coef *= q[i][mask];
            }
        }
        ans += popcount[mask] * coef;
    }
    cout << ans << '\n';
    exit(0);
}