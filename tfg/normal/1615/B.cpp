#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
    std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
    const int me = 20;
    const int ms = 200200;
    std::vector<std::vector<int>> a(me, std::vector<int>(ms, 0));
    for(int i = 1; i < ms; i++) for(int j = 0; j < me; j++) {
        a[j][i] = a[j][i-1] + (i >> j) % 2;
    }
    int t;
    std::cin >> t;
    while(t--) {
        int l, r;
        std::cin >> l >> r;
        int n = r - l + 1;
        int ans = n-1;
        for(int i = 0; i < me; i++) ans = std::min(ans, n - (a[i][r] - a[i][l-1]));
        std::cout << ans << '\n';
    }
}