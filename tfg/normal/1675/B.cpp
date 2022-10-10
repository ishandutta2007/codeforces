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
        std::vector<int> a(n);
        for(int i = 0; i < n; i++) {
            std::cin >> a[i];
        }
        int ans = 0;
        for(int i = n-1; i > 0; i--) {
            if(a[i] == 0) {
                ans = -1;
                break;
            }
            while(a[i-1] >= a[i]) {
                a[i-1] /= 2;
                ans++;
            }
        }
        std::cout << ans << '\n';
    }
}