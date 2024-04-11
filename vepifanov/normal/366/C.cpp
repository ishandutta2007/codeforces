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
const int N = 100000;

int n;
int m;
int a[100], b[100];
int was[100][2 * N + 1];
int res[100][2 * N + 1];

int go (int i, int j) {
    if (i == n) re -inf * int (j != 0);
    if (was[i][j + N]) re res[i][j + N];
    was[i][j + N] = 1;
    re res[i][j + N] = max (go (i + 1, j), go (i + 1, j + a[i] - m * b[i]) + a[i]);
}

int main () {
    scanf ("%d%d", &n, &m);
    for (int i = 0; i < n; i++) scanf ("%d", &a[i]);
    for (int i = 0; i < n; i++) scanf ("%d", &b[i]);
    int ans = go (0, 0);
    if (ans <= 0) ans = -1;
    printf ("%d\n", ans);
    return 0;
}