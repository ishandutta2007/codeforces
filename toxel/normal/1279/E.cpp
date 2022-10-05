#include <bits/stdc++.h>

using ll = long long;
const int N = 60;
const ll INF = ll(1.5e18);

ll mult(ll a, ll b){
    if (!a || !b) return 0;
    return a <= INF / b ? a * b : INF;
}

ll add(ll a, ll b){
    return std::min(INF, a + b);
}

ll dp[N], fac[N], op[N];
std::vector <int> ans;

std::vector <int> get(int n, ll k){
    std::vector <bool> vis(n);
    std::vector <int> ret(n, -1);
    vis[n - 1] = true;
    ret[0] = n - 1;
    for (int i = 1; i < n; ++ i){
        for (int j = 0; j < n; ++ j){
            if (vis[j]){
                continue;
            }
            ret[i] = j;
            std::vector <bool> vis1(n), head(n, true);
            for (int kk = 0; kk < n; ++ kk){
                if (ret[kk] != -1){
                    head[ret[kk]] = false;
                }
            }
            int sum = 0;
            for (int kk = 0; kk < n; ++ kk){
                if (ret[kk] == -1){
                    break;
                }
                if (!head[kk]){
                    continue;
                }
                int x = kk, sz = 0;
                bool complete = false;
                while (true){
                    vis1[x] = true;
                    ++ sz;
                    x = ret[x];
                    if (x == -1 || vis1[x]){
                        if (x != -1){
                            complete = true;
                        }
                        break;
                    }
                }
                if (complete && sz < n){
                    sum = -1;
                    break;
                }
            }
            for (int kk = 0; kk < n; ++ kk){
                if (!vis1[kk] && ret[kk] != -1){
                    int x = kk, sz = 0;
                    while (x != -1 && !vis1[x]){
                        ++ sz;
                        vis1[x] = true;
                        x = ret[x];
                    }
                    if (sz != n){
                        sum = -1;
                        break;
                    }
                }
            }
            if (sum == -1){
                continue;
            }
            for (int kk = 0; kk < n; ++ kk){
                if (!vis1[kk] && ret[kk] == -1){
                    ++ sum;
                }
                else if (head[kk]){
                    ++ sum;
                }
            }
            ll value = fac[sum - 1];
            if (k > value){
                k -= value;
                continue;
            }
            else{
                ret[i] = j;
                vis[j] = true;
                break;
            }
        }
    }
    return ret;
}

void solve(int n, ll k, int offset){
    if (n == 0){
        return;
    }
    bool flag = true;
    for (int i = 1; i <= n; ++ i){
        ll value = mult(op[i], dp[n - i]);
        if (k > value){
            k -= value;
            continue;
        }
        flag = false;
        ll num = (k - 1) / dp[n - i] + 1;
        std::vector <int> vec = get(i, num);
        for (auto u : vec){
            ans.push_back(u + offset);
        }
        solve(n - i, k - (num - 1) * dp[n - i], offset + i);
        break;
    }
    if (flag){
        ans.push_back(-1);
        return;
    }
}

void solve(int n, ll k){
    if (k > dp[n]){
        puts("-1");
        return;
    }
    solve(n, k, 1);
    if (ans.back() == -1){
        puts("-1");
    }
    else{
        for (int i = 0; i < n; ++ i){
            printf("%d%c", ans[i], " \n"[i == n - 1]);
        }
    }
    ans.clear();
}

int main(){
    fac[0] = 1;
    dp[0] = 1;
    for (int i = 1; i < N; ++ i){
        fac[i] = mult(fac[i - 1], i);
        op[i] = i <= 2 ? 1 : fac[i - 2];
    }
    for (int i = 1; i < N; ++ i){
        for (int j = 1; j <= i; ++ j){
            dp[i] = add(dp[i], mult(op[j], dp[i - j]));
        }
    }
    /*for (int i = 1; i <= dp[6] + 1; ++ i){
        solve(6, i);
    }*/
    int test;
    scanf("%d", &test);
    while (test --){
        int n;
        ll k;
        scanf("%d%lld", &n, &k);
        solve(n, k);
    }
    return 0;
}