#include <iostream>
#include <vector>
#include <string>

void solve() {
    std::string s;
    std::cin >> s;
    int n = s.length();

    std::vector<int> ans;
    int i = 0;
    char prev = '$';
    while (i < n) {
        if (s.substr(i, 3) == "one") {
            if (prev != 'o') {
                ans.push_back(i);
                i += 1;
            } else {
                ans.push_back(i + 1);
                i += 2;
            }
            prev = '$';
        } else if (s.substr(i, 3) == "two") {
            if (i + 3 >= n || s[i + 3] != 'o') {
                ans.push_back(i + 2);
                i += 3;
            } else {
                ans.push_back(i + 1);
                i += 2;
            }
            prev = '$';
        } else {
            prev = s[i];
            ++i;
        }
    }

    std::cout << ans.size() << "\n";
    for (auto a : ans) std::cout << a + 1 << " ";
    std::cout << "\n";
}

int main() {
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);

    int q;
    std::cin >> q;
    while (q--) solve();

    return 0;
}