#include <bits/stdc++.h>

using ll = long long;
const int N = 200010;

int pre[N], suf[N];
int a[N];
ll b[N];

int main(){
    int n, k, x;
    scanf("%d%d%d", &n, &k, &x);
    for (int i = 1; i <= n; ++ i){
        scanf("%d", &a[i]);
        pre[i] = pre[i - 1] | a[i];
    }
    for (int i = n; i >= 1; -- i){
        suf[i] = suf[i + 1] | a[i];
        b[i] = a[i];
        for (int j = 0; j < k; ++ j){
            b[i] *= x;
        }
    }
    ll max = 0;
    for (int i = 1; i <= n; ++ i){
        max = std::max(max, b[i] | pre[i - 1] | suf[i + 1]);
    }
    printf("%lld\n", max);
    return 0;
}