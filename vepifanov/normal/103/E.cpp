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

const int INF = 1e9;
const int MAX = 602;

int n;
int m;
int cf[602][602];
int cw[602][602];
int q[MAX], inq[602];
int d[602];
int prev[602];
int p[300], u[300];
int g[300][300];
int cost[300];

int addedge (int a, int b, int c, int d) {
    cf[a][b] = d;
    cw[a][b] = c;
    cw[b][a] = -c;
    re 0;
}

int go (int s, int t) {
    for (int i = 0; i <= t; i++) inq[i] = 0;
    d[s] = 0;
    inq[s] = 1;
    int l = 0, r = 1;
    q[0] = s;
    while (l < r) {
        int x = q[l++];
        for (int i = 0; i <= t; i++)
            if (cf[x][i] > 0 && !inq[i]) {
                prev[i] = x;
                q[r++] = i;
                inq[i] = 1;
            }
    }
    re (1 - inq[t]) * INF;
}

int main () {
    scanf ("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf ("%d", &m);
        for (int j = 0; j < m; j++) {
            int x;
            scanf ("%d", &x); x--;
            addedge (i, x + n, 0, 1);
            g[i][x] = 1;
        }
        addedge (i + n, 2 * n + 1, 0, 1);
    }
    for (int i = 0; i < n; i++) {
        int x;
        scanf ("%d", &x);
        cost[i] = x;
        addedge (2 * n, i, x, 1);
    }
    int tmp;
    while ((tmp = go (2 * n, 2 * n + 1)) < INF) {
        int i = 2 * n + 1;
        while (i != 2 * n) {
            int j = prev[i];
            cf[j][i]--;
            cf[i][j]++;
            i = j;
        }
    }
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (cf[j + n][i] > 0) {
                p[i] = j;
                u[j] = i;
            }
    memset (cf, 0, sizeof (cf));
    memset (cw, 0, sizeof (cw));
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (cost[i] > 0) addedge (i, n + 1, 1, cost[i]);
        if (cost[i] < 0) { addedge (n, i, 1, -cost[i]); ans += cost[i]; }
        for (int j = 0; j < n; j++)
            if (p[i] != j && g[i][j])
                addedge (i, u[j], 1, INF);
    }
    while ((tmp = go (n, n + 1)) < INF) {
        tmp = INF;
        int i = n + 1;
        while (i != n) {
            int j = prev[i];
            tmp = min (tmp, cf[j][i]);
            i = j;
        }
        i = n + 1;
        while (i != n) {
            int j = prev[i];
            cf[j][i] -= tmp;
            cf[i][j] += tmp;
            i = j;
        }
        ans += tmp;
    }
    printf ("%d\n", ans);
    return 0;
}