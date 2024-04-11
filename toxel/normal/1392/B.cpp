#include <bits/stdc++.h>

const int N = 200010;
using ll = long long;

ll a[N];

void solve(){
    int n;
    ll k;
    scanf("%d%lld", &n, &k);
    if (k > 4){
        k -= (k - 4) / 2 * 2;
    }
    for (int i = 0; i < n; ++ i){
        scanf("%lld", &a[i]);
    }
    for (int i = 0; i < k; ++ i){
        ll max = *std::max_element(a, a + n);
        for (int j = 0; j < n; ++ j){
            a[j] = max - a[j];
        }
    }
    for (int i = 0; i < n; ++ i){
        printf("%lld%c", a[i], " \n"[i == n - 1]);
    }
}

int main(){
    int test;
    scanf("%d", &test);
    while (test --){
        solve();
    }
    return 0;
}