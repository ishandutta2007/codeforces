#include <iostream>
#include <algorithm>
#include <vector>

using lint = long long;

void solve() {
    int n, k, l;
    std::cin >> n >> k >> l;
    int m = n * k;

    std::vector<int> xs(m);
    for (auto& x : xs) std::cin >> x;

    auto xmin = *std::min_element(xs.begin(), xs.end());
    std::vector<int> ys;
    for (auto x : xs) {
        if (x - xmin <= l) ys.push_back(x);
    }

    if ((int)ys.size() < n) {
        std::cout << "0\n";
        return;
    }

    std::sort(ys.rbegin(), ys.rend());
    lint sum = 0;
    int need = n;
    while (!ys.empty()) {
        sum += ys.back();
        ys.pop_back();
        --need;

        for (int i = 0; i < k - 1 && (int)ys.size() > need; ++i) {
            ys.pop_back();
        }
    }

    std::cout << sum << "\n";
}

int main() {
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);

    solve();

    return 0;
}