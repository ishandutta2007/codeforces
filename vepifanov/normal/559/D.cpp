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
int x[200000];
int y[200000];
ld p[200001];

int gcd (int a, int b) { re a ? gcd (b % a, a) : b; }

int main () {
    scanf ("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf ("%d%d", &x[i], &y[i]);
        x[i + n] = x[i];
        y[i + n] = y[i];
    }
    p[0] = 1;
    for (int i = 1; i <= 2 * n; i++) p[i] = p[i - 1] / 2;
    ld sum = 0, cx = 0, cy = 0, sx = 0, sy = 0;
    for (int i = 0; i < n; i++) {
        cx += x[i];
        cy += y[i];
        sx = sx / 2 + x[i];
        sy = sy / 2 + y[i];
    }
    for (int i = 0; i < n; i++) {
        cx -= x[i];
        cy -= y[i];
        sx -= x[i] * p[n - 1];
        sy -= y[i] * p[n - 1];
        sum -= x[i] * (sy / 4 - cy * p[n]) - y[i] * (sx / 4 - cx * p[n]);
        cx += x[i + n];
        cy += y[i + n];
        sx = sx / 2 + x[i + n];
        sy = sy / 2 + y[i + n];
    }
    sum /= 2;
    ld tmp2 = 1;
    for (int i = 0; i < n; i++) tmp2 /= 2;
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < i + n && j < i + 100; j++)
            sum -= gcd (abs (x[j] - x[i]), abs (y[j] - y[i])) * (p[(j - i) + 1] - tmp2) / 2;
    ld tmp = 1 + n + (ld)n * (n - 1) / 2;
    for (int i = 0; i < n; i++) tmp /= 2;
    printf ("%.10f\n", (D)(sum / (1 - tmp)) + 1);
    return 0;
}