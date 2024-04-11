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
        int n;
        std::cin >> n;
        std::vector<int> a(n);
        for(int i = 0; i < n; i++) {
            std::cin >> a[i];
        }
        int l = 0, r = n-1;
        bool zero = false;
        while(l < n && a[l] == 0) l++;
        while(r >= 0 && a[r] == 0) r--;
        for(int i = l; i <= r; i++) zero = zero || a[i] == 0;
        if(l == n) {
            std::cout << "0\n";
        } else if(!zero) {
            std::cout << "1\n";
        } else {
            std::cout << "2\n";
        }
    }
}