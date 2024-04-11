#include <bits/stdc++.h>

const int N = 500010;

std::vector<int> e[N];
int a[N], t[N];
int col[N];

int main(){
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; ++ i){
        int u, v;
        scanf("%d%d", &u, &v);
        e[u].emplace_back(v);
        e[v].emplace_back(u);
    }
    for (int i = 1; i <= n; ++ i){
        scanf("%d", &t[i]);
        a[i] = i;
    }
    std::sort(a + 1, a + n + 1, [&](const int &p1, const int &p2){return t[p1] < t[p2];});
    for (int i = 1; i <= n; ++ i){
        std::set <int> set;
        for (auto u : e[a[i]]){
            if (col[u] > 0){
                set.insert(col[u]);
            }
        }
        int mex = 0;
        for (int j = 1; ; ++ j){
            if (!set.count(j)){
                mex = j;
                break;
            }
        }
        if (mex != t[a[i]]){
            puts("-1");
            return 0;
        }
        col[a[i]] = mex;
    }
    for (int i = 1; i <= n; ++ i){
        printf("%d%c", a[i], " \n"[i == n]);
    }
    return 0;
}