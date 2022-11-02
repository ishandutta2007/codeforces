#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

void solve() {
    std::string s;
    std::cin >> s;
    int n = s.length();
    std::reverse(s.begin(), s.end());

    std::vector<int> zs(n + 1, 0);
    for (int i = n - 1; i >= 0; --i) {
        if (s[i] == '0') {
            zs[i] = zs[i + 1] + 1;
        } else {
            zs[i] = 0;
        }
    }

    int ans = 0;
    for (int l = 0; l < n; ++l) {
        int sum = 0;
        for (int k = 0; k < 20 && l + k < n; ++k) {
            if (s[l + k] == '1') {
                sum += (1 << k);
                if (sum != 0 && sum <= zs[l + k + 1] + k + 1) ++ans;
            }
        }
    }

    std::cout << ans << std::endl;
}

int main() {
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);

    int q;
    std::cin >> q;
    while (q--) solve();

    return 0;
}