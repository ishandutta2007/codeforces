#include <bits/stdc++.h>
#define LL long long
#define pii pair <LL, LL>
#define xx first
#define yy second
using namespace std;

const LL N = 510;

LL a[N][N];
LL sum[N];
int main () {
//    freopen ("in.txt", "r", stdin);
    LL n;
    cin >> n;
    if (n == 1) {
        cout << 1 << endl;
        return 0;
    }
    LL mx = 0;
    int x = 0, y = 0;
    for (LL i = 1; i <= n; i++) {
//        sum = 0;
        for (LL j = 1; j <= n; j++) {
            scanf ("%I64d", &a[i][j]);
            sum[i] += a[i][j];
            if (a[i][j] == 0) x = i, y = j;
        }
        mx = max (mx, sum[i]);
    }
    a[x][y] = mx - sum[x];
    if (a[x][y] == 0) {
        cout << -1 << endl;
        return 0;
    }
    for (LL i = 1; i <= n; i++) {
        LL tmp = 0;
        for (LL j = 1; j <= n; j++) {
            tmp += a[i][j];
        }
        if (tmp != mx) {
            cout << -1 << endl;
            return 0;
        }
    }
    for (LL i = 1; i <= n; i++) {
        LL tmp = 0;
        for (LL j = 1; j <= n; j++) {
            tmp += a[j][i];
        }
        if (tmp != mx) {
            cout << -1 << endl;
            return 0;
        }
    }
    LL tmp = 0;
    for (LL i = 1, j = 1; i <= n; i++, j++) {
        tmp += a[i][j];
    }
    if (tmp != mx) {
        cout << -1 << endl;
        return 0;
    }
    tmp = 0;
    for (LL i = 1, j = n; i <= n; i++, j--) {
        tmp += a[i][j];
    }
    if (tmp != mx) {
        cout << -1 << endl;
        return 0;
    }
    cout << a[x][y] << endl;
}