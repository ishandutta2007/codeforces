#include <bits/stdc++.h>
#define LL long long
#define ls rt << 1
#define rs rt << 1 | 1
#define lson ls, l, m
#define rson rs, m + 1, r
#define pii pair <int, int>
#define xx first
#define yy second
using namespace std;

const int N = 100100;

int a[N];
LL dp[N];
pii mx[N << 2];

void build (int rt, int l, int r) {
    if (l == r) { mx[rt] = pii (a[l], l); return; }
    int m = l + r >> 1;
    build (lson);
    build (rson);
    mx[rt] = max (mx[ls], mx[rs]);
}

pii query (int rt, int l, int r, int tl, int tr) {
    if (tl <= l && r <= tr)  return mx[rt];
    int m = l + r >> 1;
    if (tr <= m) return query (lson, tl, tr);
    else if (m < tl) return query (rson, tl, tr);
    else return max (query (lson, tl, m), query (rson, m + 1, tr));
}

int main () {
//    freopen ("in.txt", "r", stdin);
    int n;
    cin >> n;
    dp[n] = 0;
    for (int i = 1; i < n; i++) {
        scanf ("%d", &a[i]);
    }
    build (1, 1, n);
    LL res = 0;
    for (int i = n - 1; i >= 1; i--) {
        pii tmp = query (1, 1, n, i + 1, a[i]);
        dp[i] = n - i + dp[tmp.yy] - (a[i] - tmp.yy);
        res += dp[i];
    }
    cout << res << endl;
}