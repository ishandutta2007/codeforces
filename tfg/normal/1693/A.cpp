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
        int n;
        std::cin >> n;
        long long sum = 0;
        bool valid = true;
        std::vector<long long> a(n);
        int l = n+1, r = -1;
        for(int i = 0; i < n; i++) {
            int x;
            std::cin >> x;
            a[i] = x;
            sum += x;
            if(x) {
                l = std::min(l, i);
                r = std::max(r, i);
            }
            valid = valid && sum >= 0;
        }
        valid = valid && sum == 0;
        if(l != n+1) {
            valid = valid && l == 0;
            for(int i = 0; i < r; i++) {
                sum += a[i];
                valid = valid && sum > 0;
            }
        }
        std::cout << (valid ? "YES\n" : "NO\n");
    }
}