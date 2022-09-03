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

const ll inf = 1e18;

int n;
int m;
int k;
ll best[301];
ll res[301][301];
vii v[300];

int main () {
    scanf ("%d%d%d", &n, &m, &k);
    for (int i = 0; i < m; i++) {
        int a, b, c;
        scanf ("%d%d%d", &a, &b, &c); a--; b--;
        v[a].pb (mp (b + 1, c));
    }
    for (int i = 0; i <= n; i++) best[i] = inf;
    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= n; j++)
            res[i][j] = inf;
    res[0][0] = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < sz (v[i]); j++)
            best[v[i][j].fi] = min (best[v[i][j].fi], (ll)v[i][j].se);
        for (int j = 0; j <= i; j++) {
            res[i + 1][j] = min (res[i + 1][j], res[i][j]);
            for (int t = i + 1; t <= n; t++)
                if (best[t] <= inf)
                    res[t][j + (t - i)] = min (res[t][j + (t - i)], res[i][j] + best[t]);
        }
    }
    ll ans = inf;
    for (int j = k; j <= n; j++) ans = min (ans, res[n][j]);
    if (ans == inf) ans = -1;
    cout << ans << endl;
    return 0;
}