#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using lint = long long;
using ldouble = long double;

void solve() {
    std::string s;
    std::cin >> s;
    int n = s.length();

    for (int i = -1; i < n; ++i) {
        int cnt = 0;
        for (int j = 0; j <= i; ++j) {
            if (s[j] == '(') ++cnt;
        }
        int pcnt = cnt;
        for (int j = i + 1; j < n; ++j) {
            if (s[j] == ')') --cnt;
        }

        if (cnt == 0) {
            if (pcnt == 0) {
                std::cout << 0 << std::endl;
                return;
            }

            std::cout << 1 << std::endl
                      << pcnt * 2 << std::endl;

            for (int j = 0; j <= i; ++j) {
                if (s[j] == '(') std::cout << j + 1 << " ";
            }
            for (int j = i + 1; j < n; ++j) {
                if (s[j] == ')') std::cout << j + 1 << " ";
            }
            std::cout << std::endl;
            return;
        }
    }
    std::terminate();
}

int main() {
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::ios::sync_with_stdio(false);

    solve();

    return 0;
}