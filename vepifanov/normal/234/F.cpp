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
int was[201][40001][2];
int res[201][40001][2];
int x[201];
int a, b;

int go (int i, int a, int b, int c) {
    if (i == -1) re 0;
    if (was[i][a][c]) re res[i][a][c];
    was[i][a][c] = 1;
    int cur = 1e9;
    if (a >= x[i]) cur = min (cur, go (i - 1, a - x[i], b, 0) + int (c == 1) * min (x[i], x[i + 1]));
    if (b >= x[i]) cur = min (cur, go (i - 1, a, b - x[i], 1) + int (c == 0) * min (x[i], x[i + 1]));
    re res[i][a][c] = cur;
}

int main () {
    freopen ("input.txt", "r", stdin);
    freopen ("output.txt", "w", stdout);
    scanf ("%d%d%d", &n, &a, &b);
    for (int i = 0; i < n; i++) scanf ("%d", &x[i]);
    x[n] = 0;
    int tmp = go (n - 1, a, b, 0);
    if (tmp > 1e6) tmp = -1;
    printf ("%d\n", tmp);
    return 0;
}