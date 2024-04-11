#include <bits/stdc++.h>

const int N = 1010;
using pii = std::pair <int, int>;

std::vector <int> e[N], vec[N];
int dep[N], fa[N];

pii ask(const std::vector <int> &vec){
    int n = vec.size();
    if (n == 0){
        return {INT_MAX, INT_MAX};
    }
    printf("? %d", n);
    for (auto u : vec){
        printf(" %d", u);
    }
    puts("");
    fflush(stdout);
    int a, b;
    scanf("%d%d", &a, &b);
    if (a == -1){
        exit(0);
    }
    return {a, b};
}

void dfs(int u, int fa){
    ::fa[u] = fa;
    for (auto v : e[u]){
        if (v == fa){
            continue;
        }
        dep[v] = dep[u] + 1;
        dfs(v, u);
    }
}

void solve(){
    for (int i = 0; i < N; ++ i){
        e[i].clear();
        vec[i].clear();
    }
    int n;
    scanf("%d", &n);
    for (int i = 0, u, v; i < n - 1; ++ i){
        scanf("%d%d", &u, &v);
        e[u].emplace_back(v);
        e[v].emplace_back(u);
    }
    std::vector<int> to_ask;
    for (int i = 1; i <= n; ++ i){
        to_ask.emplace_back(i);
    }
    pii p = ask(to_ask);
    int root = p.first, len = p.second;
    dep[root] = 0;
    dfs(root, 0);
    for (int i = 1; i <= n; ++ i){
        vec[dep[i]].emplace_back(i);
    }
    int left = (len + 1) / 2, right = len;
    while (left < right){
        int mid = (left + right + 1) / 2;
        pii p1 = ask(vec[mid]);
        if (p1.second > len){
            right = mid - 1;
        }
        else{
            left = mid;
            p = p1;
        }
    }
    if (left == (len + 1) / 2){
        p = ask(vec[left]);
    }
    int x = p.first;
    to_ask.clear();
    int known = x;
    for (int i = 0; i < dep[x] - (len - dep[x]); ++ i){
        known = fa[known];
    }
    for (auto u : vec[len - dep[x]]){
        if (u == root || u != known){
            to_ask.emplace_back(u);
        }
    }
    p = ask(to_ask);
    int y = p.first;
    printf("! %d %d\n", x, y);
    fflush(stdout);
    char s[100];
    scanf("%s", s);
    if (strcmp(s, "Correct")){
        exit(0);
    }
}

int main(){
    int test;
    scanf("%d", &test);
    while (test --){
        solve();
    }
    return 0;
}