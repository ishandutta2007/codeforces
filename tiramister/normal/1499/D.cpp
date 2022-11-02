#include <iostream>
#include <vector>
#include <map>

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

using namespace std;
using lint = long long;

constexpr int N = 20000000;
vector<int> fsize(N + 1, 0);

void init() {
    for (int p = 2; p <= N; ++p) {
        if (fsize[p] != 0) continue;
        for (int x = p; x <= N; x += p) ++fsize[x];
    }
}

const Prime P(10000);

void solve() {
    int c, d, x;
    cin >> c >> d >> x;

    lint ans = 0;

    for (auto e : P.divisors(x)) {
        auto nx = x / e;
        if ((nx + d) % c != 0) continue;

        auto ab = (nx + d) / c;
        ans += 1LL << fsize[ab];
    }

    cout << ans << "\n";
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    init();

    int q;
    cin >> q;
    while (q--) solve();

    return 0;
}