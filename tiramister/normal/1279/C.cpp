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
        int n, m;
        std::cin >> n >> m;

        std::vector<int> apos(n, -1);
        for (int i = 0; i < n; ++i) {
            int a;
            std::cin >> a;
            apos[--a] = i;
        }

        lint ans = 0, cnt = 0, poped = -1;
        for (int i = 0; i < m; ++i) {
            int b;
            std::cin >> b;
            --b;
            if (apos[b] < poped) {
                ans += 1;
            } else {
                int k = apos[b] - cnt;
                ans += k * 2 + 1;
                poped = apos[b];
            }
            cnt += 1;
        }

        std::cout << ans << "\n";
    }
    return 0;
}