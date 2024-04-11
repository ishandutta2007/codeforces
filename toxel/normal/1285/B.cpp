#include <bits/stdc++.h>

const int N = 100010;
using ll = long long;

int a[N];
ll pre[N];

void solve(){
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++ i){
        scanf("%d", &a[i]);
        pre[i] = pre[i - 1] + a[i];
    }
    ll min = 0, ans = LLONG_MIN;
    for (int i = 1; i < n; ++ i){
        ans = std::max(ans, pre[i] - min);
        min = std::min(min, pre[i]);
    }
    for (int i = 1; i < n; ++ i){
        ans = std::max(ans, pre[n] - pre[i]);
    }
    if (ans < pre[n]){
        puts("YES");
    }
    else{
        puts("NO");
    }
}

int main(){
    int test;
    scanf("%d", &test);
    while (test --){
        solve();
    }
}