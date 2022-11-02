#include <iostream>
#include <vector>

using lint = long long;

void solve() {
    int n;
    lint l, r;
    std::cin >> n >> l >> r;
    --l;

    std::vector<int> ans;
    for (int s = 1; s <= n; ++s) {
        lint len = (n - s) * 2;
        if (ans.empty() && len <= l) {
            l -= len;
            r -= len;
            continue;
        }

        for (int v = s + 1; v <= n; ++v) {
            ans.push_back(s);
            ans.push_back(v);
        }

        if ((lint)ans.size() >= r) break;
    }
    ans.push_back(1);

    for (int i = l; i < r; ++i) {
        std::cout << ans[i] << " ";
    }
    std::cout << "\n";
}

int main() {
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);

    int q;
    std::cin >> q;
    while (q--) solve();

    return 0;
}