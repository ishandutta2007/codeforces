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
int x1, y1, x2, y2;
int x[1000], y[1000], r[1000];

int dist (int x1, int y1, int x2, int y2) {
    re sqr (x2 - x1) + sqr (y2 - y1);
}

int calc (int xc, int yc) {
    for (int i = 0; i < n; i++)
        if (dist (x[i], y[i], xc, yc) <= r[i] * r[i])
            re 0;
    re 1;
}

int main () {
    scanf ("%d%d%d%d", &x1, &y1, &x2, &y2);
    scanf ("%d", &n);
    for (int i = 0; i < n; i++) scanf ("%d%d%d", &x[i], &y[i], &r[i]);
    if (x1 > x2) swap (x1, x2);
    if (y1 > y2) swap (y1, y2);
    int ans = 0;
    for (int x = x1; x <= x2; x++) ans += calc (x, y1) + calc (x, y2);
    for (int y = y1 + 1; y < y2; y++) ans += calc (x1, y) + calc (x2, y);
    printf ("%d\n", ans);
    return 0;
}