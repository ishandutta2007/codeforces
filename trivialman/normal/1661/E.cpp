#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define rrep(i, a, b) for (int i = (a); i >= (b); --i)
#define PB push_back
#define ar2 array<int, 2>
#define ar3 array<int, 3>
typedef long long LL;
const LL P = 998244353;
const int INF = 1e9 + 1;
const int N = (1 << 20) + 5;
mt19937 rng(time(0));

struct dat {
    int num;
    char maskl, maskr, nl, nr;
    bool twoline;
    const dat operator+(dat y) {
        dat res;
        res.maskl = maskl, res.maskr = y.maskr;
        res.num = num + y.num;
        res.nl = nl, res.nr = y.nr;
        res.twoline = twoline && y.twoline;
        if (maskr + y.maskl != (maskr | y.maskl)) {
            bool f1 = maskr == 7 || maskr == 5, f2 = y.maskl == 7 || y.maskl == 5;
            res.num -= (nr == 2 && y.nl == 2 || nr == 2 && f2 || y.nl == 2 && f1) ? 2 : 1;
            res.nl = (nl == 1 || twoline && (y.maskl == 7 || y.maskl == 5 && y.nl == 1)) ? 1 : 2;
            res.nr = (y.nr == 1 || y.twoline && (maskr == 7 || maskr == 5 && nr == 1)) ? 1 : 2;
        }
        return res;
    }
} tr[N];
int n, q, l, r;
char s[N >> 1], a[N >> 1];

void build(int l, int r, int i = 1) {
    if (l == r) {
        int num = a[l] == 0 ? 0 : (a[l] == 5 ? 2 : 1);
        tr[i] = {num, a[l], a[l], num, num, a[l] == 5};
        return;
    }
    int m = l + r >> 1;
    build(l, m, i << 1), build(m + 1, r, i << 1 | 1);
    tr[i] = tr[i << 1] + tr[i << 1 | 1];
}

dat query(int l, int r, int l1 = 1, int r1 = n, int i = 1) {
    if (l1 >= l && r1 <= r)
        return tr[i];
    int m = l1 + r1 >> 1;
    dat xl, xr;
    xl = m >= l ? query(l, r, l1, m, i << 1) : (dat){0, 0, 0, 0, 0, 0};
    xr = m + 1 <= r ? query(l, r, m + 1, r1, i << 1 | 1) : (dat){0, 0, 0, 0, 0, 0};
    return xl + xr;
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> n;
    rep(_, 1, 3) {
        cin >> (s + 1);
        rep(i, 1, n) a[i] = a[i] * 2 + s[i] - '0';
    }
    build(1, n);
    cin >> q;
    while (q--) {
        cin >> l >> r;
        cout << query(l, r).num << "\n";
    }
    return 0;
}