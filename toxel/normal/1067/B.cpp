#include<bits/stdc++.h>

const int N = 100010;
typedef std::pair <int, int> pii;

std::vector <int> e[N];
bool vis[N];
int fa[N];
std::vector <pii> dep;

void error(){
    puts("No");
    exit(0);
}

void dfs(int u, int f, int d) {
    fa[u] = f;
    dep.push_back({d, u});
    for (auto v : e[u]) {
        if (v == fa[u] || vis[v]) continue;
        dfs(v, u, d + 1);
    }
}

int get_ctr(int u) {
    dep.clear();
    dfs(u, 0, 0);
    int ctr = std::max_element(dep.begin(), dep.end()) -> second;
    dep.clear();
    dfs(ctr, 0, 0);
    auto p = std::max_element(dep.begin(), dep.end());
    int d = p -> first;
    ctr = p -> second;
    for (int i = 0; i < d / 2; ++ i) ctr = fa[ctr];
    if (d & 1){
        error();
    }
    return ctr;
}

void check(int u, int k){
    if (!k){
        for (auto v : e[u]){
            if (!vis[v]){
                error();
            }
        }
        return;
    }
    int ctr = get_ctr(u);
    int cnt = 0;
    vis[ctr] = true;
    for (auto v : e[ctr]){
        if (!vis[v]){
            check(v, k - 1);
            ++ cnt;
        }
    }
    if (cnt < 3){
        error();
    }
}

int main(){
    int n, k;
    scanf("%d%d", &n, &k);
    for (int i = 0, u, v; i < n - 1; ++ i){
        scanf("%d%d", &u, &v);
        e[u].push_back(v);
        e[v].push_back(u);
    }
    check(1, k);
    puts("Yes");
    return 0;
}