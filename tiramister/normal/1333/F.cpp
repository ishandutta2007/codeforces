#include <iostream>
#include <vector>

void solve() {
    int n;
    std::cin >> n;

    std::vector<int> ans(n + 1, n);
    std::vector<bool> chosen(n + 1, false);
    int cnt = 0;

    for (int g = n; g >= 1; --g) {
        for (int h = g; h <= n; h += g) {
            if (chosen[h]) --cnt;
            chosen[h] = false;
        }
        chosen[g] = true;
        ++cnt;

        int k = cnt + g - 1;
        ans[k] = g - 1;
    }

    for (int k = n - 1; k >= 2; --k) {
        ans[k] = std::min(ans[k], ans[k + 1]);
    }

    for (int k = 2; k <= n; ++k) {
        std::cout << ans[k] << " ";
    }
    std::cout << std::endl;
}

int main() {
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);

    solve();

    return 0;
}