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

const int N = 1010;

int a[N][N];
int pre[N][N];

void solve(){
    int n;
    std::cin >> n;
    for (int i = 0; i <= n; ++ i){
        for (int j = 0; j <= n; ++ j){
            a[i][j] = pre[i][j] = 0;
        }
    }
    for (int i = 1; i <= n; ++ i){
        for (int j = 1; j <= n; ++ j){
            std::cin >> a[i][j];
            pre[i][j] = a[i][j];
        }
    }
    for (int i = 1; i <= n; ++ i){
        for (int j = 1; j <= n; ++ j){
            pre[i][j] ^= pre[i][j - 1];
        }
    }
    for (int i = 1; i <= n; ++ i){
        for (int j = 1; j <= n; ++ j){
            pre[i][j] ^= pre[i - 1][j];
        }
    }
    int ans = 0;
    for (int i = 1; i <= n / 2; i += 2){
        int size = n / 2 - i + 1;
        if (size == 1){
            continue;
        }
        size = (size - 1) * 2;
        int right = i + 1 + size - 1;
        ans ^= pre[right][right] ^ pre[i][right] ^ pre[right][i] ^ pre[i][i];
    }
    for (int i = 1; i <= n; i += 2){
        for (int j = 1; j <= n + 1 - i; j += 2){
            ans ^= a[i][j];
        }
        for (int j = i + 1; j <= n; j += 2){
            ans ^= a[i][j];
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