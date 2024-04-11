#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

void solve() {
    int n;
    std::cin >> n;

    std::vector<int> xs(n), revx(n);
    for (int i = 0; i < n; ++i) {
        auto& x = xs[i];
        std::cin >> x;
        revx[--x] = i;
    }

    std::vector<int> ls(n), rs(n);
    {
        std::set<int> idxs{-1, n};
        for (int x = n - 1; x >= 0; --x) {
            int i = revx[x];

            auto it = idxs.upper_bound(i);
            rs[i] = *it;
            --it;
            ls[i] = *it;

            idxs.insert(i);
        }
    }

    int ans = 0;
    for (int i = 0; i < n; ++i) {
        if (i - ls[i] < rs[i] - i) {
            for (int j = i - 1; j > ls[i]; --j) {
                int y = xs[i] - xs[j] - 1;
                if (i < revx[y] && revx[y] < rs[i]) ++ans;
            }
        } else {
            for (int j = i + 1; j < rs[i]; ++j) {
                int y = xs[i] - xs[j] - 1;
                if (ls[i] < revx[y] && revx[y] < i) ++ans;
            }
        }
    }

    std::cout << ans << "\n";
}

int main() {
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);

    solve();

    return 0;
}