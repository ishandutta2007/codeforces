#include<bits/stdc++.h>

const int N = 300010;
const int M = 26;

std::vector <int> e[N];
int c[N];
char s[N];
int sz[N];
int son[N][M];

int unite(int u, int v){
    int ret = 1;
    for (int i = 0; i < M; ++ i){
        if (son[v][i]){
            if (son[u][i]){
                ret += unite(son[u][i], son[v][i]);
            }
            else{
                son[u][i] = son[v][i];
            }
        }
    }
    return ret;
}

void dfs(int u, int fa){
    std::vector <int> vec;
    sz[u] = 1;
    for (auto v : e[u]){
        if (v == fa) continue;
        vec.push_back(v);
        dfs(v, u);
        sz[u] += sz[v];
    }
    std::sort(vec.begin(), vec.end(), [&](int p1, int p2){
        return sz[p1] > sz[p2];
    });
    for (int i = 0, sz = vec.size(); i < sz; ++ i){
        if (son[u][s[vec[i]]]){
            ::sz[u] -= unite(son[u][s[vec[i]]], vec[i]);
        }
        else{
            son[u][s[vec[i]]] = vec[i];
        }
    }
}

int main(){
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++ i){
        scanf("%d", &c[i]);
    }
    scanf("%s", s + 1);
    for (int i = 0, u, v; i < n - 1; ++ i){
        scanf("%d%d", &u, &v);
        e[u].push_back(v);
        e[v].push_back(u);
    }
    for (int i = 1; i <= n; ++ i){
        s[i] -= 'a';
    }
    dfs(1, 0);
    int max = 0;
    for (int i = 1; i <= n; ++ i){
        sz[i] += c[i];
        max = std::max(max, sz[i]);
    }
    int cnt = 0;
    for (int i = 1; i <= n; ++ i){
        if (max == sz[i]){
            ++ cnt;
        }
    }
    printf("%d\n%d\n", max, cnt);
    return 0;
}