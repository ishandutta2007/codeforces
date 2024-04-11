#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

// #define endl '\n'
#define fi first
#define se second
#define For(i, l, r) for (auto i = (l); i < (r); i++)
#define ForE(i, l, r) for (auto i = (l); i <= (r); i++)
#define FordE(i, l, r) for (auto i = (l); i >= (r); i--)
#define Fora(v, a) for (auto v: (a))
#define bend(a) (a).begin(), (a).end()
#define isz(a) ((signed)(a).size())

using ll = long long;
using ld = long double;
using pii = pair <int, int>;
using vi = vector <int>;
using vpii = vector <pii>;
using vvi = vector <vi>;

const int N = 16 + 1;

int dig(int r, int c){
    cout << "DIG " << r << ' ' << c << endl;
    int ans; cin >> ans; return ans;
}

int scan(int r, int c){
    cout << "SCAN " << r << ' ' << c << endl;
    int ans; cin >> ans; return ans;
}

int n, m;

int scanned[N][N];

signed main(){
    // ios_base::sync_with_stdio(0);
    // cin.tie(0); cout.tie(0);
    // freopen("KEK.inp", "r", stdin);
    // freopen("KEK.out", "w", stdout);
int tests; cin >> tests; while (tests--){
    cin >> n >> m;

    memset(scanned, 0, sizeof(scanned));
    scanned[1][1] = scan(1, 1);
    scanned[n][m] = 2 * n + 2 * m - (scanned[1][1] + 4);
    scanned[1][m] = scan(1, m);
    scanned[n][1] = 2 * n - 2 - (scanned[1][m] - 2 * m + 2);
    int lx = 1, rx = n;
    if (scanned[1][1] > scanned[n][1]){
        lx += (scanned[1][1] - scanned[n][1]) / 2;
    }
    if (scanned[1][1] < scanned[n][1]){
        rx -= (scanned[n][1] - scanned[1][1]) / 2;
    }
    int x = (lx + rx) / 2;
    scanned[x][1] = scan(x, 1);
    int ly = 1, ry = m;
    if (scanned[1][1] > scanned[1][m]){
        ly += (scanned[1][1] - scanned[1][m]) / 2;
    }
    if (scanned[1][1] < scanned[1][m]){
        ry -= (scanned[1][m] - scanned[1][1]) / 2;
    }
    int y = (ly + ry) / 2;
    scanned[1][y] = scan(1, y);

    // cout << "RANGE " << lx << ' ' << rx << ' ' << ly << ' ' << ry << ' ' << x << ' ' << y << endl;
    int dx = (min(scanned[1][1], scanned[n][1]) - scanned[x][1]) / 2;
    lx += dx; rx -= dx;
    int dy = (min(scanned[1][1], scanned[1][m]) - scanned[1][y]) / 2;
    ly += dy; ry -= dy;
    // cout << dx << ' ' << dy << endl;
    if (dig(lx, ly)){
        dig(rx, ry);
    }
    else{
        dig(lx, ry);
        dig(rx, ly);
    }
}
}

/*
==================================================+
INPUT:                                            |
--------------------------------------------------|

--------------------------------------------------|
==================================================+
OUTPUT:                                           |
--------------------------------------------------|

--------------------------------------------------|
==================================================+
*/