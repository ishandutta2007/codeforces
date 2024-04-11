#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>
#include <algorithm>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

long long solve(const std::vector<int> &a, const std::vector<int> &b) {
    int n = (int) a.size(), m = (int) b.size();
    long long ans = 0;
    // a comes first
    // so at most m or n-1 doubled
    for(int i = 0; i < n; i++) {
        ans += i < std::min(n-1, m) ? 2 * a[i] : a[i];
    }
    // b comes second
    // so at most m or n doubled
    for(int i = 0; i < m; i++) {
        ans += i < n ? 2 * b[i] : b[i];
    }
    return ans;
}

int main() {
    std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
    int t;
    std::cin >> t;
    while(t--) {
        int n;
        std::cin >> n;
        std::vector<int> a(n);
        for(int i = 0; i < n; i++) {
            std::cin >> a[i];
        }
        std::vector<int> vecs[2];
        for(int i = 0; i < n; i++) {
            int x;
            std::cin >> x;
            vecs[a[i]].push_back(x);
        }
        for(int i = 0; i < 2; i++) {
            std::sort(vecs[i].rbegin(), vecs[i].rend());
        }
        std::cout << std::max(solve(vecs[0], vecs[1]), solve(vecs[1], vecs[0])) << '\n';
    }
}