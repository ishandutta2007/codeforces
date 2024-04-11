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
vii v[300000];
ll res[300000];
ll tree[2000000];
ll add[2000000];
int x[300000];

ll upd (int x, int l, int r, int lc, int rc, ll q) {
    if (r < lc || l > rc) re tree[x] + add[x];
    if (l >= lc && r <= rc) {
        add[x] += q;
        re tree[x] + add[x];
    }
    int s = (l + r) / 2;
    tree[x] = max (upd (x * 2 + 1, l, s, lc, rc, q), upd (x * 2 + 2, s + 1, r, lc, rc, q));
    re tree[x] + add[x];
}

ll get (int x, int l, int r, int lc, int rc) {
    if (r < lc || l > rc) re -1e18;
    if (l >= lc && r <= rc) re tree[x] + add[x];
    int s = (l + r) / 2;
    re max (get (x * 2 + 1, l, s, lc, rc), get (x * 2 + 2, s + 1, r, lc, rc)) + add[x];
}

int main () {
    scanf ("%d%d", &n, &m);
    for (int i = 0; i < n; i++)
        scanf ("%d", &x[i]);
    for (int i = 0; i < m; i++) {
        int a, b, c;
        scanf ("%d%d%d", &a, &b, &c);
        v[b].pb (mp (a - 1, c));
    }
    int N = n;
    while (N & (N - 1)) N++;
    res[0] = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < sz (v[i]); j++) {
            int a = v[i][j].fi, b = v[i][j].se;
            upd (0, 0, N - 1, 0, a, b);
        }
        upd (0, 0, N - 1, 0, i - 1, -x[i - 1]);
        ll cur = max (get (0, 0, N - 1, 0, i - 1), res[i - 1]);
        res[i] = cur;
        if (i < n) upd (0, 0, N - 1, i, i, cur);
    }
    cout << res[n] << endl;
    return 0;
}