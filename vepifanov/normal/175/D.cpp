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

const int MAX = 5000;

int n;
int m;
double res[2][MAX + 1][201];
int hp[2], dt[2];

int main () {
    for (int i = 0; i < 2; i++) {
        int l, r;
        double p;
        int pp;
        cin >> hp[i] >> dt[i] >> l >> r >> pp; p = pp / 100.0;
        if (i == 0 && pp == 100) {
            printf ("%.10f\n", 0.0);
            re 0;
        }
        if (i == 1 && pp == 100) {
            printf ("%.10f\n", 1.0);
            re 0;
        }
        res[i][0][0] = 1;
        for (int j = 1; j <= MAX; j++)
            for (int k = 0; k <= 200; k++) {
                for (int x = l; x <= r; x++)
                    res[i][j][k] += res[i][j - 1][max (k - x, 0)] * (1 - p);
                res[i][j][k] /= (r - l + 1);
                res[i][j][k] += res[i][j - 1][k] * p;
            }   
    }
    double ans = 0;
    for (int i = 1; i <= MAX; i++) {
        int j = max (0, ((i - 1) * dt[0] - 1) / dt[1] + int (i > 1));
//      if (j <= MAX) ans += res[0][i][hp[1]] - res[0][i - 1][hp[1]]; else
        if (j <= MAX) {
            ans += (res[0][i][hp[1]] - res[0][i - 1][hp[1]]) * (1 - res[1][j][hp[0]]);
//          printf ("%.10f %.10f %.10f %d %d\n", res[0][i][hp[1]], res[0][i][hp[1]] - res[0][i - 1][hp[1]], 1 - res[1][j][hp[0]], i, j);
        }   
    }
    printf ("%.10f\n", ans);
    return 0;
}