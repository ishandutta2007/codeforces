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

const int MAX = 2e9;

int n;
int m;

int r;
ll p[30];
int w[30], ww[30];
int q[100000];
int g[100000][30];
int u[30];
int P[100000];
ll v;
ll X, Y, Z, ans;

int gen (int i, int x) {
    if (i == n) {
        for (int j = 0; j < n; j++)
            g[r][j] = u[j];
        P[r] = r;
        q[r++] = x;
        re 0;
    }
    for (int j = 0; j <= w[i]; j++)  {
        u[i] = j;
        gen (i + 1, x);
        if (j < w[i] && x <= MAX / p[i]) x *= p[i]; else break;
        if (x > v / x / x) break;
    }
    re 0;
}

int gen2 (int i, int x, int y, ll z) {
    if (i == n) {
        if (x >= y) {
            z /= x;
            ll tmp = (ll)y * x + y * z + x * z;
            if (tmp < ans) {
                ans = tmp;
                X = y;
                Y = x;
                Z = z;
            }
        }
        re 0;
    }
    for (int j = 0; j <= ww[i]; j++) {
        gen2 (i + 1, x, y, z);
        if (j < ww[i] && x <= MAX / p[i]) x *= p[i]; else break;
        if (x > z / x) break;
    }
    re 0;
}

bool l1 (int i, int j) {
    re q[i] < q[j];
}

int main () {
    int tt;
    scanf ("%d", &tt);
    for (int it = 0; it < tt; it++) {
        scanf ("%d", &n);
        v = 1;
        for (int i = 0; i < n; i++) {
            scanf ("%I64d%d", &p[i], &w[i]);
            for (int j = 0; j < w[i]; j++) v *= p[i];
        }   
        ans = 4e18;
        r = 0;
        gen (0, 1);
        sort (P, P + r, l1);
        for (int I = r - 1; I >= 0; I--) {
            int i = P[I];
            double b = sqrt (v / q[i] + 0.0);
            if (2 * q[i] * b + b * b >= ans) continue;
            for (int j = 0; j < n; j++)
                ww[j] = w[j] - g[i][j];
            gen2 (0, 1, q[i], v / q[i]);
        }
        cout << ans * 2 << " " << X << " " << Y << " " << Z << endl;
    }
    return 0;
}