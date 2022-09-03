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

const int mul = 23917;
const int mod = 1000000000 + 7;

int n;
int m;
char h[400001];
char u[400001];
vi v[400001];
int anc[400001][20];
int d[400001];
int ht[400001];

int go (int x, int l, int p, int s) {
    d[x] = l;
    anc[x][0] = p;
    for (int i = 1; i < 20; i++)
        anc[x][i] = anc[anc[x][i - 1]][i - 1];
    ht[x] = s;
    for (int i = 0; i < sz (v[x]); i++) {
        int y = v[x][i];
        int ns = ((ll)s * mul + u[y]) % mod;
        go (y, l + 1, x, ns);
    }
    re 0;
}

int up (int x, int m) {
    int j = 19;
    while (d[x] > m)
        if (d[anc[x][j]] < m) j--; else x = anc[x][j];
    re x;
}

int main () {
    scanf ("%d", &n);
    int o = n;
    for (int i = 1; i < n; i++) {
        int x;
        scanf ("%d %s", &x, h); x--;
        int l = strlen (h);
        for (int j = 0; j < l; j++) {
            int y = i;
            if (j + 1 < l) {
                u[o] = h[j];
                y = o++;
            }   
            u[i] = h[l - 1];
            v[x].pb (y);
            x = y;
        }
    }
    scanf (" %s", h);
    int cur = 0;
    m = strlen (h);
    for (int i = 0; i < m; i++) cur = ((ll)cur * mul + h[i]) % mod;
    int base = 1;
    for (int i = 0; i < m; i++) base = ((ll)base * mul) % mod;
    go (0, 0, 0, 0);
    int ans = 0;
    for (int i = 0; i < o; i++)
        if (d[i] >= m) {
            int j = up (i, d[i] - m);
            int tmp = (ht[i] - (ll)ht[j] * base % mod + mod) % mod;
            if (tmp == cur) ans++;
        }
    printf ("%d\n", ans);
    return 0;
}