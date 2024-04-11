#include <bits/stdc++.h>

const int N = 1010;

int a[N];
bool vis[N];

void solve(){
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++ i){
        scanf("%d", &a[i]);
    }
    std::vector<int> ans;
    while (true){
        bool flag = true;
        for (int i = 0; i < n - 1; ++ i){
            if (a[i] > a[i + 1]){
                flag = false;
                break;
            }
        }
        if (flag){
            break;
        }
        memset(vis, 0, sizeof(vis[0]) * (n + 1));
        for (int j = 0; j < n; ++ j){
            vis[a[j]] = true;
        }
        int x = -1;
        for (int j = 0; j <= n; ++ j){
            if (!vis[j]){
                x = j;
                break;
            }
        }
        int pos = x;
        if (pos == n){
            for (int i = 0; i < n; ++ i){
                if (a[i] != i){
                    pos = i;
                    break;
                }
            }
        }
        a[pos] = x;
        ans.emplace_back(pos);
    }
    int sz = ans.size();
    printf("%d\n", sz);
    for (int i = 0; i < sz; ++ i){
        printf("%d%c", ans[i] + 1, " \n"[i == sz - 1]);
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