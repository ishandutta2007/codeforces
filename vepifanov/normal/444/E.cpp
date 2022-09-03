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
typedef double D;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<string> vs;
typedef vector<vi> vvi;

template<class T> T abs(T x) { re x > 0 ? x : -x; }

int n;
int m;
int p[10000];
int x[10000];
int y[10000];
int w[10000];
pair<int, ii> v[10000]; 

int gp (int x) {
    if (p[x] == x) re x;
    re p[x] = gp (p[x]);
}

int can (int h) {
    for (int i = 0; i < n; i++) {
        p[i] = i;
        x[i] = 1;
        y[i] = w[i];
    }
    for (int i = 0; i < h; i++) {
        int a = gp (v[i].se.fi);
        int b = gp (v[i].se.se);
        if (a != b) {
            p[a] = b;
            x[b] += x[a];
            y[b] += y[a];
        }
    }
    int sx = 0, sy = 0;
    vii u;
    for (int i = 0; i < n; i++)
        if (p[i] == i) {
            u.pb (mp (x[i], y[i]));
            sx += x[i];
            sy += y[i];
        }
    for (int i = 0; i < sz (u); i++)
        if (u[i].fi > sy - u[i].se)
            re 0;
    re 1;
}

int main () {
    scanf ("%d", &n);
    for (int i = 0; i + 1 < n; i++) {
        int a, b, c;
        scanf ("%d%d%d", &a, &b, &c); a--; b--;
        v[i] = mp (c, mp (a, b));
    }
    for (int i = 0; i < n; i++) scanf ("%d", &w[i]);
    sort (v, v + n - 1);
    int l = 0, r = n;
    while (r - l > 1) {
        int s = (l + r) / 2;
        if (can (s)) l = s; else r = s;
    }
    printf ("%d\n", v[l].fi);
    return 0;
}