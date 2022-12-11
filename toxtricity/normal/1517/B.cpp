#include <bits/stdc++.h>

const int N = 110;
using pii = std::pair <int, int>;

int b[N][N];
pii p[N * N];
int ans[N][N];
std::set <int> set[N];

void solve(){
    int n, m;
    scanf("%d%d", &n, &m);
    int cnt = 0;
    for (int i = 1; i <= n; ++ i){
        for (int j = 1; j <= m; ++ j){
            scanf("%d", &b[i][j]);
            p[cnt ++] = {i, j};
        }
    }
    std::sort(p, p + cnt, [&](const pii &p1, const pii &p2){
        return b[p1.first][p1.second] < b[p2.first][p2.second];
    });
    for (int i = 0; i <= std::max(n, m); ++ i){
        for (int j = 0; j <= std::max(n, m); ++ j){
            ans[i][j] = 0;
        }
        set[i].clear();
        for (int j = 1; j <= m; ++ j){
            set[i].insert(j);
        }
    }
    for (int i = 0; i < m; ++ i){
        ans[i][p[i].first] = p[i].second;
        set[p[i].first].erase(p[i].second);
    }
    for (int i = 0; i < m; ++ i){
        for (int j = 1; j <= n; ++ j){
            if (ans[i][j]){
                continue;
            }
            ans[i][j] = *(set[j].begin());
            set[j].erase(set[j].begin());
        }
    }
    for (int i = 1; i <= n; ++ i){
        for (int j = 0; j < m; ++ j){
            printf("%d%c", b[i][ans[j][i]], " \n"[j == m - 1]);
        }
    }
}

int main(){
    int test;
    scanf("%d", &test);
    while (test --){
        solve();
    }
    return 0;
}