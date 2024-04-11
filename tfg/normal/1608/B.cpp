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
        int l = 1, r = n;
        int a, b;
        std::cin >> a >> b;
        std::vector<int> ans(n);
        if(a+b >= n-1 || std::abs(a-b) > 1) {
            std::cout << "-1\n";
            continue;
        }
        if(a + b == 0) {
            for(int i = 0; i < n; i++) {
                ans[i] = l++;
            }
        } else if(a > b) {
            int id = 0;
            ans[id++] = l++;
            while(a > 1) {
                ans[id++] = r--;
                ans[id++] = l++;
                a--;
            }
            ans[n-1] = l++;
            while(id+1 < n) {
                ans[id++] = l++;
            }
        } else if(a < b) {
            int id = 0;
            ans[id++] = r--;
            while(b > 1) {
                ans[id++] = l++;
                ans[id++] = r--;
                b--;
            }
            ans[n-1] = r--;
            while(id+1 < n) {
                ans[id++] = r--;
            }
        } else {
            int id = 0;
            ans[id++] = l++;
            while(a > 0) {
                ans[id++] = r--;
                ans[id++] = l++;
                a--;
            }
            while(id < n) {
                ans[id++] = l++;
            }
            assert(id == n);
        }
        for(int i = 0; i < n; i++) {
            std::cout << ans[i] << (i + 1 == n ? '\n' : ' ');
        }
    }
}