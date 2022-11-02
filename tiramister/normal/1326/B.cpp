#include <iostream>

using lint = long long;

void solve() {
    int n;
    std::cin >> n;

    lint max = 0;
    while (n--) {
        lint d;
        std::cin >> d;
        std::cout << max + d << " ";
        if (d > 0) max += d;
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