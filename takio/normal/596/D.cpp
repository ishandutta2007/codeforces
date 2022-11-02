#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;

const int N = 2010, mod = 1e9 + 7;
double dp[N][N][2][2];
bool vis[N][N][2][2];
int x[N];
//int l[N], r[N];
int n, h;
double p;

double solve (int l, int r, int a, int b) {
    if (l > r) return 0;
    if (vis[l][r][a][b]) return dp[l][r][a][b];
    double res = 0;
    vis[l][r][a][b] = 1;
    if (a && x[l] - x[l - 1] < h) {
        res += solve (l + 1, r, 1, b) + min (h, x[l + 1] - x[l] - ((l == r && b) ? h : 0));
    } else if (b && x[r + 1] - x[r] < h) {
        res += solve (l, r - 1, a, 1) + min (h, x[r] - x[r - 1] - ((l == r && a) ? h : 0));
    } else {
        res += (solve (l + 1, r, 0, b) + min (h, x[l] - x[l - 1] - (a ? h : 0))) * 0.5 * p;
//        cout << res << endl;
        res += (solve (l + 1, r, 1, b) + min (h, x[l + 1] - x[l] - ((l == r && b) ? h : 0))) * 0.5 * (1 - p);
//        cout << x[l] - x[l - 1] << ' ' << min (h, x[l] - x[l - 1] - ((l == r && b) ? h : 0)) << ' ' << res << endl;
//        cout << res << endl;
        res += (solve (l, r - 1, a, 0) + min (h, x[r + 1] - x[r] - (b ? h : 0))) * 0.5 * (1 - p);
//        cout << res << endl;
        res += (solve (l, r - 1, a, 1) + min (h, x[r] - x[r - 1] - ((l == r && a) ? h : 0))) * 0.5 * p;
//        cout << res << endl;
    }
//    cout << l << ' ' << r << ' ' << a << ' ' << b << ' ' << res <<endl;
    return dp[l][r][a][b] = res;
}

int main () {
//    freopen ("in.txt", "r", stdin);
    cin >> n >> h >> p;
    for (int i = 1; i <= n; i++) {
        scanf ("%d", &x[i]);
    }
    sort (x + 1, x + 1 + n);
    x[0] = -1e9;
    x[n + 1] = 1e9;
//    l[1] = 1;
//    for (int i = 2; i <= n; i++) {
//        if (x[i] - x[i - 1] < h) l[i] = l[i - 1];
//        else l[i] = i;
//    }
//    r[n] = n;
//    for (int i = n - 1; i >= 1; i--) {
//        if (x[i + 1] - x[i] < h) r[i] = r[i + 1];
//        else r[i] = i;
//    }
    printf ("%.10f\n", solve (1, n, 0, 0));
}