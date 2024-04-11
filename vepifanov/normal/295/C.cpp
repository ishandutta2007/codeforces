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

const int inf = 1e9;
const int mod = 1000000000 + 7;

int n;
int m;
ii res[51][51][2];
int d[51][51][2];
pair<ii, int> q[51 * 51 * 2];
int a, b;
int cnk[51][51];

int upd (int t, int a, int b, int c, int d, int mul) {
    if (::d[a][b][t] + 1 == ::d[c][d][t ^ 1]) {
        if (res[a][b][t].fi > res[c][d][t ^ 1].fi + 1) res[a][b][t] = mp (res[c][d][t ^ 1].fi + 1, ((ll)res[c][d][t ^ 1].se * mul) % mod); else
        if (res[a][b][t].fi == res[c][d][t ^ 1].fi + 1) res[a][b][t].se = (res[a][b][t].se + (ll)res[c][d][t ^ 1].se * mul) % mod;
    }
    re 0;
}

int get (int a, int b, int c, int d) {
    re ((ll)cnk[a][c] * cnk[b][d]) % mod;
}

int main () {
    for (int i = 0; i <= 50; i++)
        for (int j = 0; j <= i; j++)
            if (i == 0 || j % i == 0)
                cnk[i][j] = 1;
            else
                cnk[i][j] = (cnk[i - 1][j] + cnk[i - 1][j - 1]) % mod;
    scanf ("%d%d", &n, &m); m /= 50;
    for (int i = 0; i < n; i++) {
        int x;
        scanf ("%d", &x);
        a += int (x == 50);
        b += int (x == 100);
    }
    int l = 0, r = 1;
    d[a][b][0] = 1;
    q[0] = mp (mp (a, b), 0);
    while (l < r) {
        int a = q[l].fi.fi;
        int b = q[l].fi.se;
        int e = q[l].se;
        int c = ::a - a;
        int d = ::b - b;
        l++;
        for (int x = 0; x <= a; x++)
            for (int y = 0; y <= b && x + 2 * y <= m; y++)
                if (x + y > 0)
                    if (!::d[c + x][d + y][e ^ 1]) {
                        ::d[c + x][d + y][e ^ 1] = ::d[a][b][e] + 1;
                        q[r++] = mp (mp (c + x, d + y), e ^ 1);
                    }
    }
    if (!::d[a][b][1]) {
        printf ("-1\n0\n");
        re 0;
    }
    for (int l = r - 1; l >= 0; l--) {  
        int a = q[l].fi.fi;
        int b = q[l].fi.se;
        int e = q[l].se;
        int c = ::a - a;
        int d = ::b - b;
        res[a][b][e] = mp (inf, 0);
        if (c == 0 && d == 0 && e == 1) res[a][b][e] = mp (0, 1);
        for (int x = 0; x <= a; x++)
            for (int y = 0; y <= b && x + 2 * y <= m; y++)
                if (x + y > 0)
                    upd (e, a, b, c + x, d + y, get (a, b, x, y));
    }
    printf ("%d\n%d\n", res[a][b][0].fi, res[a][b][0].se);
    return 0;
}