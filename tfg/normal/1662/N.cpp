#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
    std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
    int n;
    std::cin >> n;
    std::vector<long long> row(n, 0), col(n, 0);
    long long ans = 0;
    std::vector<std::pair<int, int>> pos(n*n);
    for(int i = 0; i < n; i++) for(int j = 0; j < n; j++) {
        int x;
        std::cin >> x;
        pos[x-1] = {i, j};
    }
    for(auto [x, y] : pos) {
        ans += row[x]++ * col[y]++;
    }
    long long tot = (long long) n * (n-1) / 2 * n * (n-1) / 2;
    ans = tot - (ans - tot);
    std::cout << ans << '\n';
}