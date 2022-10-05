#include <bits/stdc++.h>

const int N = 1010;

int x[N], y[N];
bool vis[N];

void solve(){
    int n, k;
    scanf("%d%d", &n, &k);
    memset(vis, 0, sizeof(vis));
    for (int i = 0; i < k; ++ i){
        scanf("%d%d", &x[i], &y[i]);
        vis[x[i]] = vis[y[i]] = true;
    }
    std::vector <int> vec;
    for (int i = 1; i <= 2 * n; ++ i){
        if (!vis[i]){
            vec.emplace_back(i);
        }
    }
    int sz = vec.size();
    int cur = k;
    for (int i = 0; i < sz / 2; ++ i){
        x[cur] = vec[i], y[cur] = vec[i + sz / 2];
        ++ cur;
    }
    int ans = 0;
    for (int i = 0; i < n; ++ i){
        if (x[i] > y[i]){
            std::swap(x[i], y[i]);
        }
    }
    for (int i = 0; i < n; ++ i){
        for (int j = i + 1; j < n; ++ j){
            if (y[i] < x[j] || y[j] < x[i]){
                continue;
            }
            if (x[i] < x[j] && y[j] < y[i]){
                continue;
            }
            if (x[j] < x[i] && y[i] < y[j]){
                continue;
            }
            ++ ans;
        }
    }
    printf("%d\n", ans);
}

int main(){
    int test;
    scanf("%d", &test);
    while (test --){
        solve();
    }
    return 0;
}