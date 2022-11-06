#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 5;
vector<int> g[maxn];
int dp[2][maxn], ans;

int dfs(int x, int p) {
    int sz = 1;
    for (int u : g[x]) if (u != p) {
        sz += dfs(u, x);
    }
    if (sz % 2 == 0 && p > 0) ++ans, sz = 0;
    return sz;
} 


int main() {
    int n; scanf("%d", &n);
    for (int i = 0; i < n - 1; ++i) {
        int a, b; scanf("%d %d", &a, &b);
        g[a].push_back(b); g[b].push_back(a);
    }
    if (n & 1) {
        puts("-1");
        return 0;
    }
    dfs(1, 0);
    printf("%d\n", ans);
    return 0;
}