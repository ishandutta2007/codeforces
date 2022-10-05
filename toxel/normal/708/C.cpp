#include<bits/stdc++.h>

const int N = 400010;

int n;
std::vector <int> e[N];
int sz[N], max[N], maxsit[N];
bool ans[N];
int down[N];

void getsz(int u, int fa){
    sz[u] = 1;
    for (auto v : e[u]){
        if (v == fa) continue;
        getsz(v, u);
        sz[u] += sz[v];
        if (max[u] < sz[v]){
            max[u] = sz[v];
            maxsit[u] = v;
        }
    }
    if (max[u] < n - sz[u]){
        max[u] = n - sz[u];
        maxsit[u] = fa;
    }
}

void getdown(int u, int fa){
    if (sz[u] <= n / 2){
        down[u] = std::max(down[u], sz[u]);
    }
    for (auto v : e[u]){
        if (v == fa) continue;
        getdown(v, u);
        down[u] = std::max(down[u], down[v]);
    }
}

void dfs(int u, int fa, int up){
    if (max[u] <= n / 2){
        ans[u] = true;
    }
    else{
        if (maxsit[u] == fa){
            if (max[u] - up <= n / 2){
                ans[u] = true;
            }
        }
        else{
            if (max[u] - down[maxsit[u]] <= n / 2){
                ans[u] = true;
            }
        }
    }
    int msit = 0, smsit = 0;
    for (auto v : e[u]){
        if (v == fa) continue;
        if (down[msit] <= down[v]){
            smsit = msit;
            msit = v;
        }
        else if (down[smsit] < down[v]){
            smsit = v;
        }
    }
    for (auto v : e[u]){
        if (v == fa) continue;
        int nup = up;
        if (n - sz[v] <= n / 2){
            nup = std::max(up, n - sz[v]);
        }
        if (v == msit){
            nup = std::max(nup, down[smsit]);
        }
        else{
            nup = std::max(nup, down[msit]);
        }
        dfs(v, u, nup);
    }
}

int main(){
    scanf("%d", &n);
    for (int i = 0, u, v; i < n - 1; ++ i){
        scanf("%d%d", &u, &v);
        e[u].push_back(v);
        e[v].push_back(u);
    }
    getsz(1, 0);
    getdown(1, 0);
    dfs(1, 0, 0);
    for (int i = 1; i <= n; ++ i){
        printf("%d%c", ans[i] ? 1 : 0, " \n"[i == n]);
    }
    return 0;
}