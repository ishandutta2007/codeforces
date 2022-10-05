#include <bits/stdc++.h>

using ll = long long;
const int N = 300010;
const int M = 5;

ll dp[N][M];
int p[N];
ll low[N][M], high[N][M];
ll pre_low[N][M], pre_high[N][M];

void solve(){
    int n, c, q;
    scanf("%d%d%d", &n, &c, &q);
    for (int i = 0; i <= n; ++ i){
        memset(dp[i], 0, sizeof(dp[i]));
        memset(low[i], 0, sizeof(low[i]));
        memset(high[i], 0, sizeof(high[i]));
    }
    for (int i = 1; i <= n; ++ i){
        scanf("%d", &p[i]);
    }
    for (int i = 0; i <= c; ++ i){
        dp[0][i] = 1;
    }
    for (int i = 1; i <= n; ++ i){
        for (int j = 0; j <= c; ++ j){
            for (int k = 0; k <= j && k + 1 <= i; ++ k){
                ll value = dp[i - k - 1][j - k];
                dp[i][j] += value;
                if (p[n + 1 - (i - k)] < p[n + 1 - i]){
                    low[i][j] += value;
                }
                else if (p[n + 1 - (i - k)] > p[n + 1 - i]){
                    high[i][j] += value;
                }
            }
        }
    }
    for (int i = 0; i <= c; ++ i){
        for (int j = 1; j <= n; ++ j){
            pre_low[j][i] = pre_low[j - 1][i] + low[j][i];
            pre_high[j][i] = pre_high[j - 1][i] + high[j][i];
        }
    }
    while (q --){
        int pos;
        ll num;
        scanf("%d%lld", &pos, &num);
        if (num > dp[n][c]){
            puts("-1");
            continue;
        }
        int len = n, cur = c;
        while (len >= n + 1 - pos){
            int l = 0, r = len;
            while (l < r){
                int mid = (l + r + 1) / 2;
                ll low_num = pre_low[len][cur] - pre_low[len - mid][cur];
                ll high_num = pre_high[len][cur] - pre_high[len - mid][cur];
                if (num <= low_num || num >= dp[len][cur] - high_num + 1){
                    r = mid - 1;
                }
                else{
                    l = mid;
                }
            }
            int left = n + 1 - len, right = left + l - 1;
            if (left <= pos && pos <= right){
                printf("%d\n", p[pos]);
                break;
            }
            num -= pre_low[len][cur] - pre_low[len - l][cur];
            len -= l;
            if (len == 0){
                break;
            }
            using piii = std::tuple <ll, ll, ll>;
            piii pp[M] = {};
            int cnt = 0;
            for (int i = 0; i <= cur && i + 1 <= len; ++ i){
                ll value = dp[len - i - 1][cur - i];
                pp[cnt ++] = {p[n + 1 - (len - i)], i, value};
            }
            std::sort(pp, pp + cnt);
            for (int i = 0; i < cnt; ++ i){
                auto [u, v, w] = pp[i];
                if (num <= w){
                    left = n + 1 - len, right = left + v;
                    if (left <= pos && pos <= right){
                        printf("%d\n", p[right - (pos - left)]);
                    }
                    len -= v + 1;
                    cur -= v;
                    break;
                }
                else{
                    num -= w;
                }
            }
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