#include <bits/stdc++.h>

typedef long long ll;
const int N = 100010;

ll p[N];

ll getpiece(ll sit, ll offset, ll k){
    return (sit - offset) / k;
}

int main(){
    ll n, m, k;
    scanf("%lld%lld%lld", &n, &m, &k);
    for (int i = 0; i < m; ++ i){
        scanf("%lld", &p[i]);
        -- p[i];
    }
    int offset = 0, ans = 0;
    for (int i = 0, j = 0; i < m; ){
        while (j < n && getpiece(p[j], offset, k) == getpiece(p[i], offset, k)){
            ++ j;
        }
        ++ ans;
        offset += j - i;
        i = j;
    }
    printf("%d\n", ans);
    return 0;
}