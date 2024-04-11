#include <iostream>
#include <vector>

void solve() {
    int n, m;
    std::cin >> n >> m;

    std::vector<int> xs(n), ys(m);
    for (auto& x : xs) std::cin >> x;
    for (auto& y : ys) std::cin >> y;

    int i = 0, j = 0;
    while (i < n && j < m) {
        if (xs[i] <= ys[j]) ++j;
        ++i;
    }

    std::cout << j << "\n";
}

int main() {
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);

    solve();

    return 0;
}