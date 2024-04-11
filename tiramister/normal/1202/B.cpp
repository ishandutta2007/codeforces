#include <iostream>
#include <vector>
#include <string>

using lint = long long;
constexpr lint INF = 1LL << 30;

void solve() {
    std::vector<int> app(10, 0);
    {
        std::string s;
        std::cin >> s;
        for (int i = 0; i + 1 < (int)s.length(); ++i) {
            int c = s[i] - '0', d = s[i + 1] - '0';
            ++app[(d - c + 10) % 10];
        }
    }

    for (int x = 0; x < 10; ++x) {
        for (int y = 0; y < 10; ++y) {
            lint score = 0;

            for (int d = 0; d < 10; ++d) {
                int cost = INF;
                for (int dx = 0; dx < 10; ++dx) {
                    for (int dy = 0; dy < 10; ++dy) {
                        if (dx + dy > 0 && (x * dx + y * dy) % 10 == d) {
                            cost = std::min(cost, dx + dy - 1);
                        }
                    }
                }

                score += lint(cost) * app[d];
            }

            std::cout << (score >= INF ? -1 : score) << " ";
        }
        std::cout << "\n";
    }
}

int main() {
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);

    solve();

    return 0;
}