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
int was[100000];
vi v[100000];
int p[100000];
int q[100000];
vi res;

int fix (int x) {
    if (was[x] != 2 || p[x] != q[x]) re 0;
    res.pb (x + 1);
    q[x]++;
    for (int i = 0; i < sz (v[x]); i++) q[v[x][i]]++;
    for (int i = 0; i < sz (v[x]); i++) fix (v[x][i]);
    re 0;
}

int go (int x) {
    was[x] = 1;
    for (int i = 0; i < sz (v[x]); i++) {
        int y = v[x][i];
        if (!was[y]) go (y);
    }
    was[x] = 2;
    fix (x);
    re 0;
}

int main () {
    scanf ("%d%d", &n, &m);
    for (int i = 0; i < m; i++) {
        int a, b;
        scanf ("%d%d", &a, &b); a--; b--;
        v[a].pb (b);
        v[b].pb (a);
    }
    for (int i = 0; i < n; i++) scanf ("%d", &p[i]);
    for (int i = 0; i < n; i++)
        if (!was[i])
            go (i);
    printf ("%d\n", sz (res));
    sort (all (res));
    for (int i = 0; i < sz (res); i++) printf ("%d ", res[i]);
    printf ("\n");
    return 0;
}