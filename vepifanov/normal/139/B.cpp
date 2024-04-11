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
int x[500], y[500], z[500], l[500], w[500], c[500];

int main () {
    scanf ("%d", &n);
    for (int i = 0; i < n; i++) scanf ("%d%d%d", &x[i], &y[i], &z[i]);
    scanf ("%d", &m);
    for (int i = 0; i < m; i++) scanf ("%d%d%d", &l[i], &w[i], &c[i]);
    int ans = 0;
    for (int i = 0; i < n; i++) {
        int cur = 1e9;
        for (int j = 0; j < m; j++) 
            if (l[j] >= z[i]) {
                int t = (l[j] / z[i]) * w[j];
                cur = min (cur, c[j] * ((2 * (x[i] + y[i]) + t - 1) / t));
            }
        ans += cur;
    }
    printf ("%d\n", ans);
    return 0;
}