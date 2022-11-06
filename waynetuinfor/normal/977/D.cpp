#include <bits/stdc++.h>
using namespace std;

const int maxn = 100 + 5;
long long a[maxn];
vector<int> graf[maxn];
int dp[maxn], to[maxn];

int dfs(int x) {
    if (dp[x]) return dp[x];
    dp[x] = 1;
    for (int u : graf[x]) {
        if (dfs(u) + 1 > dp[x]) {
            dp[x] = dfs(u) + 1;
            to[x] = u;
        }
    }
    return dp[x];
}

int main() {
    int n; scanf("%d", &n);
    for (int i = 0; i < n; ++i) scanf("%lld", &a[i]);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) if (i != j) {
            if (a[i] % 3 == 0 && a[i] / 3 == a[j] || a[i] * 2 == a[j]) graf[i].push_back(j);
        }
    }
    memset(to, -1, sizeof(to));
    int ans = -1, z = -1;
    for (int i = 0; i < n; ++i) if (dfs(i) > ans) ans = dfs(i), z = i;
    assert(ans == n);
    for (int i = z; i != -1; i = to[i]) printf("%lld ", a[i]);
    puts("");
}