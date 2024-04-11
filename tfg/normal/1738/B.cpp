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
        int n, k;
        std::cin >> n >> k;
        long long highest = 1e18;
        long long sum = 0;
        bool good = true;
        std::vector<long long> a(k);
        for(int i = 0; i < k; i++) {
            std::cin >> a[i];
        }
        for(int i = 0; i < k; i++) {
            long long nxtSum = a[k-i-1];
            if(i == 0) {
                sum = nxtSum;
            } else {
                long long nextHighest = sum - nxtSum;
                if(nextHighest > highest) {
                    good = false;
                }
                highest = nextHighest;
                sum = nxtSum;
            }
        }
        if(k == n) {
            if(sum > highest) {
                good = false;
            }
        } else if(k == 1) {
            good = true;
        } else {
            // can get -infinity up until highest * (n-k+1)
            if(highest * (n - k + 1) < sum) {
                good = false;
            }
        }
        std::cout << (good ? "Yes\n" : "No\n");
    }
}