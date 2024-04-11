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

int w[501][501];
int g[501][501];
int res[501][501][2];

int sum (int i, int j, int di, int dj) {
    re w[i][j] - w[i + di][j] - w[i][j + dj] + w[i + di][j + dj];
}

int main () {
    scanf ("%d%d", &n, &m);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            scanf ("%d", &g[i][j]);
    for (int i = n - 1; i >= 0; i--)
        for (int j = m - 1; j >= 0; j--)
            w[i][j] = g[i][j] + w[i + 1][j] + w[i][j + 1] - w[i + 1][j + 1];
    int ans = -2e9;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            res[i][j][0] = g[i][j];
    for (int k = 5; k <= min (n, m); k += 4) {
        int ci = (k / 4) & 1;
        int pi = 1 - ci;
        for (int i = 0; i + k <= n; i++)
            for (int j = 0; j + k <= m; j++) {
                res[i][j][ci] = sum (i, j, 1, k) + sum (i + 1, j + k - 1, k - 1, 1) + sum (i + k - 1, j, 1, k - 1) + sum (i + 2, j, k - 3, 1) + g[i + 2][j + 1] + res[i + 2][j + 2][pi];
                ans = max (ans, res[i][j][ci]);
            }
    }
    for (int i = 0; i + 3 <= n; i++)
        for (int j = 0; j + 3 <= m; j++) {
            res[i][j][0] = g[i][j] + g[i][j + 1] + g[i][j + 2] + g[i + 1][j + 2] + g[i + 2][j + 2] + g[i + 2][j + 1] + g[i + 2][j];
            ans = max (ans, res[i][j][0]);
        }                                                                                                                          
    for (int k = 7; k <= min (n, m); k += 4) {
        int ci = (k / 4) & 1;
        int pi = 1 - ci;
        for (int i = 0; i + k <= n; i++)
            for (int j = 0; j + k <= m; j++) {
                res[i][j][ci] = sum (i, j, 1, k) + sum (i + 1, j + k - 1, k - 1, 1) + sum (i + k - 1, j, 1, k - 1) + sum (i + 2, j, k - 3, 1) + g[i + 2][j + 1] + res[i + 2][j + 2][pi];
                ans = max (ans, res[i][j][ci]);
            }
    }
    printf ("%d\n", ans);
    return 0;
}