#include <cstdio>
#include <stack>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#include <map>
#include <iostream>
#include <cmath>
#include <queue>
#include <map>
#define LL long long
#define pii pair <int, int>
using namespace std;

vector <int> g;
const int N = 1010;
const double eps = 1e-8;
double dp[N], ll;
int x[N], p[N], n, pre[N];

double f (double res) {
    for (int i = 1; i <= n; i++) {
        dp[i] = -1e10;
        for (int j = 0; j < i; j++) {
            dp[i] = max (dp[i], dp[j] + res * p[i] - sqrt(abs(x[i] - x[j] - ll)));
        }
    }
//    for (int i = 0; i <= n; i++) {
//        cout << dp[i] << ' ';
//    } cout << endl;
//    cout << res << ' ' << dp[n] << endl;
    return dp[n];
}

int main () {
//    freopen ("in.txt", "r", stdin);
    cin >> n >> ll;
    for (int i = 1; i <= n; i++) {
        scanf ("%d%d", &x[i], &p[i]);
    }
    double l = 0, r = 1000, res;
//    f (0.36);
    int T = 50;
    while (T--) {
        res = (l + r) / 2;
        if (f (res) < 0) l = res;
        else r = res;
    }
//    cout << res << endl;
    for (int i = 1; i <= n; i++) {
        dp[i] = -1e10;
        for (int j = 0; j < i; j++) {
            double tmp = dp[j] - sqrt(abs(x[i] - x[j] - ll));
//            cout << i << ' ' << j << ' '<< tmp << endl;
            if (dp[i] < tmp) {
                dp[i] = tmp;
                pre[i] = j;
            }
        }
        dp[i] += res * p[i];
    }
    while (n) { g.push_back (n); n = pre[n]; }
    int sz = g.size ();
    for (int i = sz - 1; i >= 0; i--) {
        cout << g[i];
        if (i) cout << ' ';
    }
}