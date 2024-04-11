#include<bits/stdc++.h>

const int N = 100010;
typedef std::pair <int, int> pii;
typedef long long ll;

std::vector <pii> e[N];
int n, moder;
int power[N], invpower[N], sz[N];
ll ans = 0;
bool vis[N];
std::map <int, int> map[N];

int inv(int a, int moder){
    int b = moder, s = 1, t = 0;
    while (b){
        int tmp = a, q = a / b;
        a = b, b = tmp % a;
        tmp = s;
        s = t;
        t = tmp - s * q;
    }
    if (a > 1) return -1;
    return s < 0 ? s + moder : s;
}

void getsz(int u, int fa){
    sz[u] = 1;
    for (auto p : e[u]){
        int v = p.first;
        if (vis[v] || v == fa) continue;
        getsz(v, u);
        sz[u] += sz[v];
    }
}

void getroot(int u, int fa, int &root, int rsz, int &min){
    int max = rsz - sz[u];
    for (auto p : e[u]){
        int v = p.first;
        if (vis[v] || v == fa) continue;
        getroot(v, u, root, rsz, min);
        max = std::max(max, sz[v]);
    }
    if (max < min){
        min = max;
        root = u;
    }
}

void dfs(int u, int fa, int value, int dep, auto &map){
    ++ map[value];
    for (auto p : e[u]){
        int v = p.first;
        if (vis[v] || v == fa) continue;
        dfs(v, u, (value + 1ll * power[dep] * p.second) % moder, dep + 1, map);
    }
}

void dfs1(int u, int fa, int value, int dep, auto &totmap, int sit){
    int x = 1ll * (moder - value) * invpower[dep] % moder;
    ans += totmap[x] - map[sit][x];
    for (auto p : e[u]){
        int v = p.first;
        if (vis[v] || v == fa) continue;
        dfs1(v, u, (10ll * value + p.second) % moder, dep + 1, totmap, fa == -1 ? v : sit);
    }
}

void solve(){
    std::queue <int> queue;
    queue.push(0);
    while (!queue.empty()){
        int u = queue.front();
        queue.pop();
        getsz(u, -1);
        int root, min = INT_MAX;
        getroot(u, -1, root, sz[u], min);
        vis[root] = true;
        std::map <int, int> totmap;
        for (auto p : e[root]){
            int v = p.first;
            if (vis[v]) continue;
            map[v].clear();
            dfs(v, root, p.second % moder, 1, map[v]);
            if (!vis[v]){
                queue.push(v);
            }
            for (auto u : map[v]){
                totmap[u.first] += u.second;
            }
        }
        map[root].clear();
        map[root][0] = 1;
        ++ totmap[0];
        dfs1(root, -1, 0, 0, totmap, root);
    }
}

int main(){
    scanf("%d%d", &n, &moder);
    for (int i = 0; i < n - 1; ++ i){
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
        e[u].push_back({v, w});
        e[v].push_back({u, w});
    }
    power[0] = invpower[0] = 1;
    for (int i = 1; i < N; ++ i){
        power[i] = 10ll * power[i - 1] % moder;
    }
    invpower[1] = inv(10, moder);
    for (int i = 2; i < N; ++ i){
        invpower[i] = 1ll * invpower[i - 1] * invpower[1] % moder;
    }
    solve();
    printf("%lld\n", ans);
    return 0;
}