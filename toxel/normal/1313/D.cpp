#include <bits/stdc++.h>

const int N = 200010;
const int M = 8;

std::vector <int> vec[N];
int c[N], dp[N][1 << M];
int l[N], r[N], bitcnt[N];

int main(){
    for (int i = 1; i < N; ++ i){
        bitcnt[i] = bitcnt[i ^ (i & -i)] + 1;
    }
    int n, m, k;
    scanf("%d%d%d", &n, &m, &k);
    int cnt = 0;
    for (int i = 0; i < n; ++ i){
        scanf("%d%d", &l[i], &r[i]);
        c[cnt ++] = l[i];
        c[cnt ++] = r[i] + 1;
    }
    std::sort(c, c + cnt);
    cnt = std::unique(c, c + cnt) - c;
    for (int i = 0; i < n; ++ i){
        l[i] = std::lower_bound(c, c + cnt, l[i]) - c;
        r[i] = std::lower_bound(c, c + cnt, r[i] + 1) - c;
        for (int j = l[i]; j < r[i]; ++ j){
            vec[j + 1].emplace_back(i);
        }
    }
    memset(dp, -1, sizeof(dp));
    dp[0][0] = 0;
    for (int i = 1; i < cnt; ++ i){
        int value = c[i] - c[i - 1];
        std::vector <int> maxvec(1 << vec[i].size(), -1);
        std::vector <int> map(vec[i - 1].size(), -1);
        int sz = vec[i].size();
        int sz1 = vec[i - 1].size();
        for (int j = 0; j < sz1; ++ j){
            for (int k = 0; k < sz; ++ k){
                if (vec[i - 1][j] == vec[i][k]){
                    map[j] = k;
                    break;
                }
            }
        }
        for (int j = 0; j < 1 << sz1; ++ j){
            int bit = 0;
            for (int k = 0; k < sz1; ++ k){
                if (j >> k & 1 && map[k] != -1){
                    bit |= 1 << map[k];
                }
            }
            maxvec[bit] = std::max(maxvec[bit], dp[i - 1][j]);
        }
        int mask = 0;
        for (int k = 0; k < sz1; ++ k){
            if (map[k] != -1){
                mask |= 1 << map[k];
            }
        }
        for (int j = 0; j < 1 << vec[i].size(); ++ j){
            int pre = maxvec[j & mask];
            if (pre != -1){
                dp[i][j] = std::max(dp[i][j], pre + (bitcnt[j] & 1 ? value : 0));
            }
        }
    }
    int max = 0;
    for (int i = 0; i < 1 << M; ++ i){
        max = std::max(max, dp[cnt - 1][i]);
    }
    printf("%d\n", max);
    return 0;
}