#include <bits/stdc++.h>

const int N = 200010;
const int K = 60;
using ll = long long;

ll t[N], pre[N];
double dp[N][K], preprod[N], preinv[N];

double calc(int l, int r){
    return preprod[r] - preprod[l - 1] - pre[l - 1] * (preinv[r] - preinv[l - 1]);
}

void solve(int l, int r, int transl, int transr, int level){
    if (l > r){
        return;
    }
    int mid = (l + r) / 2;
    dp[mid][level] = 1e100;
    int transmid = 0;
    for (int i = transl; i <= transr && i < mid; ++ i){
        double value = dp[i][level - 1] + calc(i + 1, mid);
        if (value < dp[mid][level]){
            dp[mid][level] = value;
            transmid = i;
        }
    }
    solve(l, mid - 1, transl, transmid, level);
    solve(mid + 1, r, transmid, transr, level);
}

int main(){
    int n, k;
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; ++ i){
        scanf("%d", &t[i]);
        pre[i] = pre[i - 1] + t[i];
    }
    for (int i = 1; i <= n; ++ i){
        dp[i][1] = dp[i - 1][1] + 1.0 * pre[i] / t[i];
        preprod[i] = dp[i][1];
    }
    for (int i = 1; i <= n; ++ i){
        preinv[i] = preinv[i - 1] + 1.0 / t[i];
    }
    for (int i = 2; i <= k; ++ i){
        solve(1, n, 1, n, i);
    }
    printf("%.15f\n", dp[n][k]);
    return 0;
}