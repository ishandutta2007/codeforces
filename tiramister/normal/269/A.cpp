#include <iostream>

using lint = long long;

void solve() {
    int n;
    std::cin >> n;

    int ans = 0;
    while (n--) {
        int k;
        lint a;
        std::cin >> k >> a;

        int d = 1;
        while ((1LL << d) * (1LL << d) < a) {
            ++d;
        }
        ans = std::max(ans, k + d);
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