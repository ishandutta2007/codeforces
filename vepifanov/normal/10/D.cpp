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
int m, x[501], y[501], prev[501][501], res[501][501], py[501], g[501][501];
vector<int> v;

int out (int j, int i) {
    int k = prev[j][i];
    if (k != -1) {
        while (y[k] != x[i]) i--;
        out (k, i);
    }
    v.push_back (y[j]);
}

int main() {
    int n, m;
    scanf ("%d", &n);
    for (int i = 0; i < n; i++) scanf ("%d", &x[i]);
    scanf ("%d", &m);
    for (int i = 0; i < m; i++) scanf ("%d", &y[i]);
    memset (res, 0, sizeof (res));
    for (int i = 0; i < m; i++) py[i] = -1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            if (x[i] == y[j])
                py[j] = i;
        for (int j = 0; j < m; j++)
            g[i][j] = py[j];
    }
    for (int i = 0; i < n; i++) 
        for (int j = 0; j < m; j++)
            prev[j][i] = -1;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        int cur = 0, last = -1;
        for (int j = 0; j < m; j++) {
            int k = g[i][j];
            if (k != -1 && y[j] < x[i] && cur < res[j][k]) {
                cur = res[j][k];
                last = j;
            }
            if (y[j] == x[i] && cur + 1 > res[j][i]) {
                res[j][i] = cur + 1;
                prev[j][i] = last;
            }
            if (res[j][i] > ans) {
                ans = res[j][i];
                v.clear ();
                out (j, i);
            }                                          
        }
    }
    printf ("%d\n", ans);
    if (ans > 0) {
        for (int i = 0; i < ans; i++) printf ("%d ", v[i]);
        printf ("\n");
    }
    return 0;
}