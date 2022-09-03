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

int g[7][7];
vii v[7][7];
vii res;
int cnt[7];

int go (int x) {
    for (int y = 0; y < 7; y++)
        while (g[x][y]) {
            g[x][y]--;
            g[y][x]--;
            int tmp = g[x][y];
            go (y);
            res.pb (v[x][y][tmp]);
        }
    re 0;
}

int main () {
    scanf ("%d", &n);
    for (int i = 0; i < n; i++) {
        int a, b;
        scanf ("%d%d", &a, &b);
        g[a][b]++;
        g[b][a]++;
        v[a][b].pb (mp (i + 1, 1));
        v[b][a].pb (mp (i + 1, 0));
        cnt[a]++;
        cnt[b]++;
    }
    int r = -1, k = 0;
    for (int i = 0; i < 7; i++)
        if (cnt[i] & 1) {
            r = i;
            k++;
        }   
    if (r == -1)
        for (int i = 0; i < 7; i++)
            if (cnt[i])
                r = i;
    go (r);
    if (sz (res) != n || k > 2) printf ("No solution\n"); else {
        for (int i = 0; i < n; i++) printf ("%d %c\n", res[i].fi, res[i].se ? '-' : '+');
    }
    return 0;
}