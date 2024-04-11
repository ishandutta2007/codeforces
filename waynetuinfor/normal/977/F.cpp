#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e5 + 5;
int a[maxn];
map<int, int> dp, who, fr;

int main() {
    int n; scanf("%d", &n);
    for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
    for (int i = 1; i <= n; ++i) {
        dp[a[i]] = max(dp[a[i]], dp[a[i] - 1] + 1); 
    }
    int ans = -1, z = -1;
    for (int i = 1; i <= n; ++i) if (dp[a[i]] > ans) ans = dp[a[i]], z = a[i];
    printf("%d\n", ans);
    int p = z - ans + 1;
    vector<int> v;
    for (int i = 1; i <= n; ++i) {
        if (a[i] == p) {
            v.push_back(i);
            ++p;
        }
    }
    assert((int)v.size() == ans);
    for (int i = 0; i < ans; ++i) printf("%d ", v[i]); puts("");
    return 0;
}