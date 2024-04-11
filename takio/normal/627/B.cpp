#include <bits/stdc++.h>
#define LL long long
#define pii pair <LL, LL>
#define xx first
#define yy second
#define ls rt << 1
#define rs rt << 1 | 1
#define lson ls, l, m
#define rson rs, m + 1, r
using namespace std;

const int N = 200010;

int tree[2][N], c[N];

int f (int x) {
    return x & -x;
}

void add (int k, int x, int c) {
    if (x == 0) return;
    for (int i = x; i < N; i += f (i)) tree[k][i] += c;
}

int qry (int k, int x) {
    int r = 0;
    for (int i = x; i; i -= f (i)) r += tree[k][i];
    return r;
}

int main () {
//    freopen ("in.txt", "r", stdin);
    int n, k, a, b, q, t, d, x;
    cin >> n >> k >> a >> b >> q;
    while (q--) {
        scanf("%d%d", &t, &d);
        if (t == 1) {
            scanf("%d", &x);
            if (c[d] < b) add (0, d, min (x, b - c[d]));
            if (c[d] < a) add (1, d, min (x, a - c[d]));
            c[d] += x;
        } else {
            printf ("%d\n", qry (0, d - 1) + qry (1, n) - qry (1, d + k - 1));
        }
    }
}