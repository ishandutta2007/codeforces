#include <iostream>
#include <string>

void solve() {
    std::string a, b, c;
    std::cin >> a >> b >> c;

    int n = a.length();
    for (int i = 0; i < n; ++i) {
        if (a[i] == c[i] || b[i] == c[i]) continue;
        std::cout << "NO" << std::endl;
        return;
    }
    std::cout << "YES" << std::endl;
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