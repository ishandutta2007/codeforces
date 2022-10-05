#include <bits/stdc++.h>

const int N = 200010;
using ll = long long;

int a[N], b[N];
int inv[N];

int main(){
    int n, m;
    scanf("%d%d", &n, &m);
    int x, k, y;
    scanf("%d%d%d", &x, &k, &y);
    for (int i = 1; i <= n; ++ i){
        scanf("%d", &a[i]);
        inv[a[i]] = i;
    }
    for (int i = 1; i <= m; ++ i){
        scanf("%d", &b[i]);
        b[i] = inv[b[i]];
    }
    b[0] = 0, b[m + 1] = n + 1;
    ll ans = 0;
    for (int i = 0; i <= m; ++ i){
        if (b[i] > b[i + 1]){
            puts("-1");
            return 0;
        }
        int l = b[i] + 1, r = b[i + 1] - 1;
        if (l > r){
            continue;
        }
        int max = 0;
        for (int j = l; j <= r; ++ j){
            max = std::max(max, a[j]);
        }
        int start = std::max(a[l - 1], a[r + 1]) > max ? 0 : 1;
        ll min = LLONG_MAX;
        for (int j = start; j <= r - l + 1; ++ j){
            if (j % k){
                continue;
            }
            min = std::min(min, 1ll * (r - l + 1 - j) * y + 1ll * (j / k) * x);
        }
        if (min == LLONG_MAX){
            puts("-1");
            return 0;
        }
        ans += min;
    }
    printf("%lld\n", ans);
    return 0;
}