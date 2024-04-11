#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <cassert>

void solve() {
    int n;
    std::cin >> n;

    std::vector<std::set<int>> ss;
    std::vector<int> cnt(n, 0);

    for (int i = 0; i < n - 1; ++i) {
        int k;
        std::cin >> k;

        std::set<int> s;
        while (k--) {
            int x;
            std::cin >> x;
            --x;

            s.insert(x);
            ++cnt[x];
        }

        ss.push_back(s);
    }

    auto check = [&](const auto& v) {
        if ((int)v.size() != n) return false;

        for (int r = 1; r < n; ++r) {
            bool found = false;
            std::set<int> s;

            for (int l = r; l >= 0; --l) {
                s.insert(v[l]);
                if (std::count(ss.begin(), ss.end(), s)) found = true;
            }

            if (!found) return false;
        }

        return true;
    };

    for (int fst = 0; fst < n; ++fst) {
        auto nss = ss;
        std::vector<int> ans;
        int e = fst;

        while (true) {
            ans.push_back(e);
            for (auto& s : nss) s.erase(e);

            auto it = std::find_if(nss.begin(), nss.end(),
                                   [](const auto& s) { return s.size() == 1; });
            if (it == nss.end()) break;

            e = *it->begin();
            nss.erase(it);
        }

        if (!check(ans)) continue;

        for (auto x : ans) std::cout << x + 1 << " ";
        std::cout << std::endl;
        return;
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