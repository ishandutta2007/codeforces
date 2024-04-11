#include <bits/stdc++.h>

using i64 = long long;

bool isprime[100];

void solve() {
    int k;
    std::cin >> k;

    std::string s;
    std::cin >> s;

    for (int i = 0; i < k; i++) {
        if (s[i] != '0' && !isprime[s[i] - '0']) {
            std::cout << 1 << "\n" << s[i] << "\n";
            return;
        }
    }

    for (int i = 0; i < k; i++) {
        for (int j = i + 1; j < k; j++) {
            if (s[i] != '0' && !isprime[(s[i] - '0') * 10 + (s[j] - '0')]) {
                std::cout << 2 << "\n" << s[i] << s[j] << "\n";
                return;
            }
        }
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    for (int i = 2; i < 100; i++) isprime[i] = true;

    for (int i = 2; i < 100; i++) {
        if (!isprime[i]) continue;
        for (int j = i + i; j < 100; j += i) {
            isprime[j] = false;
        }
    }

    int tt;
    std::cin >> tt;

    while (tt--) {
        solve();
    }

    return 0;
}