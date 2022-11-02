#include <iostream>
#include <string>

void solve() {
    std::string t;
    int d;
    std::cin >> t >> d;

    int n = t.length();
    std::string s(n, '$');

    for (int i = 0; i < n; ++i) {
        switch (t[i]) {
            case '0': {
                if (i - d >= 0) {
                    if (s[i - d] == '1') {
                        std::cout << "-1\n";
                        return;
                    }
                    s[i - d] = '0';
                }

                if (i + d < n) {
                    if (s[i + d] == '1') {
                        std::cout << "-1\n";
                        return;
                    }
                    s[i + d] = '0';
                }
                break;
            }
            case '1': {
                bool ext = false;

                if (i - d >= 0) {
                    if (s[i - d] != '0') s[i - d] = '1';
                    if (s[i - d] == '1') ext = true;
                }

                if (!ext && i + d < n) {
                    if (s[i + d] != '0') s[i + d] = '1';
                    if (s[i + d] == '1') ext = true;
                }

                if (!ext) {
                    std::cout << "-1\n";
                    return;
                }
                break;
            }
        }
    }

    for (auto& c : s) {
        if (c == '$') c = '0';
    }

    std::cout << s << "\n";
}

int main() {
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);

    int q;
    std::cin >> q;
    while (q--) solve();

    return 0;
}