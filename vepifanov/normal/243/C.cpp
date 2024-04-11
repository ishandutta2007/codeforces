#include <cstdio>
#include <numeric>
#include <iostream>
#include <vector>
#include <set>
#include <cstring>
#include <string>
#include <map>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <bitset>
#include <queue>
#include <sstream>
#include <deque>

using namespace std;

#define mp make_pair
#define pb push_back
#define rep(i,n) for(int i = 0; i < (n); i++)
#define re return
#define fi first
#define se second
#define sz(x) ((int) (x).size())
#define all(x) (x).begin(), (x).end()
#define sqr(x) ((x) * (x))
#define sqrt(x) sqrt(abs(x))
#define y0 y3487465
#define y1 y8687969
#define fill(x,y) memset(x,y,sizeof(x))
                         
typedef vector<int> vi;
typedef long long ll;
typedef long double ld;
typedef double D;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<string> vs;
typedef vector<vi> vvi;

template<class T> T abs(T x) { re x > 0 ? x : -x; }

int n;
int m;
pair<ii, ii> e[1000];
int g[2100][2100];
vii wx, wy;

int add (int x1, int y1, int x2, int y2) {
    if (x1 > x2) swap (x1, x2);
    if (y1 > y2) swap (y1, y2);
    e[m++] = mp (mp (x1, y1), mp (x2, y2));
    wx.pb (mp (x1, 1));
    wx.pb (mp (x2, 1));
    wy.pb (mp (y1, 1));
    wy.pb (mp (y2, 1));
    re 0;
}

int go (int x, int y) {
    if (x < 0 || y < 0 || x >= sz (wx) || y >= sz (wy) || g[x][y] != 0) re 0;
    g[x][y] = 2;
    go (x - 1, y);
    go (x + 1, y);
    go (x, y - 1);
    go (x, y + 1);
    re 0;
}

int main () {
    cin >> n;
    int x = 0, y = 0;
    for (int i = 0; i < n; i++) {
        string s;
        int d;
        cin >> s >> d;
        int dx = int (s == "R") - int (s == "L");
        int dy = int (s == "U") - int (s == "D");
        int nx = x + dx * d, ny = y + dy * d;
        add (x, y, nx, ny);
        x = nx;
        y = ny;
    }
    wx.pb (mp (-2e9, 0));
    wx.pb (mp (2e9, 0));
    wy.pb (mp (-2e9, 0));
    wy.pb (mp (2e9, 0));
    sort (all (wx));
    wx.resize (unique (all (wx)) - wx.begin ());
    sort (all (wy));
    wy.resize (unique (all (wy)) - wy.begin ());
    int tmp = sz (wx);
    for (int i = 0; i + 1 < tmp; i++)
        if (wx[i + 1].fi - wx[i].fi - 1 > 0)
            wx.pb (mp (wx[i].fi + 1, wx[i + 1].fi - wx[i].fi - 1));
    tmp = sz (wy);
    for (int i = 0; i + 1 < tmp; i++)
        if (wy[i + 1].fi - wy[i].fi - 1 > 0)
            wy.pb (mp (wy[i].fi + 1, wy[i + 1].fi - wy[i].fi - 1));
    sort (all (wx));
    sort (all (wy));
    for (int i = 0; i < n; i++) {
        int x1, y1, x2, y2;
        for (int j = 0; j < sz (wx); j++) {
            if (wx[j].fi == e[i].fi.fi)
                x1 = j;
            if (wx[j].fi == e[i].se.fi)
                x2 = j;
        }
        for (int j = 0; j < sz (wy); j++) {
            if (wy[j].fi == e[i].fi.se)
                y1 = j;
            if (wy[j].fi == e[i].se.se)
                y2 = j;
        }
        for (int a = x1; a <= x2; a++)
            for (int b = y1; b <= y2; b++)
                g[a][b] = 1;
    }
    go (0, 0);
    ll ans = 0;
    for (int i = 0; i < sz (wx); i++)
        for (int j = 0; j < sz (wy); j++)
            if (g[i][j] != 2)
                ans += (ll)wx[i].se * wy[j].se;
    cout << ans << endl;
    return 0;
}