#include <iostream>
#include <vector>

using lint = long long;
constexpr lint INF = 1 << 30;

void solve() {
    lint n;
    int m;
    std::cin >> n >> m;

    std::vector<int> cnt(61, 0);
    while (m--) {
        lint a;
        std::cin >> a;

        int c = 0;
        while (a > 1) {
            a >>= 1;
            ++c;
        }
        ++cnt[c];
    }

    int ans = 0, prev = -1;
    for (int k = 0; k < 60; ++k) {
        if (prev >= 0) {
            if (cnt[k] > 0) {
                --cnt[k];
                ans += k - prev;
                prev = -1;
            } else {
                continue;
            }
        }

        if ((n >> k) & 1) {
            if (cnt[k] > 0) {
                --cnt[k];
            } else {
                prev = k;
            }
        }
        cnt[k + 1] += cnt[k] / 2;
    }

    std::cout << (prev != -1 ? -1 : ans) << std::endl;
}

int main() {
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::ios::sync_with_stdio(false);

    int q;
    std::cin >> q;
    while (q--) solve();

    return 0;
}