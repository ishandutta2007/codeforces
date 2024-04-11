#include<bits/stdc++.h>

typedef std::pair <int, int> pii;
typedef long long ll;

int main(){
    int n;
    scanf("%d", &n);
    std::map <int, int> Hash1, Hash2;
    std::map <pii, int> Hash3;
    for (int i = 0, x, y; i < n; ++ i){
        scanf("%d%d", &x, &y);
        ++ Hash1[x];
        ++ Hash2[y];
        ++ Hash3[{x, y}];
    }
    ll ans = 0;
    for (auto u : Hash1){
        int x = u.second;
        ans += 1ll * x * (x - 1) / 2;
    }
    for (auto u : Hash2){
        int x = u.second;
        ans += 1ll * x * (x - 1) / 2;
    }
    for (auto u : Hash3){
        int x = u.second;
        ans -= 1ll * x * (x - 1) / 2;
    }
    printf("%lld\n", ans);
    return 0;
}