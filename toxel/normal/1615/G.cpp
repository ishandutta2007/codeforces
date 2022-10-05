//
// Created by  on 2022/1/6.
//

#include <bits/stdc++.h>
#define mp std::make_pair
#define scanf dont_use_scanf
#define printf dont_use_printf
#define puts dont_use_puts
#define endl dont_use_endl

using ll = int64_t;
using i128 = __int128_t;
using pii = std::pair <int, int>;
using piii = std::tuple <int, int, int>;

//
// Created by  on 2022/1/23.
//

#include <bits/stdc++.h>

class DisjointSet{
public:
    std::vector <int> fa, sz, extra_edge;

    explicit DisjointSet(int n){
        n += 10;
        fa.resize(n);
        sz.resize(n);
        extra_edge.resize(n);
        for (int i = 0; i < n; ++ i){
            fa[i] = i;
            sz[i] = 1;
        }
    }

    int find(int u){
        return fa[u] == u ? u : (fa[u] = find(fa[u]));
    }

    void unite(int u, int v){
        u = find(u), v = find(v);
        if (u == v){
            extra_edge[u] = true;
            return;
        }
        fa[u] = v;
        sz[v] += sz[u];
        extra_edge[v] |= extra_edge[u];
    }
};

#include <bits/stdc++.h>

namespace GM{
    const int N = 1010;

    std::vector <int> e[N];
    int color[N], queue[N];
    int nxt[N], pre[N], fa[N], vis[N];
    int head, tail, viscnt;

    int find(int u){
        return u == fa[u] ? u : (fa[u] = find(fa[u]));
    }

    void addedge(int u, int v){
        e[u].emplace_back(v);
        e[v].emplace_back(u);
    }

    int lca(int u, int v){
        ++ viscnt;
        u = find(u), v = find(v);
        while (true){
            if (u){
                if (vis[u] == viscnt) return u;
                vis[u] = viscnt;
                u = find(pre[nxt[u]]);
            }
            std::swap(u, v);
        }
    }

    void blossom(int u, int v, int l){
        while (find(u) != l){
            pre[u] = v;
            if (color[nxt[u]] == 1){
                color[nxt[u]] = 0;
                queue[tail ++] = nxt[u];
            }
            fa[u] = fa[nxt[u]] = l;
            v = nxt[u], u = pre[v];
        }
    }

    void match(int start){
        memset(pre, 0, sizeof(pre));
        memset(color, -1, sizeof(color));
        head = 0, tail = 0;
        queue[tail ++] = start;
        color[start] = 0;
        for ( ; head < tail; ++ head){
            int u = queue[head];
            for (auto v : e[u]){
                if (color[v] == -1){
                    color[v] = 1, pre[v] = u;
                    if (nxt[v] == 0){ // found augment path
                        int x = u, y = v;
                        while (x){
                            int tmp = nxt[x];
                            nxt[x] = y, nxt[y] = x;
                            x = pre[tmp], y = tmp;
                        }
                        assert(!x && !y);
                        return;
                    }
                    queue[tail ++] = nxt[v];
                    color[nxt[v]] = 0;
                }
                else if (color[v] == 0 && find(u) != find(v)){
                    int l = lca(u, v);
                    blossom(u, v, l), blossom(v, u, l);
                }
            }
        }
    }

    int solve(int n){
        memset(vis, 0, sizeof(vis));
        memset(nxt, 0, sizeof(nxt));
        viscnt = 0;
        for (int i = 1; i <= n; ++ i){
            if (nxt[i]){
                continue;
            }
            for (int j = 1; j <= n; ++ j){
                fa[j] = j;
            }
            match(i);
        }
        int ans = 0;
        for (int i = 1; i <= n; ++ i){
            ans += nxt[i] != 0;
        }
        return ans / 2;
    }
}

const int N = 300010;

int a[N];
std::vector <piii> e[N];
bool vis1[N];

void dfs(int u, int fa, std::vector <int> &unvis){
    vis1[u] = true;
    for (auto [v, l, r]: e[u]){
        if (v == fa){
            continue;
        }
        if (a[l - 1] == v){
            a[l] = a[l - 1];
            ++ l;
        }
        else{
            a[r] = a[r + 1];
            -- r;
        }
        while (l < r){
            a[l] = a[l + 1] = unvis.back();
            l += 2;
            unvis.pop_back();
        }
        dfs(v, u, unvis);
    }
}

void solve(){
    int n;
    std::cin >> n;
    std::vector <int> visit(n + 1);
    for (int i = 0; i < n; ++ i){
        std::cin >> a[i];
        visit[a[i]] = 1;
    }
    std::vector <int> unvis;
    for (int i = 1; i <= n; ++ i){
        if (!visit[i]){
            unvis.emplace_back(i);
        }
    }
    int pre = -1;
    std::vector <pii> zeros;
    for (int i = 0; i <= n; ++ i){
        if (i == n || a[i] != 0){
            if (i - pre > 1){
                zeros.emplace_back(pre + 1, i - 1);
            }
            pre = i;
        }
    }
    if (zeros.size() == 1 && zeros[0] == mp(0, n - 1)){
        for (int i = 0; i < n; ++ i){
            std::cout << i / 2 + 1 << " \n"[i == n - 1];
        }
        return;
    }
    std::vector <bool> vis(n + 1);
    for (int i = 0; i < n - 1; ++ i){
        if (a[i] == a[i + 1] && a[i] != 0){
            vis[a[i]] = true;
        }
    }
    int ans = 0;
    std::vector <pii> e1, e2, e1_pos, e2_pos;
    for (auto [l, r]: zeros){
        int l_el = -1, r_el = -1;
        if (l > 0){
            l_el = a[l - 1];
        }
        if (r < n - 1){
            r_el = a[r + 1];
        }
        if (l_el == -1){
            std::swap(l_el, r_el);
        }
        if (l_el == r_el){
            r_el = -1;
        }
        int length = r - l + 1;
        if (r_el == -1){
            ans += length / 2;
            if (length % 2 == 1){
                vis[l_el] = true;
                if (l >= 0 && a[l - 1] == l_el){
                    a[l] = l_el;
                    ++ l;
                }
                else{
                    a[r] = l_el;
                    -- r;
                }
            }
            while (l < r){
                a[l] = a[l + 1] = unvis.back();
                l += 2;
                unvis.pop_back();
            }
        }
        else{
            if (length % 2 == 1){
                e1.emplace_back(l_el, r_el);
                e1_pos.emplace_back(l, r);
            }
            else{
                e2.emplace_back(l_el, r_el);
                e2_pos.emplace_back(l, r);
            }
        }
    }
    DisjointSet disjointSet(n);
    int sz = e1.size();
    for (int i = 0; i < sz; ++ i){
        auto [u, v] = e1[i];
        auto [l, r] = e1_pos[i];
        if (disjointSet.find(u) == disjointSet.find(v)){
            vis[a[l - 1]] = true;
            a[l] = a[l - 1];
            ++ l;
            while (l < r){
                a[l] = a[l + 1] = unvis.back();
                l += 2;
                unvis.pop_back();
            }
        }
        else{
            e[u].emplace_back(v, l, r);
            e[v].emplace_back(u, l, r);
        }
        disjointSet.unite(u, v);
    }
    for (int i = 1; i <= n; ++ i){
        if (vis[i]){
            disjointSet.extra_edge[disjointSet.find(i)] = 1;
        }
    }
    for (int i = 1; i <= n; ++ i){
        if (disjointSet.find(i) == i){
            ans += disjointSet.sz[i] - (disjointSet.extra_edge[i] ? 0 : 1);
        }
    }
    std::vector <pii> e3;
    std::vector <int> c;
    for (auto [u, v]: e2){
        u = disjointSet.find(u);
        v = disjointSet.find(v);
        if (disjointSet.extra_edge[u] == 1 || disjointSet.extra_edge[v] == 1){
            continue;
        }
        e3.emplace_back(u, v);
        c.emplace_back(u);
        c.emplace_back(v);
    }
    std::sort(c.begin(), c.end());
    c.erase(std::unique(c.begin(), c.end()), c.end());
    int nn = c.size();
    for (int i = 0; i <= nn; ++ i){
        GM::e[i].clear();
    }
    for (auto [u, v]: e3){
        u = std::lower_bound(c.begin(), c.end(), u) - c.begin() + 1;
        v = std::lower_bound(c.begin(), c.end(), v) - c.begin() + 1;
        GM::addedge(u, v);
    }
    ans += GM::solve(nn);
    sz = e2.size();
    for (int i = 0; i < sz; ++ i){
        auto [l, r] = e2_pos[i];
        auto [u, v] = e2[i];
        u = disjointSet.find(u);
        v = disjointSet.find(v);
        u = std::lower_bound(c.begin(), c.end(), u) - c.begin() + 1;
        v = std::lower_bound(c.begin(), c.end(), v) - c.begin() + 1;
        if (GM::nxt[u] == v){
            int l_el = a[l - 1], r_el = a[r + 1];
            vis[l_el] = vis[r_el] = true;
            a[l] = a[l - 1], a[r] = a[r + 1];
            ++ l, -- r;
            while (l < r){
                a[l] = a[l + 1] = unvis.back();
                l += 2;
                unvis.pop_back();
            }
            GM::nxt[u] = GM::nxt[v] = 0;
        }
        else{
            while (l < r){
                a[l] = a[l + 1] = unvis.back();
                l += 2;
                unvis.pop_back();
            }
        }
    }
    for (int i = 1; i <= n; ++ i){
        if (vis[i] && !vis1[i]){
            dfs(i, 0, unvis);
        }
    }
    for (int i = 1; i <= n; ++ i){
        if (!vis1[i]){
            dfs(i, 0, unvis);
        }
    }
    // std::cout << ans << '\n';
    for (int i = 0; i < n; ++ i){
        std::cout << a[i] << " \n"[i == n - 1];
    }
}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    int test = 1;
    while (test --){
        solve();
    }
    return 0;
}