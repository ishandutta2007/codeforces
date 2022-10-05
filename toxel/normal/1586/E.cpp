#include <bits/stdc++.h>

const int N = 500010;

std::vector <int> e[N];
int u[N], v[N];
int a[N], b[N];
int cnt[N];
int fa[N];

int find(int u){
    return fa[u] == u ? u : (fa[u] = find(fa[u]));
}

void unite(int u, int v){
    u = find(u), v = find(v);
    fa[u] = v;
}

std::vector <int> stack, output;

void dfs(int u, int fa, int target){
    stack.emplace_back(u);
    if (u == target){
        output = stack;
    }
    for (auto v : e[u]){
        if (v == fa){
            continue;
        }
        dfs(v, u, target);
    }
    stack.pop_back();
}

int main(){
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; ++ i){
        scanf("%d%d", &u[i], &v[i]);
    }
    int q;
    scanf("%d", &q);
    for (int i = 0; i < q; ++ i){
        scanf("%d%d", &a[i], &b[i]);
        ++ cnt[a[i]];
        ++ cnt[b[i]];
    }
    int sum = 0;
    for (int i = 1; i <= n; ++ i){
        if (cnt[i] % 2 == 1){
            ++ sum;
        }
    }
    if (sum != 0){
        puts("NO");
        printf("%d\n", sum / 2);
        return 0;
    }
    puts("YES");
    for (int i = 1; i <= n; ++ i){
        fa[i] = i;
    }
    for (int i = 0; i < m; ++ i){
        if (find(u[i]) == find(v[i])){
            continue;
        }
        unite(u[i], v[i]);
        e[u[i]].emplace_back(v[i]);
        e[v[i]].emplace_back(u[i]);
    }
    for (int i = 0; i < q; ++ i){
        stack.clear();
        output.clear();
        dfs(a[i], 0, b[i]);
        int sz = output.size();
        printf("%d\n", sz);
        for (int j = 0; j < sz; ++ j){
            printf("%d%c", output[j], " \n"[j == sz - 1]);
        }
    }
    return 0;
}