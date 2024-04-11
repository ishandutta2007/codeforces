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
        std::vector<bool> got(n, false);
        std::vector<int> a, b;
        for(int i = 0; i < n; i++) {
            int x;
            std::cin >> x;
            if(1 <= x && x <= n && !got[x-1]) {
                got[x-1] = true;
            } else {
                a.push_back((x-1)/2);
            }
        }
        std::sort(a.begin(), a.end());
        for(int i = 0; i < n; i++) {
            if(!got[i]) {
                b.push_back(i+1);
            }
        }
        int ans = (int) a.size();
        for(int i = 0; i < ans; i++) if(a[i] < b[i]) {
            ans = -1;
        }
        std::cout << ans << '\n';
    }
}