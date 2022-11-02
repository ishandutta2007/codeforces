#include <iostream>
#include <algorithm>
#include <string>

void solve() {
    std::string s;
    std::cin >> s;
    int n = s.length();

    int l = 0;
    bool two = false;
    for (int r = 0; r < n; ++r) {
        if (s[r] == '2') two = true;

        if (two && s[r] == '0') {
            std::sort(s.begin() + l, s.begin() + r);
            l = r;
            two = false;
        }
    }
    std::sort(s.begin() + l, s.end());

    std::string ans, ones;
    for (char c : s) {
        if (c == '1') {
            ones.push_back(c);
        } else {
            ans.push_back(c);
        }
    }

    for (char c : ans) {
        if (c == '2') {
            std::cout << ones;
            ones.clear();
        }
        std::cout << c;
    }

    std::cout << ones << "\n";
}

int main() {
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);

    solve();

    return 0;
}