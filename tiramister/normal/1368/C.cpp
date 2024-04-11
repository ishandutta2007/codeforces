#include <iostream>
#include <vector>

void solve() {
    int n;
    std::cin >> n;

    std::cout << n * 3 + 4 << "\n";
    for (int s = 0; s <= n; ++s) {
        std::cout << s + 0 << " " << s + 0 << "\n"
                  << s + 1 << " " << s + 0 << "\n"
                  << s + 0 << " " << s + 1 << "\n";
    }
    std::cout << n + 1 << " " << n + 1 << "\n";
}

int main() {
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);

    solve();

    return 0;
}