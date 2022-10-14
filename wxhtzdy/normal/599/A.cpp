#include <bits/stdc++.h>

using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int d1, d2, d3;
    std::cin >> d1 >> d2 >> d3;
    
    std::cout << std::min({d1 + d2 + d3, d1 * 2 + d2 * 2, d1 * 2 + d3 * 2, d2* 2 + d3 * 2});
    return 0;
}