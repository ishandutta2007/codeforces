#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>
#include <algorithm>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

long long solve(std::vector<int> a) {
    std::sort(a.begin(), a.end());
    int n = (int) a.size();
    return n % 2 == 1 ? 1 : a[n/2] - a[n/2-1] + 1;
}

int main() {
    std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
    int t;
    std::cin >> t;
    while(t--) {
        int n;
        std::cin >> n;
        std::vector<int> x(n), y(n);
        for(int i = 0; i < n; i++) {
            std::cin >> x[i] >> y[i];
        }
        std::cout << solve(x) * solve(y) << '\n';
    }
}