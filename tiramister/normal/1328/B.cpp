#include <iostream>
#include <string>

using lint = long long;

void solve() {
    lint n, k;
    std::cin >> n >> k;
    --k;

    std::string ans(n, 'a');

    for (lint i = 1; i < n; ++i) {
        if (k >= i) {
            k -= i;
        } else {
            ans[n - 1 - i] = 'b';
            ans[n - 1 - k] = 'b';
            break;
        }
    }

    std::cout << ans << std::endl;
}

int main() {
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::ios::sync_with_stdio(false);

    int q;
    std::cin >> q;
    while (q--) solve();

    return 0;
}