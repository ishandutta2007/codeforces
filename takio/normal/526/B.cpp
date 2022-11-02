#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
#include <set>
#include <cmath>
#include <vector>
#define pii pair <int, int>
#define xx first
#define yy second
#define LL long long
#define ls rt << 1
#define rs rt << 1 | 1
#define lson ls, l, m
#define rson rs, m + 1, r

using namespace std;

const int N = 2300;

int dp[N], a[N], res = 0, n;

void dfs (int u, int d) {
    if (d == n) { dp[u] = 0; return; }
    int l = u * 2, r = l + 1;
    dfs (l, d + 1);
    dfs (r, d + 1);
    int x = dp[l] + a[l], y = dp[r] + a[r];
    if (x < y) swap (x, y);
    dp[u] = x;
    res += x - y;
//    cout << u << ' ' << dp[l] << ' ' << dp[r] << ' ' << dp[u] << endl;
}

int main () {
//    freopen ("in.txt", "r", stdin);
    cin >> n;
    for (int i = 2; i < (1 << n + 1); i++) {
//        cout << i << endl;
        scanf ("%d", &a[i]);
    }
    dfs (1, 0);
    cout << res << endl;
}