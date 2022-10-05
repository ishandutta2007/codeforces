//
// Created by  on 2022/1/6.
//

#include <bits/stdc++.h>
#define mp std::make_pair
#define scanf dont_use_scanf
#define printf dont_use_printf
#define endl dont_use_endl

using ll = int64_t;
using i128 = __int128_t;
using pii = std::pair <int, int>;
using piii = std::tuple <int, int, int>;

void solve(){
    int n, k;
    std::cin >> n >> k;
    std::vector <int> ans(n);
    for (int i = 0; i < n; ++ i){
        ans[i] = n - 1 - i;
    }
    if (k == 0){
    }
    else if (k < n - 1){
        ans[0] = n - 1 - k;
        ans[n - 1 - k] = 0;
        ans[k] = n - 1;
        ans[n - 1] = k;
    }
    else{
        if (n == 4){
            std::cout << "-1\n";
            return;
        }
        ans[0] = 1;
        ans[1] = 0;
        ans[n - 2] = n - 1;
        ans[n - 1] = n - 2;
        ans[n / 2 - 2] = n / 2;
        ans[n / 2] = n / 2 - 2;
        ans[n / 2 - 1] = n / 2 + 1;
        ans[n / 2 + 1] = n / 2 - 1;
    }
    int sum = 0;
    for (int i = 0; i < n; ++ i){
        if (ans[i] > i){
            std::cout << i << ' ' << ans[i] << '\n';
            sum += i & ans[i];
        }
    }
    assert(sum == k);
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