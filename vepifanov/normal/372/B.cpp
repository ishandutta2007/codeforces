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
int q;
int g[41][41];
int w[41][41];
int u[41][41][41][41];
int res[41][41][41][41];
char h[100];

int main () {
    scanf ("%d%d%d", &n, &m, &q);
    for (int i = 0; i < n; i++) {
        scanf (" %s", h);
        for (int j = 0; j < m; j++)
            g[i][j] = h[j] - '0';
    }
    for (int i = n - 1; i >= 0; i--)
        for (int j = m - 1; j >= 0; j--) {
            w[i][j] = w[i + 1][j] + w[i][j + 1] - w[i + 1][j + 1] + g[i][j];
            for (int a = i; a < n; a++)
                for (int b = j; b < m; b++) {
                    int tmp = w[i][j] - w[a + 1][j] - w[i][b + 1] + w[a + 1][b + 1];
                    u[i][j][a][b] = int (tmp == 0);
                    if (a > i) u[i][j][a][b] += u[i][j][a - 1][b];
                    if (b > j) u[i][j][a][b] += u[i][j][a][b - 1];
                    if (a > i && b > j) u[i][j][a][b] -= u[i][j][a - 1][b - 1];
                    res[i][j][a][b] = u[i][j][a][b] + res[i + 1][j][a][b] + res[i][j + 1][a][b] - res[i + 1][j + 1][a][b];
                }
        }
    for (int i = 0; i < q; i++) {
        int a, b, c, d;
        scanf ("%d%d%d%d", &a, &b, &c, &d); a--; b--; c--; d--;
        printf ("%d\n", res[a][b][c][d]);
    }
    return 0;
}