#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cassert>

void solve() {
    int n;
    std::string s, t;
    std::cin >> n >> s >> t;

    int l = 0, r = n - 1;
    bool rev = false;

    auto get = [&](int i) {
        return (rev ? (s[r - i] == '0' ? '1' : '0') : s[l + i]);
    };

    std::vector<int> ans;
    for (int i = n - 1; i >= 0; --i) {
        if (get(0) == t[i]) {
            ans.push_back(1);
        }
        ans.push_back(i + 1);

        rev = !rev;
        if (rev) {
            ++l;
        } else {
            --r;
        }
    }

    std::cout << ans.size();
    for (auto a : ans) std::cout << " " << a;
    std::cout << "\n";

    // for (auto a : ans) {
    //     for (int i = 0; i < a; ++i) {
    //         s[i] = (s[i] == '0' ? '1' : '0');
    //     }
    //     std::reverse(s.begin(), s.begin() + a);
    // }
    // std::cerr << s << "\n";
    // assert(s == t);
}

int main() {
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);

    int q;
    std::cin >> q;
    while (q--) solve();

    return 0;
}