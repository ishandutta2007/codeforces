#include <bits/stdc++.h>

using ll = long long;
const int N = 100010;

ll a[N];

void update(ll &u, int pos, int value){
    if (pos == 1 || a[pos] > 0){
        u -= a[pos];
    }
    a[pos] += value;
    if (pos == 1 || a[pos] > 0){
        u += a[pos];
    }
}

int main(){
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++ i){
        scanf("%lld", &a[i]);
    }
    for (int i = n; i >= 1; -- i){
        a[i] -= a[i - 1];
    }
    ll ans = 0;
    for (int i = 1; i <= n; ++ i){
        if (i == 1 || a[i] > 0){
            ans += a[i];
        }
    }
    printf("%lld\n", (ans + 1) >> 1);
    int test;
    scanf("%d", &test);
    while (test --){
        int l, r, x;
        scanf("%d%d%d", &l, &r, &x);
        if (r < n){
            update(ans, r + 1, -x);
        }
        update(ans, l, x);
        printf("%lld\n", (ans + 1) >> 1);
    }
    return 0;
}