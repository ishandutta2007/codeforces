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
        int n, m;
        std::cin >> n >> m;
        const unsigned long long INF = 1.01e18;
        std::vector<std::vector<unsigned long long>> a(n);
        std::vector<unsigned long long> wtf(n, 0);
        for(int i = 0; i < n; i++) {
            a[i].resize(m);
            for(int j = 0; j < m; j++) {
                std::cin >> a[i][j];
                wtf[i] += a[i][j] * j;
            }
        }
        int other = 1;
        while(wtf[other] == wtf[0]) other++;
        int ans = wtf[other] - wtf[0] > INF ? 0 : other;
        std::cout << ans+1 << ' ' << wtf[ans] - wtf[ans^other] << '\n';
    }
}