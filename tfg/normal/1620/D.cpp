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
        int top = 0;
        for(int i = 0; i < n; i++) {
            std::cin >> a[i];
            top = std::max(top, a[i] / 3 - 2);
        }
        int ans = 1e9;
        for(int i = top; i < ans; i++) for(int j = 0; j <= 2 && i + j < ans; j++) for(int k = 0; k <= 2 && i + j + k < ans; k++) {
            bool good = true;
            for(auto x : a) {
                bool got = false;
                for(int jj = 0; jj <= j; jj++) for(int kk = 0; kk <= k; kk++) {
                    int y = x - jj - kk * 2;
                    if(y >= 0 && y % 3 == 0 && y / 3 <= i) {
                        got = true;
                    }
                }
                if(!got) {
                    good = false;
                    break;
                }
            }
            if(good) {
                ans = std::min(ans, i + j + k);
            }
        }
        std::cout << ans << '\n';
    }
}