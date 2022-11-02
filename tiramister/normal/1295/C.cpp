#include <iostream>
#include <vector>
#include <string>

void solve() {
    std::string s, t;
    std::cin >> s >> t;

    int n = s.length();
    std::vector<std::vector<int>> nxt(n * 2 + 1,
                                      std::vector<int>(26, -1));
    for (int i = n * 2 - 1; i >= 0; --i) {
        nxt[i] = nxt[i + 1];
        char c = s[i % n];
        nxt[i][c - 'a'] = i;
    }

    int ans = 1, idx = 0;
    for (char c : t) {
        while (idx >= n) {
            ++ans;
            idx -= n;
        }

        idx = nxt[idx][c - 'a'] + 1;
        if (idx == 0) {
            ans = -1;
            break;
        }

        while (idx > n) {
            ++ans;
            idx -= n;
        }
    }
    std::cout << ans << std::endl;
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