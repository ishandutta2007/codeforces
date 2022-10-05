#include<bits/stdc++.h>

typedef long long ll;

const int N = 30010;
const int M = 110;

int gen[N];
ll power[N];
int d, m;
ll dp[M][M];
int digit[M];
ll res[M][M][2];
int n;

void dfs(int now, int max, ll remain, auto vec, ll &ans, ll r){
    if (now == max){
        return;
    }
    if ((int) vec.size() == 1){
        int sit = r % power[now] >= remain;
        for (int i = 0; i < m; ++ i){
            if (vec[0] >> i & 1){
                ans += res[now][i][sit];
            }
        }
        return;
    }
    for (int i = 0; i < d; ++ i){
        ll nremain = remain + power[now] * i;
        std::vector <ll> nvec;
        ll y = (1ll << m) - 1;
        for (int j = i, sz = vec.size(); j < i + sz; ++ j){
            ll x = vec[j - i], rem = gen[j % d];
            x = (x >> rem) | ((x & ((1ll << rem) - 1)) << (m - rem));
            y &= x;
            if (j == i + sz - 1 || j % d == d - 1){
                nvec.push_back(y);
                y = (1ll << m) - 1;
            }
        }
        dfs(now + 1, max, nremain, nvec, ans, r);
    }
}

ll solve(ll r, auto vec){
    if (r < 0) return 0;
    power[0] = 1;
    int max = 0;
    for (int i = 1; i < N; ++ i){
        power[i] = power[i - 1] * d;
        if (power[i - 1] > std::max((ll) n * d, r)){
            max = i;
            break;
        }
    }
    memset(dp, 0, sizeof(dp));
    dp[0][0] = 1;
    for (int i = 1; i <= max; ++ i){
        for (int j = 0; j < m; ++ j){
            for (int k = 0; k < d; ++ k){
                dp[i][(j + gen[k]) % m] += dp[i - 1][j];
            }
        }
    }
    auto calc = [&](ll x, int remain){
        int cnt = 0;
        while (x){
            digit[cnt ++] = x % d;
            x /= d;
        }
        std::reverse(digit, digit + cnt);
        int nowremain = 0;
        ll ans = 0;
        for (int i = 0; i < cnt; ++ i){
            for (int j = 0; j < digit[i]; ++ j){
                int x = (nowremain + gen[j]) % m;
                x = (remain - x + m) % m;
                ans += dp[cnt - i - 1][x];
            }
            nowremain = (nowremain + gen[digit[i]]) % m;
        }
        return ans;
    };
    memset(res, 0, sizeof(res));
    for (int i = 0; i <= max; ++ i){
        for (int j = 0; j < m; ++ j){
            res[i][j][0] = calc(r / power[i], j);
            res[i][j][1] = calc(r / power[i] + 1, j);
        }
    }
    ll ans = 0;
    dfs(0, max, 0, vec, ans, r);
    return ans;
}

int main(){
    scanf("%d%d", &d, &m);
    for (int i = 0; i < d; ++ i){
        scanf("%d", &gen[i]);
    }
    scanf("%d", &n);
    std::vector <ll> vec;
    for (int i = 0, x; i < n; ++ i){
        scanf("%d", &x);
        vec.push_back((1ll << (x + 1)) - 1);
    }
    ll l, r;
    scanf("%lld%lld", &l, &r);
    -- l, -- r;
    if (r - l + 1 < n){
        puts("0");
        return 0;
    }
    printf("%lld\n", solve(r - (n - 1), vec) - solve(l - 1, vec));
    return 0;
}