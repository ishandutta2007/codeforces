#include <iostream>
#include <vector>

constexpr int X = 10000000;

void solve() {
    std::vector<int> ps(X + 1, -1);
    for (int p = 2; p * p <= X; ++p) {
        if (ps[p] != -1) continue;
        for (int q = p * 2; q <= X; q += p) {
            ps[q] = p;
        }
    }

    int q;
    std::cin >> q;
    std::vector<std::pair<int, int>> anss(q);

    for (auto& ans : anss) {
        int n;
        std::cin >> n;

        if (ps[n] == -1) {
            ans.first = ans.second = -1;
        } else {
            int p = ps[n];

            ans.first = 1;
            while (n % p == 0) {
                n /= p;
                ans.first *= p;
            }
            ans.second = n;

            if (n == 1) {
                ans.first = ans.second = -1;
            }
        }
    }

    for (const auto& ans : anss) std::cout << ans.first << " ";
    std::cout << "\n";
    for (const auto& ans : anss) std::cout << ans.second << " ";
    std::cout << "\n";
}

int main() {
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);

    solve();

    return 0;
}