#include <bits/stdc++.h>

const int N = 5001;
using ll = long long;

int cnt[N], min[N];
std::vector <int> prime;
std::vector <short> vec[N];
int n;
ll mini = 0;

void dfs(int l, int r, int now, ll sum){
    for (int i = l, j = l; i <= r; i = j){
        if (vec[i].size() <= now){
            ++ j;
            continue;
        }
        ll nsum = sum;
        while (j <= r && vec[j][now] == vec[i][now]){
            nsum += cnt[j ++];
        }
        mini = std::min(mini, -2 * nsum + 1ll * n * (now + 1));
        dfs(i, j - 1, now + 1, nsum);
    }
}

int main(){
    for (int i = 2; i < N; ++ i){
        if (!min[i]){
            min[i] = i;
            prime.push_back(i);
        }
        for (auto u : prime){
            if (i * u >= N) break;
            min[i * u] = u;
            if (i % u == 0) break;
        }
    }
    scanf("%d", &n);
    for (int i = 0, x; i < n; ++ i){
        scanf("%d", &x);
        ++ cnt[x];
    }
    ll ans = 0;
    for (int i = 1; i < N; ++ i){
        for (auto u : prime){
            int x = i;
            int len = 0;
            while (x){
                len += x / u;
                x /= u;
            }
            for (int j = 0; j < len; ++ j){
                vec[i].emplace_back(u);
            }
        }
        std::reverse(vec[i].begin(), vec[i].end());
        ans += 1ll * cnt[i] * vec[i].size();
    }
    std::vector <int> cur(N - 1);
    for (int j = 1; j < N; ++ j){
        cur[j - 1] = j;
    }
    dfs(1, N - 1, 0, 0);
    printf("%lld\n", ans + mini);
    return 0;
}