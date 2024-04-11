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

const int N = 1 << 20;

int n;
int m;
vector<pair<int, ii> > v;
int tree[2 * N + 1];
int last[300000];
int res[300000];

int upd (int x, int l, int r, int y, int z) {
    if (r < y || l > y) re tree[x];
    if (l == r) re tree[x] += z;
    int s = (l + r) / 2;
    re tree[x] = upd (x * 2 + 1, l, s, y, z) + upd (x * 2 + 2, s + 1, r, y, z);
}

int get (int x, int l, int r, int lc, int rc) {
    if (r < lc || l > rc) re 0;
    if (l >= lc && r <= rc) re tree[x];
    int s = (l + r) / 2;
    re get (x * 2 + 1, l, s, lc, rc) + get (x * 2 + 2, s + 1, r, lc, rc);
}

int main () {
    scanf ("%d%d", &n, &m);
    for (int i = 0; i < n; i++) {
        int a, b;
        scanf ("%d%d", &a, &b);
        v.pb (mp (a, mp (0, 0)));
        v.pb (mp (b, mp (2, a)));
    }
    for (int i = 0; i < m; i++) {
        int k;
        scanf ("%d", &k);
        for (int j = 0; j < k; j++) {
            int x;
            scanf ("%d", &x);
            v.pb (mp (x, mp (1, i)));
        }
        last[i] = -1;
    }
    sort (all (v));
    for (int i = 0; i < sz (v); i++)
        if (v[i].se.fi == 0)
            upd (0, 0, N - 1, v[i].fi, 1);
        else
        if (v[i].se.fi == 2)    
            upd (0, 0, N - 1, v[i].se.se, -1);
        else {
            res[v[i].se.se] += get (0, 0, N - 1, last[v[i].se.se] + 1, v[i].fi);
            last[v[i].se.se] = v[i].fi;
        }   
    for (int i = 0; i < m; i++) printf ("%d\n", res[i]);
    return 0;
}