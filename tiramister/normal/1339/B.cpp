#include <iostream>
#include <algorithm>
#include <vector>

void solve() {
    int n;
    std::cin >> n;

    std::vector<int> xs(n);
    for (auto& x : xs) std::cin >> x;

    std::sort(xs.begin(), xs.end());

    std::vector<int> ans;
    int l = 0, r = n - 1;
    for (int i = 0; i < n; ++i) {
        ans.push_back(i % 2 == 0 ? xs[l++] : xs[r--]);
    }

    std::reverse(ans.begin(), ans.end());
    for (auto a : ans) std::cout << a << " ";
    std::cout << std::endl;
}

int main() {
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);

    int q;
    std::cin >> q;
    while (q--) solve();

    return 0;
}