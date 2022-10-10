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
        std::vector<int> a(n);
        int ans = n-1;
        for(int i = 0; i < n; i++) {
            std::cin >> a[i];
        }
        for(int x = 0; x < n; x++) for(int y = x+1; y < n; y++) {
            int got = 2;
            for(int i = y+1; i < n; i++) {
                //if((a[i] - a[x]) / (i - x) == (a[y] - a[x]) / (y - x))
                if((a[i] - a[x]) * (y - x) == (a[y] - a[x]) * (i - x )) {
                    got++;
                }
            }
            //std::cout << "with (" << x << ", " << y << ") got " << got << '\n';
            ans = std::min(ans, n - got);
        }
        std::cout << ans << '\n';
    }
}