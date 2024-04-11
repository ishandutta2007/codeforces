#include <iostream>
#include <numeric>
#include <vector>

void solve() {
    int n, m;
    std::cin >> n >> m;

    if (m < n - 1) {
        std::cout << "Impossible\n";
        return;
    }

    std::vector<std::pair<int, int>> ps;
    for (int v = 1; v <= n; ++v) {
        for (int u = v + 1; u <= n; ++u) {
            if (std::gcd(u, v) == 1) {
                ps.emplace_back(v, u);
                if ((int)ps.size() == m) break;
            }
        }
        if ((int)ps.size() == m) break;
    }

    if ((int)ps.size() != m) {
        std::cout << "Impossible\n";
    } else {
        std::cout << "Possible\n";
        for (auto p : ps) {
            std::cout << p.first << " " << p.second << "\n";
        }
    }
}

int main() {
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);

    solve();

    return 0;
}