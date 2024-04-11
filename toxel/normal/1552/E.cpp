#include <bits/stdc++.h>

const int N = 10010;

bool vis[N];
int a[N];
std::vector <int> vec[N];

void solve(){
    int n, k;
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n * k; ++ i){
        scanf("%d", &a[i]);
    }
    int most = (n + k - 1 - 1) / (k - 1);
    std::vector <int> wait;
    for (int i = 1; i <= n * k; ++ i){
        if (vis[a[i]]){
            continue;
        }
        if (int(vec[a[i]].size()) < 2){
            vec[a[i]].emplace_back(i);
            if (int(vec[a[i]].size()) == 2){
                wait.emplace_back(a[i]);
            }
        }
        if (int(wait.size()) == most){
            for (auto u : wait){
                vis[u] = true;
            }
            wait.clear();
            for (int j = 1; j <= n; ++ j){
                if (!vis[j]){
                    vec[j].clear();
                }
            }
        }
    }
    for (auto u : wait){
        assert(int(vec[u].size()) == 2);
    }
    for (int i = 1; i <= n; ++ i){
        printf("%d %d\n", vec[i][0], vec[i][1]);
    }
}

int main(){
    /*for (int n = 1; n <= 100; ++ n){
        for (int k = 2; k <= 100; ++ k){
            int most = (n + k - 1 - 1) / (k - 1);
            int need = (n + most - 1) / most;
            ++ need;
            assert(need <= k);
            printf("%d\n", need - k);
        }
    }*/
    int test;
    test = 1;
    while (test --){
        solve();
    }
    return 0;
}