#include <cstring>
#include <cstdio>
#include <cmath>
#include <queue>
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#define LL long long

using namespace std;

const int N = 100100;

int num[N], a[N], b[N], c[N];
vector <int> g[N];

void dfs (int u, int fa) {
    num[u] = 1;
    for (int i = 0; i < (int) g[u].size (); i++) {
        int v = g[u][i];
        if (v == fa) continue;
        dfs (v, u);
        num[u] += num[v];
    }
}

int main () {
//    freopen ("in.txt", "r", stdin);
    int n;
    cin >> n;
    for (int i = 1; i < n; i++) {
        scanf ("%d%d%d", &a[i], &b[i], &c[i]);
        g[b[i]].push_back (a[i]);
        g[a[i]].push_back (b[i]);
    }
    dfs (1, -1);
    double now = 0, all = 1.0 * n * (n - 1) * (n - 2) / 6;
//    for (int i = 1; i <= n; i++) cout << num[i] << ' ';
    int ta, tb;
    for (int i = 1; i < n; i++) {
        if (num[a[i]] < num[b[i]]) ta = num[a[i]];
        else ta = num[b[i]];
        tb = n - ta;
//        cout << a[i] << ' ' << b[i] << ' ' << ta << ' ' << tb << endl;
        now += 1.0 * ta * tb * (ta + tb - 2) * c[i] / all;
//        cout << now << endl;
    }
//    now /= n, now /= n - 1, now /= n - 2, now *= 6;
//    cout << now << endl;
    int x, y, q;
    cin >> q;
    while (q--) {
        scanf ("%d%d", &x, &y);
        int t = c[x] - y;
        if (num[a[x]] < num[b[x]]) ta = num[a[x]];
        else ta = num[b[x]];
        tb = n - ta;
        now -= 1.0 * ta * tb * (ta + tb - 2) * t / all;
        c[x] = y;
        printf ("%.10lf\n", now);
    }
}