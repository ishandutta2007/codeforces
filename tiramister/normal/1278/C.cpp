#include <iostream>
#include <vector>
#include <map>

void solve() {
    int n;
    std::cin >> n;

    std::vector<int> xs(n * 2);
    for (auto& x : xs) std::cin >> x;

    int d = 0;
    for (auto x : xs) d += (x == 1 ? 1 : -1);

    std::map<int, int> left;
    left[0] = 0;
    {
        int cnt = 0;
        for (int k = 1; k <= n; ++k) {
            cnt += (xs[n - k] == 1 ? 1 : -1);
            if (!left.count(cnt)) left[cnt] = k;
        }
    }

    int ans = n * 2;

    int cnt = 0;
    if (left.count(d - cnt)) ans = left[d - cnt];
    for (int k = 1; k <= n; ++k) {
        cnt += (xs[n + k - 1] == 1 ? 1 : -1);
        if (left.count(d - cnt)) ans = std::min(ans, k + left[d - cnt]);
    }
    std::cout << ans << std::endl;
}

int main() {
    int q;
    std::cin >> q;
    while (q--) solve();
    return 0;
}