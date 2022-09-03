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
vii v[200000];
int use[200000];
int res[200000];
int p[200000];
int e[200000];
int q[200000];
int f[200000];

int main () {
    scanf ("%d%d", &n, &m);
    for (int i = 0; i < m; i++) {
        int a, b, c;
        scanf ("%d%d%d", &a, &b, &c); a--; b--;
        e[i] = c;
        p[i] = a;
        v[a].pb (mp (b, i));
        v[b].pb (mp (a, i));
        f[a] += c;
        f[b] += c;
    }
    int l = 0, r = 1;
    q[0] = 0;
    while (l < r) {
        int x = q[l++];
        for (int i = 0; i < sz (v[x]); i++) {
            int y = v[x][i].fi;
            int z = v[x][i].se;
            if (use[z]) continue;
            res[z] = int (y == p[z]);
            use[z] = 1;
            if (y != n - 1) {
                f[y] -= 2 * e[z];
                if (f[y] == 0) q[r++] = y;
            }
        }
    }
    for (int i = 0; i < m; i++) printf ("%d\n", res[i]);
    return 0;
}