#include <bits/stdc++.h>
int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int T;
    std::cin >> T;
    for (int t = 0; t < T; ++t) {
        int N;
        std::cin >> N;
        std::string S;
        std::cin >> S;
        std::set<char> C;
        bool good = true;
        for (int i = 0; i < N; ++i) {
            if (C.count(S[i])) {
                good = false;
                break;
            }
            C.insert(S[i]);
            while (i + 1 < N && S[i] == S[i + 1]) ++i;
        }
        std::cout << (good ? "YES" : "NO") << '\n';
    }
    exit(0);
}