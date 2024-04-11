#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
    std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
    int n;
    std::cin >> n;
    std::vector<long long> a(n);
    for(int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    long long ans = 1e18;
    for(int mid = 0; mid <= n; mid++) {
        long long curCost = 0;
        long long v = 0;
        for(int i = mid+1; i < n; i++) {
            long long use = v / a[i] + 1;
            curCost += use;
            v = a[i] * use;
        }
        v = 0;
        for(int i = mid-1; i >= 0; i--) {
            long long use = v / a[i] + 1;
            curCost += use;
            v = a[i] * use;
        }
        ans = std::min(ans, curCost);
    }
    std::cout << ans << '\n';
}