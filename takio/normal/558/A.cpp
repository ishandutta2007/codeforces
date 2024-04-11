#include <bits/stdc++.h>
#define ls rt << 1
#define rs rt << 1 | 1
#define lson ls, l, m
#define rson rs, m + 1, r
#define pii pair <int, int>
#define LL long long
#define xx first
#define yy second
using namespace std;

const int N = 110;
const LL INF = 1LL << 60;

int a[N], n, x[N], now, d, vis[N];

int solve () {
    int r = 0;
    memset (vis, 0, sizeof vis);
    while (1) {
        int p = -1;
        for (int i = 1; i <= n; i++) {
            if (vis[i] == 0) {
                if (d == 0) {
                    if (x[i] < now && (p == -1 || x[p] < x[i])) p = i;
                } else {
                    if (x[i] > now && (p == -1 || x[p] > x[i])) p = i;
                }
            }
        }
//        cout << p << endl;
        if (p == -1) break;
        r += a[p];
        now = x[p];
        d ^= 1;
        vis[p] = 1;
    }
    return r;
}

int main () {
//    freopen ("in.txt", "r", stdin);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> x[i] >> a[i];
    }
    int r = 0;
    now = 0, d = 0;
    r = solve ();
    now = 0, d = 1;
    r = max (solve (), r);
    cout << r << endl;
}