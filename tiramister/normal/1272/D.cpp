#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

void solve() {
    int n;
    std::cin >> n;

    std::vector<int> xs(n);
    for (auto& x : xs) std::cin >> x;

    std::vector<int> fore(n), back(n);
    fore[0] = 1;
    for (int i = 1; i < n; ++i) {
        if (xs[i - 1] < xs[i]) {
            fore[i] = fore[i - 1] + 1;
        } else {
            fore[i] = 1;
        }
    }

    back[n - 1] = 1;
    for (int i = n - 2; i >= 0; --i) {
        if (xs[i] < xs[i + 1]) {
            back[i] = back[i + 1] + 1;
        } else {
            back[i] = 1;
        }
    }

    int ans = *std::max_element(fore.begin(), fore.end());
    for (int i = 1; i < n - 1; ++i) {
        if (xs[i - 1] >= xs[i + 1]) continue;
        ans = std::max(ans, fore[i - 1] + back[i + 1]);
    }
    std::cout << ans << std::endl;
}

int main() {
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::ios::sync_with_stdio(false);

    solve();

    return 0;
}