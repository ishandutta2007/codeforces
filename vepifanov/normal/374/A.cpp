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

int n;
int m;
int nn, mm;
int i, j, a, b;

int get (int i1, int j1, int i2, int j2) {
    if (i1 == i2 && j1 == j2) re 0;
    if (nn == 1 || mm == 1) re inf;
    if ((i1 + j1) % 2 == (i2 + j2) % 2) re max (abs (i1 - i2), abs (j1 - j2));
    re inf;
}

int main () {
    scanf ("%d%d%d%d%d%d", &n, &m, &i, &j, &a, &b);
    nn = (n - (i - 1) % a - 1) / a + 1;
    mm = (m - (j - 1) % b - 1) / b + 1;
    int ii = (i - 1) / a + 1;
    int jj = (j - 1) / b + 1;
    int ans = inf;
    if (i % a == 1 % a && j % b == 1 % b) ans = min (ans, get (ii, jj, 1, 1));
    if (i % a == n % a && j % b == 1 % b) ans = min (ans, get (ii, jj, nn, 1));
    if (i % a == 1 % a && j % b == m % b) ans = min (ans, get (ii, jj, 1, mm));
    if (i % a == n % a && j % b == m % b) ans = min (ans, get (ii, jj, nn, mm));
    if (ans == inf) printf ("Poor Inna and pony!\n"); else printf ("%d\n", ans);
    return 0;
}