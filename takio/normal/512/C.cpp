#include <cstdio>
#include <queue>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <map>
#define LL long long
#define pii pair <int, int>
using namespace std;

const int N = 210;
int mp[N][N];
int g[N], d[N], p[N], c[N], a[N];
int ish[20010];
int sap (int s, int t, int all) {
    memset (c, 0, sizeof c);
    memset (d, 0, sizeof d);
    memset (g, 0, sizeof g);
    int u = p[s] = s, mx = 0, aug = -1;
    g[0] = all;
    while (d[s] < all) {
        loop:
            for (int  v = c[u]; v < all; v++) {
                if (mp[u][v] && d[u] == d[v] + 1) {
                    if (aug == -1 || aug > mp[u][v] ) aug = mp[u][v];
                    p[v] = u;
                    u = c[u] = v;
                    if (v == t) {
                        mx += aug;
                        for (u = p[u]; v != s; v = u, u = p[u]) {
                            mp[u][v] -= aug;
                            mp[v][u] += aug;
                        }
                        aug = -1;
                    }
                    goto loop;
                }
            }
            int m = all - 1;
            for (int v = 0; v < all; v++)
                if (mp[u][v] && m > d[v]) {
                    c[u] = v;
                    m = d[v];
                }
            if ((--g[d[u]]) == 0) break;
            g[d[u] = m + 1]++;
            u = p[u];
    }
    return mx;
}

vector <int> g2[N], res[N];
int vis[N];

int main () {
//    freopen ("in.txt", "r", stdin);
    int n;
    cin >> n;
    for (int i = 2; i <= 20000; i++) if (!ish[i] && i <= 10000) {
        for (int j = i * i; j <= 20000; j += i) ish[j] = 1;
    }
    int s = 0, t = n + 1;
    for (int i = 1; i <= n; i++) {
        scanf ("%d", &a[i]);
        if (a[i] & 1) mp[s][i] = 2;
        else mp[i][t] = 2;
    }
    for (int i = 1; i <= n; i++) if (a[i] & 1) {
        for (int j = 1; j <= n; j++) if ((a[j] & 1) == 0){
            if (!ish [a[i] + a[j]]) {
//                cout << i << ' ' << j << endl;
                mp[i][j] = 1;
            }
        }
    }
    int mx = sap (s, t, t + 1);
    if (mx != n) {
        cout << "Impossible";
        return 0;
    }
    for (int i = 1; i <= n; i++) if (a[i] & 1) {
        for (int j = 1; j <= n; j++) if ((a[j] & 1) == 0){
            if (!ish [a[i] + a[j]] && mp[i][j] == 0) {
//                cout << i << ' ' << j << endl;
                g2[i].push_back (j);
                g2[j].push_back (i);
            }
        }
    }
    int rn = 0;
    for (int i = 1; i <= n; i++) if (!vis[i]) {
        int u = i, p = 0;
        rn++;
        while (!p || u != i) {
            vis[u] = 1;
            for (int j = 0; j < (int) g2[u].size (); j++) {
                if (g2[u][j] != p) {
                    res[rn].push_back (g2[u][j]);
                    p = u;
                    u = g2[u][j];
                    break;
                }
            }
        }
    }
    cout << rn << endl;
    for (int i = 1; i <= rn; i++) {
        cout << (int) res[i].size ();
        for (int j = 0; j < (int) res[i].size (); j++)
            cout << ' ' << res[i][j];
        cout << endl;
    }
}