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

int n;
int m;
int x[5000], y[5000], z[5000];
double d[5000];

int main() {
    scanf ("%d", &n);
    for (int i = 0; i < n; i++) scanf ("%d%d%d", &x[i], &y[i], &z[i]);
    for (int i = 1; i < n; i++) {
        x[i] -= x[0];
        y[i] -= y[0];
        z[i] -= z[0];
        d[i] = sqrt (x[i] * x[i] + y[i] * y[i] + z[i] * z[i] + 0.0);
    }   
    double ans = 1e10;
    for (int i = 1; i < n; i++)
        for (int j = i + 1; j < n; j++) {
            double cur = d[i] + d[j] + sqrt (sqr (x[i] - x[j]) + sqr (y[i] - y[j]) + sqr (z[i] - z[j]) + 0.0);
            ans = min (ans, cur / 2);
        }
    printf ("%.10f\n", ans);
    return 0;
}