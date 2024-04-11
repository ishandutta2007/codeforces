#include <bits/stdc++.h>

using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::string s;
    std::cin >> s;

    int n = s.size();
    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) std::cout << s[(n - 1) / 2 - i / 2];
        else std::cout << s[(n - 1) / 2 + (i + 1) / 2];
    }

    return 0;
}