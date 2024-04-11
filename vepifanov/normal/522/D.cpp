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
#include <cassert>

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
#define prev PREV
                         
typedef vector<int> vi;
typedef long long ll;
typedef long double ld;
typedef double D;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<string> vs;
typedef vector<vi> vvi;

template<class T> T abs(T x) { re x > 0 ? x : -x; }

const int inf = 1e9;
const int N = 1 << 19;

int n;
int m;

int tree[2 * N];
int x[N];
int ans[N];
vii v[N];
map<int, int> res;

void build (int x, int l, int r) {
    tree[x] = inf;
    if (l == r) re;
    int s = (l + r) / 2;
    build (x * 2 + 1, l, s);
    build (x * 2 + 2, s + 1, r);
}

void add (int x, int l, int r, int lc, int rc, int y) {
    if (r < lc || l > rc) re;
    if (l >= lc && r <= rc) {
        tree[x] = min (tree[x], y);
        re;
    }
    int s = (l + r) / 2;
    add (x * 2 + 1, l, s, lc, rc, y);
    add (x * 2 + 2, s + 1, r, lc, rc, y);
}

int get (int x, int l, int r, int y) {
    if (r < y || l > y) re inf;
    if (l == r) re tree[x];
    int s = (l + r) / 2;
    re min (tree[x], min (get (x * 2 + 1, l, s, y), get (x * 2 + 2, s + 1, r, y)));
}

int main () {
    scanf ("%d%d", &n, &m);
    for (int i = 0; i < n; i++) scanf ("%d", &x[i]);
    for (int i = 0; i < m; i++) {
        int a, b;
        scanf ("%d%d", &a, &b); a--; b--;
        v[a].pb (mp (b, i));
    }
    build (0, 0, n - 1);
    for (int i = n - 1; i >= 0; i--) {
        if (res.count (x[i])) {
            int j = res[x[i]];
            add (0, 0, n - 1, j, n - 1, j - i);
        }
        for (int j = 0; j < sz (v[i]); j++)
            ans[v[i][j].se] = get (0, 0, n - 1, v[i][j].fi);
        res[x[i]] = i;
    }
    for (int i = 0; i < m; i++)
        printf ("%d\n", ans[i] == inf ? -1 : ans[i]);
    return 0;
}