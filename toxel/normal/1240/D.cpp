#include <bits/stdc++.h>

const int N = 300010;
typedef long long ll;

int a[N];
int dp[N];
std::unordered_map <int, int> map[N];

void solve(){
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n + 5; ++ i){
        map[i].clear();
    }
    for (int i = 0; i < n; ++ i){
        scanf("%d", &a[i]);
    }
    dp[n - 1] = dp[n] = 0;
    ll ans = 0;
    for (int i = n - 2; i >= 0; -- i){
        int pos = -1;
        if (a[i] == a[i + 1]){
            pos = i + 2;
        }
        else{
            if (!map[i + 1].count(a[i])){
                dp[i] = 0;
                continue;
            }
            pos = map[i + 1][a[i]] + 1;
        }
        std::swap(map[i], map[pos]);
        if (pos < n){
            if (!map[i].count(a[pos]) || map[i][a[pos]] > pos){
                map[i][a[pos]] = pos;
            }
        }
        dp[i] = dp[pos] + 1;
        ans += dp[i];
    }
    printf("%lld\n", ans);
}

int main(){
    int test;
    scanf("%d", &test);
    while (test --){
        solve();
    }
    return 0;
}