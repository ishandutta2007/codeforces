#include <bits/stdc++.h>

const int N = 100100;
using ll = long long;

int h[N];
ll pre[N];
int n, a, r, m;

void update(ll small, ll big, ll &ans){
    ans = std::min(small * a + big * r, ans);
    ll diff = std::min(small, big);
    ans = std::min(ans, (small - diff) * a + (big - diff) * r + diff * m);
}

int main(){
    scanf("%d%d%d%d", &n, &a, &r, &m);
    for (int i = 1; i <= n; ++ i){
        scanf("%d", &h[i]);
    }
    std::sort(h + 1, h + n + 1);
    for (int i = 1; i <= n; ++ i){
        pre[i] = pre[i - 1] + h[i];
    }
    ll ans = LLONG_MAX;
    for (int i = 0; i <= n; ++ i){
        ll small = 1ll * i * h[i] - pre[i];
        ll big = (pre[n] - pre[i]) - 1ll * (n - i) * h[i];
        update(small, big, ans);
    }
    for (int i = 1; i < n; ++ i){
        ll small = 1ll * i * h[i] - pre[i];
        ll big = (pre[n] - pre[i]) - 1ll * (n - i) * h[i];
        if (big < small){
            break;
        }
        ll add = (big - small) / n;
        for (int delta = -2; delta <= 2; ++ delta){
            ll nv = h[i] + add + delta;
            if (h[i] <= nv && nv <= h[i + 1]){
                update(small + (add + delta) * i, big - (add + delta) * (n - i), ans);
            }
        }
    }
    printf("%lld\n", ans);
}