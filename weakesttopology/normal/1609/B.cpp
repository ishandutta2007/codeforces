#include <bits/stdc++.h>
int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int N, Q;
    std::string s;
    std::cin >> N >> Q >> s;
    int cost = 0;
    for (int i = 0; i + 3 <= N; ++i) {
        cost += s.substr(i, 3) == "abc";
    }
    for (int q = 0; q < Q; ++q) {
        int i;
        char c;
        std::cin >> i >> c;
        --i;
        auto check = [&]() {
            for (int j = std::max(i - 2, 0); j + 3 <= N && j <= i; ++j) {
                if (s.substr(j, 3) == "abc") {
                    return true;
                }
            }
            return false;
        };
        cost -= check();
        s[i] = c;
        cost += check();
        std::cout << cost << '\n';
    }
    exit(0);
}