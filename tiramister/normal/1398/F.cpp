#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

void solve() {
    int n;
    std::string s;
    std::cin >> n >> s;

    std::vector<int> rs(n, 0);
    {
        std::vector<int> ls(2, n);
        for (int i = n - 1; i >= 0; --i) {
            char c = s[i];
            if (c == '?') {
                rs[i] = std::max(ls[0], ls[1]) - i;
            } else {
                rs[i] = ls[1 - (c - '0')] - i;
                ls[c - '0'] = i;
            }
        }
    }

    std::vector<int> skip(n, 1);
    for (int x = 1; x <= n; ++x) {
        int ans = 0;

        int i = 0, pi = 0;
        bool skipped = false;

        while (i < n) {
            if (x <= rs[i]) {
                ++ans;
                skipped = false;
                i += x;

            } else {
                int ppi = i;
                i += skip[i];
                if (skipped) skip[pi] = i - pi;

                pi = ppi;
                skipped = true;
            }
        }

        std::cout << ans << " ";
    }

    std::cout << "\n";
}

int main() {
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);

    solve();

    return 0;
}