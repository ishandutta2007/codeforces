#include<bits/stdc++.h>

const int N = 200010;
typedef long long ll;

int a[N];

int main(){
    int n, s;
    scanf("%d%d", &n, &s);
    for (int i = 0; i < n; ++ i){
        scanf("%d", &a[i]);
    }
    std::sort(a, a + n);
    ll ans = 0;
    for (int i = 0; i <= n >> 1; ++ i){
        if (a[i] > s){
            ans += std::abs(a[i] - s);
        }
    }
    for (int i = n >> 1; i < n; ++ i){
        if (a[i] < s){
            ans += std::abs(a[i] - s);
        }
    }
    printf("%lld\n", ans);
    return 0;
}