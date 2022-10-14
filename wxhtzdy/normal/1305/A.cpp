#include <bits/stdc++.h>

using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t;
    std::cin >> t;

    while (t--) {
        int n;
        std::cin >> n;

        std::vector<int> a(n);
        for (int i = 0; i < n; i++) {
            std::cin >> a[i];
        }

        std::vector<int> b(n);
        for (int i = 0; i < n; i++) {
            std::cin >> b[i];
        }

        std::sort(a.begin(), a.end());
        std::sort(b.begin(), b.end());

        for (int i = 0; i < n; i++) {
            std::cout << a[i] << " ";
        }
        std::cout << "\n";
        for (int i = 0; i < n; i++) {
            std::cout << b[i] << " ";
        }
        std::cout << "\n";
    }
    return 0;
}