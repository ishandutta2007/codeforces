#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
    std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
    const int ms = 1001000;
    std::vector<bool> isPrime(ms, true);
    isPrime[0] = isPrime[1] = false;
    for(int i = 2; i < ms; i++) if(isPrime[i]) {
        for(int j = i+i; j < ms; j += i) {
            isPrime[j] = false;
        }
    }
    int t;
    std::cin >> t;
    auto solve = [&](const std::vector<int> &a) {
        long long ans = 0;
        for(int i = 0; i < (int) a.size(); i++) {
            if(isPrime[a[i]]) {
                int l = i, r = i;
                while(l > 0 && a[l-1] == 1) l--;
                while(r+1 < (int) a.size() && a[r+1] == 1) r++;
                ans += (long long) (i - l + 1) * (r - i + 1) - 1;
            }
        }
        return ans;
    };
    while(t--) {
        int n, e;
        std::cin >> n >> e;
        std::vector<std::vector<int>> a(e);
        for(int i = 0; i < n; i++) {
            int x;
            std::cin >> x;
            a[i%e].push_back(x);
        }
        long long ans = 0;
        for(int i = 0; i < e; i++) {
            ans += solve(a[i]);
        }
        std::cout << ans << '\n';
    }
}