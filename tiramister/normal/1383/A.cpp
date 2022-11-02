#include <iostream>
#include <vector>
#include <string>
#include <set>

constexpr int X = 20;

void solve() {
    int n;
    std::string s, t;
    std::cin >> n >> s >> t;

    std::vector<std::set<int>> to(X);
    for (int i = 0; i < n; ++i) {
        char c = s[i],
             d = t[i];
        if (c > d) {
            std::cout << "-1\n";
            return;
        }
        if (c < d) {
            to[c - 'a'].insert(d - 'a');
        }
    }

    int ans = 0;
    for (auto& ss : to) {
        if (ss.empty()) continue;

        ++ans;
        int nxt = *ss.begin();

        for (auto x : ss) {
            if (x != nxt) to[nxt].insert(x);
        }
    }

    std::cout << ans << "\n";
}

int main() {
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);

    int q;
    std::cin >> q;
    while (q--) solve();

    return 0;
}