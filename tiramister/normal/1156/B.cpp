#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

void solve() {
    std::string s;
    std::cin >> s;

    std::vector<int> cnt(26, 0);
    for (char c : s) ++cnt[c - 'a'];

    std::vector<std::pair<char, int>> ps;
    for (int c = 0; c < 26; ++c) {
        if (cnt[c] == 0) continue;
        ps.emplace_back('a' + c, cnt[c]);
    }

    int m = ps.size();
    if (m > 3) {
        int l = 0, r = m / 2;
        while (true) {
            if (r == m) break;
            while (ps[r].second--) {
                std::cout << ps[r].first;
            }
            ++r;

            if (l == m / 2) break;
            while (ps[l].second--) {
                std::cout << ps[l].first;
            }
            ++l;
        }
        std::cout << "\n";

    } else {
        do {
            bool ok = true;
            for (int i = 0; i + 1 < m; ++i) {
                if (std::abs((int)ps[i].first - ps[i + 1].first) == 1) ok = false;
            }
            if (!ok) continue;

            for (auto p : ps) {
                while (p.second--) {
                    std::cout << p.first;
                }
            }
            std::cout << "\n";
            return;
        } while (std::next_permutation(ps.begin(), ps.end()));

        std::cout << "No answer\n";
    }
}

int main() {
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);

    int q;
    std::cin >> q;
    while (q--) solve();

    return 0;
}