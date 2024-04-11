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
#define prev PREV
                         
typedef vector<int> vi;
typedef long long ll;
typedef long double D;
//typedef double D;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<string> vs;
typedef vector<vi> vvi;

template<class T> T abs(T x) { re x > 0 ? x : -x; }

int n;
int m;
double a, b, c, d;

pair<D, D> mul (D a1, D a2, D b1, D b2) {
    D l = min (min (a1 * b1, a1 * b2), min (a2 * b1, a2 * b2));
    D r = max (max (a1 * b1, a1 * b2), max (a2 * b1, a2 * b2));
    re mp (l, r);
}

bool can (D h) {
    pair<D, D> x = mul (a - h, a + h, d - h, d + h);
    pair<D, D> y = mul (b - h, b + h, c - h, c + h);
    re max (x.fi, y.fi) <= min (x.se, y.se);
}              

int main () {
    cin >> a >> b >> c >> d;
    D l = 0, r = 1e10;
    for (int it = 0; it < 200; it++) {
        D s = (l + r) / 2;
        if (can (s)) r = s; else l = s;
    }
    printf ("%.10f\n", (double)((l + r) / 2));
    return 0;
}