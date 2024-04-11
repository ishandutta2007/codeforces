#include <iostream>
#include <vector>

template <class T>
std::vector<T> vec(int len, T elem) { return std::vector<T>(len, elem); }

void solve() {
    int n;
    std::cin >> n;

    if (n <= 2) {
        std::cout << -1 << std::endl;
        return;
    }

    auto ans = vec(n, vec(n, -1));
    ans[0][0] = 8, ans[0][1] = 6, ans[0][2] = 7;
    ans[1][0] = 2, ans[1][1] = 5, ans[1][2] = 0;
    ans[2][0] = 1, ans[2][1] = 3, ans[2][2] = 4;

    int id = 9, j = 3;
    for (int i = 0; i < n; ++i) {
        if (j == n - 1) {
            while (j >= 0 && ans[i][j] == -1) {
                ans[i][j] = id++;
                --j;
            }
            ++j;
        } else {
            while (j < n && ans[i][j] == -1) {
                ans[i][j] = id++;
                ++j;
            }
            --j;
        }
    }

    for (const auto& v : ans) {
        for (auto a : v) {
            std::cout << n * n - a << " ";
        }
        std::cout << std::endl;
    }
}

int main() {
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);

    solve();

    return 0;
}