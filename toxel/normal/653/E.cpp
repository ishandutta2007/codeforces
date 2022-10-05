#include<bits/stdc++.h>

const int N = 300010;

std::vector <int> e[N];

bool find(std::vector <int> &vec, int x){
    auto u = std::lower_bound(vec.begin(), vec.end(), x);
    return u != vec.end() && *u == x;
}

bool vis[N];

int main(){
    int n, m, k;
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 0, u, v; i < m; ++ i){
        scanf("%d%d", &u, &v);
        e[u].push_back(v);
        e[v].push_back(u);
    }
    for (int i = 0; i < N; ++ i){
        std::sort(e[i].begin(), e[i].end());
    }
    vis[1] = true;
    std::queue <int> queue;
    std::set <int> remain;
    for (int i = 2; i <= n; ++ i){
        remain.insert(i);
    }
    queue.push(1);
    while (!queue.empty()){
        int u = queue.front();
        queue.pop();
        std::vector <int> remove;
        for (auto v : remain){
            if (!find(e[u], v)){
                queue.push(v);
                remove.push_back(v);
            }
        }
        for (auto v : remove){
            remain.erase(v);
        }
    }
    if (!remain.empty()){
        puts("impossible");
        return 0;
    }
    for (int i = 2; i <= n; ++ i){
        remain.insert(i);
    }
    int cnt = 0;
    for (int i = 2; i <= n; ++ i){
        if (!find(e[1], i) && remain.count(i)){
            remain.erase(i);
            ++ cnt;
            std::queue <int> queue;
            queue.push(i);
            while (!queue.empty()){
                int u = queue.front();
                queue.pop();
                std::vector <int> remove;
                for (auto v : remain){
                    if (!find(e[u], v)){
                        queue.push(v);
                        remove.push_back(v);
                    }
                }
                for (auto v : remove){
                    remain.erase(v);
                }
            }
        }
    }
    puts(cnt <= k && k <= n - e[1].size() - 1 ? "possible" : "impossible");
    return 0;
}