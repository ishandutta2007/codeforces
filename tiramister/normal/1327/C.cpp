#include <iostream>

void solve() {
    int n, m;
    std::cin >> n >> m;

    std::cout << n * m + n + m - 3 << std::endl;

    for (int i = 0; i < m - 1; ++i) std::cout << 'L';
    for (int i = 0; i < n - 1; ++i) std::cout << 'U';

    for (int i = 0; i < n; ++i) {
        char c = (i % 2 == 0 ? 'R' : 'L');
        for (int j = 0; j < m - 1; ++j) std::cout << c;
        if (i != n - 1) std::cout << 'D';
    }

    std::cout << std::endl;
}

int main() {
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::ios::sync_with_stdio(false);

    solve();

    return 0;
}