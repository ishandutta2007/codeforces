#include <bits/stdc++.h>

const int N = 200010;
using ll = long long;

int a[N];

void solve(){
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++ i){
        scanf("%d", &a[i]);
    }
    ll sum = 0;
    for (int i = 1; i <= n; i += 2){
        sum += a[i];
    }
    ll ans = sum;
    for (int i = 3; i <= n; i += 2){
        sum += a[i - 1] - a[i - 2];
        ans = std::max(ans, sum);
    }
    sum = a[1];
    for (int i = 2; i <= n; i += 2){
        sum += a[i];
    }
    ans = std::max(ans, sum);
    for (int i = 4; i <= n; i += 2){
        sum += a[i - 1] - a[i - 2];
        ans = std::max(ans, sum);
    }
    printf("%lld\n", ans);
}
int main(){
    solve();
    return 0;
}