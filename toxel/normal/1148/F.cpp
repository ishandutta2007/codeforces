#include <bits/stdc++.h>

using ll = long long;
using pii = std::pair <ll, ll>;
const int N = 300010;
inline int sig(ll p){ return (p > 0) - (p < 0); }

pii p[N];

int main(){
    int n;
    scanf("%d", &n);
    ll sum = 0;
    for (int i = 0; i < n; ++ i){
        scanf("%lld%lld", &p[i].second, &p[i].first);
        sum += p[i].second;
    }
    std::sort(p, p + n);
    ll ans = 0;
    for (int i = 0, j = 0, bit = 1; i < n; i = j, ++ bit){
        ll tot = 0;
        while (j < n && p[j].first < (1ll << bit)){
            ll mask = p[j].first & ans;
            tot += __builtin_popcountll(mask) & 1 ? -p[j].second : p[j].second;
            ++ j;
        }
        if (sig(tot) == sig(sum)){
            ans |= 1ll << (bit - 1);
        }
    }
    printf("%lld\n", ans);
    return 0;
}