#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>
#include <algorithm>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

long long gcd(long long a, long long b) { return b == 0 ? a : gcd(b, a % b); }

int main() {
    std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
    int t;
    std::cin >> t;
    while(t--) {
        long long n;
        std::cin >> n;
        for(int i = 2; i < n; i++) {
            if(gcd(i, n-i-1) + i + n-i-1 == n) {
                std::cout << i << ' ' << n-i-1 << ' ' << 1 << '\n';
                break;
            }
        }
    }
}