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

const int INF = 1e9;

int n;
int m;

int g[300][300];
int res[601][301][301];

int go (int t, int ai, int bi) {
    int aj = t - ai;
    int bj = t - bi;
    if (ai < 0 || ai >= n || bi < 0 || bi >= n || aj < 0 || aj >= n || bj < 0 || bj >= n) re -1e9;
    if (t == 2 * n - 2) re g[n - 1][n - 1];
    if (res[t][ai][bi] > -INF) re res[t][ai][bi];
    int cur = -1e9;
    for (int a = 0; a <= 1; a++)
        for (int b = 0; b <= 1; b++)
            cur = max (cur, go (t + 1, ai + a, bi + b));
    cur += g[ai][aj] + g[bi][bj] * int (ai != bi);
    re res[t][ai][bi] = cur;
}

int main () {
    scanf ("%d", &n);
    for (int i = 0; i < n; i++) 
        for (int j = 0; j < n; j++)
            scanf ("%d", &g[i][j]);
    for (int i = 0; i < 2 * n; i++)
        for (int j = 0; j < n; j++)
            for (int k = 0; k < n; k++)
                res[i][j][k] = -INF;
    printf ("%d\n", go (0, 0, 0));
    return 0;
}