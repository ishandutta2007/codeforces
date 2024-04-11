#include <bits/stdc++.h>
int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int T;
    std::cin >> T;
    for (int t = 0; t < T; ++t) {
        int N;
        std::cin >> N;
        std::vector<int> a(N);
        for (int i = 0; i < N; ++i) {
            std::cin >> a[i];
        }
        bool dead = false;
        for (int i = 0; i + 1 < N; ++i) {
            if (a[i] == 0 && a[i + 1] == 0) {
                dead = true;
                break;
            }
        }
        int ans = -1;
        if (!dead) {
            ans = 1;
            for (int i = 0; i < N; ++i) {
                if (a[i] == 1) {
                    ++ans;
                    if (i > 0 && a[i - 1] == 1) {
                        ans += 4;
                    }
                }
            }
        }
        std::cout << ans << '\n';
    }
    exit(0);
}