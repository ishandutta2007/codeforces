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
ii z[2][200001];
int x[100000];
int y[100000];
vi res[2];

int go (int f) {
    int i = 0, j = 0, k = 0, t = f;
    while (i < n || j < m) {
        while (i < n && x[i] == t) z[f][k++] = mp (i++, t);
        while (j < m && y[j] == t) z[f][k++] = mp ((j++) + n, t);
        t ^= 1;
    }
    z[f][k++] = mp (0, 0);
    res[f].clear ();
    for (int i = 0; i < n + m; i++)
        if (z[f][i].se != z[f][i + 1].se)
            res[f].pb (i + 1);
    re sz (res[f]);
}

int main () {
    freopen ("input.txt", "r", stdin);
    freopen ("output.txt", "w", stdout);
    scanf ("%d", &n);
    for (int i = 0; i < n; i++) scanf ("%d", &x[i]);
    scanf ("%d", &m);
    for (int i = 0; i < m; i++) scanf ("%d", &y[i]);
    int t = 0;
    if (go (1) < go (0)) t = 1;
    for (int i = 0; i < n + m; i++) printf ("%d ", z[t][i].fi + 1);
    printf ("\n%d\n", sz (res[t]));
    for (int i = 0; i < sz (res[t]); i++) printf ("%d ", res[t][i]);
    printf ("\n");
    return 0;
}