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
#define prev PREV
                         
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
int T;

double res[2][5001];

int main () {
    scanf ("%d%d", &n, &T);
    memset (res, 0, sizeof (res));
    res[0][0] = 1;
    double ans = 0;
    for (int i = 0; i < n; i++) {
        int ci = i & 1;
        int ni = 1 - ci;
        memset (res[ni], 0, sizeof (res[ni]));
        int pp, t;
        scanf ("%d%d", &pp, &t);
        double p = pp / 100.0;
        double cur = 0;
        double base = 1;
        for (int j = 0; j < t - 1; j++) base *= 1 - p;
        for (int j = 0; j <= T; j++) {
            cur -= j >= t ? res[ci][j - t] * base : 0;
            res[ni][j] = cur * p + (j >= t ? res[ci][j - t] * base : 0);
            cur = cur * (1 - p) + res[ci][j];
        }
        ans = (ans + cur * i);
    }
    for (int i = 0; i <= T; i++) ans += n * res[n & 1][i];
    printf ("%.10f\n", ans);
    return 0;
}