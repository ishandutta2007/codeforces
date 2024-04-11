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

const int inf = 1.05e9;

int n;
int m;
int k;
int w[100000];
int f[500];
int c[500];
int g[500][500];
int p[100000];

int gp (int x) {
    if (p[x] != x) p[x] = gp (p[x]);
    re p[x];
}

int main () {
    scanf ("%d%d%d", &n, &m, &k);
    int cur = 0;
    for (int i = 0; i < k; i++) {
        scanf ("%d", &c[i]);
        f[i] = cur;
        cur += c[i];
        for (int t = 0; t < c[i]; t++)
            w[f[i] + t] = i;
    }
    for (int i = 0; i < k; i++)
        for (int j = 0; j < k; j++)
            g[i][j] = inf * int (i != j);
    for (int i = 0; i < n; i++) p[i] = i;
    for (int i = 0; i < m; i++) {
        int a, b, c;
        scanf ("%d%d%d", &a, &b, &c); a--; b--;
        g[w[b]][w[a]] = g[w[a]][w[b]] = min (g[w[a]][w[b]], c);
        if (c == 0) p[gp (a)] = b;
    }
    for (int i = 0; i < k; i++)
        for (int j = 1; j < c[i]; j++)
            if (gp (f[i] + j - 1) != gp (f[i] + j)) {
                printf ("No\n");
                re 0;
            }
    for (int t = 0; t < k; t++)
        for (int i = 0; i < k; i++)
            for (int j = 0; j < k; j++)
                g[i][j] = min (g[i][j], g[i][t] + g[t][j]);
    printf ("Yes\n");
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < k; j++)
            printf ("%d ", g[i][j] == inf ? -1 : g[i][j]);
        printf ("\n");
    }   
    return 0;
}