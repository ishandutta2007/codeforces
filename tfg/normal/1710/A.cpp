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
        int n, m, k;
        std::cin >> n >> m >> k;
        long long got[2] = {0, 0};
        auto f = [](int val, int dim, int other) {
            val = val / dim;
            if(val == other-1) val--;
            if(val <= 1) return 0LL;
            else return (long long) val;
        };
        bool other[2] = {false, false};
        while(k--) {
            int x;
            std::cin >> x;
            auto a = f(x, n, m);
            auto b = f(x, m, n);
            if(a > 2) {
                other[0] = true;
            }
            if(b > 2) {
                other[1] = true;
            }
            got[0] += a;
            got[1] += b;
        }
        auto test = [](long long got, long long target, bool info) {
            if(info) {
                return got >= target;
            } else {
                return got >= target && target % 2 == 0;
            }
        };
        if(test(got[0], m, other[0]) || test(got[1], n, other[1])) {
            std::cout << "Yes\n";
        } else {
            std::cout << "No\n";
        }
    }
}