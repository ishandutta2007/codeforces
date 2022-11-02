#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

void solve() {
    std::string s, t;
    std::cin >> s >> t;

    if (t.length() > s.length()) {
        std::sort(s.rbegin(), s.rend());
        std::cout << s << "\n";
        return;
    }

    int n = s.length();

    auto dfs = [&](auto&& f, int i, bool over) -> bool {
        if (i == n) return true;

        for (char c = (over ? '9' : t[i]); c >= '0'; --c) {
            int j;
            for (j = i; j < n; ++j) {
                if (s[j] == c) break;
            }

            if (j != n) {
                std::swap(s[i], s[j]);
                if (f(f, i + 1, over || s[i] < t[i])) return true;
                std::swap(s[i], s[j]);
            }
        }
        return false;
    };

    dfs(dfs, 0, false);

    std::cout << s << "\n";
}

int main() {
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);

    solve();

    return 0;
}