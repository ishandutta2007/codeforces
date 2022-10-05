#include <bits/stdc++.h>

const int N = 100010;
typedef long long ll;

int b[N], g[N];

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    int max = 0, smax = 0;
    ll sum = 0;
    for (int i = 0; i < n; ++ i){
        scanf("%d", &b[i]);
        sum += b[i];
        if (b[i] >= max){
            smax = max;
            max = b[i];
        }
        else if (b[i] > smax){
            smax = b[i];
        }
    }
    int min = INT_MAX;
    for (int i = 0; i < m; ++ i){
        scanf("%d", &g[i]);
        min = std::min(min, g[i]);
    }
    if (min < max){
        puts("-1");
        return 0;
    }
    ll ans = sum * m;
    if (min == max) {
        for (int i = 0; i < m; ++ i){
            ans += g[i] - max;
        }
    }
    else{
        for (int i = 0; i < m; ++ i){
            ans += g[i] - max;
        }
        ans += max - smax;
    }
    printf("%lld\n", ans);
    return 0;
}