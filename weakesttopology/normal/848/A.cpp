#include <bits/stdc++.h>
int C2(int N) {
    return N * (N - 1) / 2;
}
int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int K;
    std::cin >> K;
    for (char ch = 'a'; ch <= 'z'; ++ch) {
        int N = 0;
        while (C2(N + 1) <= K) ++N;
        K -= C2(N);
        std::cout << std::string(N, ch);
    }
    std::cout << '\n';
    exit(0);
}