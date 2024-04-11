#include <iostream>
#include <vector>
#include <string>
#include <map>

constexpr int INF = 1 << 30;
const std::vector<int> dx{-1, 1, 0, 0}, dy{0, 0, 1, -1};

void solve() {
    int n;
    std::string s;
    std::cin >> n >> s;

    int t = 0, x = 0, y = 0;
    int ans = INF, l, r;

    std::map<std::pair<int, int>, int> prev;
    prev[std::make_pair(x, y)] = t++;
    for (char c : s) {
        for (int i = 0; i < 4; ++i) {
            if (c == "LRUD"[i]) {
                x += dx[i];
                y += dy[i];
                break;
            }
        }

        auto p = std::make_pair(x, y);
        if (prev.count(p) && t - prev[p] < ans) {
            ans = t - prev[p];
            l = prev[p] + 1, r = t;
        }
        prev[p] = t++;
    }

    if (ans == INF) {
        std::cout << -1 << std::endl;
    } else {
        std::cout << l << " " << r << std::endl;
    }
}

int main() {
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::ios::sync_with_stdio(false);

    int q;
    std::cin >> q;
    while (q--) solve();

    return 0;
}