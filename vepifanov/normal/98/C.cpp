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
double a, b, p;

double calc (double ang) {
    double x = cos (ang) * p;
    double y = sin (ang) * p;
    re -((a - x) * (b - y) - a * b) / p;
}

int main () {
    cin >> a >> b >> p;
    double l = 0, r = pi / 2;
    for (int it = 0; it < 200; it++) {
        double s1 = l + (r - l) / 3;
        double s2 = l + 2 * (r - l) / 3;
        double f1 = calc (s1);
        double f2 = calc (s2);
        if (f1 < f2) r = s2; else l = s1;
    }
    double res = min (calc ((l + r) / 2), p);
    if (p < max (a, b) + 1e-9) res = max (res, min (a, b));
    if (res < 0) printf ("My poor head =(\n"); else printf ("%.10f\n", min (res, p));
    return 0;
}