#include <bits/stdc++.h>

const int N = 300010;
const int TRY = 100;

int p[N], p1[N];
bool vis[N];

void solve(){
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++ i){
        scanf("%d", &p[i]);
    }
    std::mt19937_64 rnd(std::chrono::steady_clock::now().time_since_epoch().count());
    std::set <int> ans;
    for (int i = 0; i < TRY; ++ i){
        int remain = rnd() % n + 1;
        int shift = p[remain] - remain;
        shift += shift < 0 ? n : 0;
        for (int j = 1; j <= n; ++ j){
            int base = j + shift;
            base -= base > n ? n : 0;
            p1[base] = p[j];
        }
        memset(vis, 0, sizeof(vis[0]) * (n + 1));
        int sum = 0;
        for (int j = 1; j <= n; ++ j){
            if (vis[j]){
                continue;
            }
            int cnt = 0, x = j;
            while (!vis[x]){
                ++ cnt;
                vis[x] = true;
                x = p1[x];
            }
            sum += cnt - 1;
        }
        if (sum <= m){
            ans.emplace((n - shift) % n);
        }
    }
    int sz = ans.size();
    printf("%d", sz);
    for (auto u : ans){
        printf(" %d", u);
    }
    puts("");
}

int main(){
    int test;
    scanf("%d", &test);
    while (test --){
        solve();
    }
    return 0;
}