#include <iostream>
#include <vector>
#include <algorithm>

void solve() {
    int n;
    std::cin >> n;

    std::vector<int> xs(n);
    for (auto& x : xs) std::cin >> x;

    std::vector<int> ans(n);
    ans[0] = 0;
    for (int i = 1; i < n; ++i) {
        if (xs[i - 1] != xs[i]) {
            ans[i] = 1 - ans[i - 1];
        } else {
            ans[i] = ans[i - 1];
        }
    }

    if (xs[n - 1] != xs[0] && ans[n - 1] == ans[0]) {
        bool swapped = false;
        ans[0] = 0;
        for (int i = 1; i < n; ++i) {
            if (xs[i - 1] != xs[i]) {
                ans[i] = 1 - ans[i - 1];
            } else if (!swapped) {
                ans[i] = 1 - ans[i - 1];
                swapped = true;
            } else {
                ans[i] = ans[i - 1];
            }
        }
    }

    if (xs[n - 1] != xs[0] && ans[n - 1] == ans[0]) ans[0] = 2;

    std::cout << *std::max_element(ans.begin(), ans.end()) + 1 << "\n";
    for (auto a : ans) std::cout << a + 1 << " ";
    std::cout << "\n";
}

int main() {
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::ios::sync_with_stdio(false);

    int q;
    std::cin >> q;
    while (q--) solve();

    return 0;
}