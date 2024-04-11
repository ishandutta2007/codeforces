#include <iostream>
#include <algorithm>
#include <vector>

void solve() {
    int n, z;
    std::cin >> n >> z;

    std::vector<int> xs(n);
    for (auto& x : xs) std::cin >> x;
    std::sort(xs.begin(), xs.end());

    int ok = 0, ng = n / 2 + 1;
    while (ng - ok > 1) {
        int k = (ok + ng) / 2;

        bool judge = true;
        for (int i = 0; i < k; ++i) {
            if (xs[n - k + i] - xs[i] < z) judge = false;
        }

        if (judge) {
            ok = k;
        } else {
            ng = k;
        }
    }

    std::cout << ok << "\n";
}

int main() {
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);

    solve();

    return 0;
}