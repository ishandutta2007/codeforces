#include <bits/stdc++.h>

using ll = long long;
const int N = 50;

ll comb[N][N];
ll l[N][N], r[N][N];
ll a[N][N];

int main(){
    for (int i = 0; i < N; ++ i){
        comb[i][0] = 1;
        for (int j = 1; j <= i; ++ j){
            comb[i][j] = comb[i - 1][j - 1] + comb[i - 1][j];
        }
    }
    for (int i = 0; i < N; ++ i){
        ll cur = 0;
        for (int j = 0; j <= i; ++ j){
            l[j][i - j] = cur;
            r[j][i - j] = cur + comb[i][j] - 1;
            cur = r[j][i - j] + 1;
        }
    }
    for (int i = 0; i < 25; ++ i){
        for (int j = 0; j < 25; ++ j){
            // printf("%lld,%lld%c", l[i][j], r[i][j], " \n"[j == 24]);
            a[i][j] = i == 0 ? 0 : l[i][j] - l[i - 1][j];
            // printf("%lld%c", a[i][j], " \n"[j == 24]);
        }
    }
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++ i){
        for (int j = 0; j < n; ++ j){
            printf("%lld%c", a[i][j], " \n"[j == n - 1]);
        }
    }
    fflush(stdout);
    int test;
    scanf("%d", &test);
    while (test --){
        ll k;
        scanf("%lld", &k);
        using pii = std::pair <int, int>;
        pii p = {n - 1, n - 1};
        std::vector<pii> ans;
        while (p.first || p.second){
            ans.emplace_back(p);
            k -= a[p.first][p.second];
            if (!p.first){
                -- p.second;
            }
            else if (!p.second){
                -- p.first;
            }
            else{
                int x = p.first, y = p.second;
                if (l[x - 1][y] <= k && k <= r[x - 1][y]){
                    -- p.first;
                }
                else{
                    -- p.second;
                }
            }
        }
        ans.emplace_back(0, 0);
        std::reverse(ans.begin(), ans.end());
        for (auto u : ans){
            printf("%d %d\n", u.first + 1, u.second + 1);
        }
        fflush(stdout);
    }
    return 0;
}