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

const double pi = 2 * asin (1.0);

int n;
int m;
int l, r;
int x[20];
int y[20];
double ang[20];
double cosa[20];
double sina[20];
double res[1 << 20];

int main () {
    scanf ("%d%d%d", &n, &l, &r);
    for (int i = 0; i < n; i++) {
        int c;
        scanf ("%d%d%d", &x[i], &y[i], &c);
        ang[i] = c / 180.0 * pi;
        cosa[i] = cos (ang[i]);
        sina[i] = sin (ang[i]);
    }
    for (int i = 0; i < (1 << n); i++) res[i] = -1e9;
    res[0] = l;
    for (int i = 0; i < (1 << n); i++) {
        double cur = res[i];
        for (int j = 0; j < n; j++)
            if (((i >> j) & 1) == 0)  {
                double xx = (cur - x[j]) * cosa[j] - (0 - y[j]) * sina[j] + x[j];
                double yy = (cur - x[j]) * sina[j] + (0 - y[j]) * cosa[j] + y[j];
                double tmp = r;
                if (yy < y[j] - 1e-6) tmp = min (tmp, x[j] + (xx - x[j]) / (y[j] - yy) * y[j]);
                res[i + (1 << j)] = max (res[i + (1 << j)], tmp);
            }
    }
    printf ("%.10f\n", res[(1 << n) - 1] - l);
    return 0;
}