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
int m, k;
int x[50], y[50], z[50], p[50];

ll go (int m, int j) {
    ll ans = -1e18;

    if (!(m & 1)) {
        ans = 0;
        for (int i = 0; i < n; i++) ans += (ll)x[i] * z[i];
        if (m == 0) re ans;
    }
    int X[50];
    for (int i = 0; i < n; i++) X[i] = x[i];
    if (!j) {
        for (int i = 0; i < n; i++) x[i] ^= y[i];
        ans = max (ans, go (m - 1, 1));
    }
    for (int i = 0; i < n; i++) x[i] = X[p[i] - 1] + k;
    ans = max (ans, go (m - 1, 0));
    for (int i = 0; i < n; i++) x[i] = X[i];
    re ans;
}

int main () {
    scanf ("%d%d%d", &n, &m, &k);
    for (int i = 0; i < n; i++) scanf ("%d", &x[i]);
    for (int i = 0; i < n; i++) scanf ("%d", &y[i]);
    for (int i = 0; i < n; i++) scanf ("%d", &z[i]);
    for (int i = 0; i < n; i++) scanf ("%d", &p[i]);
    printf ("%I64d\n", go (m, 0));
    return 0;
}