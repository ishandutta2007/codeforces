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
typedef long double ld;
typedef double D;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<string> vs;
typedef vector<vi> vvi;

template<class T> T abs(T x) { re x > 0 ? x : -x; }

const int N = 6000000;

int n;
int m;
int tree[2][N];
int ll[2][N];
int rr[2][N];
int o[2];
set<int> all;

int get (int t, int x, int l, int r, int y) {
//  printf ("%d %d %d %d | %d = %d\n", t, x, l, r, y, tree[t][x]);
    if (l == r) re tree[t][x];
    int s = (l + r) / 2;
    int cur = tree[t][x];
    if (y <= s && ll[t][x] != 0) cur = max (cur, get (t, ll[t][x], l, s, y));
    if (y > s && rr[t][x] != 0) cur = max (cur, get (t, rr[t][x], s + 1, r, y));
    re cur;
}

int upd (int t, int x, int l, int r, int lc, int rc, int y) {
    if (r < lc || l > rc) re -1;
    if (l >= lc && r <= rc) {
//      printf ("set %d | %d %d | %d %d = %d\n", x, l, r, lc, rc, y);
        tree[t][x] = max (tree[t][x], y);
        re 0;
    }
    int s = (l + r) / 2;
    if (ll[t][x] == 0) {
        tree[t][o[t]] = -1;
        ll[t][x] = o[t]++;
        tree[t][o[t]] = -1;
        rr[t][x] = o[t]++;
    }
//  printf ("%d = %d %d\n", x, ll[t][x], rr[t][x]);
    upd (t, ll[t][x], l, s, lc, rc, y);
    upd (t, rr[t][x], s + 1, r, lc, rc, y);
    re 0;
}

int main () {
    scanf ("%d%d", &n, &m);
    for (int t = 0; t < 2; t++) {
        o[t] = 1;
        ll[t][0] = rr[t][0] = 0;
        tree[t][0] = -1;
    }
    for (int i = 0; i < m; i++) {
        int x, y;
        char h[5];
        scanf ("%d%d %s", &x, &y, h); x--; y--;
//      printf ("%d %d %c\n", x, y, h[0]);
        if (all.find (x) != all.end ()) {
            printf ("0\n");
            continue;
        }
        all.insert (x);
        if (h[0] == 'L') {
            int z = get (0, 0, 0, n - 1, y);
            printf ("%d\n", x - z);
//          printf ("get %d %d = %d\n", 0, y, z);
//          printf ("upd %d %d %d = %d\n", 1, z + 1, x, y);
            upd (1, 0, 0, n - 1, z + 1, x, y);
        } else {
            int z = get (1, 0, 0, n - 1, x);
            printf ("%d\n", y - z);
//          printf ("get %d %d = %d\n", 1, x, z);
//          printf ("upd %d %d %d = %d\n", 0, z + 1, y, x);
            upd (0, 0, 0, n - 1, z + 1, y, x);
        }
    }
    return 0;
}