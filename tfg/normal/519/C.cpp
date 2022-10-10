#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
    std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
    int n, m, ans = 0;
    std::cin >> n >> m;
    while(n > 0 && m > 0 && n + m >= 3) {
        if(n > m) {
            n -= 2, m -= 1;
        } else {
            m -= 2, n -= 1;
        }
        ans++;
    }
    std::cout << ans << '\n';
}