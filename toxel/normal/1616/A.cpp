#include <bits/stdc++.h>

void solve(){
    int n;
    scanf("%d", &n);
    std::map <int, int> map;
    for (int i = 0; i < n; ++ i){
        int x;
        scanf("%d", &x);
        map[std::abs(x)] += 1;
    }
    int ans = 0;
    for (auto [key, value]: map){
        if (key == 0){
            ans += 1;
        }
        else{
            ans += std::min(value, 2);
        }
    }
    printf("%d\n", ans);
}

int main(){
    int test;
    scanf("%d", &test);
    while (test --){
        solve();
    }
    return 0;
}