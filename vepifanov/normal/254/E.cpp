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
int m, V;
int x[400];
vii v[400];
int was[400][401];
int res[400][401];
ii use[400][401];

int dec (int *a, int *b, int c) {
    int t = min (*a, c);
    *a -= t;
    c -= t;
    *b -= c;
    re 0;
}

int go (int i, int j) {
    if (i == n) re 0;
    if (was[i][j]) re res[i][j];
    was[i][j] = 1;
    int cur = -1e9;
    int k = x[i], J = j;
    dec (&j, &k, V);
    if (k >= 0) {
        cur = go (i + 1, k);
        use[i][J] = mp (0, k);
        for (int t = 0; t < sz (v[i]); t++) {
            dec (&j, &k, v[i][t].fi);
            if (k < 0) break;
            int tmp = go (i + 1, k) + t + 1;
            if (tmp > cur) {
                cur = tmp;
                use[i][J] = mp (t + 1, k);
            }
            cur = max (cur, go (i + 1, k) + t + 1);
        }
    }
    re res[i][J] = cur;
}

int out (int i, int j) {
    if (i == n) re 0;
    printf ("%d", use[i][j].fi);
    for (int t = 0; t < use[i][j].fi; t++) printf (" %d", v[i][t].se);
    printf ("\n");
    out (i + 1, use[i][j].se);
    re 0;
}

int main () {
    freopen ("input.txt", "r", stdin);
    freopen ("output.txt", "w", stdout);
    scanf ("%d%d", &n, &V);
    for (int i = 0; i < n; i++) scanf ("%d", &x[i]);
    scanf ("%d", &m);
        for (int i = 0; i < m; i++) {
            int a, b, c;
            scanf ("%d%d%d", &a, &b, &c); a--; b--;
            for (int j = a; j <= b; j++) v[j].pb (mp (c, i + 1));
        }
        for (int i = 0; i < n; i++) sort (all (v[i]));
        printf ("%d\n", go (0, 0));
        out (0, 0);
    return 0;
}