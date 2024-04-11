#include <bits/stdc++.h>
using namespace std;

#define nl "\n"
#define nf endl
#define ll long long
#define pb push_back
#define _ << ' ' <<

#define INF (int)1e9
#define mod 998244353
#define maxn 200010
#define sq 450 // change it

int i, i1, j, k, k1, t, n, m, res, flag[10], a, b;
int x[maxn], y[maxn], cr[maxn], ar[maxn], cn[maxn];
int df[maxn], ddf[sq + 5][maxn];

void upd(int l, int r, int x, int y) {
    // cout << "upd" _ l _ r _ x _ y << nl;
    int i, z;
    if (x + y > sq) {
        z = r; r = l + (x + y) * ((r - l) / (x + y)) + x + y - 1;
        for (i = z + 1; i <= min(r - y, m); i += m) {
            if (i <= m) df[i]--;
            if (r - y + 1 <= m) df[r - y + 1]++;
        }
        for (i = l; i <= min(r, m); i += (x + y)) df[i]++;
        for (i = l + x; i <= min(r, m); i += (x + y)) df[i]--;
    } else {
        z = r; r = l + (x + y) * ((r - l) / (x + y)) + x + y - 1;
        for (i = z + 1; i <= min(r - y, m); i++) ar[i]--;
        if (l <= m) ddf[x + y][l]++;
        if (l + x <= m) ddf[x + y][l + x]--;
        if (r + 1 <= m) ddf[x + y][r + 1]--;
        if (r + x + 1 <= m) ddf[x + y][r + x + 1]++;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    #if !ONLINE_JUDGE && !EVAL
        ifstream cin("input.txt");
        ofstream cout("output.txt");
    #endif

    cin >> n >> m;
    for (i = 1; i <= n; i++) {
        cin >> x[i] >> y[i];
    }

    for (i = 1; i <= m; i++) {
        cin >> a >> b;
        if (a == 1) {
            cr[b] = i; cn[i] = cn[i - 1] + 1;
        } else {
            cn[i] = cn[i - 1] - 1;
            upd(cr[b], i - 1, x[b], y[b]); cr[b] = 0;
        }
    }

    for (i = 1; i <= n; i++) {
        if (cr[i] == 0) continue;
        upd(cr[i], m, x[i], y[i]);
    }

    // for (i = 1; i <= m; i++) cout << ar[i] _ df[i] << nl;

    for (i = 1; i <= m; i++) {
        df[i] += df[i - 1]; ar[i] += df[i];
    }

    /* for (i = 1; i <= sq; i++) {
        for (j = 1; j <= m; j++) {
            cout << ddf[i][j] << ' ';
        }
        cout << nl;
    } */

    for (i = 1; i <= sq; i++) {
        for (j = i; j <= m; j++) {
            ddf[i][j] += ddf[i][j - i];
        }
    }

    /* for (i = 1; i <= sq; i++) {
        for (j = 1; j <= m; j++) {
            cout << ddf[i][j] << ' ';
        }
        cout << nl;
    } */

    for (i = 1; i <= sq; i++) {
        for (j = 1; j <= m; j++) {
            ddf[i][j] += ddf[i][j - 1]; ar[j] += ddf[i][j];
        }
    }

    for (i = 1; i <= m; i++) cout << cn[i] - ar[i] << nl;

    return 0;
}