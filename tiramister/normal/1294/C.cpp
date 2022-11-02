#include <iostream>
#include <vector>

void solve() {
    int n;
    std::cin >> n;

    int idx = 0;
    std::vector<int> ans(2);

    for (int p = 2; p * p <= n && idx < 2; ++p) {
        if (n % p == 0 && idx < 2) {
            ans[idx] = p;
            n /= p;
            ++idx;
        }
    }

    if (idx < 2 || n == ans[1]) {
        std::cout << "NO" << std::endl;
    } else {
        std::cout << "YES" << std::endl
                  << ans[0] << " " << ans[1] << " " << n
                  << std::endl;
    }
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