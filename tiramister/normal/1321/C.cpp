#include <iostream>
#include <vector>
#include <string>
#include <cmath>

template <class T>
std::vector<T> vec(int len, T elem) { return std::vector<T>(len, elem); }

void solve() {
    int n;
    std::string s;
    std::cin >> n >> s;

    auto erasable = vec(n + 1, vec(n + 1, false));
    auto cnt = vec(n + 1, vec(n + 1, 0));
    for (int len = 0; len <= n; ++len) {
        for (int l = 0; l + len <= n; ++l) {
            int r = l + len;

            if (len == 0) {
                erasable[l][r] = true;
                cnt[l][r] = 0;
                continue;
            }

            char pc = (l == 0 ? '$' : s[l - 1]),
                 nc = (r == n ? '$' : s[r]);

            for (int i = l; i < r; ++i) {
                int sum = cnt[l][i] + cnt[i + 1][r];

                if (erasable[l][i] &&
                    erasable[i + 1][r] &&
                    (s[i] - pc == 1 ||
                     s[i] - nc == 1)) {
                    erasable[l][r] = true;
                    ++sum;
                }

                cnt[l][r] = std::max(cnt[l][r], sum);
            }
        }
    }

    std::cout << cnt[0][n] << std::endl;
}

int main() {
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::ios::sync_with_stdio(false);

    solve();

    return 0;
}