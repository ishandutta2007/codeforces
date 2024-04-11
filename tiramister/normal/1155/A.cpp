#include <iostream>
#include <string>

void solve() {
    int n;
    std::string s;
    std::cin >> n >> s;

    for (int i = 0; i + 1 < n; ++i) {
        if (s[i] <= s[i + 1]) continue;

        std::cout << "YES\n"
                  << i + 1 << " " << i + 2
                  << "\n";
        return;
    }

    std::cout << "NO\n";
}

int main() {
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);

    solve();

    return 0;
}