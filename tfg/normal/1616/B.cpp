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
        std::string str;
        std::cin >> n >> str;
        int ans = 1;
        while(ans < n && str[ans] <= str[ans-1]) ans++;
        if(n >= 2 && str[1] >= str[0]) {
            ans = 1;
        }
        auto wtf = str.substr(0, ans);
        wtf += wtf;
        std::reverse(wtf.begin() + ans, wtf.end());
        std::cout << wtf << '\n';
    }
}