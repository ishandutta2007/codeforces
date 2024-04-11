#include <cstring>
#include <vector>
#include <map>
#include <set>
#include <stack>
#include <bitset>
#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#define ls rt << 1
#define rs rt << 1 | 1
#define lson ls, l, m
#define rson rs, m + 1, r
#define getm int m = (l + r) >> 1
#define LL long long
#define pii pair <int, int>

using namespace std;

const int N = 1010;
int vis[N], x[N], y[N];

int main () {
//    freopen ("in.txt", "r", stdin);
    int n, x0, y0;
    cin >> n >> x0 >> y0;
    for (int i = 1; i <= n; i++) {
        cin >> x[i] >> y[i];
    }
    memset (vis, 0, sizeof vis);
    int res = 0;
    for (int i = 1; i <= n; i++) if (!vis[i]) {
        res++;
        for (int j = i; j <= n; j++) {
            if ((x0 - x[i]) * (y0 - y[j]) == (x0 - x[j]) * (y0 - y[i])) vis[j] = 1;
        }
    }
    cout << res << endl;
}