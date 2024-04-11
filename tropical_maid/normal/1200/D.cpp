#include <bits/stdc++.h>
#define fs first
#define se second
#define y0 qwertyuiop
#define y1 asdfghjkl

/*
Author : Tropical_maid
Created : 2019/08/11, 22:14:08
*/

using namespace std;
typedef long long llong;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<llong, llong> pll;

int n, k;
char grid[2001][2002];
int sum[2001][2001];
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> k;
    for (int i = 1; i <= n; ++i) {
        cin >> grid[i] + 1;
    }
    int ret = 0;
    for (int i = 1; i <= n; ++i) {
        int mn = n + 1, mx = 0;
        for (int j = 1; j <= n; ++j) {
            if (grid[i][j] == 'B') {
                mn = min(mn, j);
                mx = max(mx, j);
            }
        }
        if (mx == 0) {
            ++ret;
            continue;
        }
        if (mx - mn + 1 > k) continue;
        int sx = max(1, i - k + 1);
        int ex = min(n - k + 1, i) + 1;
        int sy = max(1, mx - k + 1);
        int ey = min(n - k + 1, mn) + 1;
        ++sum[sx][sy];
        --sum[sx][ey];
        --sum[ex][sy];
        ++sum[ex][ey];
    }
    for (int i = 1; i <= n; ++i) {
        int mn = n + 1, mx = 0;
        for (int j = 1; j <= n; ++j) {
            if (grid[j][i] == 'B') {
                mn = min(mn, j);
                mx = max(mx, j);
            }
        }
        if (mx == 0) {
            ++ret;
            continue;
        }
        if (mx - mn + 1 > k) continue;
        int sy = max(1, i - k + 1);
        int ey = min(n - k + 1, i) + 1;
        int sx = max(1, mx - k + 1);
        int ex = min(n - k + 1, mn) + 1;
        ++sum[sx][sy];
        --sum[sx][ey];
        --sum[ex][sy];
        ++sum[ex][ey];
    }
    int ans = 0;
    for (int i = 1; i <= n; ++i) for (int j = 1; j <= n; ++j) {
        sum[i][j] += sum[i][j - 1] + sum[i - 1][j] - sum[i - 1][j - 1];
        ans = max(ans, sum[i][j]);
    }
    printf("%d\n", ans + ret);
    return 0;
}