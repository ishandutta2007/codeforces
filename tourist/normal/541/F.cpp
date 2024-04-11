#include <bits/stdc++.h>

using namespace std;

struct leaf {
    int depth;
    int cost;
};

int const INF = 1 << 30;
int const N = 1234;
vector<leaf> a[N];

int dp[N][N];
    

int main() {
    int n, T;
    scanf("%d%d", &n, &T);    
    for (int i = 0; i < n; i++) {
        int t, x;
        scanf("%d%d", &t, &x);
        t = T - t;
        a[t].push_back({t, x});
    }
    for (int i = 0; i <= T; i++)
        fill(dp[i], dp[i] + n + 1, -INF);
    dp[0][min(n, 1)] = 0;
    for (int i = 0; i < T; i++) {
        sort(a[i].begin(), a[i].end(), [](leaf const & a, leaf const & b) {
            return a.cost > b.cost;
        });
        int sz = (int) a[i].size();
        for (int can = 0; can <= n; can++) {
            int sum = 0;
            int val = dp[i][can];
            if (val == -INF) continue;
//            printf("%d %d %d\n", i, can, val);
            for (int j = 0; j <= can && j <= sz; j++) {
                if (j > 0) sum += a[i][j - 1].cost;
                int newCan = min((can - j) * 2, n);
                dp[i + 1][newCan] = max(dp[i + 1][newCan], val + sum);
            }
        }
    }
    int ans = -INF;
    for (int i = 0; i <= n; i++) ans = max(ans, dp[T][i]);
    printf("%d\n", ans);
}