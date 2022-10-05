#include <bits/stdc++.h>

const int N = 100010;
using ll = long long;

int w[N], deg[N];

void solve(){
    int n;
    scanf("%d", &n);
    for (int i = 0; i <= n; ++ i){
        deg[i] = 0;
    }
    std::priority_queue<int> pq;
    for (int i = 1; i <= n; ++ i){
        scanf("%d", &w[i]);
    }
    for (int i = 0, u, v; i < n - 1; ++ i){
        scanf("%d%d", &u, &v);
        ++ deg[u];
        ++ deg[v];
    }
    ll ans = 0;
    for (int i = 1; i <= n; ++ i){
        ans += w[i];
        for (int j = 0; j < deg[i] - 1; ++ j){
            pq.push(w[i]);
        }
    }
    for (int i = 1; i <= n - 1; ++ i){
        printf("%lld%c", ans, " \n"[i == n - 1]);
        if (i < n - 1){
            ans += pq.top();
            pq.pop();
        }
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