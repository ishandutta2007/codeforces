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
int l1, r1, l2, r2;

int ans = 0;
vii v[2];

int get (int t, int l, int r, int mid) {
    if (l > r) re 0;
    v[t].pb (mp (l, r));
    if (mid == 1) re 0;
    if (r <= mid) get (t, l, min (r, mid - 1), mid / 2); else
    if (l >= mid) get (t, max (l, mid + 1) - mid, r - mid, mid / 2); else {
        if (l > 1 && r < 2 * mid - 1) {
            get (t, l, mid - 1, mid / 2);
            get (t, 1, r - mid, mid / 2);
        } else get (t, 1, mid - 1, mid / 2);
    }
    re 0;
}

int main () {
    scanf ("%d%d%d%d", &l1, &r1, &l2, &r2);
    get (0, l1, r1, 1 << 29);
    get (1, l2, r2, 1 << 29);
    for (int i = 0; i < sz (v[0]); i++)
        for (int j = 0; j < sz(v[1]); j++)
            ans = max (ans, min (v[0][i].se, v[1][j].se) - max (v[0][i].fi, v[1][j].fi) + 1);
    printf ("%d\n", ans);
    return 0;
}