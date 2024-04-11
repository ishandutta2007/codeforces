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
#define j0 j1347829
#define j1 j234892
                         
typedef vector<int> vi;
typedef long long ll;
typedef long double ld;
typedef double D;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<string> vs;
typedef vector<vi> vvi;

template<class T> T abs(T x) { re x > 0 ? x : -x; }

const int N = (1 << 18) + 10;

int n;
int m;

ll tree[N];
ll add[N];
int same[N];
int col[N];

int build (int x, int l, int r) {
    tree[x] = 0;
    same[x] = 0;
    col[x] = 0;
    add[x] = 0;
    if (l == r) {
        same[x] = 1;
        col[x] = l + 1;
        re 0;
    }         
    int s = (l + r) / 2;
    build (x * 2 + 1, l, s);
    build (x * 2 + 2, s + 1, r);
    re 0;
}

int push (int x, int l, int r) {
    if (add[x]) {
        tree[x] += (ll)(r - l + 1) * add[x];
        if (l != r) {
            add[x * 2 + 1] += add[x];
            add[x * 2 + 2] += add[x];
        }
        add[x] = 0;
    }
    if (same[x]) {
        if (l != r) {
            same[x * 2 + 1] = same[x * 2 + 2] = 1;
            col[x * 2 + 1] = col[x * 2 + 2] = col[x];
        }
    }
    re 0;
}

ll upd (int x, int l, int r, int lc, int rc, int y) {
    push (x, l, r);
    if (r < lc || l > rc) re tree[x];
    if (l >= lc && r <= rc) {
        if (same[x]) {
            add[x] += abs (col[x] - y);
            col[x] = y;
            push (x, l, r);
            re tree[x];
        } else {
            same[x] = 1;
            col[x] = y;
        }        
    } else {
        if (same[x] && col[x] != y) {
            same[x] = 0;
            col[x] = 0;
        }   
    }
    int s = (l + r) / 2;
    re tree[x] = upd (x * 2 + 1, l, s, lc, rc, y) + upd (x * 2 + 2, s + 1, r, lc, rc, y);
}

ll get (int x, int l, int r, int lc, int rc) {
    push (x, l, r);
    if (r < lc || l > rc) re 0;
    if (l >= lc && r <= rc) re tree[x];
    int s = (l + r) / 2;
    re get (x * 2 + 1, l, s, lc, rc) + get (x * 2 + 2, s + 1, r, lc, rc);
}

int main () {
    scanf ("%d%d", &n, &m);
    build (0, 0, n - 1);
    for (int i = 0; i < m; i++) {
        int t;
        scanf ("%d", &t);
        if (t == 1) {
            int l, r, x;
            scanf ("%d%d%d", &l, &r, &x); l--; r--;
            upd (0, 0, n - 1, l, r, x);
        } else {
            int l, r;
            scanf ("%d%d", &l, &r); l--; r--;
            printf ("%I64d\n", get (0, 0, n - 1, l, r));
        }
    }
    return 0;
}