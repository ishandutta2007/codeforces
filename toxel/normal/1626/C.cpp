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

const int N = 10010;

int h[N], k[N];

void solve(){
    int n;
    std::cin >> n;
    std::vector <int> c;
    for (int i = 0; i < n; ++ i){
        std::cin >> k[i];
    }
    for (int i = 0; i < n; ++ i){
        std::cin >> h[i];
        c.emplace_back(k[i] - h[i] + 1);
        c.emplace_back(k[i] + 1);
    }
    c.emplace_back(1);
    std::sort(c.begin(), c.end());
    c.erase(std::unique(c.begin(), c.end()), c.end());
    int sz = c.size();
    ll ans = 0;
    int prev = 0;
    for (int i = 0; i < sz - 1; ++ i){
        int l = c[i], r = c[i + 1] - 1;
        int max = 0;
        for (int j = 0; j < n; ++ j){
            if (k[j] - h[j] + 1 <= l && r <= k[j]){
                max = std::max(max, h[j] - (k[j] - l));
            }
        }
        if (prev > 0 && max > 1){
            max = std::max(max, prev + 1);
        }
        if (max > 0){
            ans += 1ll * (max + max + r - l) * (r - l + 1) / 2;
            prev = max + r - l;
        }
        else{
            prev = 0;
        }
    }
    std::cout << ans << '\n';
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