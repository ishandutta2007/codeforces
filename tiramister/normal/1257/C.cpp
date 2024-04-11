#include <iostream>
#include <vector>

void solve() {
    int n;
    std::cin >> n;

    int ans = n + 1;
    std::vector<int> prev(n, -1);
    for (int i = 0; i < n; ++i) {
        int x;
        std::cin >> x;
        --x;

        if (prev[x] < 0) {
            prev[x] = i;
        } else {
            ans = std::min(ans, i - prev[x] + 1);
            prev[x] = i;
        }
    }

    std::cout << (ans > n ? -1 : ans) << std::endl;
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