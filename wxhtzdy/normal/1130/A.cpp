#include <bits/stdc++.h>

using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;

    std::vector<int> a(n);
    std::vector<int> cnt(2);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
        if (a[i] < 0) cnt[0]++;
        if (a[i] > 0) cnt[1]++;
    }

    if (cnt[0] >= (n + 1) / 2) {
        std::cout << -1;
    } else {
        if (cnt[1] >= (n + 1) / 2) {
            std::cout << 1;
        } else {
            std::cout << 0;
        }
    }

    return 0;
}