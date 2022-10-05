#include <bits/stdc++.h>

const int N = 19;
using ll = long long;

void FWT_OR(ll *a, int n){
    for (int j = 0; j < n; ++ j){
        for (int i = 0; i < 1 << n; ++ i){
            if (i >> j & 1){
               a[i] += a[i ^ 1 << j];
            }
        }
    }
}

std::map <std::vector<int>, ll> map;

char s[N][N];
ll dp[1 << N][N];
ll num[1 << N];
ll fwt[N][1 << N];
int bitcnt[1 << N];
ll ans[1 << N];

void dfs(int sum, int max, const std::vector<ll> &value, const std::vector<int> &vec){
    if (sum == 0){
        ll ret = 0;
        int sz = value.size();
        for (int i = 0; i < sz; ++ i){
            if (bitcnt[i & (sz - 1)] & 1) ret -= value[sz - 1 - i];
            else ret += value[sz - 1 - i];
        }
        map[vec] = ret;
        return;
    }
    for (int i = max; i <= sum; ++ i){
        if (i < sum && i > sum - i){
            continue;
        }
        std::vector<ll> nvalue = value;
        std::vector<int> nvec = vec;
        nvec.emplace_back(i);
        int sz = value.size();
        for (int j = 0; j < sz; ++ j){
            nvalue[j] = nvalue[j] * fwt[i][j];
        }
        dfs(sum - i, i, nvalue, nvec);
    }
}

void solve(int n){
    for (int i = 0; i < n; ++ i){
        dp[1 << i][i] = 1;
    }
    for (int i = 1; i < 1 << n; ++ i){
        for (int j = 0; j < n; ++ j){
            if (i >> j & 1){
                continue;
            }
            for (int k = 0; k < n; ++ k){
                if (s[j][k] != '1'){
                    continue;
                }
                dp[i | 1 << j][j] += dp[i][k];
            }
        }
    }
    for (int i = 0; i < 1 << n; ++ i){
        for (int j = 0; j < n; ++ j){
            num[i] += dp[i][j];
        }
    }
    for (int i = 0; i <= n; ++ i){
        for (int j = 0; j < 1 << n; ++ j){
            fwt[i][j] = bitcnt[j] == i ? num[j] : 0;
        }
        FWT_OR(fwt[i], n);
    }
    dfs(n, 1, std::vector <ll>(1 << n, 1), {});
    for (int i = 0; i < 1 << (n - 1); ++ i){
        std::vector<int> vec;
        int pre = -1;
        for (int j = 0; j < n - 1; ++ j){
            if (!(i >> j & 1)){
                vec.emplace_back(j - pre);
                pre = j;
            }
        }
        vec.emplace_back(n - 1 - pre);
        std::sort(vec.begin(), vec.end());
        ans[i] = map[vec];
    }
    for (int j = 0; j < n - 1; ++ j){
        for (int i = 0; i < 1 << (n - 1); ++ i){
            if (!(i >> j & 1)){
                ans[i] -= ans[i ^ 1 << j];
            }
        }
    }
    int sz = 1 << (n - 1);
    for (int i = 0; i < sz; ++ i){
        printf("%lld%c", ans[i], " \n"[i == sz - 1]);
    }
}

int main(){
    for (int i = 1; i < 1 << N; ++ i){
        bitcnt[i] = bitcnt[i >> 1] + (i & 1);
    }
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++ i){
        scanf("%s", s[i]);
    }
    solve(n);
    return 0;
}