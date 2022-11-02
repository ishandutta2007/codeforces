#include <iostream>
#include <algorithm>
#include <vector>

using lint = long long;

int main() {
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);

    int q;
    std::cin >> q;

    while (q--) {
        int n;
        lint s;
        std::cin >> n >> s;

        std::vector<lint> as(n);
        for (auto& a : as) {
            std::cin >> a;
        }

        std::vector<lint> ss(n);
        ss[0] = as[0];
        for (int i = 1; i < n; ++i) {
            ss[i] = ss[i - 1] + as[i];
        }

        int r = std::upper_bound(ss.begin(), ss.end(), s) - ss.begin();
        if (r == n) {
            std::cout << 0 << std::endl;
            continue;
        }

        int maidx = std::max_element(as.begin(), as.begin() + r + 1) - as.begin();
        int rm = std::upper_bound(ss.begin(), ss.end(), s + as[maidx]) - ss.begin() - 1;
        if (rm > r) {
            std::cout << maidx + 1 << std::endl;
        } else {
            std::cout << 0 << std::endl;
        }
    }
    return 0;
}