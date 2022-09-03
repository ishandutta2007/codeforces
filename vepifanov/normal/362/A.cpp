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

string s[8];
int was[8][8][8][8];

int go (int i1, int j1, int i2, int j2) {
    if (i1 < 0 || j1 < 0 || i1 > 7 || j1 > 7 || i2 < 0 || j2 < 0 || i2 > 7 || j2 > 7 || was[i1][j1][i2][j2]) re 0;
    if (i1 == i2 && j1 == j2 && s[i1][j1] != '#') re 1;
    was[i1][j1][i2][j2] = 1;
    for (int a = -2; a <= 2; a += 4)
        for (int b = -2; b <= 2; b += 4)
            for (int c = -2; c <= 2; c += 4)
                for (int d = -2; d <= 2; d += 4)
                    if (go (i1 + a, j1 + b, i2 + c, j2 + d))
                        re 1;
    re 0;
}

int main () {
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int a = 0; a < 8; a++) cin >> s[a];
        vii v;
        for (int a = 0; a < 8; a++)
            for (int b = 0; b < 8; b++)
                if (s[a][b] == 'K')
                    v.pb (mp (a, b));
        memset (was, 0, sizeof (was));
        if (go (v[0].fi, v[0].se, v[1].fi, v[1].se)) printf ("YES\n"); else printf ("NO\n");
    }
    return 0;
}