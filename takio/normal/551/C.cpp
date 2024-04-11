#include <bits/stdc++.h>
#define LL long long
#define pii pair <int, int>
#define xx first
#define yy second
#define ls rt << 1
#define rs rt << 1 | 1
#define lson ls, l, m
#define rson rs, m + 1, r

using namespace std;

const int N = 100100;
int a[N], b[N], c[N];
int n, m;

int jug (LL x) {
    int now = n;
    while (now > 0 && a[now] == 0) now--;
    if (now == 0) return 1;
    if (x <= now) return 0;
    for (int i = 1; i <= n; i++) b[i] = a[i];
    for (int i = 1; i <= m; i++) {
        LL t = x - now;
        while (1) {
            if (t <= b[now]) {
                b[now] -= t;
                break;
            } else {
                t -= b[now];
                b[now] = 0;
            }
            while (now > 0 && b[now] == 0) now--;
            if (now == 0) return 1;
        }
        while (now > 0 && b[now] == 0) now--;
        if (now == 0) return 1;
    }
    return now == 0;
}

int main () {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) scanf ("%d", &a[i]);
    LL l = -1, r = 1LL << 60;
//    cout << jug(4) << endl;
    while (l + 1 < r) {
        LL m = (l + r) >> 1;
        if (jug (m)) r = m;
        else l = m;
    }
    cout << r << endl;
}