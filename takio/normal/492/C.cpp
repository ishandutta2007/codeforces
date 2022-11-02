#include<stdio.h>
#include <iostream>
#include <algorithm>
#define LL long long
using namespace std;
struct data {
    int a, b;
}a[100100];

bool cmp (data a, data b) {
    return a.b < b.b;
}

int main () {
//    freopen ("in.txt", "r", stdin);
    LL avg, now = 0, res = 0, n, r;
    cin >> n >> r >> avg;
    avg *= n;
    for (int i = 1; i <= n; i++) {
        scanf ("%d%d", &a[i].a, &a[i].b);
        now += a[i].a;
    }
    if (now >= avg) {
        cout << 0; return 0;
    }
    sort (a + 1, a + 1 + n, cmp);
//    for (int i = 1; i <= n; i++) {
//        cout << a[i].a << ' ' <<  a[i].b << endl;
//    }
    int i;
    for (i = 1; i <= n; i++) {
        if (now + r - a[i].a >= avg) break;
        now += r - a[i].a;
        res += (r - a[i].a) * a[i].b;
    }
//    cout << now << ' ' << avg << ' ' << i << endl;
    LL f = 0, e = r - a[i].a;
    while (f + 1 < e) {
        LL m = (f + e) >> 1;
        if (now + m >= avg) e = m;
        else f = m;
    }
    cout << res + e * a[i].b;
}