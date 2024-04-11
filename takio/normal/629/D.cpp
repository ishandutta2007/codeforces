#include <bits/stdc++.h>
//#define LL long long
#define LL unsigned long long
#define pii pair <LL, LL>
#define xx first
#define yy second
using namespace std;

const int N = 100010, F = 20;
const double pi = acos (-1.0);

pii a[N];
LL tree[N];

int f (int x) {
    return x & -x;
}

void add (int x, LL y) {
    for (int i = x; i < N; i += f (i)) tree[i] = max (tree[i], y);
}

LL qry (int x) {
    LL r = 0;
    for (int i = x; i; i -= f (i)) r = max (r, tree[i]);
    return r;
}

int main () {
//    freopen ("in.txt", "r", stdin);
//    long double x;
//    cin >> x;
//    cout << (LL)(x / pi) << endl;
//    return 0;
    int n, r, h;
    cin >> n;
    LL sum = 0, flag = 1;
    for (int i = 1; i <= n; i++) {
        scanf ("%d%d", &r, &h);
        a[i] = pii (1LL * r * r * h, n - i + 1);
        sum += 1LL * r * r * h;
        if (i > 1 && a[i].xx < a[i - 1].xx) flag = 0;
    }
//    if (n == 100000 && a[1].xx == 3 * 3 * 136) cout << sum << ' ' << pi * sum << ' ' << flag << endl;
//    cout << a[1].xx + a[2].xx + a[4].xx << endl;
    sort (a + 1, a + 1 + n);
    LL res = 0;
    for (int i = 1; i <= n; i++) {
        LL tmp = qry (n - a[i].yy + 1) + a[i].xx;
        res = max (res, tmp);
        add (n - a[i].yy + 1, tmp);
    }
    printf ("%.10f\n", (double) (pi * res));
}