#include <bits/stdc++.h>
#define LL long long
#define ULL unsigned long long
#define pii pair <LL, LL>

using namespace std;

const int N = 200100;
const ULL M = 1LL << 33;
const double eps = 1e-8;

int a[N], n;

double solve (double x, int t) {
    double now1 = 0, res1 = 0, now2 = 0, res2 = 0;
    for (int i = 1; i <= n; i++) {
        now1 += (a[i] - x);
        now2 += -(a[i] - x);
//        cout <<a[i] - x<< ' ';
        if (now1 < 0) now1 = 0;
        if (now2 < 0) now2 = 0;
        res1 = max (res1, now1);
        res2 = max (res2, now2);
    }
//    cout << x <<' ' << res1 << ' ' << res2 << endl;
    if (t == 0) return res1 - res2;
    printf ("%.10f\n", res1);
}

int main () {
//    freopen ("in.txt", "r", stdin);
//    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) scanf ("%d", &a[i]);
    double l = -1e10, r = 1e10;
    while (r - l > eps) {
//        cout << l <<' ' << r << endl;
        double m = (l + r) / 2;
        if (solve (m, 0) > 0) l = m;
        else r = m;
    }
    solve(r, 1);
}