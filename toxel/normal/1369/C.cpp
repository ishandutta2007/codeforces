#include <bits/stdc++.h>

const int N = 200010;

int a[N], w[N];

void solve(){
    int n, k;
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; ++ i){
        scanf("%d", &a[i]);
    }
    for (int i = 1; i <= k; ++ i){
        scanf("%d", &w[i]);
    }
    std::sort(a + 1, a + n + 1);
    std::sort(w + 1, w + 1 + k, [&](const int &p1, const int &p2){
        int x = p1 == 1 ? INT_MAX : p1;
        int y = p2 == 1 ? INT_MAX : p2;
        return x > y;
    });
    int l = 1, r = n;
    long long ans = 0;
    for (int i = 1; i <= k; ++ i){
        ans += a[r --];
        if (w[i] > 1){
            ans += a[l];
            l += w[i] - 1;
        }
        else{
            ans += a[r + 1];
        }
    }
    printf("%lld\n", ans);
}

int main(){
    int test;
    scanf("%d", &test);
    while (test --){
        solve();
    }
    return 0;
}