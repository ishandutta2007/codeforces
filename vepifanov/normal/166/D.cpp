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
int m, r;

vii v[200000];
int cost[200000];
int num[200000];
int p[100000], q[100000];
map<int, int> all;
ll res[200000][2];
int was[200000][2], use[200000][2];
int u[200000];
vii ans;

ll go (int i, int j) {
    if (i == r) re 0;
    if (was[i][j]) re res[i][j];
    was[i][j] = 1;
    ll cur = go (i + 1, 0);
    use[i][j] = -1;
    if (sz (v[i]) > 0) {
        if (i + 1 < r && u[i + 1] == u[i] + 1 && v[i][0].fi >= cost[i + 1] && cur < go (i + 1, 1) + cost[i + 1]) {
            cur = go (i + 1, 1) + cost[i + 1];
            use[i][j] = 0;
        }
        if (j == 0 && v[i][0].fi >= cost[i] && cur < go (i + 1, 0) + cost[i]) {
            cur = go (i + 1, 0) + cost[i];
            use[i][j] = 1;
        }
    }
    if (sz (v[i]) > 1 && i + 1 < r && j == 0 && u[i + 1] == u[i] + 1) {
        if (v[i][0].fi >= cost[i] && v[i][1].fi >= cost[i + 1] && cur < go (i + 1, 1) + cost[i] + cost[i + 1]) {
            cur = go (i + 1, 1) + cost[i] + cost[i + 1];
            use[i][j] = 2;
        }
        if (v[i][0].fi >= cost[i + 1] && v[i][1].fi >= cost[i] && cur < go (i + 1, 1) + cost[i] + cost[i + 1]) {
            cur = go (i + 1, 1) + cost[i] + cost[i + 1];
            use[i][j] = 3;
        }
    }
    re res[i][j] = cur;
}

int out (int i, int j) {
    if (i == r) re 0;
    if (use[i][j] == -1) out (i + 1, 0);
    if (use[i][j] == 0) {
        ans.pb (mp (v[i][0].se, num[i + 1]));
        out (i + 1, 1);
    }
    if (use[i][j] == 1) {
        ans.pb (mp (v[i][0].se, num[i]));
        out (i + 1, 0);
    }
    if (use[i][j] == 2) {
        ans.pb (mp (v[i][0].se, num[i]));
        ans.pb (mp (v[i][1].se, num[i + 1]));
        out (i + 1, 1);
    }
    if (use[i][j] == 3) {
        ans.pb (mp (v[i][0].se, num[i + 1]));
        ans.pb (mp (v[i][1].se, num[i]));
        out (i + 1, 1);
    }
    re 0;
}

vi w;

int main () {
    scanf ("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf ("%d%d", &p[i], &q[i]);
        w.pb (q[i]);
        w.pb (q[i] - 1);
    }
    sort (all (w));
    r = 0;
    for (int i = 0; i < sz (w); i++) {
        if (i == 0 || w[i - 1] != w[i]) {
            num[r] = -1;
            cost[r] = 2e9;
            r++;
        }
        u[r - 1] = w[i];
        all[w[i]] = r - 1;
    }
    for (int i = 0; i < n; i++) {
        q[i] = all[q[i]];
        num[q[i]] = i;
        cost[q[i]] = p[i];
    }
    scanf ("%d", &m);
    for (int i = 0; i < m; i++) {
        int a, b;
        scanf ("%d%d", &a, &b);
        if (all.count (b)) v[all[b]].pb (mp (a, i));
    }
    for (int i = 0; i < r; i++) {
        sort (all (v[i]));
        reverse (all (v[i]));
    }   
    printf ("%I64d\n", go (0, 0));
    out (0, 0);
    printf ("%d\n", sz (ans));
    for (int i = 0; i < sz (ans); i++) printf ("%d %d\n", ans[i].fi + 1, ans[i].se + 1);
    return 0;
}