#include <bits/stdc++.h>
#define LL long long
#define pii pair <LL, LL>
#define xx first
#define yy second
#define ULL unsigned long long
using namespace std;

const int N = 200020, mod = 1e9 + 7;

//pii solve1 ()

int a[N];
LL sum[N];

LL cal (int x, int m, int n) {
    return sum[x] - sum[x - m - 1] + sum[n] - sum[n - m];
}

int main () {
//    freopen ("in.txt", "r", stdin);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) scanf ("%d", &a[i]);
    sort (a + 1, a + 1 + n);
    pii res = pii (0, 1);
    pii pos = pii (0, 1);
//    int t = 0;
    for (int i = 1; i <= n; i++) sum[i] = sum[i - 1] + a[i];
    for (int i = 1; i <= n; i++) {
        int l = 0, r = min (n - i, i - 1);
        while (l < r) {
            int mid1 = (2 * l + r) / 3;
            int mid2 = (l + 2 * r + 2) / 3;
            if (cal (i, mid1, n) * (2 * mid2 + 1) >= cal (i, mid2, n) * (2 * mid1 + 1)) r = mid2 - 1;
            else l = mid1 + 1;
        }
        pii tmp = pii (cal (i, l, n), 2 * l + 1);
        tmp.xx -= 1LL * a[i] * tmp.yy;
        if (tmp.xx * res.yy > tmp.yy * res.xx) {
            res = tmp;
            pos = pii (l, i);
        }
    }
    cout << pos.xx * 2 + 1 << endl;
    for (int i = pos.yy - pos.xx; i <= pos.yy; i++) {
        printf ("%d ", a[i]);
    }
    for (int i = n - pos.xx + 1; i <= n; i++) {
        printf ("%d ", a[i]);
    }
}