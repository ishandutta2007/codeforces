#include <bits/stdc++.h>
int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int N, M;
    std::cin >> N >> M;
    int64_t X = 1;
    for (int i = 0; i < N && X <= M; ++i) {
        X *= 2;
    }
    M %= X;
    std::cout << M << '\n';
    exit(0);
}