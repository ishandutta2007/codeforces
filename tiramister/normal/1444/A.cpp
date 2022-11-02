#include <iostream>
#include <vector>
#include <cassert>

struct Prime {
    int max_n;
    std::vector<int> primes;
    std::vector<bool> isp;

    explicit Prime(int max_n)
        : max_n(max_n), isp(max_n + 1, true) {
        isp[0] = isp[1] = false;
        for (int i = 2; i * i <= max_n; ++i) {
            if (isp[i]) {
                for (int j = i; i * j <= max_n; ++j) {
                    isp[i * j] = false;
                }
            }
        }

        for (int p = 2; p <= max_n; ++p) {
            if (isp[p]) primes.push_back(p);
        }
    }

    template <class T>
    bool isprime(T n) const {
        if (n <= max_n) return isp[n];
        for (T p : primes) {
            if (p * p > n) break;
            if (n % p == 0) return false;
        }
        return true;
    }

    template <class T>
    std::vector<std::pair<T, int>> factorize(T n) const {
        std::vector<std::pair<T, int>> facts;
        for (T p : primes) {
            if (p * p > n) break;
            if (n % p != 0) continue;
            int exp = 0;
            while (n % p == 0) {
                n /= p;
                ++exp;
            }
            facts.emplace_back(p, exp);
        }
        if (n > 1) {
            facts.emplace_back(n, 1);
        }
        return facts;
    }

    template <class T>
    static std::vector<T> divisors(T n) {
        std::vector<T> ret;
        for (T p = 1; p * p <= n; ++p) {
            if (n % p != 0) continue;
            ret.push_back(p);
            if (n / p == p) continue;
            ret.push_back(n / p);
        }
        return ret;
    }
};

using lint = long long;
const Prime P(100000);

void solve() {
    lint x, y;
    std::cin >> x >> y;

    if (x % y != 0) {
        std::cout << x << "\n";
        return;
    }

    auto ps = P.factorize(y);
    lint ans = 0;
    for (auto [p, c] : ps) {
        auto xx = x;
        while (xx % p == 0) xx /= p;
        for (int i = 0; i < c - 1; ++i) xx *= p;

        assert(x % xx == 0 && xx % y != 0);
        ans = std::max(ans, xx);
    }

    std::cout << ans << "\n";
}

int main() {
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);

    int q;
    std::cin >> q;
    while (q--) solve();

    return 0;
}