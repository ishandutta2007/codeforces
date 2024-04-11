#include <bits/stdc++.h>
#define pii pair <int, int>
#define LL long long
#define ls rt << 1
#define rs rt << 1 | 1
#define pii pair <int, int>
#define xx first
#define yy second
using namespace std;

const int N = 100010;
int a[N], ll[N], rr[N], is[N], c[N];
int n, q;
pii b[N];

LL solve (int l, int r) {
    LL res = 0;
    for (int i = 1; i <= n; i++) ll[i] = rr[i] = i;
    memset (is, 0, sizeof is);
    for (int i = 1; i <= n; i++) {
        if (b[i].yy >= l && b[i].yy <= r) {
            int p = b[i].yy;
//            cout << p << ' ' << b[i].xx << ' ' << ll[p] << ' ' << rr[p] << endl;
            is[p] = 1;
            res += 1LL * b[i].xx * (rr[p] - p + 1) * (p - ll[p] + 1);
//            res -= a[p];
            if (!is[ll[p] - 1]) rr[ll[p] - 1] = rr[p];
            if (!is[rr[p] + 1]) ll[rr[p] + 1] = ll[p];
        }
    }
    return res;
}

int main () {
//    freopen ("in.txt", "r", stdin);
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        scanf ("%d", &a[i]);
        c[i] = a[i] - a[i - 1];
        if (i > 1) b[i - 1] = pii (abs(c[i]), i - 1);
    }
    sort (b + 1, b + n);
    while (q--) {
        int l, r;
        cin >> l >> r;
        cout << solve (l, r - 1) << endl;
    }
}