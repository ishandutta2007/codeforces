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

int was[1000][1000][4];
int g[1000][1000];
int w[1001][1001];
int use[1000][1000];
vi res;
int ct;

int get (int x1, int y1, int x2, int y2) {
    if (x1 > x2) swap (x1, x2);
    if (y1 > y2) swap (y1, y2);
    re w[x1][y1] - w[x2 + 1][y1] - w[x1][y2 + 1] + w[x2 + 1][y2 + 1];
}

int go (int x, int y, int k) {
    int cur = int (use[x][y] != ct);
    use[x][y] = ct;
    for (int t = 0; t < 4; t++) {
        int dx = int (t == 0) - int (t == 1);
        int dy = int (t == 2) - int (t == 3);
        int nx = x + dx * k, ny = y + dy * k;
        if (nx >= 0 && ny >= 0 && nx < n && ny < m && was[x][y][t] != ct && get (x, y, nx, ny) == k + 1) {
            was[x][y][t] = was[nx][ny][t ^ 1] = ct;
            cur += go (nx, ny, k) + k - 1;
        }
    }
    re cur;
}

int main () {
    scanf ("%d%d", &n, &m);
    int all = 0, ii = -1, jj = -1;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            scanf ("%d", &g[i][j]);
            if (g[i][j]) {
                all++;
                if (ii == -1) {
                    ii = i;
                    jj = j;
                }
            }
        }
    for (int i = n - 1; i >= 0; i--)
        for (int j = m - 1; j >= 0; j--)
            w[i][j] = g[i][j] + w[i + 1][j] + w[i][j + 1] - w[i + 1][j + 1];
    for (int k = 2; k < min (n, m); k++) {
        ct++;
        int x = -1, y = -1, c = -1, cnt = 0;
        for (int i = ii % k; i < n; i += k)
            for (int j = jj % k; j < n; j += k)
                if (g[i][j]) {
                    int tmp = 0;
                    for (int t = 0; t < 4; t++) {
                        int ni = i + int (t == 0) - int (t == 1);
                        int nj = j + int (t == 2) - int (t == 3);
                        if (ni >= 0 && nj >= 0 && ni < n && nj < m) tmp += g[ni][nj];
                    }
                    if (tmp & 1) {
                        cnt++;
                        x = i;
                        y = j;
                        c = 1;
                    } else
                    if (c == -1) {
                        x = i;
                        y = j;
                        c = 0;
                    }
                }
        int cur = go (x, y, k);
//      printf ("%d %d %d = %d | %d\n", k, x + 1, y + 1, cur, all);
        if (cur == all && cnt <= 2 && all > 1) res.pb (k);
    }
    if (res.empty ()) res.pb (-1);
    for (int i = 0; i < sz (res); i++)
        printf ("%d ", res[i]);
    printf ("\n");
    return 0;
}