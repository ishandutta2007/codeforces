#include <bits/stdc++.h>

typedef long long ll;
const int N = 100010;

int x[N];

int main(){
    int n;
    scanf("%d", &n);
    ll ans = 0;
    for (int i = 0; i < n; ++ i){
        int a, b;
        scanf("%d%d", &a, &b);
        ans += -a + 1ll * b * n;
        x[i] = a - b;
    }
    std::sort(x, x + n, std::greater <int>());
    for (int i = 0; i < n; ++ i){
        ans += 1ll * x[i] * (i + 1);
    }
    printf("%lld\n", ans);
    return 0;
}