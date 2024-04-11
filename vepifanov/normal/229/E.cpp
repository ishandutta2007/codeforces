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
vii v;
vi w;
double res[1001][1001];
int x[1000];
int y[1000];

int main () {
    scanf ("%d%d", &n, &m);
    for (int i = 0; i < m; i++) {
        scanf ("%d", &x[i]);
        for (int j = 0; j < x[i]; j++) {
            int y;
            scanf ("%d", &y);
            v.pb (mp (y, i));
        }
    }
    sort (all (v));
    reverse (all (v));
    int k = n;
    for (int i = 0; i < sz (v); i++)
        if (v[i].fi > v[k - 1].fi) {
            n--;
            y[v[i].se]++;
        } else
        if (v[i].fi == v[k - 1].fi)
            w.pb (v[i].se);
    double ans = 1;
    for (int i = 0; i < m; i++)
        for (int j = 0; j < y[i]; j++)
            ans = ans * (j + 1) / (x[i] - j);
    memset (res, 0, sizeof (res));
    res[0][0] = ans;
    for (int i = 0; i < sz (w); i++)
        for (int j = 0; j <= i; j++) {
            res[i + 1][j + 1] += res[i][j] * (y[w[i]] + 1) / (x[w[i]] - y[w[i]]) * (j + 1) / (i + 1);
            res[i + 1][j] += res[i][j] * (i - j + 1) / (i + 1);
        }           
    printf ("%.10f\n", res[sz (w)][n]);
    return 0;
}