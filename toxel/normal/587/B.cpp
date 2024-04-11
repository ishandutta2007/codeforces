#include<bits/stdc++.h>

const int N = 1000010;
const int moder = (int) 1e9 + 7;
typedef long long ll;

int dp[2][N];
int a[N], c[N];
int cnt[N], precnt[N];
int pre[N], tmp[N], pretmp[N];

void add(int &a, int b){
    a += b;
    a -= a >= moder ? moder : 0;
}

void multadd(int &a, int b, int c){
    a = (a + 1ll * b * c) % moder;
}

int main(){
    int n, k;
    ll l;
    scanf("%d%lld%d", &n, &l, &k);
    for (int i = 0; i < n; ++ i){
        scanf("%d", &a[i]);
        c[i] = a[i];
    }
    std::sort(c, c + n);
    int cnt = std::unique(c, c + n) - c;
    for (int i = 0; i < n; ++ i){
        a[i] = std::lower_bound(c, c + cnt, a[i]) - c;
        ++ ::cnt[a[i]];
    }
    for (int i = 0; i < l % n; ++ i){
        ++ tmp[a[i]];
    }
    for (int i = 0; i < N; ++ i){
        precnt[i] = i ? precnt[i - 1] + ::cnt[i] : ::cnt[0];
        pretmp[i] = i ? pretmp[i - 1] + tmp[i] : tmp[0];
    }
    if (l < n){
        printf("%lld\n", l);
        return 0;
    }
    for (int i = 0; i < N; ++ i){
        dp[0][i] = ::cnt[i];
    }
    int now = 0;
    ll total = l / n;
    int ans = 1ll * n * (total % moder) % moder;
    add(ans, l % n);
    for (int i = 2; i <= k; ++ i){
        for (int j = 0; j < cnt; ++ j){
            pre[j] = dp[now][j];
            if (j){
                add(pre[j], pre[j - 1]);
            }
        }
        int sum = 0;
        for (int j = 0; j < cnt; ++ j){
            dp[now ^ 1][j] = 1ll * ::cnt[j] * pre[j] % moder;
            if (i - 1 <= total){
                add(ans, 1ll * tmp[j] * pre[j] % moder);
            }
            add(sum, dp[now ^ 1][j]);
        }
        ll x = total - i + 1;
        if (x > 0){
            multadd(ans, sum, x % moder);
        }
        now ^= 1;
    }
    printf("%d\n", ans);
    return 0;
}