#include <bits/stdc++.h>

const int N = 10010;
const int M = 5010;
const int BIT = 20;

char s[N];
int sa[N], id[N], rk[N], oldrk[N << 1], tmp[N], cnt[N], height[N];

void get_sa(char *s, int *sa){
    int n = strlen(s + 1), m = 300;
    for (int i = 1; i <= n; ++ i) ++ cnt[rk[i] = s[i]];
    for (int i = 1; i <= m; ++ i) cnt[i] += cnt[i - 1];
    for (int i = n; i >= 1; -- i) sa[cnt[s[i]] --] = i;
    if (n == 1) rk[1] = 1;
    auto equal = [&](int x, int y, int w){return oldrk[x] == oldrk[y] && oldrk[x + w] == oldrk[y + w];};
    for (int w = 1, p; w < n; w <<= 1, m = p){
        p = 0;
        for (int i = n; i > n - w; -- i) id[++ p] = i;
        for (int i = 1; i <= n; ++ i){
            if (sa[i] > w) id[++ p] = sa[i] - w;
        }
        memset(cnt, 0, sizeof(cnt));
        for (int i = 1; i <= n; ++ i) ++ cnt[tmp[i] = rk[id[i]]];
        for (int i = 1; i <= m; ++ i) cnt[i] += cnt[i - 1];
        for (int i = n; i >= 1; -- i) sa[cnt[tmp[i]] --] = id[i];
        memcpy(oldrk, rk, sizeof(rk));
        p = 0;
        for (int i = 1; i <= n; ++ i){
            rk[sa[i]] = equal(sa[i - 1], sa[i], w) ? p : ++ p;
        }
    }
    for (int i = 1, p = 0; i <= n; ++ i){
        if (p) -- p;
        while (s[i + p] == s[sa[rk[i] - 1] + p]) ++ p;
        height[rk[i]] = p;
    }
}

void init(){
    memset(cnt, 0, sizeof(cnt));
    memset(rk, 0, sizeof(rk));
}

int dp[M];
int lcp[M][M];

void solve(){
    int n;
    scanf("%d%s", &n, s + 1);
    init();
    get_sa(s, sa);
    for (int i = 1; i <= n; ++ i){
        int min = INT_MAX;
        for (int j = i + 1; j <= n; ++ j){
            min = std::min(min, height[j]);
            int x = sa[i], y = sa[j];
            lcp[x][y] = lcp[y][x] = min;
        }
    }
    dp[0] = 0;
    for (int i = 1; i <= n; ++ i){
        dp[i] = n + 1 - i;
        for (int j = 1; j < i; ++ j){
            int len = lcp[j][i];
            if (i + len - 1 == n){
                continue;
            }
            if (s[i + len] < s[j + len]){
                continue;
            }
            dp[i] = std::max(dp[i], dp[j] + (n - (i + len) + 1));
        }
    }
    int ans = *std::max_element(dp + 1, dp + n + 1);
    printf("%d\n", ans);
    for (int i = 0; i <= n + 5; ++ i){
        for (int j = 0; j <= n + 5; ++ j){
            lcp[i][j] = 0;
        }
        dp[i] = 0;
    }
}

int main(){
    int test;
    scanf("%d", &test);
    while (test --){
        solve();
    }
    return 0;
}