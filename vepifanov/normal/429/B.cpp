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

const int N = 1000;

int n;
int m;
int g[N][N];
ll a[N][N];
ll b[N][N];
ll c[N][N];
ll d[N][N];

int main () {
    scanf ("%d%d", &n, &m);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            scanf ("%d", &g[i][j]);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            a[i][j] = 0;
            if (i > 0) a[i][j] = max (a[i][j], a[i - 1][j]);
            if (j > 0) a[i][j] = max (a[i][j], a[i][j - 1]);
            a[i][j] += g[i][j];
        }
    for (int i = n - 1; i >= 0; i--)
        for (int j = m - 1; j >= 0; j--) {
            b[i][j] = 0;
            if (i + 1 < n) b[i][j] = max (b[i][j], b[i + 1][j]);
            if (j + 1 < m) b[i][j] = max (b[i][j], b[i][j + 1]);
            b[i][j] += g[i][j];
        }
    for (int i = 0; i < n; i++)
        for (int j = m - 1; j >= 0; j--) {
            c[i][j] = 0;
            if (i > 0) c[i][j] = max (c[i][j], c[i - 1][j]);
            if (j + 1 < m) c[i][j] = max (c[i][j], c[i][j + 1]);
            c[i][j] += g[i][j];
        }       
    for (int i = n - 1; i >= 0; i--)
        for (int j = 0; j < m; j++) {
            d[i][j] = 0;
            if (i + 1 < n) d[i][j] = max (d[i][j], d[i + 1][j]);
            if (j > 0) d[i][j] = max (d[i][j], d[i][j - 1]);
            d[i][j] += g[i][j];
        }
    ll ans = 0;
    for (int i = 1; i + 1 < n; i++)
        for (int j = 1; j + 1 < m; j++) {
            ans = max (ans, a[i - 1][j] + b[i + 1][j] + d[i][j - 1] + c[i][j + 1]);
            ans = max (ans, c[i - 1][j] + d[i + 1][j] + a[i][j - 1] + b[i][j + 1]);
        }
    cout << ans << endl;
    return 0;
}