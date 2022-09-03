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
vi v[4000];
int bad[4000];
int was[4000];
int g[4000][4000];
vi w;

int add (int a, int b) {
    v[a].pb (b);
    v[b].pb (a);
    g[a][b] = g[b][a] = 1;
    re 0;
}

int go (int x) {
    w.pb (x);
    was[x] = 1;
    for (int i = 0; i < sz (v[x]); i++) {
        int y = v[x][i];
        if (!was[y]) go (y);
    }
    re 0;
}

int main () {
    scanf ("%d%d", &n, &m);
    for (int i = 0; i < m; i++) {
        int a, b;
        scanf ("%d%d", &a, &b); a--; b--;
        bad[a] = 1;
        bad[n + a] = 1;
        bad[2 * n + b] = 1;
        bad[3 * n + b] = 1;
    }
    bad[0] = bad[n - 1] = bad[n] = bad[2 * n - 1] = 1;
    bad[2 * n] = bad[3 * n - 1] = bad[3 * n] = bad[4 * n - 1] = 1;
    for (int i = 1; i + 1 < n; i++) {
        add (i, i + n);
        add (i + 2 * n, i + 3 * n);
        add (i, i + 2 * n);
        add (i + n, i + 3 * n);
        add (i, 4 * n - 1 - i);
        add (i + n, 3 * n - 1 - i);
    }
    int ans = 0;
    for (int i = 0; i < 4 * n; i++)
        if (!was[i]) {
            w.clear ();
            go (i);
            int cur = 0;
            for (int mask = 0; mask < (1 << sz (w)); mask++) {
                int ok = 1, now = 0;
                for (int j = 0; j < sz (w); j++)
                    if ((mask >> j) & 1) {
                        now++;
                        if (bad[w[j]]) ok = 0;
                    }
                for (int j = 0; j < sz (w); j++)
                    for (int k = j + 1; k < sz (w); k++)
                        if (((mask >> j) & 1) && ((mask >> k) & 1) && g[w[j]][w[k]])
                            ok = 0;
                if (ok) cur = max (cur, now);
            }
            ans += cur;
        }
    printf ("%d\n", ans);
    return 0;
}