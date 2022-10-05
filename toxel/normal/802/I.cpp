#include <bits/stdc++.h>

const int N = 1000010;
using ll = long long;

char s[N];
int sa[N], id[N], rk[N], oldrk[N << 1], tmp[N], cnt[N], height[N];

void get_sa(char *s, int *sa){
    int n = strlen(s + 1), m = 300;
    for (int i = 1; i <= n; ++ i) ++ cnt[rk[i] = s[i]];
    for (int i = 1; i <= m; ++ i) cnt[i] += cnt[i - 1];
    for (int i = n; i >= 1; -- i) sa[cnt[s[i]] --] = i;
    if (n == 1) rk[1] = 1;
    auto equal = [&](int x, int y, int w){return oldrk[x] == oldrk[y] && oldrk[x + w] == oldrk[y + w];};
    for (int w = 1, p; w < n; w <<= 1, m = p){
        p = 0;
        for (int i = n; i > n - w; -- i) id[++ p] = i;
        for (int i = 1; i <= n; ++ i){
            if (sa[i] > w) id[++ p] = sa[i] - w;
        }
        memset(cnt, 0, sizeof(cnt));
        for (int i = 1; i <= n; ++ i) ++ cnt[tmp[i] = rk[id[i]]];
        for (int i = 1; i <= m; ++ i) cnt[i] += cnt[i - 1];
        for (int i = n; i >= 1; -- i) sa[cnt[tmp[i]] --] = id[i];
        memcpy(oldrk, rk, sizeof(rk));
        p = 0;
        for (int i = 1; i <= n; ++ i){
            rk[sa[i]] = equal(sa[i - 1], sa[i], w) ? p : ++ p;
        }
    }
    for (int i = 1, p = 0; i <= n; ++ i){
        if (p) -- p;
        while (s[i + p] == s[sa[rk[i] - 1] + p]) ++ p;
        height[rk[i]] = p;
    }
}

void init(){
    memset(cnt, 0, sizeof(cnt));
    memset(rk, 0, sizeof(rk));
}

int fa[N], sz[N], begin[N];
ll ccnt[N];
std::vector<int> vec[N];

int find(int u){
    return fa[u] == u ? u : (fa[u] = find(fa[u]));
}

void unite(int u, int v, int pos){
    u = find(u), v = find(v);
    if (u == v){
        return;
    }
    ccnt[sz[u]] += begin[u] - pos;
    ccnt[sz[v]] += begin[v] - pos;
    sz[v] += sz[u];
    begin[v] = pos;
    fa[u] = v;
}

void solve(){
    init();
    scanf("%s", s + 1);
    int n = strlen(s + 1);
    get_sa(s, sa);
    for (int i = 0; i <= n; ++ i){
        fa[i] = i;
        begin[i] = i == 0 ? 0 : n - sa[i] + 1;
        vec[i].clear();
        sz[i] = 1;
        ccnt[i] = 0;
    }
    for (int i = 1; i <= n; ++ i){
        vec[height[i]].emplace_back(i);
    }
    for (int i = n - 1; i >= 0; -- i){
        for (auto u : vec[i]){
            unite(u - 1, u, i);
        }
    }
    ll ans = 0;
    for (int i = 1; i <= n; ++ i){
        ans += ccnt[i] * i * i;
    }
    printf("%lld\n", ans);
}

int main(){
    int test;
    scanf("%d", &test);
    while (test --){
        solve();
    }
}