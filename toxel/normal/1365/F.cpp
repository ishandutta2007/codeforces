#include <bits/stdc++.h>

const int N = 510;

int a[N], b[N];

void solve(){
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++ i){
        scanf("%d", &a[i]);
    }
    for (int i = 0; i < n; ++ i){
        scanf("%d", &b[i]);
    }
    if (n % 2 == 1){
        if (a[n / 2] != b[n / 2]){
            puts("No");
            return;
        }
    }
    using pii = std::pair <int, int>;
    std::map <pii, int> cnt;
    for (int i = 0; i < n / 2; ++ i){
        int x = a[i], y = a[n - 1 - i];
        if (x > y){
            std::swap(x, y);
        }
        ++ cnt[{x, y}];
        x = b[i], y = b[n - 1 - i];
        if (x > y){
            std::swap(x, y);
        }
        -- cnt[{x, y}];
    }
    for (auto u : cnt){
        if (u.second != 0){
            puts("No");
            return;
        }
    }
    puts("Yes");
}

int main(){
    int test;
    scanf("%d", &test);
    while (test --){
        solve();
    }
    return 0;
}