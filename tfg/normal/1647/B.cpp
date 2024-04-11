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
        std::vector<std::vector<int>> a(n, std::vector<int>(m, 0));
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                char ch;
                std::cin >> ch;
                a[i][j] = ch - '0';
            }
        }
        bool good = true;
        for(int i = 0; i+1 < n; i++) {
            for(int j = 0; j+1 < m; j++) {
                int sum = a[i][j] + a[i+1][j] + a[i][j+1] + a[i+1][j+1];
                good = good && sum != 3;
            }
        }
        std::cout << (good ? "YES\n" : "NO\n");
    }
}