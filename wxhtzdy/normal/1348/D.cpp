#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n;
    std::cin >> n;

    std::vector<int> a;
    for (int i = 0; i < 31 && n >= (1 << i); i++) {
        a.push_back((1 << i));
        n -= (1 << i);
    }

    if (n > 0) {
        a.push_back(n);
    }

    std::sort(a.begin(), a.end());

    std::vector<int> ans;
    for (int i = 1; i < a.size(); i++) {
        ans.push_back(a[i] - a[i - 1]);
    }

    std::cout << ans.size() << "\n";
    for (int x : ans) std::cout << x << " ";
    std::cout << "\n";
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t;
    std::cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}