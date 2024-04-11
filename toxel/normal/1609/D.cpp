#include <bits/stdc++.h>

const int N = 1010;

int fa[N];
int sz[N];

int find(int u){
    return fa[u] == u ? u : (fa[u] = find(fa[u]));
}

void unite(int u, int v){
    u = find(u), v = find(v);
    sz[v] += sz[u];
    fa[u] = v;
}

int main(){
    int n, d;
    scanf("%d%d", &n, &d);
    for (int i = 1; i <= n; ++ i){
        fa[i] = i;
        sz[i] = 1;
    }
    int left = 0;
    for (int i = 0; i < d; ++ i){
        int x, y;
        scanf("%d%d", &x, &y);
        if (find(x) == find(y)){
            ++ left;
        }
        else{
            unite(x, y);
        }
        std::vector <int> vec;
        for (int j = 1; j <= n; ++ j){
            if (find(j) == j){
                vec.emplace_back(sz[j]);
            }
        }
        std::sort(vec.begin(), vec.end(), std::greater <int>());
        int sum = 0;
        for (int j = 0; j < left + 1; ++ j){
            sum += vec[j];
        }
        printf("%d\n", sum - 1);
    }
    return 0;
}