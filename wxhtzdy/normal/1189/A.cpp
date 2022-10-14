#include <bits/stdc++.h>

using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;

    std::string s;
    std::cin >> s;

    int f = 0;
    for (int i = 0; i < n; i++) {
        f += (s[i] == '1' ? +1 : -1);
    }

    if (f != 0) {
        std::cout << "1\n" << s << "\n";
    } else {
        std::cout << "2\n";
        for (int i = 0; i < n - 1; i++) std::cout << s[i];
        std::cout << " " << s[n - 1] << "\n";
    }

    return 0;
}