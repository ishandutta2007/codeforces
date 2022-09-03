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

int main () {
    double r1 = 0, p1 = 0, p2 = 1e9;
    scanf ("%d", &n);
    for (int i = 0; i < n; i++) {
        double x;
        scanf ("%lf", &x);
        r1 = max (r1, x);
    }
    scanf ("%d", &n);
    for (int i = 0; i < n; i++) {
        double x;
        scanf ("%lf", &x);
        p1 = max (p1, x);
    }
    scanf ("%d", &n);
    for (int i = 0; i < n; i++) {
        double x;
        scanf ("%lf", &x);
        p2 = min (p2, x);
    }
    double a, b;
    scanf ("%lf%lf", &a, &b);
    printf ("%.10f\n", r1 / sqrt ((a * p2) / (b * p1) + 1));
    return 0;
}