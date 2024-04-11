#include <bits/stdc++.h>

const int N = 2100;
const int moder = 998244353;

void add(int &a, int b){
    a += b, a -= a >= moder ? moder : 0;
}

int dp[N];
int dp1[2][N][N];

void solve1(int n){
    dp[0] = 1;
    for (int i = 1; i <= n; ++ i){
        for (int j = i; j <= n; ++ j){
            add(dp[j], dp[j - i]);
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; ++ i){
        add(ans, dp[i]);
    }
    printf("%d\n", ans);
}

void solve2(int n){
    int now = 0;
    dp1[now][n][0] = 1;
    int ans = 0, upper_bound = n;
    for (int i = 1; i <= n; ++ i){
        for (int j = upper_bound - 1; j >= 0; -- j){
            for (int k = 0; k <= n; ++ k){
                add(dp1[now][j][k], dp1[now][j + 1][k]);
            }
        }
        upper_bound = n / i;
        for (int j = 1; j <= upper_bound; ++ j){
            memset(dp1[now ^ 1][j], 0, sizeof(dp1[now][j]));
            for (int k = 0; k <= n; ++ k){
                if (k - i * j >= 0){
                    add(dp1[now ^ 1][j][k], dp1[now][j][k - i * j]);
                    add(ans, dp1[now ^ 1][j][k]);
                }
            }
        }
        now ^= 1;
    }
    printf("%d\n", ans);
}

const int MAX_SIZE = 65;
const int MAX_SUM = 65;

bool check(std::vector <int> vec, int n, int k){
    if (k == 2){
        int sum = 0, sz = vec.size();
        for (int i = sz - 1; i >= 0; -- i){
            sum += (sz - i) * vec[i];
        }
        return sum <= n;
    }
    std::vector <int> nvec;
    int sz = vec.size();
    for (int i = sz - 1; i >= 0; -- i){
        for (int j = 0; j < vec[i]; ++ j){
            if (nvec.size() >= MAX_SIZE){
                return false;
            }
            nvec.emplace_back(sz - i);
        }
    }
    return check(nvec, n, k - 1);
}

void dfs(int sum, int pre, int n, int k, int &ans, std::vector <int> &vec){
    if (check(vec, n, k)){
        if (!vec.empty()){
            ++ ans;
        }
    }
    else{
        return;
    }
    for (int i = pre; i <= sum; ++ i){
        vec.emplace_back(i);
        int pre_ans = ans;
        dfs(sum - i, i, n, k, ans, vec);
        vec.pop_back();
        if (ans == pre_ans){
            break;
        }
    }
}

void solve(int n, int k){
    int ans = 0;
    std::vector <int> vec;
    dfs(MAX_SUM, 1, n, k, ans, vec);
    printf("%d\n", ans);
}

int main(){
    int n, k;
    scanf("%d%d", &n, &k);
    if (k == 1){
        solve1(n);
        return 0;
    }
    if (k == 2){
        solve2(n);
        return 0;
    }
    solve(n, k);
    return 0;
}