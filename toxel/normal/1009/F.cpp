#include<bits/stdc++.h>

const int N = 1000010;
typedef std::pair <int, int> pii;

int dir[N], first[N];
std::vector <int> queue[N];
int max[N];
std::vector <int> e[N];

pii mp(int x, int y){
    return {x, y};
}

void dfs(int u, int fa){
    int maxson = 0;
    for (auto v : e[u]){
        if (v == fa) continue;
        dfs(v, u);
        if (queue[dir[v]].size() > queue[dir[maxson]].size()){
            maxson = v;
        }
    }
    if (!maxson){
        dir[u] = u;
        queue[u].push_back(1);
        return;
    }
    dir[u] = dir[maxson];
    max[u] = max[maxson];
    for (auto v : e[u]){
        if (v == fa || v == maxson) continue;
        int sz = queue[dir[v]].size();
        int szu = queue[dir[u]].size();
        for (int i = 0; i < sz; ++ i){
            queue[dir[u]][szu - i - 1] += queue[dir[v]][sz - i - 1];
            if (mp(queue[dir[u]][szu - i - 1], -i) > mp(queue[dir[u]][szu - max[u] - 1], -max[u])){
                max[u] = i;
            }
        }
    }
    ++ max[u];
    queue[dir[u]].push_back(1);
    int szu = queue[dir[u]].size();
    if (mp(queue[dir[u]][szu - 0 - 1], 0) > mp(queue[dir[u]][szu - max[u] - 1], -max[u])){
        max[u] = 0;
    }
}

void addedge(int u, int v){
    e[u].push_back(v);
    e[v].push_back(u);
}

int main(){
    int n;
    scanf("%d", &n);
    for (int i = 1, u, v; i < n; ++ i){
        scanf("%d%d", &u, &v);
        addedge(u, v);
    }
    dfs(1, 0);
    for (int i = 1; i <= n; ++ i){
        printf("%d\n", max[i]);
    }
    return 0;
}