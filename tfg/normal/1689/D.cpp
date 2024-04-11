#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
    std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
    int t;
    std::cin >> t;
    while(t--) {
        const int INF = 1e9;
        int n, m;
        std::cin >> n >> m;
        int d1[] = {INF, -INF}, d2[] = {INF, -INF};
        std::vector<std::pair<int, int>> a;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                char ch;
                std::cin >> ch;
                if(ch == 'B') {
                    a.emplace_back(i, j);
                    d1[0] = std::min(d1[0], i+j);
                    d1[1] = std::max(d1[1], i+j);
                    d2[0] = std::min(d2[0], i-j);
                    d2[1] = std::max(d2[1], i-j);
                }
            }
        }
        int x2 = d1[0] + d1[1];
        int y2 = d2[0] + d2[1];
        int x4 = x2 + y2;
        int y4 = x2 - y2;
        auto f = [&](int x, int y) {
            int ans = 0;
            for(auto [i, j] : a) {
                ans = std::max(ans, std::abs(i-x) + std::abs(j-y));
            }
            return ans;
        };
        int x = x4 / 4, y = y4 / 4;
        int best[3] = {INF, 0, 0};
        for(int dx = -1; dx <= 1; dx++) for(int dy = -1; dy <= 1; dy++) {
            int got = f(x+dx, y+dy);
            if(best[0] > got) {
                best[0] = got;
                best[1] = x+dx;
                best[2] = y+dy;
            }
        }
        std::cout << best[1]+1 << ' ' << best[2]+1 << '\n';
    }
}