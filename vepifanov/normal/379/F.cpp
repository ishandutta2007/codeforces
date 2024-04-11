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

const int N = 2100000;

int n;
int m;
int r = N;
int o = 4;
int p[N][21];
int d[N];
int bad[N];

int init (int x) {
    for (int i = 0; i < 20; i++)
        p[x][i + 1] = p[p[x][i]][i];
    re 0;
}

int add (int i, int j) {
    r--;
    bad[r] = 1;
    p[r][0] = i;
    d[r] = d[i] + 1;
    p[j][0] = r;
    d[j] = d[r] + 1;
    init (r);
    init (j);
    re 0;
}

int lca (int a, int b) {
    if (d[a] > d[b]) swap (a, b);
    int j = 20;
    while (d[b] != d[a])
        if (d[p[b][j]] >= d[a]) b = p[b][j]; else j--;
    j = 20;
    while (a != b)
        if (j == 0 || p[a][j] != p[b][j]) a = p[a][j], b = p[b][j]; else j--;
    re a;
}

int up (int x, int y) {
    int j = 20;
    while (d[x] != y)
        if (d[p[x][j]] >= y) x = p[x][j]; else j--;
    re x;
}

int main () {
    scanf ("%d", &n);
    p[0][0] = 0;
    init (0);
    add (0, 1);
    add (0, 2);
    add (0, 3);
    int mid = 0, len = 2;
    for (int i = 0; i < n; i++) {
        int x;
        scanf ("%d", &x); x--;
        int y = o;
        add (x, o);
        add (x, o + 1);
        o += 2;
        int z = lca (mid, y);
        int cur = d[mid] + d[y] - 2 * d[z];
        if (cur > len) {
            len++;
            if (z != mid) mid = p[mid][0]; else mid = up (y, d[mid] + 1);
        }
        printf ("%d\n", len);
    }
    return 0;
}