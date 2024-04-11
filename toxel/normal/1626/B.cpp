//
// Created by  on 2022/1/6.
//

#include <bits/stdc++.h>
#define mp std::make_pair
#define scanf dont_use_scanf
#define printf dont_use_printf
#define endl dont_use_endl

using ll = int64_t;
using pii = std::pair <int, int>;
using piii = std::tuple <int, int, int>;

const int N = 200010;

char s[N];

void solve(){
    std::cin >> s;
    int n = strlen(s);
    bool has_big = false;
    for (int i = 0; i < n - 1; ++ i){
        if (s[i] - '0' + s[i + 1] - '0' >= 10){
            has_big = true;
        }
    }
    if (has_big){
        for (int i = n - 2; i >= 0; -- i){
            if (s[i] - '0' + s[i + 1] - '0' >= 10){
                int value = s[i] - '0' + s[i + 1] - '0';
                s[i] = value / 10 + '0';
                s[i + 1] = value % 10 + '0';
                break;
            }
        }
        std::cout << s << '\n';
        return;
    }
    s[1] += s[0] - '0';
    std::cout << s + 1 << '\n';
}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    int test;
    std::cin >> test;
    while (test --){
        solve();
    }
    return 0;
}