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
int was[100][7];
int a[100], b[100];
int x;

int go (int i, int x) {
    if (i == n) re 1;
    if (was[i][x]) re 1;
    was[i][x] = 1;
    int cur = 0;
    for (int y = 1; y <= 6; y++)
        if (y != x && y != a[i] && y != b[i] && y != 7 - a[i] && y != 7 - b[i])
            cur += go (i + 1, y);
    re cur;
}

int main () {
    scanf ("%d", &n);
    scanf ("%d", &x);
    for (int i = 0; i < n; i++) scanf ("%d%d", &a[i], &b[i]);
    if (go (0, 7 - x) != 1) printf ("NO\n"); else printf ("YES\n");
    return 0;
}