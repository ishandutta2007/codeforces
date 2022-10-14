#include <bits/stdc++.h>

using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::string s;
    std::cin >> s;
    int n = s.size();

    for (int i = 0; i < n; i++) {
        if (s[i] == 'r') std::cout << i + 1 << "\n";
     }

     for (int i = n - 1; i >= 0; i--) {
         if (s[i] == 'l') std::cout << i + 1 << "\n";
     }
    return 0;
}