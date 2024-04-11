#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <set>

std::multiset<std::string> query(int l, int r) {
    std::cout << "? " << l << " " << r << std::endl;

    int n = r - l + 1;
    int m = n * (n + 1) / 2;

    std::multiset<std::string> res;
    while (m--) {
        std::string s;
        std::cin >> s;
        std::sort(s.begin(), s.end());
        res.insert(s);
    }

    return res;
}

int main() {
    int n;
    std::cin >> n;

    auto all = query(1, n);

    if (n == 1) {
        std::cout << "! " << *all.begin() << std::endl;
        return 0;
    }

    auto rim = query(2, n);
    for (const auto& s : rim) {
        all.erase(all.find(s));
    }

    std::vector<std::string> ss(all.begin(), all.end());
    std::sort(ss.begin(), ss.end(),
              [](const std::string& a, const std::string& b) {
                  return a.length() < b.length();
              });

    std::string ans(n, '?');
    for (int i = 0; i < n; ++i) {
        auto s = ss[i];

        std::multiset<char> cs(s.begin(), s.end());
        for (int j = 0; j < i; ++j) {
            cs.erase(cs.find(ans[j]));
        }
        ans[i] = *cs.begin();
    }

    std::cout << "! " << ans << std::endl;
    return 0;
}