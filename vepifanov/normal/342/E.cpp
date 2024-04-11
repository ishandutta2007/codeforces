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
int r = 0;
int cnt[100000];
int was[100000];
int best[100000];
int base[100000];
map<int, ii> num[100000];
int bad[100000];
int ct;
vi v[100000];
int mid;
      
int go (int x) {
    was[x] = ct;
    int cur = 1;
    for (int i = 0; i < sz (v[x]); i++) {
        int y = v[x][i];
        if (was[y] == ct || bad[y]) continue;
        cur += go (y);
    }
    cnt[x] = cur;
    re cur;
}

int go2 (int x, int all) {
    was[x] = ct;
    int ok = 1;
    int sum = 0;
    for (int i = 0; i < sz (v[x]); i++) {
        int y = v[x][i];
        if (was[y] == ct || bad[y]) continue;
        go2 (y, all);
        int tmp = cnt[y];
        sum += tmp;
        if (2 * tmp > all) ok = 0;
    }
    if (2 * (all - sum - 1) > all) ok = 0;
    if (ok) mid = x;
    re 0;
}

int go3 (int x, int cd, int nz, int z) {
    was[x] = ct;
    num[z][x] = mp (cd, nz);
    for (int i = 0; i < sz (v[x]); i++) {
        int y = v[x][i];
        if (was[y] == ct || bad[y]) continue;
        go3 (y, cd + 1, nz, z);
    }
    re 0;
}

int build (int x, int z) {
    ct++;
    int all = go (x);
    go (x);
    mid = -1;
    ct++;
    go2 (x, all);
    vii w;
    for (int i = 0; i < sz (v[mid]); i++) {
        int y = v[mid][i];
        if (!bad[y]) {
            w.pb (mp (y, r));
            r++;
        }
    }
    bad[mid] = 1;
    base[z] = mid;
    best[z] = 1e9;
    ct++;
    for (int i = 0; i < sz (w); i++)
        go3 (w[i].fi, 1, w[i].se, z);
    for (int i = 0; i < sz (w); i++)
        build (w[i].fi, w[i].se);
    re 0;
}

int add (int x, int z) {
    if (base[z] == x) best[z] = 0; else {
        ii tmp = num[z][x];
        best[z] = min (tmp.fi, best[z]);
        add (x, tmp.se);
    }
    re 0;
}

int get (int x, int z) {
    if (base[z] == x) re best[z]; else {
        ii tmp = num[z][x];
        re min (best[z] + tmp.fi, get (x, tmp.se));
    }
}

int main () {
    scanf ("%d%d", &n, &m);
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        scanf ("%d%d", &a, &b); a--; b--;
        v[a].pb (b);
        v[b].pb (a);
    }
    r = 1;
    build (0, 0);
    add (0, 0);
    for (int i = 0; i < m; i++) {
        int a, b;
        scanf ("%d%d", &a, &b); a--; b--;
        if (a == 0) add (b, 0); else printf ("%d\n", get (b, 0));
    }
//  cerr << clock () << endl;
    return 0;
}