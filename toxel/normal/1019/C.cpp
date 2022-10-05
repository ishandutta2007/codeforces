#include<bits/stdc++.h>

const int N = 1000010;

std::vector <int> e[N];
bool vis[N];

int main(){
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 0, u, v; i < m; ++ i){
        scanf("%d%d", &u, &v);
        e[u].push_back(v);
    }
    std::stack <int> stack;
    for (int i = 1; i <= n; ++ i){
        if (!vis[i]){
            vis[i] = true;
            stack.push(i);
            for (auto v : e[i]){
                vis[v] = true;
            }
        }
    }
    memset(vis, 0, sizeof(vis));
    std::vector <int> ans;
    while (!stack.empty()){
        int u = stack.top();
        stack.pop();
        if (!vis[u]){
            ans.push_back(u);
            for (auto v : e[u]){
                vis[v] = true;
            }
        }
    }
    int sz = ans.size();
    printf("%d\n", sz);
    for (int i = 0; i < sz; ++ i){
        printf("%d%c", ans[i], " \n"[i == sz - 1]);
    }
    return 0;
}