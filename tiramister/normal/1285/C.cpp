#include <iostream>
#include <vector>

using lint = long long;

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
};

const Prime P(2000000);

int main() {
    lint x;
    std::cin >> x;

    auto fs = P.factorize(x);
    std::vector<lint> ps;
    for (auto p : fs) {
        lint a = 1;
        while (p.second--) a *= p.first;
        ps.push_back(a);
    }

    lint al = 1, ar = x;
    int n = ps.size();
    for (int b = 0; b < (1 << n); ++b) {
        lint l = 1, r = 1;
        for (int i = 0; i < n; ++i) {
            if ((b >> i) & 1) {
                l *= ps[i];
            } else {
                r *= ps[i];
            }
        }
        if (l > r) continue;
        if (r < ar) {
            al = l, ar = r;
        }
    }

    std::cout << al << " " << ar << std::endl;
    return 0;
}