#include <iostream>

using lint = long long;

void solve() {
    int n;
    std::cin >> n;

    int ans = 0;
    for (int i = 2; i + 1 <= n; ++i) ans += i * (i + 1);

    std::cout << ans << "\n";
}

int main() {
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);

    solve();

    return 0;
}