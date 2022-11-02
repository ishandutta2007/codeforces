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

const int N = 100005;
const LL INF = 1LL << 60;

LL l[N], r[N];
int ans[N], t[N];

bool cmp1 (int a, int b) {
    if (l[a] == l[b]) return r[a] < r[b];
    return l[a] < l[b];
}

bool cmp2 (int a, int b) {
    if (r[a] == r[b]) return l[a] > l[b];
    return l[a] > l[b];
}

int solve () {
    int h, q;
    cin >> h >> q;
    LL mn = 1, mx;
    for (int i = 1; i < h; i++) mn = 2 * mn;
    mx = mn * 2 - 1;
//    cout << mn << ' ' << mx << endl;
    for (int i = 1; i <= q; i++) {
        int t;
        scanf ("%d%I64d%I64d%d", &t, &l[i], &r[i], &ans[i]);
        t = h - t;
        while (t--) {
            l[i] = 2 * l[i];
            r[i] = 2 * r[i] + 1;
        }
//        cout << l[i] << ' ' << r[i] << ' ' << ans[i] << endl;
//        cout << l[i] << ' ' << r[i] << endl;
        if (ans[i] == 1) {
            mn = max (mn, l[i]);
            mx = min (mx, r[i]);
        }
    }
//    cout << mn << ' ' << mx << endl;
    if (mx < mn) {
        return 2;
    }
    for (int i = 1; i <= q; i++) t[i] = i;
    sort (t + 1, t + 1 + q, cmp1);
    for (int i = 1; i <= q; i++) if (ans[t[i]] == 0) {
        if (l[t[i]] <= mn) {
            if (r[t[i]] >= mx) return 2;
            if (r[t[i]] >= mn) mn = r[t[i]] + 1;
            continue;
        }
//        cout << i << ' ' << mn << ' ' << mx << endl;
    }
    for (int i = 1; i <= q; i++) t[i] = i;
    sort (t + 1, t + 1 + q, cmp2);
    for (int i = 1; i <= q; i++) if (ans[t[i]] == 0) {
        if (r[t[i]] >= mx) {
            if (l[t[i]] <= mn) return 2;
            if (l[t[i]] <= mx) mx = l[t[i]] - 1;
            continue;
        }
//        cout << i << ' ' << mn << ' ' << mx << endl;
    }
//    cout << mn << ' ' << mx << endl;
    LL ll = mn, rr = mx;
    for (int i = 1; i <= q; i++) t[i] = i;
    sort (t + 1, t + 1 + q, cmp1);
    for (int i = 1; i <= q; i++) if (ans[t[i]] == 0 && mn < l[t[i]] && r[t[i]] < mx) {
        LL tl = l[t[i]], tr = r[t[i]];
        if (tl <= ll) ll = max (tr + 1, ll);
        else break;
    }
    for (int i = 1; i <= q; i++) t[i] = i;
    sort (t + 1, t + 1 + q, cmp2);
    for (int i = 1; i <= q; i++) if (ans[t[i]] == 0 && mn < l[t[i]] && r[t[i]] < mx) {
        LL tl = l[t[i]], tr = r[t[i]];
//        cout << tl << ' ' << tr <<endl;
        if (tr >= rr) rr = min (tl - 1, rr);
        else break;
    }
//    cout << ll << ' ' << rr << endl;
    if (ll == rr) {
        cout << ll;
        return 0;
    } else if (ll < rr) return 1;
    return 2;
}

int main () {
//    freopen ("in.txt", "r", stdin);
    int ans = solve ();
    if (ans == 1) {
        cout << "Data not sufficient!";
    } else if (ans == 2) {
        cout << "Game cheated!";
    }
}