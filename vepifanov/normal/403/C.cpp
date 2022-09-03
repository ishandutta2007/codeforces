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
#include <cassert>

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

int g[2000][2000];
int was[2000];

int dfs (int x) {
    if (was[x]) re 0;
    was[x] = 1;
    int cur = 1;
    for (int i = 0; i < n; i++)
        if (g[x][i])
            cur += dfs (i);
    re cur;
}

int main () {
    scanf ("%d", &n);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            int x;
            scanf ("%d", &x);
            g[i][j] = int (x > 0);
        }
    memset (was, 0, sizeof (was));
    int ok = int (dfs (0) == n);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (i < j)
                swap (g[i][j], g[j][i]);
    memset (was, 0, sizeof (was));
    ok &= int (dfs (0) == n);
    if (ok) printf ("YES\n"); else printf ("NO\n");
    return 0;
}