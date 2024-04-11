#include <bits/stdc++.h>

const int N = 1000010;
using ll = long long;

std::vector <int> prime;
int min[N];
int a[N], left[N], right[N];

void solve(){
    int n, e;
    scanf("%d%d", &n, &e);
    for (int i = 1; i <= n; ++ i){
        scanf("%d", &a[i]);
    }
    for (int i = 0; i <= n + 1; ++ i){
        left[i] = right[i] = 0;
    }
    for (int i = 1; i <= n; ++ i){
        if (a[i] == 1){
            left[i] = (i - e <= 0 ? 0 : left[i - e]) + 1;
        }
        else{
            left[i] = 0;
        }
    }
    for (int i = n; i >= 1; -- i){
        if (a[i] == 1){
            right[i] = (i + e > n ? 0 : right[i + e]) + 1;
        }
        else{
            right[i] = 0;
        }
    }
    ll ans = 0;
    for (int i = 1; i <= n; ++ i){
        if (min[a[i]] != a[i]){
            continue;
        }
        int l = i - e <= 0 ? 0 : left[i - e];
        int r = i + e > n ? 0 : right[i + e];
        ans += 1ll * (l + 1) * (r + 1) - 1;
    }
    printf("%lld\n", ans);
}

int main(){
    for (int i = 2; i < N; ++ i){
        if (!min[i]){
            min[i] = i;
            prime.emplace_back(i);
        }
        for (auto u : prime){
            if (i * u >= N) break;
            min[i * u] = u;
            if (i % u == 0){
                break;
            }
        }
    }
    int test;
    scanf("%d", &test);
    while (test --){
        solve();
    }
    return 0;
}