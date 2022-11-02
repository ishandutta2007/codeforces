#include <iostream>
#include <algorithm>
#include <vector>

void solve() {
    int n, k;
    std::cin >> n >> k;

    std::vector<int> xs(n);
    for (auto& x : xs) std::cin >> x;

    std::vector<int> cnt(k * 2 + 10, 0);
    for (int i = 0; i < n / 2; ++i) {
        int x = xs[i],
            y = xs[n - i - 1];

        if (x > y) std::swap(x, y);
        // x <= y

        cnt[0] += 2;
        cnt[x + 1] -= 1;
        cnt[x + y] -= 1;
        cnt[x + y + 1] += 1;
        cnt[y + k + 1] += 1;
    }

    for (int i = 1; i < (int)cnt.size(); ++i) {
        cnt[i] += cnt[i - 1];
    }

    std::cout << *std::min_element(cnt.begin(), cnt.end())
              << std::endl;
}

int main() {
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);

    int q;
    std::cin >> q;
    while (q--) solve();

    return 0;
}