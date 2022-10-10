#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
    std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
    int tt;
    std::cin >> tt;
    while(tt--) {
        int n, x;
        std::cin >> n >> x;
        int ans = 0;
        const int INF = 1e9;
        int l = INF, r = -INF;
        while(n--) {
            int v;
            std::cin >> v;
            if(std::max(r, v) - std::min(l, v) > 2 * x) {
                l = r = v;
                ans++;
            } else {
                r = std::max(r, v);
                l = std::min(l, v);
            }
        }
        std::cout << ans << '\n';
    }
}