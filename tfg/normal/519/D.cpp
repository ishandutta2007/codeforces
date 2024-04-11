#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>
#include <map>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

std::map<long long, int> f[26];

int main() {
    std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
    std::vector<long long> cost(26);
    for(auto &c : cost) std::cin >> c;
    std::string str;
    std::cin >> str;
    int n = (int) str.size();
    std::vector<long long> sum(n+1, 0);
    long long ans = 0;
    for(int i = 0; i < n; i++) {
        sum[i+1] = sum[i] + cost[str[i]-'a'];
        ans += f[str[i]-'a'][sum[i]];
        f[str[i]-'a'][sum[i+1]]++;
    }
    std::cout << ans << '\n';
}