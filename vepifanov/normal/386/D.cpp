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
#include <cassert>

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
int was[70][70][70];
ii prev[70][70][70];
string g[70];
int a, b, c;
pair<int, ii> q[70 * 70 * 70];

int cool (int a, int b, int c) {
    re int (a + b + c == 3);
}

int out (int a, int b, int c, int k) {
    int x = prev[a][b][c].fi;
    int y = prev[a][b][c].se;
    if (x == 0) {
        printf ("%d\n", k);
        re 0;
    }
    if (x == 1) out (y, b, c, k + 1);
    if (x == 2) out (a, y, c, k + 1);
    if (x == 3) out (a, b, y, k + 1);
    printf ("%d %d\n", y + 1, (x == 1 ? a : (x == 2 ? b : c)) + 1);
    re 0;
}

int main () {
    cin >> n;
    cin >> a >> b >> c; a--; b--; c--;
    int tmp = a + b + c;
    for (int i = 0; i < n; i++) cin >> g[i];
    int l = 0, r = 1;
    q[0] = mp (a, mp (b, c));
    prev[a][b][c] = mp (0, 0);
    was[a][b][c] = 1;
    while (l < r) {
        a = q[l].fi;
        b = q[l].se.fi;
        c = q[l].se.se;
        l++;
        if (cool (a, b, c)) {
            out (a, b, c, 0);
            re 0;
        }
        for (int k = 0; k < n; k++) {
            if (k == a || k == b || k == c) continue;
            if (g[a][k] == g[b][c] && !was[k][b][c]) {
                prev[k][b][c] = mp (1, a);
                was[k][b][c] = 1;
                q[r++] = mp (k, mp (b, c));
            }
            if (g[b][k] == g[a][c] && !was[a][k][c]) {
                prev[a][k][c] = mp (2, b);
                was[a][k][c] = 1;
                q[r++] = mp (a, mp (k, c));
            }
            if (g[c][k] == g[a][b] && !was[a][b][k]) {
                prev[a][b][k] = mp (3, c);
                was[a][b][k] = 1;
                q[r++] = mp (a, mp (b, k));
            }
        }
    }
    printf ("-1\n");
    return 0;                            
}