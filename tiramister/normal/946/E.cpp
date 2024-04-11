#include <iostream>
#include <string>
#include <vector>

int main() {
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);

    int q;
    std::cin >> q;

    while (q--) {
        std::string s;
        std::cin >> s;
        int n = s.length();

        std::vector<int> num;
        num.reserve(n);
        for (char c : s) {
            num.push_back(c - '0');
        }

        std::vector<int> cnt(10, 0);
        for (auto d : num) ++cnt[d];

        bool found = false;
        int free = -1;
        for (int i = n - 1; i >= 0; --i) {
            --cnt[num[i]];
            ++free;

            int low = (i == 0 ? 1 : 0);
            if (num[i] == low) continue;

            int odds = 0;
            for (auto c : cnt) odds += c % 2;

            int dst = -1;
            for (int d = low; d < num[i]; ++d) {
                if (cnt[d] % 2 > 0) {
                    dst = d;
                }
            }
            odds += (dst < 0 ? 1 : -1);

            if (odds <= free) {
                if (dst < 0 || free - odds >= 1) dst = num[i] - 1;
                num[i] = dst;
                ++cnt[dst];

                for (int j = n - 1; j > i; --j) {
                    bool out = false;
                    for (int d = 0; d <= 9; ++d) {
                        if (cnt[d] % 2 > 0) {
                            num[j] = d;
                            ++cnt[d];
                            out = true;
                            break;
                        }
                    }

                    if (!out) {
                        num[j] = 9;
                        ++cnt[9];
                    }
                }

                for (auto d : num) std::cout << d;
                std::cout << "\n";

                found = true;
                break;
            }
        }

        if (!found) {
            std::cout << std::string(n - 2, '9') << "\n";
        }
    }
    return 0;
}