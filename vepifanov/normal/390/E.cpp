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

const int N = 1 << 22;

int n;
int m;
int w;
ll tree[2][2 * N + 1];
ll add[2][2 * N + 1];

int push (int t, int x, int l, int r) {
    if (l < r) {
        add[t][x * 2 + 1] += add[t][x];
        add[t][x * 2 + 2] += add[t][x];
    }
    tree[t][x] += (ll)add[t][x] * (r - l + 1);
    add[t][x] = 0;
    re 0;
}

ll upd (int t, int x, int l, int r, int lc, int rc, int v) {
    push (t, x, l, r);
    if (r < lc || l > rc) re tree[t][x];
    if (l >= lc && r <= rc) {
        add[t][x] += v;
        push(t, x, l, r);
        re tree[t][x];
    }
    int s = (l + r) / 2;
    re tree[t][x] = upd (t, x * 2 + 1, l, s, lc, rc, v) + upd (t, x * 2 + 2, s + 1, r, lc, rc, v);
}

ll get (int t, int x, int l, int r, int lc, int rc) {
    push (t, x, l, r);
    if (r < lc || l > rc) re 0;
    if (l >= lc && r <= rc) re tree[t][x];
    int s = (l + r) / 2;
    re get (t, x * 2 + 1, l, s, lc, rc) + get (t, x * 2 + 2, s + 1, r, lc, rc);
}

int main () {
    scanf ("%d%d%d", &n, &m, &w);
    ll sum = 0;
    for (int i = 0; i < w; i++) {
        int t, x1, y1, x2, y2, v;
        scanf ("%d%d%d%d%d", &t, &x1, &y1, &x2, &y2); x1--; y1--; x2--; y2--;
        if (t == 0) {
            scanf ("%d", &v);
            upd (0, 0, 0, n - 1, x1, x2, v * (y2 - y1 + 1));
            upd (1, 0, 0, m - 1, y1, y2, v * (x2 - x1 + 1));
            sum += (x2 - x1 + 1) * (y2 - y1 + 1) * v;
        } else {
            ll res = sum;
            res -= get (0, 0, 0, n - 1, x1, x2);
            res -= get (1, 0, 0, m - 1, y1, y2);
            printf ("%I64d\n", -res);
        }
    }
    return 0;
}