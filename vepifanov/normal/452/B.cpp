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
#define prev PREV
#define j0 j1347829
#define j1 j234892
                         
typedef vector<int> vi;
typedef long long ll;
typedef long double ld;
//typedef double D;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<string> vs;
typedef vector<vi> vvi;

template<class T> T abs(T x) { re x > 0 ? x : -x; }

const int D = 3;

int n;
int m;
vii v;
ii w[4];
ii u[4];
double ans = 0;
int was[(D + 1) * (D + 1) * 4];

double dist (ii a, ii b) {
    re sqrt (sqr (a.fi - b.fi) + sqr (a.se - b.se) + 0.0);
}

int go (int i) {
    if (i == 4) {
        double cur = 0;
        for (int j = 0; j < 3; j++)
            cur += dist (w[j], w[j + 1]);
//      printf ("%.10f\n", cur);
        if (cur > ans) {
//          printf ("ok\n");
            ans = cur;
            for (int j = 0; j < 4; j++)
                u[j] = w[j];//,             printf ("%d %d\n", u[j].fi, u[j].se);
                
        }
        re 0;
    }
    for (int j = 0; j < sz (v); j++)
        if (!was[j]) {
            was[j] = 1;
            w[i] = v[j];
            go (i + 1);
            was[j] = 0;
        }
    re 0;   
}

int main () {
    scanf ("%d%d", &n, &m);
    for (int a = 0; a <= n && a <= D; a++)
        for (int b = 0; b <= m && b <= D; b++) {
            v.pb (mp (a, b));
            v.pb (mp (n - a, b));
            v.pb (mp (a, m - b));
            v.pb (mp (n - a, m - b));
        }   
    sort (all (v));
    v.resize (unique (all (v)) - v.begin ());
    ans = 0;
    go (0);
    for (int i = 0; i < 4; i++)
        printf ("%d %d\n", u[i].fi, u[i].se);
    return 0;
}