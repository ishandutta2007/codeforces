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

int g[100][100];
int ds[100], dt[100];
double cs[100], ct[100];
int q[100];

int main () {
    scanf ("%d%d", &n, &m);
    for (int i = 0; i < m; i++) {
        int a, b;
        scanf ("%d%d", &a, &b); a--; b--;
        g[a][b] = g[b][a] = 1;
    }
    int l = 0, r = 1;
    q[0] = 0;
    ds[0] = 0;
    cs[0] = 1;
    while (l < r) {
        int x = q[l++];
        for (int i = 0; i < n; i++)
            if (g[x][i]) {
                if (cs[i] == 0) {
                    ds[i] = ds[x] + 1;
                    q[r++] = i;
                }
                if (ds[i] == ds[x] + 1)  cs[i] += cs[x];
            }
    }
    l = 0; r = 1;
    q[0] = n - 1;
    dt[n - 1] = 0;
    ct[n - 1] = 1;
    while (l < r) {
        int x = q[l++];
        for (int i = 0; i < n; i++)
            if (g[x][i]) {
                if (ct[i] == 0) {
                    dt[i] = dt[x] + 1;
                    q[r++] = i;
                }
                if (dt[i] == dt[x] + 1) ct[i] += ct[x];
            }
    }
    double ans = 1;
    for (int i = 1; i + 1 < n; i++)
        if (ds[i] + dt[i] == dt[0])
            ans = max (ans, 2 * cs[i] * ct[i] / ct[0]);
    printf ("%.10f\n", ans);
    return 0;
}