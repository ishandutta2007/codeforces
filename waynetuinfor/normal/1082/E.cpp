#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e6 + 5;
int a[maxn], s[maxn];
vector<int> p[maxn];

int main() {
    int n, x; scanf("%d%d", &n, &x);
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &a[i]);
        p[a[i]].push_back(i);
        if (a[i] == x) ++ans, s[i] = 1;
    }
    for (int i = 1; i <= n; ++i) s[i] += s[i - 1];
    for (int i = 0; i < maxn; ++i) {
        if (p[i].size() == 0) continue;
        if (i == x) continue;
        int dp = 0;
        for (int j = 0; j < (int)p[i].size(); ++j) {
            int res = dp + 1;
            if (j) res -= s[p[i][j]] - s[p[i][j - 1]];
            ans = max(ans, s[n] + res);
            dp = max(1, res);
        }
    }
    printf("%d\n", ans);
    return 0;
}