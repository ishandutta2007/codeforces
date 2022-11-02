#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

void solve() {
    std::map<int, int> cnt;

    int n;
    std::cin >> n;
    while (n--) {
        int x;
        std::cin >> x;

        if (!cnt.count(x)) cnt[x] = 0;
        ++cnt[x];
    }

    std::vector<int> xs;
    for (auto p : cnt) xs.push_back(p.second);
    std::sort(xs.rbegin(), xs.rend());

    int a = xs.size(), b = xs.front();
    int ans = std::min(a, b);
    if (ans == a && ans == b) --ans;

    std::cout << ans << std::endl;
}

int main() {
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);

    int q;
    std::cin >> q;
    while (q--) solve();

    return 0;
}