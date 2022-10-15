#include <bits/stdc++.h>
template<int P>
struct Z {
    int x;
    Z() : x(0) {}
    Z(int64_t x_) {
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
        x = int64_t(x) * rhs.x % P;
        return *this;
    }
    Z& operator/=(Z rhs) {
        return *this *= rhs.power(-1);
    }
    Z power(int64_t p) const {
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
    friend std::ostream& operator<<(std::ostream& out, Z a) {
        return out << a.x;
    }
    friend std::istream& operator>>(std::istream& in, Z& a) {
        int64_t x;
        in >> x;
        a = Z(x);
        return in;
    }
    inline static const Z X = [](){
        std::uniform_int_distribution<int64_t> unif(1, P - 1);
        std::mt19937 rng(std::chrono::steady_clock::now().time_since_epoch().count());
        return unif(rng);
    }(), Xinv = 1 / X;
};
using Zp = Z<998244353>;
int C2(int n) {
    return n * (n - 1) / 2;
}
int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int N;
    std::cin >> N;
    Zp a, b;
    std::cin >> a >> b;
    Zp p = a / b;
    std::vector<Zp> split(N + 1), fail(N + 1), dp(N + 1);
    split[0] = split[1] = 1;
    fail[1] = 1;
    for (int n = 2; n <= N; ++n) {
        std::vector<Zp> nsplit(N + 1);
        for (int k = 0; k < n; ++k) {
            nsplit[k + 1] += split[k] * (1 - p).power(n - 1 - k);
            nsplit[k] += split[k] * p.power(k);
        }
        std::swap(split, nsplit);
        fail[n] = 1;
        for (int m = 1; m < n; ++m) {
            fail[n] -= split[m] * fail[m];
        }
        dp[n] += C2(n) * 1 / (1 - fail[n]);
        for (int m = 1; m < n; ++m) {
            dp[n] += (dp[m] + dp[n - m] - C2(n - m)) * split[m] * fail[m] / (1 - fail[n]);
        }
    }
    std::cout << dp[N] << '\n';
    exit(0);
}