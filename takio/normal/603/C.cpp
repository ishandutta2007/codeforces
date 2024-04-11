#include <bits/stdc++.h>
#define LL long long
#define ls rt << 1
#define rs rt << 1 | 1
#define lson ls, l, m
#define rson rs, m + 1, r
#define pii pair <LL, int>
#define xx first
#define yy second
using namespace std;

const int N = 100100;

int sg[N], vis[5];
int n, k;

int solve (int x) {
    if (x == 0) return 0;
    if (x == 1) return 1;
    if (x >= 5 && x % 2 == 1) {
        return 0;
    }
//    if (x % 2 == 1) return
    int vis[5], res = 0;
    memset (vis, 0, sizeof vis);
    vis[solve (x - 1)] = 1;
    if (x % 2 == 0) {
        if (k % 2 == 0) vis[0] = 1;
        else vis[solve (x / 2)] = 1;
    }
    while (vis[res]) res++;
    return res;
//    if (x % 2 == 0)
}

int main () {
//    freopen ("in.txt", "r", stdin);
    cin >> n >> k;
//    sg[0] = 0;
//    for (int i = 1; i <= 100; i++) {
//        memset (vis, 0, sizeof vis);
//        vis[sg[i - 1]] = 1;
//        if (i % 2 == 0) {
//            if (k % 2 == 0) vis[0] = 1;
//            else vis[sg[i / 2]] = 1;
//        }
//        while (vis[sg[i]]) sg[i]++;
//    }
//    for (int i = 1; i <= 100; i++) {
//        cout << sg[i] <<' ';
////         << solve (i); cout << endl;
//    }
//    return 0;
    int res = 0, a;
    for (int i = 1; i <= n; i++) {
        scanf ("%d", &a);
//        cout << a << ' ' << solve (a) <<endl;
        res ^= solve (a);
    }
//    cout << res << endl;
    if (res) printf ("Kevin\n");
    else printf ("Nicky\n");
}