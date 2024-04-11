#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
    std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
    int n, q;
    std::cin >> n >> q;
    std::string bad = "abc";
    std::string str;
    std::cin >> str;
    int ans = 0;
    for(int i = 0; i + 3 <= n; i++) {
        if(str.substr(i, 3) == bad) {
            ans++;
        }
    }
    while(q--) {
        int pos;
        char ch;
        std::cin >> pos >> ch;
        pos--;
        for(int i = std::max(0, pos-2); i <= pos && i + 3 <= n; i++) {
            if(str.substr(i, 3) == bad) {
                ans--;
            }
        }
        str[pos] = ch;
        for(int i = std::max(0, pos-2); i <= pos && i + 3 <= n; i++) {
            if(str.substr(i, 3) == bad) {
                ans++;
            }
        }
        std::cout << ans << '\n';
    }
}