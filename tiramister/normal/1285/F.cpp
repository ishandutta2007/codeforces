#include <iostream>
#include <algorithm>
#include <vector>

template <class T>
T gcd(T n, T m) {
    while (m != 0) {
        n %= m;
        std::swap(n, m);
    }
    return n;
}

using lint = long long;
constexpr int X = 100000;

int main() {
    std::vector<std::vector<int>> pss(X + 1);  // set of x's factors
    for (int p = 1; p <= X; ++p) {
        for (int x = p; x <= X; x += p) {
            pss[x].push_back(p);
        }
    }

    std::vector<int> f(X + 1, 0);  // mobius function
    f[1] = 1;
    for (int d = 2; d <= X; ++d) {
        for (int p : pss[d]) {
            if (p < d) f[d] -= f[p];
        }
    }

    int n;
    std::cin >> n;

    std::vector<int> xs(n);
    for (auto& x : xs) std::cin >> x;
    std::sort(xs.rbegin(), xs.rend());

    std::vector<std::vector<int>> yss(X + 1);  // x's multipliers
    for (auto x : xs) {
        for (auto p : pss[x]) {
            yss[p].push_back(x / p);
        }
    }

    lint ans = 0;
    std::vector<int> cnt(X + 1, 0), stk;

    for (int d = 1; d <= X; ++d) {
        const auto& ys = yss[d];

        for (auto y : ys) {
            while (true) {
                int c = 0;  // number of elements coprime to x in the stack
                for (auto p : pss[y]) c += cnt[p] * f[p];
                if (c == 0) break;

                auto x = stk.back();
                if (gcd(x, y) == 1) {
                    ans = std::max(ans, (lint)x * y * d);
                }

                for (auto p : pss[x]) --cnt[p];  // delete x from the stack
                stk.pop_back();
            }

            for (auto p : pss[y]) ++cnt[p];  // add y to the stack
            stk.push_back(y);
        }

        // clear the stack and cnt
        while (!stk.empty()) {
            auto x = stk.back();
            for (auto p : pss[x]) --cnt[p];
            stk.pop_back();
        }
    }

    std::cout << ans << std::endl;
    return 0;
}