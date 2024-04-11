#include<bits/stdc++.h>

typedef long long ll;
const int N = 500100;
typedef std::pair <int, int> pii;
const int moder = 1e9 + 7;

ll c[N];
int power[N];
int fa[N];
int vis[N];

int find(int u){
    return fa[u] == u ? u : (fa[u] = find(fa[u]));
}

void unite(int u, int v){
    u = find(u), v = find(v);
    if (u == v) return;
    fa[u] = v;
}

int main(){
    power[0] = 1;
    for (int i = 1; i < N; ++ i){
        power[i] = 2 * power[i - 1] % moder;
    }
    int n, m, k;
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 1; i <= n; ++ i){
        scanf("%lld", &c[i]);
    }
    std::map <ll, std::vector <pii>> Hash;
    for (int i = 0, u, v; i < m; ++ i){
        scanf("%d%d", &u, &v);
        Hash[c[u] ^ c[v]].push_back({u, v});
    }
    for (int i = 1; i <= n; ++ i){
        fa[i] = i;
    }
    int cnt = 0, ans = 0;
    for (auto &u : Hash){
        ++ cnt;
        std::vector <int> vec;
        for (auto v : u.second){
            vec.push_back(v.first);
            vec.push_back(v.second);
            unite(v.first, v.second);
        }
        int ccnt = 0, cccnt = 0;
        for (auto u : vec){
            if (vis[u] == cnt) continue;
            ++ cccnt;
            vis[u] = cnt;
            if (fa[u] != u) continue;
            ++ ccnt;
        }
        ans = (ans + 1ll * power[n - cccnt] * (power[cccnt] - power[ccnt])) % moder;
        ans += ans < 0 ? moder : 0;
        for (auto u : vec){
            fa[u] = u;
        }
    }
    ans = power[n + k] - ans;
    ans += ans < 0 ? moder : 0;
    printf("%d\n", ans);
    return 0;
}