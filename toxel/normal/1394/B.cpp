#include <bits/stdc++.h>

using pii = std::pair <int, int>;
const int N = 500010;
const int M = 20;
const int moder = 998244353;

std::vector<pii> e[N];
bool vis[N];
unsigned fac[M];
int value[M][M];

int powermod(int a, int exp){
    int ret = 1;
    for ( ; exp > 0; exp >>= 1){
        if (exp & 1) ret = 1ll * ret * a % moder;
        a = 1ll * a * a % moder;
    }
    return ret;
}

void add(int &u, int v){u += v; u -= u >= moder ? moder : 0;}

void dfs(int cur, int k, int sum, int hash){
    if (cur == k){
        if (sum){
            vis[hash] = false;
        }
        return;
    }
    for (int i = 0; i <= cur; ++ i){
        int nsum = sum;
        add(nsum, value[cur + 1][i]);
        dfs(cur + 1, k, nsum, hash + i * fac[cur]);
    }
}

void check(int n, int k, int expo){
    memset(value, 0, sizeof(value));
    for (int i = 1; i <= n; ++ i){
        int sz = e[i].size();
        for (int j = 0; j < sz; ++ j){
            add(value[sz][j], powermod(e[i][j].second, expo));
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; ++ i){
        add(ans, powermod(i, expo));
    }
    dfs(0, k, (moder - ans) % moder, 0);
}

int main(){
    fac[0] = 1;
    for (int i = 1; i < M; ++ i){
        fac[i] = fac[i - 1] * i;
    }
    int n, m, k;
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 0, u, v, w; i < m; ++ i){
        scanf("%d%d%d", &u, &v, &w);
        e[u].emplace_back(w, v);
    }
    for (int i = 1; i <= n; ++ i){
        std::sort(e[i].begin(), e[i].end());
    }
    for (int i = 0; i < fac[k]; ++ i){
        vis[i] = true;
    }
    std::mt19937 rnd(std::chrono::steady_clock::now().time_since_epoch().count());
    for (int i = 0; i < 5; ++ i){
        int expo = rnd() % moder;
        check(n, k, expo);
    }
    int ans = 0;
    for (int i = 0; i < fac[k]; ++ i){
        ans += vis[i];
    }
    printf("%d\n", ans);
    return 0;
}