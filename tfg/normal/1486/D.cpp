#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
    std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
    int n, k;
    std::cin >> n >> k;
    std::vector<int> a(n);
    for(int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    auto check = [&](int x) {
        std::vector<int> sum(n+1, 0);
        for(int i = 0; i < n; i++) {
            sum[i+1] = sum[i] + (a[i] < x ? -1 : 1);
        }
        int back = 1e8;
        for(int i = k; i <= n; i++) {
            back = std::min(back, sum[i-k]);
            if(sum[i] - back > 0) {
                return true;
            }
        }
        return false;
    };
    int l = 0, r = n;
    while(l != r) {
        int mid = (l + r + 1) / 2;
        if(check(mid)) {
            l = mid;
        } else {
            r = mid - 1;
        }
    }
    std::cout << l << '\n';
}