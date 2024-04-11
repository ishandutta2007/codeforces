#include <bits/stdc++.h>

const int N = 100010;
using pii = std::pair <int, int>;

std::vector <int> e[N];
std::vector <pii> ans;

void dfs(int u, int fa, int max, int in){
    std::vector<int> todo;
    for (auto v : e[u]){
        if (v == fa){
            continue;
        }
        todo.emplace_back(v);
    }
    int cur = in;
    for (auto v : todo){
        if (cur == max){
            cur = in - 1 - (todo.size() - (max - in));
            ans.emplace_back(u, cur);
        }
        ans.emplace_back(v, cur + 1);
        dfs(v, u, max, cur + 1);
        ++ cur;
        ans.emplace_back(u, cur);
    }
    if (fa != 0 && cur != in - 1){
        ans.emplace_back(u, in - 1);
    }
}

int main(){
    int n;
    scanf("%d", &n);
    for (int i = 0, u, v; i < n - 1; ++ i){
        scanf("%d%d", &u, &v);
        e[u].emplace_back(v);
        e[v].emplace_back(u);
    }
    int max = 0;
    for (int i = 1; i <= n; ++ i){
        max = std::max(max, int(e[i].size()));
    }
    ans.emplace_back(1, 0);
    dfs(1, 0, max, 0);
    printf("%d\n", int(ans.size()));
    for (auto u : ans){
        printf("%d %d\n", u.first, u.second);
    }
    return 0;
}

/*
10
1 2
1 3
1 4
2 5
2 6
5 7
5 8
5 9
5 10
 */