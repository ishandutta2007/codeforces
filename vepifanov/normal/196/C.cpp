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
int cnt[1500];
vi v[1500], w[1500];
int x[1500], y[1500];
int res[1500];

int go (int x, int p) {
    cnt[x] = 1;
    for (int i = 0; i < sz (v[x]); i++)
        if (v[x][i] != p) {
            w[x].pb (v[x][i]);
            cnt[x] += go (v[x][i], x);
        }
    re cnt[x];
}

int go2 (vi p, int t) {
    int j = 0;
    for (int i = 0; i < sz (p); i++)
        if (x[p[i]] < x[p[j]] || (x[p[i]] == x[p[j]] && y[p[i]] < y[p[j]]))
            j = i;
    swap (p[0], p[j]);
    res[p[0]] = t + 1;
    vector<pair<double, int> > q;
    for (int i = 1; i < sz (p); i++) q.pb (mp (atan2 (y[p[i]] - y[p[0]], x[p[i]] - x[p[0]]), p[i]));
    sort (all (q));
    int f = 0;
    for (int i = 0; i < sz (w[t]); i++) {
        vi e;
        for (int j = 0; j < cnt[w[t][i]]; j++) e.pb (q[f + j].se);
        f += cnt[w[t][i]];
        go2 (e, w[t][i]);
    }
    re 0;
}

int main () {
    scanf ("%d", &n);
    for (int i = 0; i + 1 < n; i++) {
        int a, b;
        scanf ("%d%d", &a, &b); a--; b--;
        v[a].pb (b);
        v[b].pb (a);
    }
    go (0, -1);
    vi p;
    for (int i = 0; i < n; i++) {
        scanf ("%d%d", &x[i], &y[i]);
        p.pb (i);
    }
    go2 (p, 0);
    for (int i = 0; i < n; i++) printf ("%d ", res[i]);
    printf ("\n");
    return 0;
}