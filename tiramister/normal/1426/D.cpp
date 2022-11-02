#include <iostream>
#include <vector>
#include <map>

using lint = long long;

void solve() {
    int n;
    std::cin >> n;

    int prev = -1, ans = 0;

    std::map<lint, int> pos;
    lint sum = 0;
    pos[sum] = 0;
    for (int i = 1; i <= n; ++i) {
        lint x;
        std::cin >> x;
        sum += x;

        if (pos.count(sum)) {
            auto p = pos[sum];
            if (p >= prev) {
                ++ans;
                prev = i - 1;
            }
        }

        pos[sum] = i;
    }

    std::cout << ans << "\n";
}

int main() {
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);

    solve();

    return 0;
}