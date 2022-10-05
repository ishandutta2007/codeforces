#include <bits/stdc++.h>

const int N = 200010;

std::vector <int> e[N];
int color[N], dep[N];
bool vis[N];
int n, k;
int max = 0;

void dfs(int u, int fa){
    max = std::max(max, dep[u]);
    for (auto v : e[u]){
        if (vis[v] || v == fa){
            continue;
        }
        dep[v] = dep[u] + 1;
        dfs(v, u);
    }
}

std::vector <int> stack;
std::vector <int> diameter;

void find_diameter(int u, int fa, int t){
    stack.push_back(u);
    if (u == t){
        diameter = stack;
    }
    for (auto v : e[u]){
        if (v == fa){
            continue;
        }
        find_diameter(v, u, t);
    }
    stack.pop_back();
}

void solve(int u, int fa, int add){
    for (auto v : e[u]){
        if (vis[v] || v == fa){
            continue;
        }
        color[v] = (color[u] + add + k) % k;
        solve(v, u, add);
    }
}

int main(){
    scanf("%d%d", &n, &k);
    for (int i = 0, u, v; i < n - 1; ++ i){
        scanf("%d%d", &u, &v);
        e[u].push_back(v);
        e[v].push_back(u);
    }
    if (k == 2){
        solve(1, 0, 1);
        puts("Yes");
        for (int i = 1; i <= n; ++ i){
            printf("%d%c", color[i] + 1, " \n"[i == n]);
        }
        return 0;
    }
    dfs(1, 0);
    int s = std::max_element(dep + 1, dep + n + 1) - dep;
    dep[s] = 0;
    dfs(s, 0);
    int t = std::max_element(dep + 1, dep + n + 1) - dep;
    find_diameter(s, 0, t);
    int sz = diameter.size();
    for (int i = 0; i < sz; ++ i){
        color[diameter[i]] = i % k;
        vis[diameter[i]] = true;
    }
    for (int i = 0; i < sz; ++ i){
        dep[diameter[i]] = 0;
        max = 0;
        dfs(diameter[i], 0);
        if (max == 0){
            continue;
        }
        if (max + i + 1 < k){
            solve(diameter[i], 0, -1);
        }
        else if (max + sz - i < k){
            solve(diameter[i], 0, 1);
        }
        else{
            puts("No");
            return 0;
        }
    }
    puts("Yes");
    for (int i = 1; i <= n; ++ i){
        printf("%d%c", color[i] + 1, " \n"[i == n]);
    }
    return 0;
}