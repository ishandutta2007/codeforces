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

const double pi = 2 * asin (1.0);

int n;
int m;

double dx[5], dy[5], x[500], y[500];

vi res[100];
vi v[500];
int g[500][500];

int add (int a, int b) {
    v[a].pb (b);
    v[b].pb (a);
    re 0;
}

int go (int x) {
    for (int i = 0; i < sz (v[x]); i++) {
        int y = v[x][i];
        if (!g[x][y]) {
            g[x][y] = g[y][x] = 1;
            go (y);
        }
    }
    printf ("%d ", x + 1);
    re 0;
}

int main () {
    scanf ("%d", &n);
    for (int i = 0; i < 5; i++) {
        dx[i] = cos (2 * pi / 5 * i) * 5 / sin (pi / 5);
        dy[i] = sin (2 * pi / 5 * i) * 5 / sin (pi / 5);
    }
    int o = 1;
    x[0] = 0;
    y[0] = 0;
    for (int i = 0; i < n; i++) {
        int ii = 0;
        for (int j = 0; j < o; j++)
            if (x[j] < x[ii])
                ii = j;
        res[i].pb (ii);
        for (int t = 0; t < 4; t++) {
            x[o + t] = x[ii] + dx[t + 1] - dx[0];
            y[o + t] = y[ii] + dy[t + 1] - dy[0];
            res[i].pb (o + t);
        }
        add (ii, o + 1);
        add (o + 1, o + 3);
        add (o + 3, o);
        add (o, o + 2);
        add (o + 2, ii);
        o += 4;
    }
    printf ("%d\n", o);
    for (int i = 0; i < o; i++) printf ("%.10f %.10f\n", x[i], y[i]);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 5; j++)
            printf ("%d ", res[i][j] + 1);
        printf ("\n");
    }
    go (0);
    printf ("\n");
    return 0;
}