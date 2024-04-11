#include <bits/stdc++.h>

const int N = 300010;
const int BIT = 20;

int a[N];
std::vector <int> vec[BIT];
int dp[N][BIT];

int main(){
    int n, q;
    scanf("%d%d", &n, &q);
    for (int i = 0; i < n; ++ i){
        scanf("%d", &a[i]);
        for (int j = 0; j < BIT; ++ j){
            if (a[i] >> j & 1){
                vec[j].push_back(i);
                dp[i][j] = i;
            }
            else{
                dp[i][j] = INT_MAX;
            }
        }
    }
    for (int i = n - 1; i >= 0; -- i){
        for (int j = 0; j < BIT; ++ j){
            if (a[i] >> j & 1){
                int sit = std::lower_bound(vec[j].begin(), vec[j].end(), i) - vec[j].begin();
                if (sit != vec[j].size() - 1){
                    for (int k = 0; k < BIT; ++ k){
                        dp[i][k] = std::min(dp[vec[j][sit + 1]][k], dp[i][k]);
                    }
                }
            }
        }
    }
    while (q --){
        int l, r;
        scanf("%d%d", &l, &r);
        -- l, -- r;
        bool flag = false;
        for (int j = 0; j < BIT; ++ j){
            if (a[r] >> j & 1){
                if (dp[l][j] <= r){
                    flag = true;
                    puts("Shi");
                    break;
                }
            }
        }
        if (!flag){
            puts("Fou");
        }
    }
    return 0;
}