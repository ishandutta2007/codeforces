#include <bits/stdc++.h>
#define LL long long
#define LD long double
#define pii pair <LL, LL>
#define xx first
#define yy second
using namespace std;

//const int N = 100010, L = 12;

//vector <pii> res;
map <pii, pii> mp;
int flag, lim, n;
int a[30], b[30], c[30];

void dfs1 (int k, int x, int y, int z, LL st) {
    if (k > lim) {
//        cout << "ins "  << x << ' ' << y << ' ' << z << ' ' << x - y <<' ' << x - z << ' ' << st << endl;
        if (mp.find (pii (x - y, x - z)) == mp.end()) mp[pii (x - y, x - z)] = pii (x, st);
        else mp[pii (x - y, x - z)] = max (mp[pii (x - y, x - z)], pii (x, st));
        return;
    }
    dfs1 (k + 1, x + a[k], y + b[k], z, st * 3);
    dfs1 (k + 1, x + a[k], y, z + c[k], st * 3 + 1);
    dfs1 (k + 1, x, y + b[k], z + c[k], st * 3 + 2);
}

pii res;
LL f;

void dfs2 (int k, int x, int y, int z, LL st) {
    if (k > n) {
//        cout << "qry "  << x << ' ' << y << ' ' << z << ' ' << x - y <<' ' << x - z << ' ' << st << endl;
        if (mp.find (pii (-(x - y), -(x - z))) != mp.end()) {
            pii t = mp[pii (-(x - y), -(x - z))];
            if (res.yy == -1 || res.xx < x + t.xx) res = pii (x + t.xx, t.yy * f + st);
        }
        return;
    }
    dfs2 (k + 1, x + a[k], y + b[k], z, st * 3);
    dfs2 (k + 1, x + a[k], y, z + c[k], st * 3 + 1);
    dfs2 (k + 1, x, y + b[k], z + c[k], st * 3 + 2);
}

int main () {
//    freopen ("in.txt", "r", stdin);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        scanf ("%d%d%d", &a[i], &b[i], &c[i]);
    }
    lim = (n + 1) / 2;
//    cout << lim << endl;
    res.yy = -1;
    f = 1;
    for (int i = 1; i <= n - lim; i++) f *= 3;
//    cout << f << endl;
    dfs1 (1, 0, 0, 0, 0);
    dfs2 (lim + 1, 0, 0, 0, 0);
    if (res.yy == -1) cout << "Impossible\n";
    else {
        LL st = res.yy;
        vector <string> r;
        for (int i = 1; i <= n; i++) {
            int t = st % 3;
            if (t == 0) r.push_back("LM");
            if (t == 1) r.push_back("LW");
            if (t == 2) r.push_back("MW");
            st /= 3;
        }
        for (int i = n - 1; i >= 0; i--) cout << r[i] << endl;
    }
}