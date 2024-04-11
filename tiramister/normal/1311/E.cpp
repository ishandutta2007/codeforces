#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using lint = long long;
using ldouble = long double;

void solve() {
    int n, d;
    std::cin >> n >> d;

    std::vector<int> vs(n, 1);

    int diff = n * (n - 1) / 2 - d;
    if (diff < 0) {
        std::cout << "NO" << std::endl;
        return;
    }

    int head = 1;
    for (int v = n - 1; v > head; --v) {
        int to = std::max(v - diff, head);
        --vs[v];
        ++vs[to];
        diff -= v - to;
        if (diff == 0) break;

        while (vs[head] == (1 << head)) ++head;
    }

    if (diff > 0) {
        std::cout << "NO" << std::endl;
        return;
    }

    std::cout << "YES" << std::endl;
    int p = 1;
    for (int i = 1; i < n; ++i) {
        int v = p, ch = 0;
        for (int j = 0; j < vs[i]; ++j) {
            std::cout << v << " ";
            if (++ch == 2) {
                ++v;
                ch = 0;
            }
        }
        p += vs[i - 1];
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