#include <bits/stdc++.h>
#define LL long long
#define pii pair <int, int>
#define xx first
#define yy second
using namespace std;

const int N = 200100;
int res[N], fa[N], sz[N], vis[N];
pii a[N];

int getfa (int x) {
    int f = x;
    while (fa[f] != f) f = fa[f];
    while (x != f) {
        int t = fa[x];
        fa[x] = f;
        x = t;
    }
    return f;
}

int mx;

void link (int x, int y) {
    x = getfa (x), y = getfa (y);
    if (x == y) return;
    fa[y] = x;
    sz[x] += sz[y];
    mx = max (mx, sz[x]);
}

int main () {
//    freopen ("in.txt", "r", stdin);
    int n;
    cin >> n;
    for (int i =1; i <= n; i++) {
        scanf ("%d", &a[i].xx);
        a[i].yy = i;
    }
    sort (a + 1, a + 1 + n);
    for (int i = 1; i <= n; i++) fa[i] = i, sz[i] = 1;
    mx = 1;
    for (int i = n; i >= 1; i--) {
        int now = a[i].yy;
        if (now != 1 && vis[now - 1]) link (now - 1, now);
        if (now != n && vis[now + 1]) link (now, now + 1);
        vis[now] = 1;
        res[mx] = max (res[mx], a[i].xx);
    }
    for (int i = n - 1; i >= 1; i--) res[i] = max (res[i], res[i + 1]);
    for (int i = 1; i <= n; i++) printf ("%d ", res[i]);
}