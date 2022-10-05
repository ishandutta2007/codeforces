//
// Created by  on 2022/1/6.
//

#include <bits/stdc++.h>
#define mp std::make_pair
#define scanf dont_use_scanf
#define printf dont_use_printf
#define puts dont_use_puts
#define endl dont_use_endl

using ll = int64_t;
using i128 = __int128_t;
using pii = std::pair <int, int>;
using piii = std::tuple <int, int, int>;

const int N = 1000010;

int a[N];
int b[N];

void solve(){
    int n, m;
    std::cin >> n >> m;
    for (int i = 0; i < n; ++ i){
        std::cin >> a[i];
    }
    int gcd = 0;
    for (int i = 0; i < m; ++ i){
        std::cin >> b[i];
        gcd = std::gcd(gcd, b[i]);
    }
    std::vector <int> minus(gcd);
    std::vector <int> min(gcd, INT_MAX);
    for (int i = 0; i < n; ++ i){
        if (a[i] < 0){
            minus[i % gcd] ^= 1;
        }
        int &u = min[i % gcd];
        u = std::min(u, std::abs(a[i]));
    }
    ll sum = 0;
    for (int i = 0; i < n; ++ i){
        sum += std::abs(a[i]);
    }
    ll ans = LLONG_MIN;
    for (int i = 0; i < 2; ++ i){
        ll tot = sum;
        for (int j = 0; j < gcd; ++ j){
            if (minus[j] ^ i){
                tot -= 2 * min[j];
            }
        }
        ans = std::max(ans, tot);
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