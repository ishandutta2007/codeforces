#include <iostream>
#include <vector>
#include <string>
#include <map>

using lint = long long;

int main() {
    int n, k;
    std::cin >> n >> k;

    std::vector<std::string> ss(n);
    for (auto& s : ss) std::cin >> s;

    std::map<std::string, int> cnt;
    lint ans = 0;

    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            std::string s(k, '.');

            for (int l = 0; l < k; ++l) {
                if (ss[i][l] == ss[j][l]) {
                    s[l] = ss[i][l];
                } else {
                    for (char c : "SET") {
                        if (c != ss[i][l] && c != ss[j][l]) {
                            s[l] = c;
                            break;
                        }
                    }
                }
            }

            if (cnt.count(s)) {
                ans += cnt[s];
            }
        }

        if (!cnt.count(ss[i])) cnt[ss[i]] = 0;
        ++cnt[ss[i]];
    }

    std::cout << ans << std::endl;
    return 0;
}