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

int n, l, k;
int m;
int was[200][200][401];
double res[200][200][401];
double p[200];
int w[200];

double go (int i, int j, int k) {
    if (k > n) k = n;
    if (i == n) re int (j >= l && k >= 0);
    if (was[i][j][k + n]) re res[i][j][k + n];
    was[i][j][k + n] = 1;
    re res[i][j][k + n] = (1 - p[i]) * go (i + 1, j, k) + p[i] * go (i + 1, j + 1, k + w[i]);
}

int main () {
    scanf ("%d%d%d", &n, &l, &k);
    for (int i = 0; i < n; i++) {
        int x;
        scanf ("%d", &x);
        p[i] = x / 100.0;
    }   
    for (int i = 0; i < n; i++) scanf ("%d", &w[i]);
    printf ("%.10f\n", go (0, 0, k));
    return 0;
}