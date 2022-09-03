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
int m, A, B;
double w[22][22];
double g[22 * 22][22 * 22 + 22];
vi v[22];
double p[22];

int main () {
    scanf ("%d%d%d%d", &n, &m, &A, &B); A--; B--;
    for (int i = 0; i < m; i++) {
        int a, b;
        scanf ("%d%d", &a, &b); a--; b--;
        v[a].pb (b);
        v[b].pb (a);
    }
    for (int i = 0; i < n; i++) scanf ("%lf", &p[i]);
    for (int i = 0; i < n; i++) {
        w[i][i] = p[i];
        for (int j = 0; j < sz (v[i]); j++)
            w[i][v[i][j]] = (1 - p[i]) / sz (v[i]);
    }
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (i == j)
                g[i * n + j][i * n + j] = 1;
            else {
                for (int a = 0; a < n; a++)
                    for (int b = 0; b < n; b++)
                        g[i * n + j][a * n + b] = w[i][a] * w[j][b];
                g[i * n + j][i * n + j] -= 1;
            }
    for (int i = 0; i < n; i++)
        g[i * n + i][n * n + i] = 1;
    int m = n * n;
    int M = n * n + n;
    for (int i = 0; i < m; i++) {
        int k = i;
        for (int j = i; j < m; j++)
            if (abs (g[i][k]) < abs (g[i][j]))
                k = j;
        for (int j = i; j < M; j++)
            swap (g[i][j], g[k][j]);
        for (int j = i + 1; j < m; j++) {
            double tmp = g[j][i] / g[i][i];
            for (int k = i; k < M; k++)
                g[j][k] -= g[i][k] * tmp;
        }
    }
    for (int i = m - 1; i >= 0; i--)
        for (int j = 0; j < i; j++) {
            double tmp = g[j][i] / g[i][i];
            for (int k = i; k < M; k++)
                g[j][k] -= g[i][k] * tmp;
        }
    for (int i = 0; i < n; i++) printf ("%.10f ", g[A * n + B][m + i] / g[A * n + B][A * n + B]);
    printf ("\n");
    return 0;
}