#include <iostream>
#include <vector>

void solve() {
    std::vector<int> xs(4);
    for (auto& x : xs) std::cin >> x;

    std::cout << (xs[0] != xs[3] || (xs[0] == 0 && xs[2] > 0) ? 0 : 1)
              << "\n";
}

int main() {
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);

    solve();

    return 0;
}