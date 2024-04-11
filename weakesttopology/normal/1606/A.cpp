
#include <bits/stdc++.h>
int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int T;
    std::cin >> T;
    for (int t = 0; t < T; ++t) {
        std::string S;
        std::cin >> S;
        if (S[0] != S.back()) {
            S.back() = S[0];
        }
        std::cout << S << '\n';
    }
    exit(0);
}