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

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, -1, 0, 1};

int n, k;
int m;

int was[50][50][4][4];
char w[51][51];

int main () {
    scanf ("%d%d", &n, &m);
    gets (w[0]);
    for (int i = 0; i < n; i++) gets (w[i]);
    k = strlen (w[0]);
    int x = 0, y = 0, dp = 3, cp = 2, ok = 0;
    for (int i = 0; i < m; i++) {
        if (was[x][y][dp][cp] != 0 && !ok) {
            int pper = was[x][y][dp][cp] - 1;
            int per = i - was[x][y][dp][cp] + 1;
            m = (m - pper) % per + pper;
            while (m <= i) m += per;
            ok = 1;
        }
        was[x][y][dp][cp] = i + 1;
        int nx = x, ny = y;
        while (true) {
            int mx = nx + dx[dp], my = ny + dy[dp];
            if (mx >= 0 && my >= 0 && mx < n && my < k && w[mx][my] == w[x][y]) {
                nx = mx;
                ny = my;
            } else break;
        }
        while (true) {
            int mx = nx + dx[cp], my = ny + dy[cp];
            if (mx >= 0 && my >= 0 && mx < n && my < k && w[mx][my] == w[x][y]) {
                nx = mx;
                ny = my;
            } else break;
        }
        nx += dx[dp];
        ny += dy[dp];
        if (nx >= 0 && ny >= 0 && nx < n && ny < k && w[nx][ny] != '0') {
            x = nx;
            y = ny;
        } else {
            if (cp == (dp + 3) % 4) cp = (dp + 1) % 4; else {
                cp = dp;
                dp = (dp + 1) % 4;
            }
        }
    }
    printf ("%c\n", w[x][y]);
    return 0;
}