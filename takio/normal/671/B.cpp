#include <bits/stdc++.h>
#define LL long long
using namespace std;

const int N = 500100;
int a[N], b[N];
int n, k;

LL cal1 (int m) {
    LL sum = 0;
    for (int i = 1; i <= n; i++) {
        if (a[i] < m) sum += m - a[i];
    }
    return sum;
}

LL cal2 (int m) {
    LL sum = 0;
    for (int i = 1; i <= n; i++) {
        if (a[i] > m) sum += a[i] - m;
    }
    return sum;
}

int main () {
//    freopen ("in.txt", "r", stdin);
    LL sum = 0;
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        sum += a[i];
    }
    sort (a + 1, a + 1 + n);
    int tmp = sum % n;
    for (int i = 1; i <= n; i++) {
        b[i] = sum / n;
        if (i >= n - tmp + 1) b[i]++;
    }
    LL sum1 = 0, sum2 = 0;
    for (int i = 1; i <= n; i++) {
        if (a[i] > b[i]) sum1 += a[i] - b[i];
        else sum2 += b[i] - a[i];
//        cout << a[i] << ' ' << b[i] << endl;
    }
//    cout << endl;
    if (max (sum1, sum2) <= k) cout << ((tmp == 0) ? 0 : 1) << endl;
    else {
        int res = 0;
        LL l = a[1], r = b[1] + 1;
        while (l + 1 < r) {
            int m = l + r >> 1;
            if (cal1 (m) <= k) l = m;
            else r = m;
        }
//        cout << l << endl;
        res = -l;
        l = b[n] - 1, r = a[n];
        while (l + 1 < r) {
            int m = l + r >> 1;
            if (cal2 (m) <= k) r = m;
            else l = m;
        }
//        cout << r << endl;
        res += r;
        cout << res << endl;
    }
}