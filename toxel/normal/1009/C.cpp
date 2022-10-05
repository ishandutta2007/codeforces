#include<bits/stdc++.h>

typedef long long ll;

int main(){
    int n, m;
    scanf("%d%d", &n, &m);
    ll ans = 0;
    for (int i = 0, x, d; i < m; ++ i){
        scanf("%d%d", &x, &d);
        ans += 2ll * n * x;
        if (d >= 0){
            ans += 1ll * (n - 1) * d * n;
        }
        else{
            int x1 = n >> 1, x2 = n - 1 >> 1;
            ans += 1ll * x1 * (x1 + 1) * d + 1ll * x2 * (x2 + 1) * d;
        }
    }
    printf("%.10Lf\n", (long double) ans / 2 / n);
    return 0;
}