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
using Zp = Z<998244353>;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int N, M;
    cin >> N >> M;
    vector<int> l(N), r(N);
    for (int i = 0; i < N; ++i) {
        cin >> l[i] >> r[i];
    }
    auto solve = [&](int d) {
        int T = M / d;
        vector<Zp> dp(T + 1);
        dp[0] = 1;
        for (int i = 0; i < N; ++i) {
            partial_sum(begin(dp), end(dp), begin(dp));
            auto sum = [&](int L, int R) {
                if (R < L) return Zp();
                return dp[R] - (L > 0 ? dp[L - 1] : Zp());
            };
            vector<Zp> dpnxt(T + 1);
            for (int x = (l[i] + d - 1) / d; x <= T; ++x) {
                dpnxt[x] = sum(x - r[i] / d, x - (l[i] + d - 1) / d);
            }
            swap(dp, dpnxt);
        }
        return accumulate(begin(dp), end(dp), Zp());
    };
    vector<Zp> a(M + 1);
    for (int d = M; d >= 1; --d) {
        a[d] = solve(d);
        for (int x = 2 * d; x <= M; x += d) {
            a[d] -= a[x];
        }
    }
    cout << a[1] << '\n';
    exit(0);
}