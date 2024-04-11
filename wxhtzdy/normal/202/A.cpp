#include <bits/stdc++.h>

using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::string s;
    std::cin >> s;

    std::vector<int> cnt(26);
    for (int i = 0; i < s.size(); i++) {
        ++cnt[s[i] - 'a'];
    }

    for (int i = 25; i >= 0; i--) {
        if (cnt[i] == 0) continue;
        while (cnt[i]--) std::cout << (char) (i + 'a');
        break;
    }
    return 0;
}