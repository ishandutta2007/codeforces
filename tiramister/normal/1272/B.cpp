#include <iostream>
#include <algorithm>
#include <numeric>
#include <vector>
#include <string>

const std::string ways = "LURD";

void solve() {
    std::string s;
    std::cin >> s;

    std::vector<int> cnt(4, 0);
    for (char c : s) {
        for (int i = 0; i < 4; ++i) {
            if (c == ways[i]) ++cnt[i];
        }
    }

    cnt[0] = cnt[2] = std::min(cnt[0], cnt[2]);
    cnt[1] = cnt[3] = std::min(cnt[1], cnt[3]);
    if (cnt[0] == 0) {
        cnt[1] = cnt[3] = std::min(cnt[1], 1);
    }
    if (cnt[1] == 0) {
        cnt[0] = cnt[2] = std::min(cnt[2], 1);
    }

    std::cout << std::accumulate(cnt.begin(), cnt.end(), 0)
              << std::endl;
    for (int i = 0; i < 4; ++i) {
        std::cout << std::string(cnt[i], ways[i]);
    }
    std::cout << std::endl;
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