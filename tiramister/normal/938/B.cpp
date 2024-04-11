#include <iostream>
#include <cmath>

void solve() {
    int n;
    std::cin >> n;

    int ans = 0;
    while (n--) {
        int x;
        std::cin >> x;
        ans = std::max(ans, std::min(std::abs(x - 1), std::abs(x - 1000000)));
    }
    std::cout << ans << std::endl;
}

int main() {
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::ios::sync_with_stdio(false);

    solve();

    return 0;
}