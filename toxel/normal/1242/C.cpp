#include <bits/stdc++.h>

const int N = 16;
using ll = long long;

struct Ans{
    int a[N][2];

    Ans(){for (int i = 0; i < N; ++ i){a[i][0] = a[i][1] = INT_MAX;}}

    void merge(const Ans &ans){
        for (int i = 0; i < N; ++ i){
            for (int j = 0; j < 2; ++ j){
                a[i][j] = std::min(a[i][j], ans.a[i][j]);
            }
        }
    }
};

std::vector <int> vec[N];
ll ssum[N];
bool dp[1 << N];
Ans ans[1 << N];

int main(){
    int k;
    scanf("%d", &k);
    ll sum = 0;
    std::map <ll, int> map;
    for (int i = 0; i < k; ++ i){
        int n;
        scanf("%d", &n);
        vec[i].resize(n);
        for (int j = 0; j < n; ++ j){
            scanf("%d", &vec[i][j]);
            sum += vec[i][j];
            ssum[i] += vec[i][j];
            map[vec[i][j]] = i;
        }
    }
    if (sum % k){
        puts("No");
        return 0;
    }
    sum /= k;
    for (int i = 0; i < k; ++ i){
        if (ssum[i] == sum){
            dp[1 << i] = true;
            ans[1 << i].a[i][0] = ans[1 << i].a[i][1] = vec[i][0];
            continue;
        }
        for (auto u : vec[i]){
            Ans a;
            a.a[i][0] = u;
            ll next = sum - (ssum[i] - u);
            if (map.count(next) && map[next] != i){
                a.a[i][1] = next;
                int cur = map[next];
                bool flag = true;
                int mask = 1 << i;
                while (true){
                    mask |= 1 << cur;
                    a.a[cur][0] = next;
                    next = sum - (ssum[cur] - next);
                    a.a[cur][1] = next;
                    if (!map.count(next)){
                        flag = false;
                        break;
                    }
                    if (map[next] == i){
                        if (next != a.a[i][0]){
                            flag = false;
                        }
                        break;
                    }
                    if (a.a[map[next]][0] != INT_MAX){
                        flag = false;
                        break;
                    }
                    cur = map[next];
                }
                if (flag && !dp[mask]){
                    dp[mask] = true;
                    ans[mask] = a;
                }
            }
        }
    }
    for (int i = 1; i < 1 << k; ++ i){
        if (!dp[i]){
            for (int j = (i - 1) & i; j; j = (j - 1) & i){
                if (dp[j] && dp[i ^ j]){
                    dp[i] = true;
                    ans[i] = ans[j];
                    ans[i].merge(ans[i ^ j]);
                    break;
                }
            }
        }
    }
    int last = (1 << k) - 1;
    if (!dp[last]){
        puts("No");
        return 0;
    }
    puts("Yes");
    for (int i = 0; i < k; ++ i){
        for (int j = 0; j < k; ++ j){
            if (ans[last].a[i][0] == ans[last].a[j][1]){
                printf("%d %d\n", ans[last].a[i][0], j + 1);
                break;
            }
        }
    }
    return 0;
}