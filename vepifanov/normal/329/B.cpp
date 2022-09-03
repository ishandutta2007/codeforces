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
string g[1000];
vii v;
ii q[1000000];
int was[1000][1000];
int d[1000][1000];
int si, sj;

int main () {
    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> g[i];
    int l = 0, r = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (g[i][j] == 'E') {
                was[i][j] = 1;
                d[i][j] = 0;
                q[r++] = mp (i, j);
            } else
            if (g[i][j] == 'S') {
                si = i;
                sj = j;
            } else
            if (g[i][j] >= '0' && g[i][j] <= '9')
                v.pb (mp (i, j));
    while (l < r) {
        int i = q[l].fi;
        int j = q[l++].se;
        for (int t = 0; t < 4; t++) {
            int ni = i + int (t == 0) - int (t == 1);
            int nj = j + int (t == 2) - int (t == 3);
            if (ni >= 0 && nj >= 0 && ni < n && nj < m && !was[ni][nj] && g[ni][nj] != 'T') {
                was[ni][nj] = 1;
                d[ni][nj] = d[i][j] + 1;
                q[r++] = mp (ni, nj);
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < sz (v); i++)
        if (was[v[i].fi][v[i].se] && d[v[i].fi][v[i].se] <= d[si][sj])
            ans += g[v[i].fi][v[i].se] - '0';
    printf ("%d\n", ans);
    return 0;
}