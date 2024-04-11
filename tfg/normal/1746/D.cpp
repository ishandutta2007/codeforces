#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>
#include <map>
#include <algorithm>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

const int ms = 200200;

std::vector<int> edges[ms];
long long s[ms];
std::map<int, long long> memo[ms];

long long dp(int on, int paths) {
    int down = (int) edges[on].size();
    if(down == 0) {
        return s[on] * paths;
    }
    if(memo[on].find(paths) != memo[on].end()) {
        return memo[on][paths];
    }
    long long ans = s[on] * paths;
    std::vector<long long> deltas;
    for(auto to : edges[on]) {
        long long val = dp(to, paths / down);
        ans += val;
        if(paths % down != 0) {
            deltas.push_back(val - dp(to, paths / down + 1));
        }
    }
    if(paths % down != 0) {
        std::nth_element(deltas.begin(), deltas.begin() + paths % down, deltas.end());
        for(int i = 0; i < paths % down; i++) {
            ans -= deltas[i];
        }
    }
    return memo[on][paths] = ans;
}

int main() {
    std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
    int t;
    std::cin >> t;
    while(t--) {
        int n, k;
        std::cin >> n >> k;
        for(int i = 1; i < n; i++) {
            int p;
            std::cin >> p;
            edges[p-1].push_back(i);
        }
        for(int i = 0; i < n; i++) {
            std::cin >> s[i];
        }
        std::cout << dp(0, k) << '\n';
        for(int i = 0; i < n; i++) {
            edges[i].clear();
            memo[i].clear();
        }
    }
}