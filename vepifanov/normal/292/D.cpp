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
int was[500];
vii v[500];
int ct;
int l, r;

inline int go (int x) {
    was[x] = 1;
    for (int i = 0; i < sz (v[x]); i++) {
        if (v[x][i].se >= l && v[x][i].se <= r || was[v[x][i].fi]) continue;
        go (v[x][i].fi);
    }
    re 0;
}

int main () {
    scanf ("%d%d", &n, &m);
    for (int i = 0; i < m; i++) {
        int a, b;
        scanf ("%d%d", &a, &b);
        a--;
        b--;
        v[a].pb (mp (b, i));
        v[b].pb (mp (a, i));
    }
    int k;
    scanf ("%d", &k);
    for (int i = 0; i < k; i++) {
        scanf ("%d%d", &l, &r); l--; r--;
        int ans = 0;
        memset (was, 0, sizeof (was));
        for (int j = 0; j < n; j++)
            if (!was[j]) {
                ans++;
                go (j);
            }
        printf ("%d\n", ans);
    }
    return 0;
}