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
        std::cin >> n;
        int sum = 0;
        std::vector<int> a(n);
        for(int i = 0; i < n; i++) {
            std::cin >> a[i];
            sum += a[i];
        }
        int removed = 0;
        for(int i = n-1, j = 0; i >= 0; i--) {
            if(a[i] == 0 && sum > 0) {
                removed++;
                sum--;
                while(a[j] == 0) j++;
                a[j] = 0;
            } else if(a[i] == 1) {
                sum--;
            }
        }
        std::cout << removed << '\n';
    }
}