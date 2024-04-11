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

const int N = 40000;
const int M = 5100;

int n;
int m;
int f[N];
int p[M];
int q[M];
int r = 0;
int a[M];
int b[M];
int c[M];
int x[M];
int y[M];
set<int> all;

int res[M][M];

int gcd (int a, int b) { re a ? gcd (b % a, a) : b; }

int calc (int x) {
    int cur = 0;
    for (int i = 0; i < r; i++)
        while (x % p[i] == 0) {
            cur += q[i];
            x /= p[i];
        }
    if (x > 1) cur += 1 - 2 * int (all.find (x) != all.end ());
    re cur;
}

int main () {
    scanf ("%d%d", &n, &m);
    for (int i = 0; i < n; i++) scanf ("%d", &a[i]);
    for (int i = 0; i < m; i++) {
        int x;
        scanf ("%d", &x);
        all.insert (x);
    }
    for (int i = 2; i < N; i++)
        if (!f[i]) {
            p[r] = i;
            q[r] = 1 - 2 * int (all.find (i) != all.end ());
            r++;
            for (int j = i; j < N; j += i)
                f[j] = 1;
        }
    int cur = 0;
    for (int i = 0; i < n; i++) {
        cur = gcd (cur, a[i]);
        c[i] = cur;
        x[i] = calc (a[i]);
        y[i] = calc (cur);
    }
    c[n] = 1;
    y[n] = 0;
    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= n; j++)
            res[i][j] = -1e9;
    res[n][n] = 0;
    for (int i = n; i > 0; i--)
        for (int j = i; j <= n; j++) {
            res[i - 1][j] = max (res[i - 1][j], res[i][j] + x[i - 1] - y[j]);
            res[i - 1][i - 1] = max (res[i - 1][i - 1], res[i][j] + x[i - 1] - y[i - 1]);
        }
    int ans = -1e9;
    for (int i = 0; i <= n; i++) ans = max (ans, res[0][i]);
    printf ("%d\n", ans);
    return 0;
}