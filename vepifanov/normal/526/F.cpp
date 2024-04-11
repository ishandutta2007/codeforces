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

template<class T> T abs(T x) { re x > 0 ? x : -x; }

const int N = 1 << 19;

int n;
int m;
ii tree[2 * N + 10];
int same[2 * N + 10];
int p[N];
ii sa[N];
ii sb[N];

ii merge (ii a, ii b) {
    if (a.fi < b.fi) re a;
    if (a.fi > b.fi) re b;
    re mp (a.fi, a.se + b.se);
}

int build (int x, int l, int r) {
    tree[x] = mp (0, r - l + 1);
    same[x] = 0;
    if (l == r) re 0;
    int s = (l + r) / 2;
    build (x * 2 + 1, l, s);
    build (x * 2 + 2, s + 1, r);
    re 0;
}

int push (int x, int l, int r) {
    if (same[x]) {
        if (l != r) {
            same[x * 2 + 1] += same[x];
            same[x * 2 + 2] += same[x];
        }
        tree[x].fi += same[x];
        same[x] = 0;
    }
    re 0;   
}

ii add (int x, int l, int r, int lc, int rc, int y) {
    push (x, l, r);
    if (r < lc || l > rc) re tree[x];
    if (l >= lc && r <= rc) {
        same[x] += y;
        push (x, l, r);
        re tree[x];
    }
    int s = (l + r) / 2;
    re tree[x] = merge (add (x * 2 + 1, l, s, lc, rc, y), add (x * 2 + 2, s + 1, r, lc, rc, y));
}

ii get (int x, int l, int r, int lc, int rc) {
    push (x, l, r);
    if (r < lc || l > rc) re mp (1e9, 0);
    if (l >= lc && r <= rc) re tree[x];
    int s = (l + r) / 2;
    re merge (get (x * 2 + 1, l, s, lc, rc), get (x * 2 + 2, s + 1, r, lc, rc));
}

int main () {
    scanf ("%d", &n);
    for (int i = 0; i < n; i++) {
        int a, b;
        scanf ("%d%d", &a, &b);
        a--; b--;
        p[a] = b;
    }
    build (0, 0, n - 1);
    int a = 0, b = 0;
    ll ans = 0;
    for (int i = n - 1; i >= 0; i--) {
        add (0, 0, n - 1, i + 1, n - 1, -1);
        {
            int cur = 1;
            while (a > 0 && sa[a - 1].fi < p[i]) {
                int tmp = sa[a - 1].se;
//              printf ("add %d %d = %d\n", i + cur, i + cur + tmp - 1, p[i] - sa[a - 1].fi);
                add (0, 0, n - 1, i + cur, i + cur + tmp - 1, p[i] - sa[a - 1].fi);
                cur += tmp;
                a--;
            }
            sa[a++] = mp (p[i], cur);
        }
        {
            int cur = 1;
            while (b > 0 && sb[b - 1].fi > p[i]) {
                int tmp = sb[b - 1].se;
//              printf ("add %d %d = %d\n", i + cur, i + cur + tmp - 1, sb[b - 1].fi - p[i]);
                add (0, 0, n - 1, i + cur, i + cur + tmp - 1, sb[b - 1].fi - p[i]);
                cur += tmp;
                b--;
            }
            sb[b++] = mp (p[i], cur);
        }
//      for (int j = i; j < n; j++) printf ("%d ", get (0, 0, n - 1, j, j).fi);
//      printf ("\n");
        ii res = get (0, 0, n - 1, i, n - 1);
        if (res.fi == 0) ans += res.se;
    }
    cout << ans << endl;
    return 0;
}