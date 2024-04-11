#include <iostream>
#include <algorithm>
#include <string>

void solve() {
    int n;
    std::string s;
    std::cin >> n >> s;

    for (int i = 0; i < 10; ++i) s.pop_back();
    n -= 10;

    std::cout << (std::count(s.begin(), s.end(), '8') <= n / 2 ? "NO" : "YES")
              << "\n";
}

int main() {
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);

    solve();

    return 0;
}