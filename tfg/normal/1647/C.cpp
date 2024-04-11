#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>
#include <queue>
#include <algorithm>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
    std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
    int t;
    std::cin >> t;
    while(t--) {
        int n, m;
        std::cin >> n >> m;
        std::vector<std::vector<int>> a(n, std::vector<int>(m, 0));
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                char ch;
                std::cin >> ch;
                a[i][j] = ch - '0';
            }
        }
        auto isGood = [&](int i, int j) {
            if(i < 0 || j < 0 || i >= n || j >= m) return false;
            if(a[i][j] == 0) return false;
            if(i > 0 && a[i-1][j] == 0) return true;
            if(j > 0 && a[i][j-1] == 0) return true;
            return false;
        };
        std::queue<std::pair<int, int>> q;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                q.push({i, j});
            }
        }
        struct Info {
            int x, y, i, j;
        };
        std::vector<Info> ans;
        while(!q.empty()) {
            auto [x, y] = q.front();
            q.pop();
            if(!isGood(x, y)) continue;
            if(x > 0 && a[x-1][y] == 0) {
                ans.push_back({x-1, y, x, y});
            } else {
                ans.push_back({x, y-1, x, y});
            }
            a[x][y] = 0;
            for(int i = 1; i <= 1; i++) for(int j = -1; j <= 1; j++) {
                q.push({x+i, y+j});
            }
        }
        bool good = true;
        for(int i = 0; i < n; i++) for(int j = 0; j < m; j++) {
            good = good && (a[i][j] != 1);
        }
        if(!good) {
            std::cout << "-1\n";
        } else {
            std::cout << ans.size() << '\n';
            std::reverse(ans.begin(), ans.end());
            for(auto [x, y, i, j] : ans) {
                std::cout << x+1 << ' ' << y+1 << ' ' << i+1 << ' ' << j+1 << '\n';
            }
        }
    }
}