#include<bits/stdc++.h>

const int N = 200010;
typedef long long ll;

int a[N], pre[N];

ll calc(ll n){
    return n * (n - 1) >> 1;
}

int main(){
    int n, k;
    scanf("%d%d", &n, &k);
    std::map <int, int> map;
    for (int i = 1; i <= n; ++ i){
        scanf("%d", &a[i]);
        pre[i] = pre[i - 1] ^ a[i];
        ++ map[pre[i] >> (k - 1) & 1 ? pre[i] ^ ((1 << k) - 1) : pre[i]];
    }
    ll ans = calc(n + 1);
    if (map.count(0)){
        ans -= calc(map[0] + 1 >> 1) + calc(map[0] + 2 >> 1);
    }
    for (auto u : map){
        if (u.first == 0) continue;
        ans -= calc(u.second >> 1) + calc(u.second + 1 >> 1);
    }
    printf("%lld\n", ans);
    return 0;
}