#include<bits/stdc++.h>

const int N = 500010;
const int MAX = 1 << 19;
const int BIT = 20;
typedef std::pair <int, int> pii;
typedef std::pair <pii, int> piii;
typedef long long ll;

struct edge{
    int v, w;
    ll pre, suf;
};

std::vector <edge> _e[N], e[N];
int end[N], fa[N][BIT];
ll dep[N], mindep[N];
int dep1[N];
ll seg[3][MAX << 1];
ll ans[N];
std::vector <piii> inter[N];
int dfn[N], dfncnt;

void getdfn(int u, int fa, int w){
    if (fa){
        e[fa].push_back({u, w, 0, 0});
    }
    dfn[u] = ++ dfncnt;
    for (auto p : _e[u]){
        getdfn(p.v, u, p.w);
    }
}

void dfs(int u, int fa){
    ::fa[u][0] = fa;
    for (int i = 1; i < BIT; ++ i){
        ::fa[u][i] = ::fa[::fa[u][i - 1]][i - 1];
    }
    end[u] = u;
    mindep[u] = e[u].empty() ? dep[u] : LLONG_MAX;
    for (auto p : e[u]){
        int v = p.v;
        dep[v] = dep[u] + p.w;
        dep1[v] = dep1[u] + 1;
        dfs(v, u);
        end[u] = std::max(end[v], end[u]);
        mindep[u] = std::min(mindep[u], mindep[v]);
    }
    int sz = e[u].size();
    for (int i = 0; i < sz; ++ i){
        auto &ed = e[u][i];
        ed.pre = i ? std::min(mindep[ed.v], e[u][i - 1].pre) : mindep[ed.v];
    }
    for (int i = sz - 1; i >= 0; -- i){
        auto &ed = e[u][i];
        ed.suf = i < sz - 1 ? std::min(mindep[ed.v], e[u][i + 1].suf) : mindep[ed.v];
    }
}

int lca(int u, int v){
    if (dep1[u] < dep1[v]){
        std::swap(u, v);
    }
    for (int i = 0; i < BIT; ++ i){
        if ((dep1[u] - dep1[v]) >> i & 1){
            u = fa[u][i];
        }
    }
    if (u == v) return u;
    for (int i = BIT - 1; i >= 0; -- i){
        if (fa[u][i] != fa[v][i]){
            u = fa[u][i], v = fa[v][i];
        }
    }
    return fa[u][0];
}

void add(ll *seg, int sit, ll value){
    seg[sit += MAX] = value;
    for (sit >>= 1; sit; sit >>= 1){
        seg[sit] = std::min(seg[sit << 1], seg[sit << 1 | 1]);
    }
}

ll query(ll *seg, int l, int r){
    if (l > r) return LLONG_MAX;
    ll ret = LLONG_MAX;
    for (l += MAX, r += MAX + 1; l < r; l >>= 1, r >>= 1){
        if (l & 1) ret = std::min(ret, seg[l ++]);
        if (r & 1) ret = std::min(ret, seg[-- r]);
    }
    return ret;
}

void solve(int u){
    for (auto q : inter[u]){
        int l = q.first.first, r = q.first.second;
        int lcal = lca(l, u), lcar = lca(r, u);
        ll ans = LLONG_MAX;
        auto getans = [&](int v){
            int l1 = std::max(v, l), r1 = std::min(end[v], r);
            ll ret = query(seg[0], l1, r1);
            return ret;
        };
        ll x = getans(u);
        if (x != LLONG_MAX){
            ans = std::min(ans, x - dep[u]);
        }
        x = getans(lcal);
        if (x != LLONG_MAX){
            ans = std::min(ans, x + dep[u] - 2 * dep[lcal]);
        }
        x = getans(lcar);
        if (x != LLONG_MAX){
            ans = std::min(ans, x + dep[u] - 2 * dep[lcar]);
        }
        int depl = dep1[lcal], depr = dep1[lcar], depu = dep1[u];
        if (l > end[u]){
            x = query(seg[2], depr + 1, depl - 1);
            if (x != LLONG_MAX){
                ans = std::min(ans, x + dep[u]);
            }
        }
        else if (r < u){
            x = query(seg[1], depl + 1, depr - 1);
            if (x != LLONG_MAX){
                ans = std::min(ans, x + dep[u]);
            }
        }
        else{
            if (l < u){
                x = query(seg[1], depl + 1, depu - 1);
                if (x != LLONG_MAX){
                    ans = std::min(ans, x + dep[u]);
                }
            }
            if (r > end[u]){
                x = query(seg[2], depr + 1, depu - 1);
                if (x != LLONG_MAX){
                    ans = std::min(ans, x + dep[u]);
                }
            }
        }
        ::ans[q.second] = ans;
    }
    int sz = e[u].size();
    for (int i = 0; i < sz; ++ i){
        add(seg[1], dep1[u], i == 0 ? LLONG_MAX : e[u][i - 1].pre - 2 * dep[u]);
        add(seg[2], dep1[u], i == sz - 1 ? LLONG_MAX : e[u][i + 1].suf - 2 * dep[u]);
        solve(e[u][i].v);
    }
}

int main(){
    int n, q;
    scanf("%d%d", &n, &q);
    for (int i = 2; i <= n; ++ i){
        int p, w;
        scanf("%d%d", &p, &w);
        _e[p].push_back({i, w, 0, 0});
    }
    getdfn(1, 0, 0);
    dfs(1, 0);
    for (int i = 1; i <= n; ++ i){
        add(seg[0], i, e[i].empty() ? dep[i] : LLONG_MAX);
    }
    for (int i = 0; i < q; ++ i){
        int v, l, r;
        scanf("%d%d%d", &v, &l, &r);
        inter[v].push_back({{l, r}, i});
    }
    solve(1);
    for (int i = 0; i < q; ++ i){
        printf("%lld\n", ans[i]);
    }
    return 0;
}