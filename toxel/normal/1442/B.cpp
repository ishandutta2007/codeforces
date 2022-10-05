#include <bits/stdc++.h>

const int N = 200010;
const int moder = 998244353;

int a[N], inv[N], b[N];
bool vis[N];

void solve(){
    int n, k;
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; ++ i){
        scanf("%d", &a[i]);
        inv[a[i]] = i;
        vis[i] = false;
    }
    for (int i = 0; i < k; ++ i){
        scanf("%d", &b[i]);
        vis[inv[b[i]]] = true;
    }
    std::set <int> set;
    for (int i = 1; i <= n; ++ i){
        if (!vis[i]){
            set.insert(i);
        }
    }
    int ans = 1;
    for (int i = 0; i < k; ++ i){
        int pos = inv[b[i]];
        auto u = set.insert(pos).first;
        int cnt = 0;
        if (u != set.begin() && *std::prev(u) == pos - 1){
            ++ cnt;
        }
        if (std::next(u) != set.end() && *std::next(u) == pos + 1){
            ++ cnt;
        }
        ans = 1ll * ans * cnt % moder;
    }
    printf("%d\n", ans);
}

int main(){
    int test;
    scanf("%d", &test);
    while (test --){
        solve();
    }
    return 0;
}