//
// Created by  on 2022/1/17.
//

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
    std::sort(s, s + n);
    std::cout << s << '\n';
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