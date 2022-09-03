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
map<int, int> all[100000];
vi cnt[100000];
int u[100000];
vi v[100000];
vii w[100000];
int c[100000];
int res[100000];

int add (int x, int y) {
    all[x][y]++;
    int z = all[x][y];
    while (sz (cnt[x]) < z) cnt[x].pb (0);
    cnt[x][z - 1]++;
    re 0;
}

int go (int x, int p) {
    u[x] = x;
    for (int i = 0; i < sz (v[x]); i++) {
        int y = v[x][i];
        if (y == p) continue;
        go (y, x);
        if (sz (all[u[x]]) < sz (all [u[y]])) u[x] = u[y];
    }
    add (u[x], c[x]);
    for (int i = 0; i < sz (v[x]); i++) {
        int y = v[x][i];
        if (y == p) continue;
        if (u[x] != u[y])
            for (map<int, int>::iterator it = all[u[y]].begin (); it != all[u[y]].end (); it++)
                for (int j = 0; j < it->se; j++)
                    add (u[x], it->fi);
    }
    for (int i = 0; i < sz (w[x]); i++) 
        if (sz (cnt[u[x]]) >= w[x][i].fi)
            res[w[x][i].se] = cnt[u[x]][w[x][i].fi - 1];
    re 0;
}

int main () {
    scanf ("%d%d", &n, &m);
    for (int i = 0; i < n; i++) scanf ("%d", &c[i]);
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        scanf ("%d%d", &a, &b); a--; b--;
        v[a].pb (b);
        v[b].pb (a);
    }
    for (int i = 0; i < m; i++) {
        int a, b;
        scanf ("%d%d", &a, &b); a--;
        w[a].pb (mp (b, i));
    }
    go (0, 0);
    for (int i = 0; i < m; i++) printf ("%d\n", res[i]);
    return 0;
}