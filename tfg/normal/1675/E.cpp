#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

const int ms = 26;

int par[ms];
int getPar(int x) { return x == par[x] ? x : par[x] = getPar(par[x]); }

int main() {
    std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
    int t;
    std::cin >> t;
    while(t--) {
        int n, k;
        std::cin >> n >> k;
        for(int i = 0; i < ms; i++) {
            par[i] = i;
        }
        std::string str;
        std::cin >> str;
        for(auto &ch : str) {
            int val = ch - 'a';
            while(1) {
                val = getPar(val);
                if(val > 0 && k > 0) {
                    k--;
                    par[val] = val-1;
                } else {
                    break;
                }
            }
            ch = char(val + 'a');
        }
        std::cout << str << '\n';
    }
}