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

const int N = 1100000;
const LL INF = 1LL << 60;

int a[N], l[N], r[N], c[N];

int main () {
//    freopen ("in.txt", "r", stdin);
    int n;
    cin >> n;
    int mx = 0;
    for (int i = 1; i <= n; i++) {
        int a;
        scanf ("%d", &a);
        if (l[a] == 0) l[a] = i;
        r[a] = i;
        c[a]++;
        mx = max (mx, c[a]);
    }
    int mn = 1e9, rl, rr;
    for (int i = 1; i < N; i++) if (c[i] == mx) {
        if (mn > r[i] - l[i] + 1) mn = r[i] - l[i] + 1, rl = l[i], rr = r[i];
    }
    cout << rl << ' ' << rr;
}