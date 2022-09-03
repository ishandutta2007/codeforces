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
#define prev PREV
#define next NEXT
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
template<class T> T gcd(T a, T b) { re a ? gcd (b % a, a) : b; }

const D pi = asin(1.0) * 2;

const int MAX = 1000*1000;

int n;
int m;
int ef[41][41];
int ec[41][41];
int ans = 0;
int prev[41];
int d[41];
int was[41];
int g[20][20][2];
int p[41];
int pf[41];
int sum[20];

int go (int S, int T, int I) {
    for (int i = 0; i <= 2 * n; i++) {
        d[i] = 2e9;
        was[i] = 0;
    }   
    d[S] = 0;
    was[S] = 1;
    for (int i = 0; i < n + I + 1; i++) {
        int k = -1;
        for (int j = 0; j < I; j++)
            if (was[j] == 1 && (k == -1 || d[k] > d[j]))
                k = j;
        for (int j = n; j <= 2 * n; j++)
            if (was[j] == 1 && (k == -1 || d[k] > d[j]))
                k = j;
//      printf ("%d = %I64d %d %I64d\n", k, d[k], pf[k], p[k]);
        if (k == T) break;
        was[k] = 2;
        int x = k;
        if (x < n) {
            for (int y = n; y < 2 * n; y++) {
                int tmp = d[x] + ec[x][y] - p[y] + p[x];
                if (ef[x][y] > 0 && d[y] > tmp) {
                    d[y] = tmp;
                    prev[y] = x;
                    was[y] = 1;
                }
            }
        } else
        if (x < 2 * n) {
            int y = pf[x];
            int tmp = d[x] + ec[x][y] - p[y] + p[x];
            if (d[y] > tmp) {
                d[y] = tmp;
                prev[y] = x;
                was[y] = 1;
            }
        }
    }
//  assert (was[T] != 0);
    int res = d[T] + p[T] - p[S];
    for (int i = 0; i <= 2 * n; i++)
        if (was[i] == 2)
            p[i] += d[i];
        else
            p[i] += d[T];   
    re res;
}

int gen (int i, int j, int cur) {
//  cerr << i << " " << j << " " << cur << endl;
    if (cur + sum[i] >= ans) re 0;
    if (i == n) {
        ans = cur;
        re 0;
    }
    for (int t = 0; t < 2; t++)
        if (j + t <= n / 2 && j + t + (n - i - 1) >= n / 2) {
            for (int k = 0; k < n; k++) {
                ef[i][k + n] = 1;
                ec[i][k + n] = g[i][k][t];
                ec[k + n][i] = -g[i][k][t];
            }
            int op[41];
            int opf[41];
            for (int k = 0; k <= 2 * n; k++) {
                op[k] = p[k];
                opf[k] = pf[k];
            }
            int tmp = go (i, 2 * n, i + 1);
            int k = 2 * n;
            vii u;
            while (k != i) {
                int pk = prev[k];
                u.pb (mp (pk, k));
                if (k >= n && k < 2 * n) pf[k] = pk;
                ef[pk][k]--;
                ef[k][pk]++;
                k = pk;
            }
            gen (i + 1, j + t, cur + tmp);
            for (int k = 0; k <= 2 * n; k++) {
                p[k] = op[k];
                pf[k] = opf[k];
            }   
            for (int k = 0; k < sz (u); k++) {
                ef[u[k].fi][u[k].se]++;
                ef[u[k].se][u[k].fi]--;
            }
            for (int k = 0; k < n; k++)
                ef[i][k + n] = 0;
        }
    re 0;
}

int main () {
    scanf ("%d", &n);
    for (int i = 0; i < n; i++) p[i] = i;
    random_shuffle (p, p + n);
    for (int t = 0; t < 2; t++)
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++) {
                scanf ("%d", &g[p[i]][j][t]);
                g[p[i]][j][t] = MAX - g[p[i]][j][t];
            }
    int cur = 0;
    for (int i = n - 1; i >= 0; i--) {
        int tmp = 1e9;
        for (int j = 0; j < n; j++)
            tmp = min (tmp, min (g[i][j][0], g[i][j][1]));
        cur += tmp;
        sum[i] = cur;
    }
    for (int i = 0; i < n; i++) {
        ef[i + n][2 * n] = 1;
        pf[i + n] = 2 * n;
    }
    ans = 1e9;
    gen (0, 0, 0);
    printf ("%d\n", n * MAX - ans);
    cerr << clock () << endl;
    re 0;
}