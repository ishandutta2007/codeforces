#include <cstdio>
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

using namespace std;

#define mp make_pair
#define pb push_back
#define rep(i,n) for(int i = 0; i < n; i++)
#define re return
#define fi first
#define se second
#define sz(x) ((int) (x).size())
#define all(x) (x).begin(), (x).end()
#define sqr(x) ((x) * (x))
#define y0 y3487465
#define y1 y8687969
#define next NEXT

typedef vector<int> vi;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<string> vs;
typedef vector<vi> vvi;

template<class T> T abs(T x) {
    re x > 0 ? x : -x;
}

const int INF = 1e9;

int n;
int m;
int res[200][200][2];
int next[200][200][2];
int y[200], ly[200], ry[200], d[200], use[200];
int g[200][200];
vi v[200];

int go (int x, int p) {
    vi w;
    for (int i = 0; i < sz (v[x]); i++)
        if (v[x][i] != p) {
            go (v[x][i], x);
            w.pb (v[x][i]);
        }
    int k = sz (w);
    res[x][n][0] = res[x][n][1] = INF;
    for (int i = 0; i < n; i++) {
        res[x][i][0] = 0;
        for (int j = 0; j < k; j++) {
            int cur = res[w[j]][i + 1][0];
            for (int k = -1; k < 1; k++)
                if (i + k >= 0 && cur > res[w[j]][i + k][1])
                    cur = res[w[j]][i + k][1];
            y[j] = cur;
            res[x][i][0] = min (res[x][i][0] + cur, INF);
        }
        for (int j = 0; j < k; j++) {
            ly[j] = y[j];
            if (j > 0) ly[j] = min (ly[j - 1] + y[j], INF);
        }
        for (int j = k - 1; j >= 0; j--) {
            ry[j] = y[j];
            if (j + 1 < k) ry[j] = min (ry[j + 1] + y[j], INF);
        }
        next[x][i][0] = -1;
        res[x][i][1] = INF;
        if (i == 0) res[x][i][1] = res[x][i][0];
        if (i > 0)
        for (int j = 0; j < k; j++) {
            int cur = res[w[j]][i - 1][1];
//          if (i > 0 && cur > res[w[j]][i - 1][1]) cur = res[w[j]][i - 1][1];
            if (j - 1 >= 0) cur = min (cur + ly[j - 1], INF);
            if (j + 1 < k) cur = min (cur + ry[j + 1], INF);
            if (res[x][i][1] > cur) {
                res[x][i][1] = cur;
                next[x][i][1] = w[j];
            }   
//          printf ("-> %d = %d %d %d\n", w[j] + 1, cur, ry[j + 1], ly[j - 1]);
        }
        res[x][i][0] += d[i];
        res[x][i][1] += d[i];
//      printf ("%d %d = %d %d\n", x + 1, i, res[x][i][0], res[x][i][1]);
    }
    re 0;
}

int out (int x, int ai, int aj, int p) {
    if (ai == 0) use[x] = 1;
//  printf ("%d %d\n", ai, d[ai]);
    vi w;
    for (int i = 0; i < sz (v[x]); i++)
        if (v[x][i] != p)
            w.pb (v[x][i]);
    int k = sz (w);
    for (int j = 0; j < k; j++) {
        int cur = res[w[j]][ai + 1][0], ak = ai + 1;
        int ok = 0;
        if (w[j] == next[x][ai][aj]) { cur = INF; ok = 1; }
        for (int k = -1; k < 1 - ok; k++)
            if (ai + k >= 0 && cur > res[w[j]][ai + k][1]) {
                ak = ai + k;
                cur = res[w[j]][ai + k][1];
            }
//      printf ("%d %d %d -> %d %d %d\n", x + 1, ai, aj, w[j] + 1, ak, int (ak <= ai));
        out (w[j], ak, int (ak <= ai), x);  
    }
    re 0;
}

int main() {
    scanf ("%d%d", &n, &m);
    d[0] = m;
    for (int i = 1; i < n; i++) scanf ("%d", &d[i]);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            g[i][j] = n + 1;
    for (int i = 0; i < n; i++) g[i][i] = 0;
    for (int i = 1; i < n; i++) {
        int a, b;
        scanf ("%d%d", &a, &b); a--; b--;
        v[a].pb (b);
        v[b].pb (a);
        g[a][b] = g[b][a] = 1;
    }
    for (int k = 0; k < n; k++)
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                g[i][j] = min (g[i][j], g[i][k] + g[k][j]);
    go (0, -1);
    int ans = INF, ai = 0;
    for (int i = 0; i < n; i++) 
        if (res[0][i][1] < ans) {
            ans = res[0][i][1];
            ai = i;
        }   
    printf ("%d\n", ans);
    out (0, ai, 1, -1);
    for (int i = 0; i < n; i++) {
        int k = -1;
        for (int j = 0; j < n; j++)
            if (use[j] && (k == -1 || g[i][k] > g[i][j]))
                k = j;
        printf ("%d ", k + 1);
    }
    printf ("\n");
    return 0;
}