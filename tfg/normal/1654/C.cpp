#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>
#include <queue>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
    std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
    int t;
    std::cin >> t;
    auto solve = []() {
        int n;
        std::cin >> n;
        std::priority_queue<long long> a, hp;
        long long sum = 0;
        for(int i = 0; i < n; i++) {
            int x;
            std::cin >> x;
            sum += x;
            a.push(x);
        }
        hp.push(sum);
        while(a.size() >= hp.size()) {
            if(a.empty()) {
                std::cout << "YES\n";
                return;
            }
            if(hp.top() == a.top()) {
                hp.pop();
                a.pop();
            } else {
                auto x = hp.top();
                hp.pop();
                hp.push(x/2);
                hp.push((x+1)/2);
            }
        }
        std::cout << "NO\n";
    };
    while(t--) {
        solve();
    }
}