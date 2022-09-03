#include <cstdio>
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

using namespace std;

#define mp make_pair
#define pb push_back
#define rep(i,n) for(int i = 0; i < n; i++)
#define re return
#define fi first
#define se second
#define sz(x) ((int) (x).size())
#define all(x) (x).begin(), (x).end()
#define sqr(x) ((x) * (x))
#define y0 y3487465
#define y1 y8687969
#define pi 3.141592653589
#define sqrt(x) sqrt(abs(x))

typedef vector<int> vi;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<string> vs;
typedef vector<vi> vvi;

template<class T> T abs(T x) {
        re x > 0 ? x : -x;
}


int n;
int m, k;
int w[2001][2001];
int f[4001][4001];

int add (int i, int j, int k) {
        int x = i + j - 1;
        int y = i - j + m;
        for (int xx = x; xx <= n + m - 1; xx |= xx + 1)
                for (int yy = y; yy <= n + m - 1; yy |= yy + 1)
                        f[xx][yy] += k;
        re 0;
}

int get (int i, int j) {
        int x = min (i - 1, n + m - 1);
        int y = min (j + m, n + m - 1);
        int s = 0;
        for (int xx = x; xx > 0; xx = (xx & (xx + 1)) - 1)
                for (int yy = y; yy > 0; yy = (yy & (yy + 1)) - 1)
                        s += f[xx][yy];
        re s;
}

int get (int i1, int j1, int i2, int j2) {
        re get (i2, j2) - get (i1 - 1, j2) - get (i2, j1 - 1) + get (i1 - 1, j1 - 1);
}

int can (int x, int y, int h) {
        re get (x + y - h, x - y - h, x + y + h, x - y + h);
}

int main() {
        scanf ("%d%d%d", &n, &m, &k);
        for (int i = 1; i <= n; i++)
                for (int j = 1; j <= m; j++)
                        add (i, j, 1);
        for (int i = 0; i < k; i++) {
                int x, y;
                scanf ("%d%d", &x, &y);
                int l = -1, r = n + m;
                while (r - l > 1) {
                        int s = (l + r) / 2;
                        if (can (x, y, s)) r = s; else l = s;
                }
                int rx = n + 1, ry = m + 1;
                for (int tt = 0; tt < 4; tt++) {
                        int tx = int (tt == 0) - int (tt == 1);
                        int ty = int (tt == 2) - int (tt == 3);
                        int dx = -int (tt == 0 || tt == 3) + int (tt == 1 || tt == 2);
                        int dy = -int (tt == 0 || tt == 2) + int (tt == 1 || tt == 3);
                        for (int t = 0; t <= r; t++) {
                                int xx = x + tx * r + dx * t;
                                int yy = y + ty * r + dy * t;
                                if (xx >= 1 && xx <= n && yy >= 1 && yy <= m && !w[xx][yy])
                                        if (xx < rx || xx == rx && yy < ry) {
                                                rx = xx;
                                                ry = yy;
                                        }
                        }
                }
                printf ("%d %d\n", rx, ry);
                add (rx, ry, -1);
                w[rx][ry] = 1;
        }
        return 0;
}