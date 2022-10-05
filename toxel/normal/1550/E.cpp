#include <bits/stdc++.h>

const int N = 200010;
const int SIGMA = 26;

char s[N];
bool valid[N][SIGMA];
int pre[N][SIGMA];
int dp[N];
std::vector <int> vec[SIGMA];

int main(){
    int n, k;
    scanf("%d%d", &n, &k);
    scanf("%s", s);
    for (int i = 1; i <= n; ++ i){
        memcpy(pre[i], pre[i - 1], sizeof(pre[i]));
        if (s[i - 1] != '?'){
            ++ pre[i][s[i - 1] - 'a'];
        }
    }
    int l = 0, r = n;
    while (l < r){
        int mid = (l + r + 1) / 2;
        for (int i = 0; i < SIGMA; ++ i){
            vec[i].clear();
        }
        for (int i = 0; i <= n - mid; ++ i){
            memset(valid[i], 0, sizeof(valid[i]));
            int cnt = 0, sum = 0;
            for (int j = 0; j < k; ++ j){
                if (pre[i + mid][j] - pre[i][j] > 0){
                    ++ cnt;
                    sum += j;
                }
            }
            if (cnt == 0){
                for (int j = 0; j < k; ++ j){
                    vec[j].emplace_back(i);
                }
            }
            else if (cnt == 1){
                valid[i][sum] = true;
                vec[sum].emplace_back(i);
            }
        }
        memset(dp, 0x3f, sizeof(dp));
        dp[0] = 0;
        for (int i = 0; i < 1 << k; ++ i){
            for (int j = 0; j < k; ++ j){
                if (!(i >> j & 1)){
                    auto u = std::lower_bound(vec[j].begin(), vec[j].end(), dp[i]);
                    if (u != vec[j].end()){
                        dp[i ^ 1 << j] = std::min(dp[i ^ 1 << j], *u + mid);
                    }
                }
            }
        }
        if (dp[(1 << k) - 1] <= n){
            l = mid;
        }
        else{
            r = mid - 1;
        }
    }
    printf("%d\n", l);
    return 0;
}