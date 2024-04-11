#include <bits/stdc++.h>

using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;

    std::string s, t;
    std::cin >> s >> t;

    int sum = 0, x = 0, y = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '1' && t[i] == '0') {
            sum++;
            x = std::max(0, x - 1);
            y++;
        }
        if (s[i] == '0' && t[i] == '1') {
            sum--;
            x++;
            y = std::max(0, y - 1);
        }
    }

    std::cout << (sum == 0 ? x + y : -1);

    return 0;
}