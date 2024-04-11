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
int xa, ya, xb, yb, xc, yc, x, y;

int main () {
    scanf ("%d%d%d%d%d%d", &x, &y, &xb, &yb, &xc, &yc);
    int ok = 0;
    for (int t = 0; t < 4; t++) {
        int xa = xb - x;
        int ya = yb - y;
        if (xa == 0 && ya == 0) ok = 1; else
        if (xc != 0 || yc != 0) {
            ll d = sqr ((ll)xc) + sqr ((ll)yc);
            ll d1 = (ll)xa * xc + (ll)ya * yc;
            ll d2 = (ll)xa * yc - (ll)ya * xc;
            if (d1 % d == 0 && d2 % d == 0) ok = 1;
        }
        swap (x, y);
        x = -x;
    }
    if (ok) printf ("YES\n"); else printf ("NO\n");
    return 0;
}