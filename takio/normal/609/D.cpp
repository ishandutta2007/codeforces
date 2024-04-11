#include <bits/stdc++.h>
#define LL long long
#define pii pair <LL, LL>
#define xx first
#define yy second
using namespace std;

const int N = 210000, F = 20;

int a[N], b[N], t[N], c[N];
int n, m, k, s;
pii d[N];
pii mna, mnb;

int jug (int nn) {
    mna = pii (1e9, 0), mnb = pii (1e9, 0);
    for (int i = 1; i <= nn; i++) {
        if (a[i] < mna.xx) mna = pii (a[i], i);
        if (b[i] < mnb.xx) mnb = pii (b[i], i);
    }
    for (int i = 1; i <= m; i++) {
        if (t[i] == 1) d[i] = pii (1LL * c[i] * mna.xx, i);
        else d[i] = pii (1LL * c[i] * mnb.xx, i);
    }
    sort (d + 1, d + 1 + m);
//    cout << mna.xx << ' ' << mna.yy << endl;
//    cout << mnb.xx << ' ' << mnb.yy << endl;
    LL sum = 0;
    for (int i = 1; i <= k; i++) sum += d[i].xx;
    return sum <= s;
}

int main () {
//    freopen ("in.txt", "r", stdin);
    cin >> n >> m >> k >> s;
    for (int i = 1; i <= n; i++) {
        scanf ("%d", &a[i]);
    }
    for (int i = 1; i <= n; i++) {
        scanf ("%d", &b[i]);
    }
    for (int i = 1; i <= m; i++) {
        scanf ("%d%d", &t[i], &c[i]);
    }
//    jug (1);
//    return 0;
    int l = 0, r = n + 1;
    while (l + 1 < r) {
        int m = l + r >> 1;
        if (jug (m)) r = m;
        else l = m;
    }
    if (r > n) cout << -1 << endl;
    else {
        cout << r << endl;
        jug (r);
        for (int i = 1; i <= k; i++) {
            if (t[d[i].yy] == 1) printf ("%I64d %I64d\n", d[i].yy, mna.yy);
            else printf ("%I64d %I64d\n", d[i].yy, mnb.yy);
        }
    }
}