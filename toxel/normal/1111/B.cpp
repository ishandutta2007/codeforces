#include<bits/stdc++.h>

const int N = 100010;
typedef long long ll;

int a[N];
ll pre[N];

int main(){
    int n, k, m;
    scanf("%d%d%d", &n, &k, &m);
    for (int i = 1; i <= n; ++ i){
        scanf("%d", &a[i]);
    }
    std::sort(a + 1, a + n + 1, std::greater <int>());
    double ans = 0;
    for (int i = 1; i <= n; ++ i){
        pre[i] = pre[i - 1] + a[i];
        if (m < n - i) continue;
        ans = std::max(ans, 1.0 * (pre[i] + std::min(1ll * i * k, (ll) m - (n - i))) / i);
    }
    printf("%.15f\n", ans);
    return 0;
}