#include<bits/stdc++.h>

const int N = 200010;
typedef long long ll;

int a[N];

int main(){
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n << 1; ++ i){
        scanf("%d", &a[i]);
    }
    std::sort(a, a + (n << 1));
    ll ans = 1ll * (a[n - 1] - a[0]) * (a[(n << 1) - 1] - a[n]);
    for (int i = 1; i < n; ++ i){
        ans = std::min(ans, 1ll * (a[(n << 1) - 1] - a[0]) * (a[i + n - 1] - a[i]));
    }
    printf("%lld\n", ans);
    return 0;
}