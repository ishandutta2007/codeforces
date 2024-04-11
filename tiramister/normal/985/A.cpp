#include <iostream>
#include <algorithm>
#include <vector>

void solve() {
    int n;
    std::cin >> n;

    std::vector<int> xs(n / 2);
    for (auto& x : xs) {
        std::cin >> x;
        --x;
    }
    std::sort(xs.begin(), xs.end());

    std::vector<int> cost(2, 0);
    for (int i = 0; i < n / 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            cost[j] += std::abs(xs[i] - (i * 2 + j));
        }
    }

    std::cout << *std::min_element(cost.begin(), cost.end()) << "\n";
}

int main() {
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);

    solve();

    return 0;
}