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
        std::vector<int> a(n);
        for(int i = 0; i < n; i++) {
            std::cin >> a[i];
        }
        while(!a.empty()) {
            int pos = (int) a.size() - 1;
            while(pos >= 0 && a[pos] % (pos+2) == 0) pos--;
            if(pos == -1) break;
            a.erase(a.begin() + pos);
        }
        std::cout << (a.empty() ? "YES\n" : "NO\n");
    }
}