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

struct node {
    double left, right, mid, sum;
};

node inf;

int n;
int m, c;
int x[150000], p[150000];

node tree[600000];

node un (node a, node b) {
    node c;
    c.left = max (a.left, a.sum + b.left);
    c.mid = max (a.right + b.left, max (a.mid, b.mid));
    c.right = max (b.right, a.right + b.sum);
    c.sum = a.sum + b.sum;
    re c;
}

node add (int x, int l, int r, int p, double q) {
    if (r < p || l > p) re tree[x];
    if (l == r) {
        if (q > 0) tree[x].left = tree[x].mid = tree[x].right = q;
        tree[x].sum = q;
        re tree[x];
    }
    int s = (l + r) / 2;
    re tree[x] = un (add (x * 2 + 1, l, s, p, q), add (x * 2 + 2, s + 1, r, p, q));
}

node get (int x, int l, int r, int lc, int rc) {
    if (r < lc || l > rc) re inf;
    if (l >= lc && r <= rc) re tree[x];
    int s = (l + r) / 2;
    re un (get (x * 2 + 1, l, s, lc, rc), get (x * 2 + 2, s + 1, r, lc, rc));
}

int main () {
    scanf ("%d%d%d", &n, &m, &c);
    for (int i = 0; i < n; i++) scanf ("%d", &x[i]);
    for (int i = 0; i + 1 < n; i++) scanf ("%d", &p[i]);
    memset (tree, 0, sizeof (tree));
    for (int i = 0; i + 1 < n; i++) add (0, 0, n - 2, i, (x[i + 1] - x[i]) / 2.0 - p[i] / 100.0 * c);
    double ans = 0;
    inf.left = inf.right = inf.mid = inf.sum = -1e18;
    for (int i = 0; i < m; i++) {
        int a, b;
        scanf ("%d%d", &a, &b); a--; b -= 2;
        ans += get (0, 0, n - 2, a, b).mid;
    }
    printf ("%.10f\n", ans);
    return 0;
}