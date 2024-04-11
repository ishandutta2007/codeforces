#include <bits/stdc++.h>

const int N = 1010;
using ll = unsigned long long;
using sll = long long;

ll c[N];
sll pre[N], min[N][N];

void solve(){
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++ i){
        scanf("%llu", &c[i]);
    }
    for (int i = 1; i <= n; ++ i){
        pre[i] = pre[i - 1] + (i % 2 == 1 ? c[i] : -c[i]);
    }
    for (int i = 1; i <= n; ++ i){
        sll cur = 0, mini = LLONG_MAX;
        for (int j = i; j <= n; ++ j){
            if (j % 2 == 1){
                mini = std::min(mini, cur);
            }
            else{
                mini = std::min(mini, cur - sll(c[j]));
            }
            min[i][j] = mini;
            cur += j % 2 == 1 ? c[j] : -c[j];
        }
    }
    ll ans = 0;
    for (int i = 1; i <= n; i += 2){
        for (int j = i + 1; j <= n; j += 2){
            if (j == i + 1){
                ans += std::min(c[i], c[j]);
                continue;
            }
            sll pref = pre[j - 1] - pre[i];
            sll least = -min[i + 1][j - 1];
            sll x = c[i], y = c[j];
            if (pref < 0){
                pref = -pref;
                if (x < pref){
                    continue;
                }
                x -= pref;
                least -= pref;
            }
            else if (pref > 0){
                if (y < pref){
                    continue;
                }
                y -= pref;
            }
            least = std::max(least, 1ll);
            sll to_add = std::min(x, y) - least + 1;
            ans += std::max(0ll, to_add);
        }
    }
    printf("%llu\n", ans);
}

int main(){
    int test;
    // scanf("%d", &test);
    test = 1;
    while (test --){
        solve();
    }
    return 0;
}