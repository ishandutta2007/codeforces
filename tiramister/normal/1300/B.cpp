#include <iostream>
#include <algorithm>
#include <vector>

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> xs(n * 2);
    for (auto& x : xs) std::cin >> x;
    std::sort(xs.begin(), xs.end());
    std::cout << xs[n] - xs[n - 1] << std::endl;
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