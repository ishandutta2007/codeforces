#include <bits/stdc++.h>
int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int T;
    std::cin >> T;
    for (int t = 0; t < T; ++t) {
        int N;
        std::cin >> N;
        std::string a, b;
        std::cin >> a >> b;
        int sum = 0;
        int cnt[2]{};
        for (int i = 0; i < N; ++i) {
            int x = a[i] - '0', y = b[i] - '0';
            if (x ^ y) {
                ++cnt[x];
                ++sum;
            }
        }
        int cost = -1;
        if (sum % 2 == 0 && cnt[0] == cnt[1]) {
            cost = sum;
        }
        sum = cnt[0] = cnt[1] = 0;
        for (int i = 0; i < N; ++i) {
            int x = a[i] - '0', y = b[i] - '0';
            if (x ^ y ^ 1) {
                ++cnt[x];
                ++sum;
            }
        }
        if (sum % 2 && cnt[0] + 1 == cnt[1]) {
            if (cost == -1) {
                cost = sum;
            } else {
                cost = std::min(cost, sum);
            }
        }
        std::cout << cost << '\n';
    }
    exit(0);
}