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
        std::vector<int> a(n), b(n);
        for(int rep = 0; rep < 2; rep++) for(int i = 0; i < n; i++) {
            int &val = (rep == 0 ? a : b)[i];
            std::cin >> val;
            val--;
        }
        std::vector<int> f(n, 0);
        int i = 0, j = 0;
        int last = -1;
        while(j < n) {
            //std::cout << "[" << i << ", " << j << "]\n";
            if(f[b[j]] > 0 && last == b[j]) {
                f[b[j++]]--;
            } else if(i < n && a[i] == b[j]) {
                last = b[j];
                i++, j++;
            } else if(i < n) {
                f[a[i++]]++;
            } else {
                break;
            }
        }
        std::cout << (j == n ? "YES\n" : "NO\n");
    }
}