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
int f[802][802];
double ct[802][802];
vi v[802];
double d[802], p[802];
int mark[802];
int prev[802];
int x[802], y[802];

int addedge (int a, int b, int c, double d) {
    v[a].pb (b);
    v[b].pb (a);
    f[a][b] = c;
    f[b][a] = 0;
    ct[a][b] = d;
    ct[b][a] = -d;
    re 0;
}

double go (int S, int T) {
    for (int i = 0; i < 2 * n + 2; i++) {
        d[i] = 1e18;
        mark[i] = 0;
    }
    d[S] = 0;
    mark[S] = 1;
    for (int i = 0; i < 2 * n + 2; i++) {
        int k = -1;
        for (int j = 0; j < 2 * n + 2; j++)
            if (mark[j] == 1 && (k == -1 || d[k] > d[j]))
                k = j;
        if (k == T) break;
        if (k == -1) re -1;
        mark[k] = 2;
        for (int j = 0; j < sz (v[k]); j++) {
            int y = v[k][j];
            if (f[k][y] > 0 && d[y] > d[k] + ct[k][y] + p[k] - p[y]) {
                d[y] = d[k] + ct[k][y] + p[k] - p[y];
                prev[y] = k;
                mark[y] = 1;
            }
        }
    }
    double res = d[T] - p[S] + p[T];
    for (int i = 0; i < 2 * n + 2; i++)
        if (mark[i] == 2)
            p[i] += d[i];
        else
            p[i] += d[T];   
    re res;
}

int main () {
    scanf ("%d", &n);
    for (int i = 0; i < n; i++) scanf ("%d%d", &x[i], &y[i]);
    for (int i = 0; i < n; i++) {
        addedge (2 * n, i, 2, 0);
        addedge (n + i, 2 * n + 1, 1, 0);
        for (int j = 0; j < n; j++)
            if (y[j] < y[i])
                addedge (i, n + j, 1, sqrt (sqr (x[i] - x[j]) + sqr (y[i] - y[j]) + 0.0));
    }
    double ans = 0;
    for (int i = 0; i + 1 < n; i++) {
        double tmp = go (2 * n, 2 * n + 1);
        if (tmp < 0) {
            printf ("-1\n");
            re 0;
        }
        ans += tmp;
        int x = 2 * n + 1;
        while (x != 2 * n) {
            int y = prev[x];
            f[y][x]--;
            f[x][y]++;
            x = y;
        }
    }
    printf ("%.10f\n", ans);
    return 0;
}