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
int l, r;
vi v[3000];

int was[3000], prev[3000], d[3000], q[3000], use[3000];

int go (int x, int p) {
    prev[x] = p;
    use[x] = 1;
    for (int i = 0; i < sz (v[x]); i++) {
        int y = v[x][i];
        if (y == p) continue;
        if (use[y]) {
            int z = x;
            q[r++] = y;
            was[y] = 1;
            while (z != y) {
                q[r++] = z;
                was[z] = 1;
                z = prev[z];
            }
            re 1;
        } else
        if (go (y, x)) re 1;
    }
    re 0;
}

int main () {
    scanf ("%d", &n);
    for (int i = 0; i < n; i++) {
        int a, b;
        scanf ("%d%d", &a, &b); a--; b--;
        v[a].pb (b);
        v[b].pb (a);
    }
    l = r = 0;

    go (0, 0);
    while (l < r) {
        int x = q[l++];
        for (int i = 0; i < sz (v[x]); i++) {
            int y = v[x][i];
            if (!was[y]) {
                was[y] = 1;
                d[y] = d[x] + 1;
                q[r++] = y;
            }
        }
    }
    for (int i = 0; i < n; i++) printf ("%d ", d[i]);
    printf ("\n");
    return 0;
}