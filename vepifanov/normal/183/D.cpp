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

double res[300][3001];
double g[300][3001];
double cur[300];

double go (int t) {
    double cur = 0;
    for (int i = 0; i <= n; i++) {
        double tmp = res[t][i];
        res[t][i] = cur * g[t][i];
        cur = cur * (1 - g[t][i]) + tmp;
    }
    re 1 - cur;
}

int main () {
    scanf ("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
        for (int j = 0; j < m; j++) {
            scanf ("%lf", &g[j][i]);
            g[j][i] /= 1000;
        }
    memset (res, 0, sizeof (res));
    for (int i = 0; i < m; i++) res[i][0] = 1;
    for (int i = 0; i < m; i++) cur[i] = go (i);
    double ans = 0;
    for (int i = 0; i < n; i++) {
        int k = 0;
        for (int j = 0; j < m; j++)
            if (cur[k] < cur[j])
                k = j;
        ans += cur[k];
        cur[k] += go (k) - 1;
    }
    printf ("%.10f\n", ans);
    return 0;
}