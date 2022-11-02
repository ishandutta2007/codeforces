#include <iostream>
#include <numeric>
#include <vector>

void solve() {
    int n;
    std::cin >> n;

    std::vector<int> xs(n);
    for (auto& x : xs) std::cin >> x;
    int sum = std::accumulate(xs.begin(), xs.end(), 0);

    int acc = 0;
    for (int i = 0; i < n; ++i) {
        acc += xs[i];
        if (acc * 2 >= sum) {
            std::cout << i + 1 << "\n";
            return;
        }
    }
}

int main() {
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);

    solve();

    return 0;
}