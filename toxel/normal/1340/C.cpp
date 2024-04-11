#include <bits/stdc++.h>

const int N = 10010;
const int M = 1010;
using pii = std::pair <int, int>;
using ll = long long;

int d[N];
bool vis[N][M];
int min[N];

int main(){
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; ++ i){
        scanf("%d", &d[i]);
    }
    std::sort(d, d + m);
    int g, r;
    scanf("%d%d", &g, &r);
    std::vector <int> zero = {0};
    int cnt = 0;
    while (!zero.empty()){
        std::queue <pii> to_vis;
        ll ans = LLONG_MAX;
        for (auto u : zero){
            to_vis.emplace(u, 0);
            if (d[m - 1] - d[u] <= g){
                ans = std::min(ans, 1ll * (g + r) * cnt + d[m - 1] - d[u]);
            }
        }
        zero.clear();
        if (ans < LLONG_MAX){
            printf("%lld\n", ans);
            return 0;
        }
        while (!to_vis.empty()){
            pii p = to_vis.front();
            to_vis.pop();
            int u = p.first, mod = p.second;
            if (u > 0){
                int nmod = mod + d[u] - d[u - 1];
                if (nmod <= g && !vis[u - 1][nmod]){
                    vis[u - 1][nmod] = true;
                    to_vis.emplace(u - 1, nmod);
                    if (nmod == g){
                        zero.emplace_back(u - 1);
                    }
                }
            }
            if (u < n - 1){
                int nmod = mod + d[u + 1] - d[u];
                if (nmod <= g && !vis[u + 1][nmod]){
                    vis[u + 1][nmod] = true;
                    to_vis.emplace(u + 1, nmod);
                    if (nmod == g){
                        zero.emplace_back(u + 1);
                    }
                }
            }
        }
        ++ cnt;
    }
    puts("-1");
    return 0;
}