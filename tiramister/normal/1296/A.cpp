#include <iostream>

void solve() {
    int n;
    std::cin >> n;
    bool odd = false, even = false;
    int sum = 0;
    for (int i = 0; i < n; ++i) {
        int x;
        std::cin >> x;
        sum += x;
        (x % 2 == 0 ? even : odd) = true;
    }

    std::cout << (!(odd && even) && sum % 2 == 0 ? "NO" : "YES")
              << std::endl;
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