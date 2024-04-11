#include <bits/stdc++.h>
int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int N, I;
    std::cin >> N >> I;
    I *= 8;
    std::vector<int> a(N);
    for (int i = 0; i < N; ++i) {
        std::cin >> a[i];
    }
    std::sort(a.begin(), a.end());
    int log = std::min(30, I / N);
    int ans = N;
    for (int l = 0, r = 0, K = 1; l < N; ++l) {
        if (r < l) {
            r = l;
            K = 1;
        }
        while (r + 1 < N && (1 << log) >= K + (a[r + 1] != a[r])) {
            K += a[r + 1] != a[r];
            ++r;
        }
        ans = std::min(ans, l + N - 1 - r);
        K -= l < r && a[l] != a[l + 1];
    }
    std::cout << ans << '\n';
    exit(0);
}