#include <iostream>
#include <vector>

template <class T>
std::vector<T> vec(int len, T elem) { return std::vector<T>(len, elem); }

void solve() {
    int n, m;
    std::cin >> n >> m;

    auto xss = vec(n, vec(m, 0));
    for (auto& xs : xss) {
        for (auto& x : xs) {
            char c;
            std::cin >> c;
            x = c - '0';
        }
    }

    std::vector<int> sum(m, 0);
    for (auto& xs : xss) {
        for (int j = 0; j < m; ++j) {
            sum[j] += xs[j];
        }
    }

    for (auto& xs : xss) {
        bool judge = true;
        for (int j = 0; j < m; ++j) {
            if (sum[j] - xs[j] == 0) judge = false;
        }

        if (judge) {
            std::cout << "YES\n";
            return;
        }
    }

    std::cout << "NO\n";
}

int main() {
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);

    solve();

    return 0;
}