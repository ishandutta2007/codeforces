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
int m, s, l;
int ea[100000], eb[100000], d[100000], mark[100000], ec[100000];
vii v[100000];
set<ii> all;

int main () {
    scanf ("%d%d%d", &n, &m, &s); s--;
    for (int i = 0; i < m; i++) {
        int a, b, c;
        scanf ("%d%d%d", &a, &b, &c); a--; b--;
        v[a].pb (mp (b, c));
        v[b].pb (mp (a, c));
        ea[i] = a;
        eb[i] = b;
        ec[i] = c;
    }
    scanf ("%d", &l);
    memset (mark, 0, sizeof (mark));
    mark[s] = 1;
    d[s] = 0;
    all.insert (mp (0, s));
    while (!all.empty ()) {
        int x = all.begin ()->se;
        all.erase (all.begin ());
        for (int i = 0; i < sz (v[x]); i++) {
            int y = v[x][i].fi;
            int nd = d[x] + v[x][i].se;
            if (mark[y] == 0 || d[y] > nd) {
                if (mark[y]) all.erase (mp (d[y], y));
                d[y] = nd;
                mark[y] = 1;
                all.insert (mp (d[y], y));
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < n; i++)
        if (d[i] == l)
            ans++;
    for (int i = 0; i < m; i++) {
        int a = d[ea[i]], b = d[eb[i]], c = ec[i];
        int r = a + b + c;
        if (a < l && 2 * l < r) ans++;
        if (b < l && 2 * l < r) ans++;
        if (2 * l == r && abs (a - b) != c) ans++;
    }
    printf ("%d\n", ans);
    return 0;
}