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

int g[10][300][300];
int w[300][300], e[300][300];

int main () {
    scanf ("%d%d", &n, &m);
    for (int i = 0; i < n; i++) 
        for (int j = 0; j < n; j++)
            g[0][i][j] = int (i != j) * 1e9;
    for (int i = 0; i < m; i++) {
        int a, b, c, d;
        scanf ("%d%d%d%d", &a, &b, &c, &d); a--; b--;
        g[0][a][b] = -c;
        g[0][b][a] = -d;
    }
    int ok2 = 0, pos = 0;
    for (int i = 1; (1 << (i - 1)) <= n; i++) {
        for (int a = 0; a < n; a++)
            for (int b = 0; b < n; b++)
                g[i][a][b] = int (a != b) * 1e9;
        for (int a = 0; a < n; a++)
            for (int b = 0; b < n; b++)
                for (int c = 0; c < n; c++)
                    g[i][a][c] = min (g[i][a][c], g[i - 1][a][b] + g[i - 1][b][c]);
        int ok = 0;
        for (int a = 0; a < n && !ok; a++)
            if (g[i][a][a] < 0) {
                ok = 1;
                break;
            }
        if (ok) {
            pos = i - 1;
            ok2 = 1;
            break;
        }
    }
    if (!ok2) {
        printf ("0\n");
        re 0;
    }
    for (int a = 0; a < n; a++)
        for (int b = 0; b < n; b++)
            w[a][b] = g[pos][a][b];
    int cur = 1 << pos, ans = n;
    for (int i = pos; i >= 0; i--) {
        int ok = 0;
        for (int a = 0; a < n && !ok; a++)
            for (int b = 0; b < n && !ok; b++)
                if (w[a][b] + g[i][b][a] < 0)
                    ok = 1;
        if (!ok) {
            cur += 1 << i;
            for (int a = 0; a < n; a++)
                for (int b = 0; b < n; b++)
                    e[a][b] = w[a][b];
            for (int a = 0; a < n; a++)
                for (int b = 0; b < n; b++)
                    for (int c = 0; c < n; c++)
                        w[a][c] = min (w[a][c], e[a][b] + g[i][b][c]);
        } else ans = min (ans, cur + (1 << i));
    }
    printf ("%d\n", ans);
    return 0;
}