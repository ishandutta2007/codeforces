#include <iostream>

using lint = long long;

void solve() {
    int n;
    lint m;
    std::cin >> n >> m;

    lint sum = 0, prev = 0;
    while (n--) {
        lint x;
        std::cin >> x;
        sum += x;

        std::cout << sum / m - prev << " ";
        prev = sum / m;
    }
    std::cout << "\n";
}

int main() {
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);

    solve();

    return 0;
}