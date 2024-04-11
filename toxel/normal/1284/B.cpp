#include <bits/stdc++.h>

const int N = 1000010;

std::vector <int> vec[N];
bool vis[N];
int cnt[N];

int main(){
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++ i){
        int l;
        scanf("%d", &l);
        for (int j = 0, x; j < l; ++ j){
            scanf("%d", &x);
            vec[i].push_back(x);
        }
        for (int j = 0; j < l - 1; ++ j){
            if (vec[i][j] < vec[i][j + 1]){
                vis[i] = true;
            }
        }
    }
    for (int i = 0; i < n; ++ i){
        if (!vis[i]){
            ++ cnt[vec[i][0]];
        }
    }
    for (int i = N - 2; i >= 0; -- i){
        cnt[i] += cnt[i + 1];
    }
    long long ans = 0;
    int aans = 0;
    for (int i = 0; i < n; ++ i){
        if (!vis[i]){
            ans += cnt[vec[i].back() + 1];
            ++ aans;
        }
    }
    ans += 1ll * n * n - 1ll * aans * aans;
    printf("%lld\n", ans);
    return 0;
}