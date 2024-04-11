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
int w[7001];
vector<pair<ii, int> > u[7001];
int ct;
int was[1000001];

int get (int x) {
    int y = 0;
    while (x) {
        y++;
        x /= 2;
    }
    re y;
}

int main () {
    scanf ("%d%d", &n, &m);
    w[1] = 1;
    for (int i = 1; i < n; i++)
        w[i + 1] = w[i] + get (w[i]);
    for (int i = 0; i < m; i++) {
        int t;
        scanf ("%d", &t);
        if (t == 1) {
            int x, l, r, z;
            scanf ("%d%d%d%d", &x, &l, &r, &z);
            u[x].pb (mp (mp (l, r), z));
        } else {
            int x, y;
            scanf ("%d%d", &x, &y);
            int l = y, r = y;
            ct++;
            int ans = 0;
            for (int k = x; k <= n; k++) {
                for (int j = 0; j < sz (u[k]); j++)
                    if (max (l, u[k][j].fi.fi) <= min (r, u[k][j].fi.se)) {
                        ans += int (was[u[k][j].se] != ct);
                        was[u[k][j].se] = ct;
                    }
                if (k < n) {
                    l = get (l - 1) + l;
                    r = get (r - 1) + r + int ((r & (r - 1)) == 0);
                }
            }
            printf ("%d\n", ans);
        }
    }   
    return 0;
}