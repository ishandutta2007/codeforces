#include <bits/stdc++.h>

const int MAXN = 1010;

namespace HK {
    int match[MAXN], d[MAXN], dis;
    bool vis[MAXN];
    std::vector<int> vec[MAXN], left;
    bool bfs() {
        std::queue<int> q; dis = INT_MAX;
        memset(d, -1, sizeof(d));
        for (auto u : left)
            if (match[u] == -1) {d[u] = 0; q.push(u);}
        while (!q.empty()) {
            int u = q.front(); q.pop();
            if (d[u] > dis) break;
            for (auto v : vec[u]) {
                if (d[v] != -1) continue;
                d[v] = d[u] + 1;
                if (match[v] == -1) dis = d[v];
                else {
                    d[match[v]] = d[v] + 1; q.push(match[v]);
                }}}
        return dis != INT_MAX;
    }
    bool dfs(int u) {
        for (auto v : vec[u])
            if (!vis[v] && d[v] == d[u] + 1) {
                vis[v] = true;
                if (match[v] != -1 && d[v] == dis) continue;
                if (match[v] == -1 || dfs(match[v])) {
                    match[v] = u; match[u] = v;
                    return true;
                }
            }
        return false;
    }
    int hk() {
        memset(match, -1, sizeof(match));
        int ret = 0;
        while (bfs()) {
            memset(vis, 0, sizeof(vis));
            for (auto u : left)
                if (match[u] == -1 && dfs(u)) ++ret;
        }
        return ret;
    }

    void init(){
        memset(match, 0, sizeof(match));
        memset(d, 0, sizeof(d));
        dis = 0;
        memset(vis, 0, sizeof(vis));
        for (int i = 0; i < MAXN; ++ i){
            vec[i].clear();
        }
        left.clear();
    }
}

int a[MAXN], b[MAXN];

void solve(){
    int n;
    scanf("%d", &n);
    HK::init();
    for (int i = 1; i <= n; ++ i){
        scanf("%d", &a[i]);
    }
    for (int i = 1; i <= n; ++ i){
        scanf("%d", &b[i]);
    }
    for (int i = 1; i <= n; ++ i){
        for (int j = 1; j <= n; ++ j){
            if (a[i] + 1 == b[j] || a[i] == b[j]){
                HK::vec[i].emplace_back(j + n);
                HK::vec[j + n].emplace_back(i);
            }
        }
        HK::left.emplace_back(i);
    }
    int ret = HK::hk();
    // printf("%d\n", ret);
    puts(ret == n ? "Yes" : "No");
}

int main(){
    int test;
    scanf("%d", &test);
    while (test --){
        solve();
    }
    return 0;
}