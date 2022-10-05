#include<bits/stdc++.h>

typedef std::pair <int, int> pii;
typedef long long ll;
const int N = 300010;
const ll INF = 0x8080808080808080ll;

std::vector <pii> e[N];
int w[N];
ll max[N], smax[N];

void dfs(int u, int fa){
    max[u] = w[u];
    for (auto p : e[u]){
        int v = p.first;
        if (v == fa) continue;
        dfs(v, u);
        ll x = max[v] + w[u] - p.second;
        if (x >= max[u]){
            smax[u] = max[u];
            max[u] = x;
        }
        else if (x > smax[u]){
            smax[u] = x;
        }
    }
}


int main(){
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++ i){
        scanf("%d", &w[i]);
    }
    for (int i = 0, u, v, w; i < n - 1; ++ i){
        scanf("%d%d%d", &u, &v, &w);
        e[u].push_back({v, w});
        e[v].push_back({u, w});
    }
    memset(max, 0x80, sizeof(max));
    memset(smax, 0x80, sizeof(smax));
    dfs(1, 0);
    ll ans = 0;
    for (int i = 1; i <= n; ++ i){
        ans = std::max(ans, max[i]);
        if (smax[i] != INF){
            ans = std::max(ans, max[i] + smax[i] - w[i]);
        }
    }
    printf("%lld\n", ans);
    return 0;
}