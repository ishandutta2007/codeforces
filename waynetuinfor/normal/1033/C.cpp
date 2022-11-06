#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 5;
int a[maxn], dp[maxn];
bool v[maxn];
vector<int> g[maxn];

int dfs(int x) {
    if (v[x]) return dp[x];
    dp[x] = 0;
    for (const int &u : g[x]) {
        int k = dfs(u);
        if (k == 0) dp[x] = 1;
    }
    v[x] = true;
    return dp[x];
}

int main() {
    int n; scanf("%d", &n);
    for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
    for (int i = 0; i < n; ++i) {
        for (int j = a[i]; i + j < n; j += a[i]) if (a[i + j] > a[i]) g[i].push_back(i + j);
        for (int j = a[i]; i - j >= 0; j += a[i]) if (a[i - j] > a[i]) g[i].push_back(i - j);
    }
    for (int i = 0; i < n; ++i) {
        int r = dfs(i);
        if (r) printf("A");
        else printf("B");
    }
    puts("");
    return 0;
}