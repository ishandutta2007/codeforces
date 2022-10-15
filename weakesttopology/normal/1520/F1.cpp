#include <bits/stdc++.h>
int query(int l, int r) {
    std::cout << "? " << l << ' ' << r << std::endl;
    int res;
    std::cin >> res;
    if (res == -1) exit(0);
    return r - l + 1 - res; // number of zeros
}
int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int N, T;
    std::cin >> N >> T;
    int K;
    std::cin >> K;
    int L = 0, R = N;
    // query(1, 0) = 0
    // query(1, L) < K
    // query(1, R) >= K
    while (L + 1 < R) {
        int M = (L + R) / 2;
        query(1, M) < K ? L = M : R = M;
    }
    std::cout << "! " << R << '\n';
    exit(0);
}