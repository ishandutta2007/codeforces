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
#define prev PREV
                         
typedef vector<int> vi;
typedef long long ll;
typedef long double ld;
typedef double D;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<string> vs;
typedef vector<vi> vvi;
typedef pair<ll, ll> pll;

template<class T> T abs(T x) { re x > 0 ? x : -x; }

const int N = 1 << 18;

int n;
int m;
pair<ll, pll> tree[2 * N + 10];
int h[N];
int d[N];
ll pos[N];

pair<ll, pll> merge (pair<ll, pll> a, pair<ll, pll> b) {
    pair<ll, pll> c;
    c.fi = max (max (a.fi, b.fi), b.se.fi - a.se.se);
    c.se.fi = max (a.se.fi, b.se.fi);
    c.se.se = min (a.se.se, b.se.se);
    re c;
}

pair<ll, pll> build (int x, int l, int r) {
    if (l == r) re tree[x] = mp (-1e18, mp (pos[l] + 2 * h[l], pos[l] - 2 * h[l]));
    int s = (l + r) / 2;
    re tree[x] = merge (build (x * 2 + 1, l, s), build (x * 2 + 2, s + 1, r));
}

pair<ll, pll> get (int x, int l, int r, int lc, int rc) {
    if (r < lc || l > rc) re mp (-1e18, mp (-1e18, 1e18));
    if (l >= lc && r <= rc) re tree[x];
    int s = (l + r) / 2;
    re merge (get (x * 2 + 1, l, s, lc, rc), get (x * 2 + 2, s + 1, r, lc, rc));
}

int main () {
    scanf ("%d%d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf ("%d", &d[i]);
        d[n + i] = d[i];
    }
    for (int i = 0; i < n; i++) {
        scanf ("%d", &h[i]);
        h[n + i] = h[i];
    }
    ll cur = 0;
    for (int i = 0; i < 2 * n; i++) {
        pos[i] = cur;
        cur += d[i];
    }
    build (0, 0, 2 * n - 1);
    for (int i = 0; i < m; i++) {
        int a, b;
        scanf ("%d%d", &a, &b); a--; b--;
        if (a <= b) {
            cout << get (0, 0, 2 * n - 1, b + 1, a + n - 1).fi << "\n";
        } else {
            cout << get (0, 0, 2 * n - 1, b + 1, a - 1).fi << "\n";
        }
    }
    return 0;
}