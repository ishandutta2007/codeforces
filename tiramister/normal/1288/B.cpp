#include <iostream>
#include <string>

using lint = long long;

void solve() {
    lint a, b;
    std::cin >> a >> b;
    lint n = std::to_string(b + 1).length() - 1;
    std::cout << n * a << std::endl;
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