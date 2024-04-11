#include <bits/stdc++.h>

const int moder = 998244353;
const int N = 100010;
using pii = std::pair <int, int>;

void add(int &u, int v){
    u += v;
    u -= u >= moder ? moder : 0;
}

int a[N];
int vis[N];

void solve(){
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++ i){
        scanf("%d", &a[i]);
    }
    std::vector <pii> possible;
    int ans = 0;
    for (int i = n; i >= 1; -- i){
        for (auto [u, v] : possible){
            int need = (a[i] + u - 1) / u;
            ans = (ans + 1ll * (need - 1) * v % moder * i) % moder;
            add(vis[a[i] / need], v);
        }
        add(vis[a[i]], 1);
        possible.clear();
        for (int j = 1, k; j <= a[i]; j = k + 1){
            int x = a[i] / j;
            k = a[i] / x;
            if (vis[x] > 0){
                possible.emplace_back(x, vis[x]);
                vis[x] = 0;
            }
        }
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