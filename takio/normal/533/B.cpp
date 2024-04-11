#include <iostream>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <vector>
#define pii pair <int, int>
#define xx first
#define yy second
#define LL long long
using namespace std;

const int N = 200100;
int a[N];
LL dp[N], dp2[N];
vector <int> g[N];

struct node {
    LL x1, x2;
} t[N];

bool cmp (node a, node b) {
    return a.x1 - a.x2 > b.x1 - b.x2;
}

void dfs (int u) {
    int sz = g[u].size();
    LL t0 = 0, t1 = -1;
    for (int i = 0; i < sz; i++) {
        int v = g[u][i];
        dfs (v);
        LL p0 = t0, p1 = t1;
        if (dp[v] != -1) {
            if (p0 != -1) t0 += dp[v];
            if (p1 != -1) t1 += dp[v];
        }
        if (dp2[v] != -1) {
            if (p0 != -1) t1 = max (t1, p0 + dp2[v]);
            if (p1 != -1) t0 = max (t0, p1 + dp2[v]);
        }
    }
    dp[u] = t0;
    dp2[u] = max (t1, t0 + a[u]);
//    int tn = 0;
//    LL sum = a[u];
//    for (int i = 0; i < sz; i++) {
//        dp2[u] += max (dp2[g[u][i]], dp[g[u][i]]);
//        sum += dp2[g[u][i]];
//        t[++tn].x1 = dp[g[u][i]];
//        t[tn].x2 = dp2[g[u][i]];
//    }
//    sort (t + 1, t + 1 + tn, cmp);
//    dp[u] = max (dp[u], sum);
//    for (int i = 2; i <= tn; i += 2) {
//        sum -= t[i - 1].x2;
//        sum -= t[i].x2;
//        sum += t[i - 1].x1;
//        sum += t[i].x1;
//        dp[u] = max (dp[u], sum);
//    }
}

int main () {
//    freopen ("in.txt", "r", stdin);
    int n, fa;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        scanf ("%d%d", &fa, &a[i]);
        if (i != 1) g[fa].push_back (i);
    }
    dfs (1);
    LL res = 0;
    for (int i = 1; i <= n; i++) {
        res = max (res, dp[i]);
        res = max (res, dp2[i]);
//        cout << i << ' ' << dp[i] << ' ' << dp2[i] << endl;
    }
    cout << res << endl;
}