#include <iostream>
#include <vector>

template <class T>
std::vector<T> vec(int len, T elem) { return std::vector<T>(len, elem); }

void solve() {
    int n, m;
    std::cin >> n >> m;

    auto a = vec(n, vec(m, 0));
    auto b = a;

    for (auto& v : a) {
        for (auto& x : v) {
            std::cin >> x;
        }
    }

    std::vector<std::pair<int, int>> ans;
    for (int i = 0; i + 1 < n; ++i) {
        for (int j = 0; j + 1 < m; ++j) {
            bool ok = true;
            for (int di = 0; di < 2; ++di) {
                for (int dj = 0; dj < 2; ++dj) {
                    if (a[i + di][j + dj] == 0) ok = false;
                }
            }
            if (!ok) continue;

            ans.emplace_back(i, j);
            for (int di = 0; di < 2; ++di) {
                for (int dj = 0; dj < 2; ++dj) {
                    b[i + di][j + dj] = 1;
                }
            }
        }
    }

    if (a != b) {
        std::cout << "-1\n";
        return;
    }

    std::cout << ans.size() << "\n";
    for (auto p : ans) {
        std::cout << p.first + 1 << " " << p.second + 1 << "\n";
    }
}

int main() {
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);

    solve();

    return 0;
}