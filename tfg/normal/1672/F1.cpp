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
        std::vector<std::pair<int, int>> a(n);
        for(int i = 0; i < n; i++) {
            std::cin >> a[i].first;
            a[i].second = i;
        }
        std::sort(a.begin(), a.end());
        int mx = 0;
        for(int l = 0, r = 0; l < n; l = r) {
            while(r < n && a[l].first == a[r].first) r++;
            mx = std::max(mx, r-l);
        }
        std::vector<int> ans(n);
        for(int i = 0; i < n; i++) {
            ans[a[i].second] = a[(i+mx)%n].first;
        }
        for(int i = 0; i < n; i++) {
            std::cout << ans[i] << (i + 1 == n ? '\n' : ' ');
        }
    }
}