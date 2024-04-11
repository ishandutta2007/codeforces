#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>
#include <algorithm>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
    std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
    int t;
    std::cin >> t;
    while(t--) {
        int n;
        std::cin >> n;
        std::vector<int> a(n+1), b;
        std::vector<std::vector<int>> pos(n+2);
        for(int i = 1; i <= n; i++) {
            std::cin >> a[i];
            pos[a[i]].push_back(i);
        }
        int cur = !pos[0].empty() ? 0 : n+1;
        int solved = 0;
        int k = 0;
        for(int i = 1; i <= n; i++) {
            if(a[i] > i) {
                k = std::max(k, i);
            }
        }
        while(solved < n) {
            bool low = cur > k;
            int special = -1;
            for(auto p : pos[cur]) {
                if(!pos[p].empty()) {
                    assert(special == -1);
                    special = p;
                }
            }
            solved += (int) pos[cur].size();
            for(auto p : pos[cur]) {
                if(p != special) {
                    b.push_back(p);
                }
            }
            if(special == -1) {
                assert(solved == n);
            } else {
                b.push_back(special);
                cur = special;
                assert((cur > k) != low);
            }
        }
        assert((int) b.size() == n);
        std::cout << k << '\n';
        for(int i = 0; i < n; i++) {
            std::cout << b[i] << (i+1 == n ? '\n' : ' ');
        }
    }
}