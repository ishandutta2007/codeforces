#include <bits/stdc++.h>

using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;

    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }

    int m;
    std::cin >> m;

    while (m--) {
        int x, y;
        std::cin >> x >> y;
        --x;

        int l = y - 1, r = a[x] - y;
        if (x > 0) a[x - 1] += l;
        if (x + 1 < n) a[x + 1] += r;
        a[x] = 0;
    }

    for (int i = 0; i < n; i++) {
        std::cout << a[i] << "\n";
    }

    return 0;
}