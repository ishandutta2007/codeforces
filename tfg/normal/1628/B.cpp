#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>
#include <set>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
    std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
    int t;
    std::cin >> t;
    while(t--) {
        std::set<int> from3get2, twos, threes;
        auto hash = [](const std::string &str) {
            int ans = 0;
            for(auto c : str) {
                ans = ans * 27 + (c - 'a' + 1);
            }
            return ans;
        };
        bool ans = false;
        int n;
        std::cin >> n;
        while(n--) {
            std::string str;
            std::cin >> str;
            auto rev = str;
            int sz = (int) str.size();
            std::swap(rev[0], rev[sz-1]);
            if(ans) continue;
            if(sz == 1) {
                ans = true;
            } else if(sz == 2) {
                int h[2] = {hash(str), hash(rev)};
                twos.insert(h[0]);
                ans = twos.count(h[1]) || from3get2.count(h[1]);
            } else {
                assert(sz == 3);
                int h[2] = {hash(str), hash(rev)};
                auto wtf = str.substr(1, 2);
                std::swap(wtf[0], wtf[1]);
                from3get2.insert(hash(str.substr(0, 2)));
                threes.insert(h[0]);
                ans = twos.count(hash(wtf)) || threes.count(h[1]);
            }
        }
        std::cout << (ans ? "YES\n" : "NO\n");
    }
}