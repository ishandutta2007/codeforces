#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>
#include <queue>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
    std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
    int t;
    std::cin >> t;
    while(t--) {
        std::priority_queue<std::pair<int, int>> hp;
        int n;
        std::cin >> n;
        std::vector<int> a(n);
        for(int i = 0; i < n; i++) {
            std::cin >> a[i];
            if(i && a[i] < a[i-1]) {
                hp.push({a[i-1] - a[i], i+1});
            }
        }
        std::vector<int> ans(n+1, -1);
        for(int i = n; i >= 1; i--) {
            int val = 1;
            if(!hp.empty()) {
                assert(hp.top().first <= i);
                val = hp.top().second;
                hp.pop();
            }
            ans[i] = val;
        }
        for(int i = 1; i <= n; i++) {
            std::cout << ans[i] << (i == n ? '\n' : ' ');
        }
    }
}