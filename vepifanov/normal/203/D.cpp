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
int m, a, b, vx, vy, vz;

double get (double x, double a) {
    if (x > 0) {
        double y = 0;
        while (y + a < x) y += a;
        while (x > a) {
            x = 2 * y - x;
            y -= a;
        }
    } else {
        double y = 0;
        while (y - a > x) y -= a;
        while (x < 0) {
            x = 2 * y - x;
            y += a;
        }
    }
    re x;
}

int main () {
    scanf ("%d%d%d%d%d%d", &a, &b, &m, &vx, &vz, &vy);
    double t = -(m + 0.0) / vz;
    double x = a / 2.0 + t * vx;
    double y = t * vy;
    printf ("%.10f %.10f\n", get (x, a), get (y, b));
    return 0;
}