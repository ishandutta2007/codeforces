#include <cstdio>
#include <stack>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#include <map>
#include <iostream>
#include <cmath>
#include <queue>
#define LL long long
#define ls rt << 1
#define rs rt << 1 | 1
#define lson ls, l, m
#define rson rs, m + 1, r
using namespace std;

const int N = 200100;

struct segment {
    int mx[N << 2];

    void build () {
        memset (mx, 0, sizeof mx);
    }

    void update (int rt, int l, int r, int x, int c) {
//        cout << l << ' ' << r << endl;
        if (l == r) {
            mx[rt] = max (mx[rt], c);
//            cout << c << endl;
            return;
        }
        int m = (l + r) >> 1;
        if (x <= m) update (lson, x, c);
        else update (rson, x, c);
        mx[rt] = max (mx[ls], mx[rs]);
    }

    int query (int rt, int l, int r, int tl, int tr) {
//        cout << l << ' ' << r << ' ' << tl <<' ' <<tr << endl;
        if (tl <= l && r <= tr) {
            return mx[rt];
        }
        int m = (l + r) >> 1;
        if (tr <= m) return query (lson, tl, tr);
        if (m < tl) return query (rson, tl, tr);
        return max (query (lson, tl, m), query (rson, m + 1, tr));
    }
} sg;

int n, mx;
int a[2][N], res[2][N], cnt[N], ans[N];

void solve (int k) {
    sg.build ();
    for (int i = 1; i <= n; i++) {
        if (a[k][i] == 1) res[k][i] = 1;
        else res[k][i] = sg.query (1, 1, 1e5, 1, a[k][i] - 1) + 1;
//        if (a[k][i] != 1) cout << i << ' ' << a[k][i] << ' ' << sg.query (1, 1, n, 1, a[k][i] - 1) << endl;
//        cout << res[k][i] << endl;
        sg.update (1, 1, 1e5, a[k][i], res[k][i]);
        mx = max (mx, res[k][i]);
    }
}

int main () {
//    freopen ("in.txt", "r", stdin);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        scanf ("%d", &a[0][i]);
        a[1][n - i + 1] = 1e5 - a[0][i] + 1;
    }
//    for (int i = 1; i <= n; i++) cout << a[1][i] << endl;
//    cout << n << endl;
    solve (1);
//    cout << n << endl;
    solve (0);
//    cout << n << endl;
    for (int i = 1; i <= n; i++) {
        if (res[0][i] + res[1][n - i + 1] - 1 == mx) cnt[res[0][i]]++, ans[i]++;
//        cout << res[0][i] <<  ' ' << res[1][i] << endl;
    }
    for (int i = 1; i <= n; i++) {
        if (ans[i] && cnt[res[0][i]] > 1) ans[i]++;
        if (ans[i] >= 1) ans[i] = 3 - ans[i];
        printf ("%d", ans[i] + 1);
    }
}