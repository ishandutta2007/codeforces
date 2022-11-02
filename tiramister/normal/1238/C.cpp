#include <iostream>
#include <algorithm>
#include <vector>

void solve() {
    int h, n;
    std::cin >> h >> n;

    std::vector<int> xs(n);
    for (auto& x : xs) std::cin >> x;
    std::reverse(xs.begin(), xs.end());

    int ans = 0;
    xs.pop_back();

    while (!xs.empty()) {
        int x = xs.back();
        xs.pop_back();

        if (xs.empty()) {
            if (x > 1) ++ans;
            break;
        }

        if (x - 1 > xs.back()) {
            ++ans;
        } else {
            xs.pop_back();
        }
    }

    std::cout << ans << std::endl;
}

int main() {
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);

    int q;
    std::cin >> q;
    while (q--) solve();

    return 0;
}