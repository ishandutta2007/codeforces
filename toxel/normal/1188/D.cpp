#include <bits/stdc++.h>

const int N = 100010;
const int BIT = 60;
typedef long long ll;

int dp[BIT + 1][N];

void update(int &a, int b){
    if (a == -1 || a > b){
        a = b;
    }
}

int main(){
    int n;
    scanf("%d", &n);
    std::vector <ll> a(n);
    for (int i = 0; i < n; ++ i){
        scanf("%lld", &a[i]);
    }
    ll max = *std::max_element(a.begin(), a.end());
    for (auto &u : a){
        u = max - u;
    }
    std::vector <ll> vec[2];
    memset(dp, -1, sizeof(dp));
    dp[0][0] = 0;
    for (int i = 0; i < BIT; ++ i){
        for (auto u : a){
            vec[u >> i & 1].push_back(u);
        }
        int cnt[3] = {(int) vec[0].size(), (int) vec[1].size(), 0};
        for (int j = 0; j <= n; ++ j){
            if (dp[i][j] != -1){
                update(dp[i + 1][cnt[2]], dp[i][j] + cnt[1]);
                update(dp[i + 1][cnt[1] + cnt[2]], dp[i][j] + cnt[0] + cnt[2]);
            }
            if (j < n){
                int bit = a[j] >> i & 1;
                -- cnt[bit];
                ++ cnt[bit + 1];
            }
        }
        std::vector <ll> na;
        for (int j = 1; j >= 0; -- j){
            for (auto u : vec[j]){
                na.push_back(u);
            }
            vec[j].clear();
        }
        a = na;
    }
    printf("%d\n", dp[BIT][0]);
    return 0;
}