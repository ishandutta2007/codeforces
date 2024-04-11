#include <bits/stdc++.h>

const int N = 510;
using ll = long long;

ll a[N];

int main(){
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++ i){
        scanf("%lld", &a[i]);
    }
    ll ans = 0;
    for (int i = 0; i < n; ++ i){
        for (int j = i; j < n; ++ j){
            for (int k = j; k < n; ++ k){
                ans = std::max(ans, a[i] | a[j] | a[k]);
            }
        }
    }
    printf("%lld\n", ans);
    return 0;
}