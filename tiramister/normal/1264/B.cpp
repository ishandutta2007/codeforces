#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

void solve() {
    std::vector<int> cnt(4);
    for (auto& c : cnt) std::cin >> c;

    auto judge = [&](const std::vector<int>& xs) {
        auto ncnt = cnt;
        int prev = -1;

        for (auto x : xs) {
            if (--ncnt[x] < 0) return false;
            if (prev != -1 && std::abs(prev - x) != 1) return false;
            prev = x;
        }

        return std::all_of(ncnt.begin(), ncnt.end(),
                           [](auto x) { return x == 0; });
    };

    for (int q = 0; q < 2; ++q) {
        std::reverse(cnt.begin(), cnt.end());

        int e = cnt[0] + cnt[2], o = cnt[1] + cnt[3];

        auto ncnt = cnt;
        std::vector<int> ans;

        if (e == o) {
            while (ncnt[0] > 0) {
                ans.push_back(0);
                --ncnt[0];
                if (ncnt[1] == 0) break;
                ans.push_back(1);
                --ncnt[1];
            }

            std::vector<int> back;
            while (ncnt[3] > 0) {
                back.push_back(3);
                --ncnt[3];
                if (ncnt[2] == 0) break;
                back.push_back(2);
                --ncnt[2];
            }

            while (ncnt[2] > 0) {
                ans.push_back(2);
                --ncnt[2];
                if (ncnt[1] == 0) break;
                ans.push_back(1);
                --ncnt[1];
            }

            std::copy(back.rbegin(), back.rend(), std::back_inserter(ans));
        } else {
            // assume e > o
            while (ncnt[0] > 0) {
                ans.push_back(0);
                --ncnt[0];
                if (ncnt[1] == 0) break;
                ans.push_back(1);
                --ncnt[1];
            }

            while (ncnt[3] > 0) {
                if (ncnt[2] == 0) break;
                ans.push_back(2);
                --ncnt[2];
                ans.push_back(3);
                --ncnt[3];
            }

            while (ncnt[2] > 0) {
                ans.push_back(2);
                --ncnt[2];
                if (ncnt[1] == 0) break;
                ans.push_back(1);
                --ncnt[1];
            }
        }

        for (int i = 0; i <= 3; ++i) {
            while (ncnt[i]--) ans.push_back(i);
        }

        if (!judge(ans)) continue;

        if (q == 0) {
            std::transform(ans.begin(), ans.end(), ans.begin(),
                           [](auto x) { return 3 - x; });
        }

        std::cout << "YES\n";
        for (auto a : ans) std::cout << a << " ";
        std::cout << "\n";
        return;
    }

    std::cout << "NO\n";
}

int main() {
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);

    solve();

    return 0;
}