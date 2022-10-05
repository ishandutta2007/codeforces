#include <bits/stdc++.h>

const int N = 300010;

std::vector<int> e[N];
int type[N];

void solve(){
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 0; i <= n; ++ i){
        e[i].clear();
        type[i] = 0;
    }
    for (int i = 0; i < m; ++ i){
        int u, v;
        scanf("%d%d", &u, &v);
        e[u].emplace_back(v);
        e[v].emplace_back(u);
    }
    std::queue<int> queue;
    queue.push(1);
    while (!queue.empty()){
        int u = queue.front();
        queue.pop();
        if (type[u] == 2){
            continue;
        }
        type[u] = 1;
        for (auto v : e[u]){
            if (type[v]){
                continue;
            }
            type[v] = 2;
            for (auto w : e[v]){
                if (type[w]){
                    continue;
                }
                queue.push(w);
            }
        }
    }
    for (int i = 1; i <= n; ++ i){
        if (!type[i]){
            puts("NO");
            return;
        }
    }
    puts("YES");
    std::vector<int> ans;
    for (int i = 1; i <= n; ++ i){
        if (type[i] == 1){
            ans.emplace_back(i);
        }
    }
    int sz = ans.size();
    printf("%d\n", sz);
    for (int i = 0; i < sz; ++ i){
        printf("%d%c", ans[i], " \n"[i == sz - 1]);
    }
}

int main(){
    int test;
    scanf("%d", &test);
    while (test --){
        solve();
    }
}