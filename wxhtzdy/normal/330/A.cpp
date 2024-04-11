#include <bits/stdc++.h>

using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int r, c;
    std::cin >> r >> c;
    
    std::vector<std::string> s(r);
    std::vector<int> x(r), y(c);
    for (int i = 0; i < r; i++) {
        std::cin >> s[i];
        for (int j = 0; j < c; j++) {
            if (s[i][j] == 'S') {
                x[i] = 1;
                y[j] = 1;
            }
        }
    }
    
    int ans = 0;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            ans += (x[i] + y[j] < 2 ? 1 : 0);
        }
    }
    
    std::cout << ans << "\n";
    
    return 0;
}