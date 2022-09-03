#include <cstdio>
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

using namespace std;

#define mp make_pair
#define pb push_back
#define rep(i,n) for(int i = 0; i < n; i++)
#define re return
#define fi first
#define se second
#define sz(x) ((int) (x).size())
#define all(x) (x).begin(), (x).end()
#define sqr(x) ((x) * (x))
#define y0 y3487465
#define y1 y8687969

typedef vector<int> vi;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<string> vs;
typedef vector<vi> vvi;

template<class T> T abs(T x) {
    re x > 0 ? x : -x;
}

const int MAX = 200;

int n;
int m;

double g[MAX + 1][MAX + 1];
double p[101];

int can (double h) {
    for (int i = 0; i <= MAX; i++)
        for (int j = 0; j <= MAX; j++)
            g[i][j] = int (i != j) * -1e9;
    for (int i = 0; i <= MAX; i++)
        for (int j = 0; j <= n; j++)
            if (i + n - 2 * j >= 0 && i + n - 2 * j <= MAX)
                g[i][i + n - 2 * j] = p[j] - h;
    for (int k = 0; k <= MAX; k++)
        for (int i = 0; i <= MAX; i++)
            for (int j = 0; j <= MAX; j++)
                g[i][j] = max (g[i][j], g[i][k] + g[k][j]);
    for (int i = 0; i <= MAX; i++)
        if (g[i][i] > 1e-9)
            re 1;
    re 0;
}

int main() {
    scanf ("%d", &n);
    for (int i = 0; i <= n; i++) scanf ("%lf", &p[i]);
    double l = 0, r = 1;
    while (r - l > 1e-6) {
        double s = (l + r) / 2;
        if (can (s)) l = s; else r = s;
    }
    printf ("%.10f\n", (l + r) / 2);
    return 0;
}