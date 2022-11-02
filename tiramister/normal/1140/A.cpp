#include <iostream>
#include <vector>

void solve() {
    int n;
    std::cin >> n;

    int ans = 0;
    int max = 0;
    for (int i = 1; i <= n; ++i) {
        int x;
        std::cin >> x;
        max = std::max(max, x);

        if (max <= i) {
            ++ans;
            max = 0;
        }
    }

    std::cout << ans << "\n";
}

int main() {
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);

    solve();

    return 0;
}