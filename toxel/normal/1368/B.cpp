#include <bits/stdc++.h>

using ll = long long;
const int N = 400;
const ll INF = ll(1.1e16);

ll dp[N][N], pre[N][N];

void solve(){
    ll k;
    scanf("%lld", &k);
    const char s[] = "codeforces";
    int n = strlen(s);
    dp[0][0] = 1;
    for (int i = 0; i < n; ++ i){
        for (int j = 0; j < N; ++ j){
            if (dp[i][j] == 0){
                continue;
            }
            for (int k = 1; j + k < N; ++ k){
                ll x = dp[i][j] * k;
                x = std::min(x, INF);
                if (dp[i + 1][j + k] < x){
                    dp[i + 1][j + k] = x;
                    pre[i + 1][j + k] = k;
                }
            }
        }
    }
    for (int i = 0; i < N; ++ i){
        if (dp[n][i] >= k){
            std::vector<int> vec;
            for (int j = n, cur = i; j >= 1; -- j){
                vec.emplace_back(pre[j][cur]);
                cur -= pre[j][cur];
            }
            std::reverse(vec.begin(), vec.end());
            for (int i = 0; i < n; ++ i){
                for (int j = 0; j < vec[i]; ++ j){
                    putchar(s[i]);
                }
            }
            puts("");
            break;
        }
    }
}

int main(){
    solve();
    return 0;
}