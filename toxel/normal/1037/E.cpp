#include<bits/stdc++.h>

const int N = 200010;

std::set <int> e[N];
int deg[N];
int u[N], v[N];
int ans[N];
int n, m, k;

int main(){
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 0; i < m; ++ i){
        scanf("%d%d", &u[i], &v[i]);
        ++ deg[u[i]], ++ deg[v[i]];
        e[u[i]].insert(v[i]);
        e[v[i]].insert(u[i]);
    }
    int cnt = 0;
    std::queue <int> queue;
    for (int i = 1; i <= n; ++ i){
        if (deg[i] < k){
            queue.push(i);
        }
    }
    while (!queue.empty()){
        int u = queue.front();
        ++ cnt;
        queue.pop();
        for (auto v : e[u]){
            -- deg[v];
            if (deg[v] == k - 1){
                queue.push(v);
            }
        }
    }
    ans[m - 1] = n - cnt;
    for (int i = m - 1; i >= 1; -- i){
        int tmp1 = deg[v[i]], tmp2 = deg[u[i]];
        if (tmp1 >= k){
            -- deg[u[i]];
            if (deg[u[i]] == k - 1){
                queue.push(u[i]);
            }
        }
        if (tmp2 >= k){
            -- deg[v[i]];
            if (deg[v[i]] == k - 1){
                queue.push(v[i]);
            }
        }
        e[u[i]].erase(v[i]);
        e[v[i]].erase(u[i]);
        while (!queue.empty()){
            int u = queue.front();
            ++ cnt;
            queue.pop();
            for (auto v : e[u]){
                -- deg[v];
                if (deg[v] == k - 1){
                    queue.push(v);
                }
            }
        }
        ans[i - 1] = n - cnt;
    }
    for (int i = 0; i < m; ++ i){
        printf("%d\n", ans[i]);
    }
    return 0;
}