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
int was[100][10001];
int res[100][10001];
int q[100];
int g[100][101];
int s1[101], s2[101], w[100];

int go (int i, int j) {
    if (i == n || j == 0) re 0;
    if (was[i][j]) re res[i][j];
    was[i][j] = 1;
    int cur = 0;
    for (int k = 0; k <= q[i] && k <= j; k++)
        cur = max (cur, go (i + 1, j - k) + g[i][k]);
    re res[i][j] = cur;
}

int main () {
    scanf ("%d%d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf ("%d", &q[i]);
        for (int j = 0; j < q[i]; j++) scanf ("%d", &w[j]);
        for (int j = 0; j <= q[i]; j++) g[i][j] = 0;
        s1[0] = s2[0] = 0;
        for (int j = 0; j < q[i]; j++) {
            s1[j + 1] = s1[j] + w[j];
            s2[j + 1] = s2[j] + w[q[i] - j - 1];
        }
        for (int j = 0; j <= q[i]; j++)
            for (int k = 0; j + k <= q[i]; k++)
                g[i][j + k] = max (g[i][j + k], s1[j] + s2[k]);
    }
    printf ("%d\n", go (0, m));
    return 0;
}