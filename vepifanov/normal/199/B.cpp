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
int x[2], y[2];
int r[2][2];

int cross (int x1, int y1, int r1, int x2, int y2, int r2, int r3) {
    int d = sqr (x2 - x1) + sqr (y2 - y1);
    if (d < sqr (r1 + r3) && d > sqr (r1 - r3) || d < sqr (r1 + r2) && d > sqr (r1 - r2)) re 0;
    if (d >= sqr (r1 + r3)) re 1;
    if (r1 < r2 && d <= sqr (r1 - r2) || r1 > r3 && d <= sqr (r1 - r3)) re 1;
    re 0;
}

int main () {
    for (int i = 0; i < 2; i++) {
        scanf ("%d%d", &x[i], &y[i]);
        for (int j = 0; j < 2; j++) scanf ("%d", &r[i][j]);
    }
    int ans = 0;
    for (int i = 0; i < 2; i++) 
        for (int j = 0; j < 2; j++)
            ans += cross (x[i], y[i], r[i][j], x[1 - i], y[1 - i], r[1 - i][0], r[1 - i][1]);
    printf ("%d\n", ans);
    return 0;
}