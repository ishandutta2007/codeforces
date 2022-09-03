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
#include <cassert>

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
#define prev PREV
#define j0 j1347829
#define j1 j234892
                         
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
double g[500][1000];
vi w, v[500];
int trap[500];
int len;
int o;
double p[500];
double u[500][500];
double e[500][500];
double res[500];
double h[500];

int main () {
    scanf ("%d%d%d", &n, &m, &len);
    for (int i = 0; i < n; i++) {
        scanf ("%d", &trap[i]);
        if (trap[i]) w.pb (i);
    }   
    o = sz (w);
    for (int i = 0; i < m; i++) {
        int a, b;
        scanf ("%d%d", &a, &b); a--; b--;
        v[a].pb (b);
        v[b].pb (a);
    }

    for (int i = 0; i < n; i++) {
        g[i][i] = 1;
        g[i][n + i] = 1;
        if (!trap[i])
            for (int j = 0; j < sz (v[i]); j++)
                g[i][v[i][j]] -= 1.0 / sz (v[i]);
    }
    for (int i = 0; i < n; i++) {
        int k = i;
        for (int j = i; j < n; j++)
            if (abs (g[j][i]) > abs (g[k][i]))
                k = j;
        for (int j = 0; j < 2 * n; j++) swap (g[i][j], g[k][j]);
        double tmp = g[i][i];
        for (int j = 0; j < 2 * n; j++)
            g[i][j] /= tmp;
        for (int j = i + 1; j < n; j++) {
            tmp = g[j][i];
            for (int k = 0; k < 2 * n; k++)
                g[j][k] -= g[i][k] * tmp;
        }   
    }
    for (int i = n - 1; i >= 0; i--)
        for (int j = i - 1; j >= 0; j--) {
            double tmp = g[j][i];
            for (int k = 0; k < 2 * n; k++)
                g[j][k] -= g[i][k] * tmp;
        }
    for (int i = 0; i < o; i++) {
        for (int j = 0; j < n; j++) {
            double tmp = 0;
            for (int k = 0; k < n; k++) {
                tmp += g[j][k + n] * int (k == w[i]);
            }   
            p[j] = tmp;
        }
        res[i] = p[0];
        for (int j = 0; j < o; j++) {
            double tmp = 0;
            for (int k = 0; k < sz (v[w[j]]); k++)
                tmp += p[v[w[j]][k]] / sz (v[w[j]]);
            u[j][i] = tmp;
        }
    }
    len -= 2;
    while (len) {
        if (len & 1) {
            for (int i = 0; i < o; i++) {
                h[i] = 0;
                for (int j = 0; j < o; j++)
                    h[i] += res[j] * u[j][i];
            }
            for (int i = 0; i < o; i++) res[i] = h[i];
        }
        len /= 2;
        for (int i = 0; i < o; i++)
            for (int j = 0; j < o; j++) {
                e[i][j] = 0;
                for (int k = 0; k < o; k++)
                    e[i][j] += u[i][k] * u[k][j];
            }
        for (int i = 0; i < o; i++)
            for (int j = 0; j < o; j++)
                u[i][j] = e[i][j];  
    }
    printf ("%.10f\n", res[o - 1]);
    return 0;
}