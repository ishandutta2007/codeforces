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
double p[100000], q[100000], sp[100000], sq[100000], sz[100000], sx, sy;
vi v[100000];

int go (int x, int a) {
    sp[x] = p[x];
    sq[x] = q[x];
    sz[x] = 0;
    for (int i = 0; i < sz (v[x]); i++) {
        int y = v[x][i];
        if (y == a) continue;
        go (y, x);
        sp[x] += sp[y];
        sq[x] += sq[y];
        sz[x] += sz[y];
    }
    sz[x] += q[x] * sp[x];
    re 0;
}

double go2 (int x, int a, double up) {
    double res = 0, sum = 0;
    for (int i = 0; i < sz (v[x]); i++) {
        int y = v[x][i];
        if (y == a) continue;
        sum += q[x] * sp[y] + sz[y];
    }
    for (int i = 0; i < sz (v[x]); i++) {
        int y = v[x][i];
        if (y == a) continue;
        res += 1 - (up + sum - q[x] * sp[y]);
        res += go2 (y, x, up + sum - q[x] * sp[y] - sz[y] + q[y] * (1 - sp[y] + p[y]));
    }
    re res;
}

int main () {
    scanf ("%d", &n);
    for (int i = 0; i + 1 < n; i++) {
        int a, b;
        scanf ("%d%d", &a, &b); a--; b--;
        v[a].pb (b);
        v[b].pb (a);
    }
    for (int i = 0; i < n; i++) {
        int x, y;
        scanf ("%d%d", &x, &y);
        sx += x;
        sy += y;
        p[i] = x; q[i] = y;
    }
    for (int i = 0; i < n; i++) p[i] /= sx, q[i] /= sy;
    go (0, -1);
    printf ("%.10f\n", go2 (0, -1, p[0] * q[0]));
    return 0;
}