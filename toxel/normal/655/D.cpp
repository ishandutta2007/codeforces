#include<bits/stdc++.h>

const int N = 100010;

std::vector <int> e[N];
int u[N], v[N], deg[N];
int n, m;

bool check(int mid){
    for (int i = 0; i < N; ++ i){
        deg[i] = 0;
        e[i].clear();
    }
    for (int i = 0; i < mid; ++ i){
        e[u[i]].push_back(v[i]);
        ++ deg[v[i]];
    }
    std::queue <int> queue;
    for (int i = 1; i <= n; ++ i){
        if (!deg[i]){
            queue.push(i);
        }
    }
    while (!queue.empty()){
        if ((int) queue.size() >= 2){
            return false;
        }
        int u = queue.front();
        queue.pop();
        for (auto v : e[u]){
            -- deg[v];
            if (!deg[v]){
                queue.push(v);
            }
        }
    }
    return true;
}

int main(){
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; ++ i){
        scanf("%d%d", &u[i], &v[i]);
    }
    int left = 1, right = m;
    while (left < right){
        int mid = (left + right) >> 1;
        if (check(mid)){
            right = mid;
        }
        else{
            left = mid + 1;
        }
    }
    if (check(left)){
        printf("%d\n", left);
    }
    else{
        puts("-1");
    }
    return 0;
}