#include<bits/stdc++.h>

const int N = 100010;
typedef long long ll;

int l[N], r[N];

int main(){
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++ i){
        scanf("%d%d", &l[i], &r[i]);
    }
    std::sort(l, l + n);
    std::sort(r, r + n);
    ll ans = 0;
    for (int i = 0; i < n; ++ i){
        ans += std::max(l[i], r[i]);
    }
    printf("%lld\n", ans + n);
    return 0;
}