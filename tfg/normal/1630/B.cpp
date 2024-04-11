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
        int n, k;
        std::cin >> n >> k;
        std::vector<int> a(n);
        for(int i = 0; i < n; i++) {
            std::cin >> a[i];
        }
        auto b = a;
        std::sort(b.begin(), b.end());
        // total sum has to be >= k
        // so x - (n - x) >= k
        // 2x >= k + n
        // x >= (k + n) / 2
        int x = b[0], y = b[n-1];
        int gap = (n + k + 1) / 2;
        for(int i = 0; i+gap <= n; i++) {
            if(b[i+gap-1] - b[i] <= y-x) {
                x = b[i], y = b[i+gap-1];
            }
        }
        std::cout << x << ' ' << y << '\n';
        int on = 0;
        while(k > 1) {
            k--;
            std::cout << on+1 << ' ';
            int bal = 0;
            while(bal <= 0) {
                bal += (x <= a[on] && a[on] <= y ? 1 : -1);
                on++;
            }
            std::cout << on << '\n';
        }
        std::cout << on+1 << ' ' << n << '\n' << '\n';
    }
}