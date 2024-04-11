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
        long long mx = 0, sum = 0;
        std::cin >> n;
        long long two = 0;
        while(n--) {
            int x;
            std::cin >> x;
            while(x % 2 == 0) {
                x /= 2;
                two++;
            }
            mx = std::max(mx, (long long) x);
            sum += x;
        }
        std::cout << (sum - mx) + (mx << two) << '\n';
    }
}