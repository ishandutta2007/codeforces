#include<bits/stdc++.h>

const int N = 200010;

std::vector <int> e[N];
int a[N], inv[N], ans[N];
bool vis[N];

int main(){
    int n;
    scanf("%d", &n);
    for (int i = 0, u, v; i < n - 1; ++ i){
        scanf("%d%d", &u, &v);
        e[u].push_back(v);
        e[v].push_back(u);
    }
    for (int i = 1; i <= n; ++ i){
        scanf("%d", &a[i]);
        inv[a[i]] = i;
    }
    for (int i = 1; i <= n; ++ i){
        std::sort(e[i].begin(), e[i].end(), [&](int u, int v){return inv[u] < inv[v];});
    }
    std::queue <int> queue;
    queue.push(1);
    vis[1] = true;
    ans[1] = 1;
    int now = 2;
    while (!queue.empty()){
        int u = queue.front();
        queue.pop();
        for (auto v : e[u]){
            if (!vis[v]){
                ans[now ++] = v;
                vis[v] = true;
                queue.push(v);
            }
        }
    }
    for (int i = 1; i <= n; ++ i){
        if (a[i] != ans[i]){
            puts("No");
            return 0;
        }
    }
    puts("Yes");
    return 0;
}