#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

std::vector<std::vector<int>> ans;

void solve(const std::vector<std::vector<int>> &edges, int on) {
    ans.emplace_back(1, on);
    while(!edges[on].empty()) {
        ans.back().push_back(edges[on][0]);
        on = edges[on][0];
    }
    for(auto vertex : ans.back()) {
        for(int i = 1; i < (int) edges[vertex].size(); i++) {
            solve(edges, edges[vertex][i]);
        }
    }
}

int main() {
    std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
    int t;
    std::cin >> t;
    while(t--) {
        int n;
        std::cin >> n;
        std::vector<std::vector<int>> edges(n);
        int r = -1;
        for(int i = 0; i < n; i++) {
            int p;
            std::cin >> p;
            p--;
            if(p == i) {
                r = i;
            } else {
                edges[p].push_back(i);
            }
        }
        ans.clear();
        solve(edges, r);
        std::cout << ans.size() << '\n';
        for(auto path : ans) {
            std::cout << path.size() << '\n';
            for(int i = 0; i < (int) path.size(); i++) {
                std::cout << path[i]+1 << (i + 1 == (int) path.size() ? '\n' : ' ');
            }
        }
        std::cout << '\n';
    }
}