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

const int N = 1 << 14;

int n;
int m;
ii tree[2 * N + 10];
vi v[100001];
vi w[100001];

ii merge (ii a, ii b) {
    re mp (a.fi + b.fi, a.se + b.se);
}

ii upd (int x, int l, int r, int y, int z) {
    if (r < y || l > y) re tree[x];
    if (l == r) {
        tree[x].fi += z;
        tree[x].se += z * y;
        re tree[x];
    }
    int s = (l + r) / 2;
    re tree[x] = merge (upd (x * 2 + 1, l, s, y, z), upd (x * 2 + 2, s + 1, r, y, z));
}

int get (int x, int l, int r, int y) {
    if (y == 0) re 0;
    if (l == r) re l * y;
    int s = (l + r) / 2;
    if (tree[x * 2 + 1].fi > y)
        re get (x * 2 + 1, l, s, y);
    else
        re tree[x * 2 + 1].se + get (x * 2 + 2, s + 1, r, y - tree[x * 2 + 1].fi); 
}

int main () {
    scanf ("%d", &n);
    for (int i = 0; i < n; i++) {
        int a, b;
        scanf ("%d%d", &a, &b);
        v[a].pb (b);
        upd (0, 0, N - 1, b, 1);
    }
    for (int i = 1; i <= 100000; i++) {
        sort (all (v[i]));
        for (int j = 0; j < sz (v[i]); j++)
            w[sz (v[i]) - j].pb (v[i][j]);
    }
    int ans = 2e9;
    int cur = 0;
    int cnt = 0;
    for (int i = n; i > 0; i--) {
        for (int j = 0; j < sz (w[i]); j++) {
            cur += w[i][j];
            cnt++;
            upd (0, 0, N - 1, w[i][j], -1);
        }
        ans = min (ans, cur + get (0, 0, N - 1, max (0, i - cnt)));
    }
    printf ("%d\n", ans);
    return 0;
}