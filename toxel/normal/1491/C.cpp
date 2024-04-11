#include <bits/stdc++.h>

using ll = long long;
const int N = 5010;

int s[N];
int fa[N];

int find(int u){
    return fa[u] == u ? u : (fa[u] = find(fa[u]));
}

void unite(int u, int v){
    u = find(u), v = find(v);
    if (u == v) return;
    if (u > v){
        std::swap(u, v);
    }
    fa[u] = v;
}

void solve(){
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++ i){
        scanf("%d", &s[i]);
        fa[i] = i;
    }
    fa[n + 1] = n + 1;
    for (int i = 1; i <= n; ++ i){
        if (s[i] == 1){
            unite(i, i + 1);
        }
    }
    ll ans = 0;
    for (int i = 1; i <= n; ++ i){
        if (i + s[i] > n + 1){
            ans += i + s[i] - (n + 1);
            s[i] = (n + 1) - i;
            if (s[i] == 1){
                unite(i, i + 1);
            }
        }
        while (s[i] > 1){
            ++ ans;
            ll x = i;
            while (x <= n){
                int tmp = s[x];
                if (tmp == 1){
                    x = find(x);
                    continue;
                }
                -- s[x];
                if (s[x] == 1){
                    unite(x, x + 1);
                }
                x += tmp;
            }
        }
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