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

int mark[503], d[503], prev[503], var[250], cur[26];
int cf[503][503], cs[503][503], r, p[503], x[250], y[250];

int addedge (int i, int j, int a, int b) {
    cf[i][j] = a;
    cf[j][i] = 0;
    cs[i][j] = b;
    cs[j][i] = -b;
    re 0;
}

int go (int S, int T) {
    memset (mark, 0, sizeof (mark));
    for (int i = 0; i < r; i++) d[i] = 1e9;
    mark[S] = 1;
    d[S] = 0;
    for (int i = 0; i < r; i++) {
        int k = -1;
        for (int j = 0; j < r; j++)
            if (mark[j] == 1 && (k == -1 || d[k] > d[j]))
                k = j;
        if (k == -1) break;
        mark[k] = 2;
        for (int j = 0; j < r; j++)
            if (cf[k][j] > 0) {
                int nd = d[k] + cs[k][j] + p[k] - p[j];
                if (nd < d[j]) {
                    d[j] = nd;
                    mark[j] = 1;
                    prev[j] = k;
                }
            }
    }
    if (mark[T] != 2) re 0;
    for (int i = 0; i < r; i++)
        if (mark[i] != 0)
            p[i] += d[i];   
    re 1;
}

int main () {
    scanf ("%d%d", &n, &m);
    r = 2 * n + 3;
    for (int i = 0; i < n; i++) {
        scanf ("%d", &x[i]);
        y[i] = 0;
        int z = x[i];
        while (z) { y[i] += z & 1; z /= 2; }
    }
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            addedge (i, j + n, 1, y[j] * int (x[i] != x[j]));
    addedge (2 * n, 2 * n + 1, m, 0);
    for (int i = 0; i < n; i++) {
        addedge (2 * n, i, 1, 0);
        addedge (i + n, 2 * n + 2, 1, 0);
        addedge (2 * n + 1, i + n, 1, y[i]);
    }
    int ans = 0;
    while (go (2 * n, 2 * n + 2)) {
        int j = 2 * n + 2;
        while (j != 2 * n) {
            int k = prev[j];
            cf[k][j]--;
            cf[j][k]++;
            ans += cs[k][j];
            j = k;
        }
    }
    int k = 0;
    for (int i = 0; i < n; i++)
        if (cf[2 * n + 1][i + n] == 0) {
            var[i] = k;
            k++;
        }
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            if (cf[i][j + n] == 0)
                var[j] = var[i];
    for (int i = 0; i < m; i++) cur[i] = -1;
    int len = 0;
    for (int i = 0; i < n; i++) {
        if (cur[var[i]] != x[i]) {
            cur[var[i]] = x[i];
            len++;
        }
        len++;
    }
    for (int i = 0; i < m; i++) cur[i] = -1;
    printf ("%d %d\n", len, ans);
    for (int i = 0; i < n; i++) {
        if (cur[var[i]] != x[i]) {
            cur[var[i]] = x[i];
            printf ("%c=%d\n", var[i] + 'a', x[i]);
        }
        printf ("print(%c)\n", var[i] + 'a');
    }
    return 0;
}