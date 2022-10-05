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

const int N = 600010;

int min_pos[N], max_pos[N];
std::string s[N];

int encode(std::string str){
    int code = 0;
    for (int i = 0; i < 4; ++ i){
        code = code * 27 + (i < str.size() ? str[i] - 'a' + 1 : 0);
    }
    return code;
}

void solve(){
    for (int i = 0; i < N; ++ i){
        min_pos[i] = INT_MAX;
        max_pos[i] = INT_MIN;
    }
    int n;
    std::cin >> n;
    for (int i = 0; i < n; ++ i){
        std::cin >> s[i];
    }
    for (int i = 0; i < n; ++ i){
        std::string rev = s[i];
        std::reverse(rev.begin(), rev.end());
        if (rev == s[i]){
            puts("YES");
            return;
        }
    }
    for (int i = 0; i < n; ++ i){
        int code = encode(s[i]);
        min_pos[code] = std::min(min_pos[code], i);
        max_pos[code] = std::max(max_pos[code], i);
    }
    for (int i = 0; i < n; ++ i){
        std::string rev = s[i];
        std::reverse(rev.begin(), rev.end());
        if (max_pos[encode(rev)] > i){
            puts("YES");
            return;
        }
        if (max_pos[encode(rev.substr(1, s[i].size() - 1))] > i){
            puts("YES");
            return;
        }
        if (min_pos[encode(rev.substr(0, s[i].size() - 1))] < i){
            puts("YES");
            return;
        }
    }
    puts("NO");
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