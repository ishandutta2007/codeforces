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
int tree[20][(1 << 18) + 1];
int rev[20][(1 << 18) + 1];

int add (int t, int x, int l, int r, int y) {
    if (y > r || y < l) re tree[t][x];
    if (l == r) re tree[t][x] = 1;
    int s = (l + r) / 2;
    re tree[t][x] = add (t, x * 2 + 1, l, s, y) + add (t, x * 2 + 2, s + 1, r, y);
}

int get (int t, int x, int l, int r, int lc, int rc) {
    if (r < lc || l > rc) re 0;
    if (l >= lc && r <= rc) {
        int tmp = tree[t][x];
        if (rev[t][x]) tmp = (r - l + 1) - tmp;
        re tmp;
    }
    int s = (l + r) / 2;
    int tmp = get (t, x * 2 + 1, l, s, lc, rc) + get (t, x * 2 + 2, s + 1, r, lc, rc);
    if (rev[t][x]) tmp = (min (r, rc) - max (l, lc) + 1) - tmp;
    re tmp;
}

int upd (int t, int x, int l, int r, int lc, int rc) {
    if (r < lc || l > rc) {
        int tmp = tree[t][x];
        if (rev[t][x]) tmp = (r - l + 1) - tmp;
        re tmp;
    }
    if (l >= lc && r <= rc) {
        rev[t][x] ^= 1;
        int tmp = tree[t][x];
        if (rev[t][x]) tmp = (r - l + 1) - tmp;
        re tmp;
    }
    int s = (l + r) / 2;
    int tmp = upd (t, x * 2 + 1, l, s, lc, rc) + upd (t, x * 2 + 2, s + 1, r, lc, rc);
    tree[t][x] = tmp;
    if (rev[t][x]) tmp = (r - l + 1) - tmp;
    re tmp;
}

int main () {
    scanf ("%d", &n);
    for (int i = 0; i < n; i++) {
        int x;
        scanf ("%d", &x);
        for (int j = 0; j < 20; j++)
            if ((x >> j) & 1)
                add (j, 0, 0, n - 1, i);
    }
    scanf ("%d", &m);
    for (int i = 0; i < m; i++) {
        int t, l, r, x;
        scanf ("%d%d%d", &t, &l, &r); l--; r--;
        if (t == 1) {
            ll ans = 0;
            for (int j = 0; j < 20; j++)
                ans += (ll)get (j, 0, 0, n - 1, l, r) << j;
            printf ("%I64d\n", ans);
        } else {
            scanf ("%d", &x);
            for (int j = 0; j < 20; j++)
                if ((x >> j) & 1)
                    upd (j, 0, 0, n - 1, l, r);
        }
    }
    return 0;
}