#include<bits/stdc++.h>

const int N = 100010;

int a[N], b[N];
int fa[N];
std::vector <int> vec[N];

int find(int u){
    return u == fa[u] ? u : (fa[u] = find(fa[u]));
}

void unite(int u, int v){
    u = find(u), v = find(v);
    fa[u] = v;
}

int main(){
    int n;
    scanf("%d", &n);
    std::map <int, int> map;
    for (int i = 0; i < n; ++ i){
        scanf("%d", &a[i]);
        b[i] = a[i];
        map[a[i]] = i;
    }
    std::sort(b, b + n);
    std::vector <std::vector <int>> ans;
    for (int i = 0; i < n; ++ i){
        fa[i] = i;
    }
    for (int i = n - 1; i >= 0; -- i){
        if (map[b[i]] == i){
            continue;
        }
        int sit = map[b[i]];
        unite(sit, i);
        std::swap(a[sit], a[i]);
        map[a[i]] = i;
        map[a[sit]] = sit;
    }
    for (int i = 0; i < n; ++ i){
        vec[find(i)].push_back(i);
    }
    for (int i = 0; i < N; ++ i){
        if (!vec[i].empty()){
            ans.push_back(vec[i]);
        }
    }
    printf("%d\n", (int) ans.size());
    for (auto u : ans){
        printf("%d", (int) u.size());
        for (auto v : u){
            printf(" %d", v + 1);
        }
        puts("");
    }
    return 0;
}