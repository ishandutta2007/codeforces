#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

std::vector<std::pair<int, long long>> solve(std::vector<int> a, int m) {
    std::vector<std::pair<int, long long>> ans;
    for(auto val : a) {
        int f = 1;
        while(val % m == 0) {
            val /= m;
            f *= m;
        }
        if(!ans.empty() && ans.back().first == val) {
            ans.back().second += f;
        } else {
            ans.emplace_back(val, f);
        }
    }
    return ans;
}

int main() {
    std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
    int t;
    std::cin >> t;
    while(t--) {
        int n, m;
        std::cin >> n >> m;
        std::vector<int> a(n);
        for(int i = 0; i < n; i++) {
            std::cin >> a[i];
        }
        int k;
        std::cin >> k;
        std::vector<int> b(k);
        for(int i = 0; i < k; i++) {
            std::cin >> b[i];
        }
        std::cout << (solve(a, m) == solve(b, m) ? "YES\n" : "NO\n");
    }
}