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

#define filename ""

const double pi = 2 * asin (1.0);

const int mod = 1000000000 + 7;

int n;
int m;
int was[2002];
int pos[2002];
int res[2002][2002];
int f[2002];

int power (int a, int b) {
    int c = 1;
    while (b) {
        if (b & 1) c = ((ll)c * a) % mod;
        a = ((ll)a * a) % mod;
        b /= 2;
    }
    re c;
}

int main () {
    scanf ("%d", &n);
    for (int i = 0; i < n; i++) {
        int x;
        scanf ("%d", &x);
        if (x == -1) pos[i] = 1; else was[x - 1] = 1;
    }
    int x = 0, y = 0;
    for (int i = 0; i < n; i++)
        if (pos[i] == 1) {
            y++;
            if (!was[i]) x++;
        }
    f[0] = 1;
    for (int i = 1; i <= n; i++) f[i] = ((ll)f[i - 1] * i) % mod;
    res[0][0] = 1;
    for (int i = 0; i < x; i++)
        for (int j = 0; j <= i; j++) {
            int cur = res[i][j];
            if (!cur) continue;
//          printf ("%d %d = %d %d\n", i, j, cur, y);
            int c1 = ((ll)cur * (i - j)) % mod;
            c1 = ((ll)c1 * power (y - i, mod - 2)) % mod;
            int c0 = cur - c1;
            if (c0 < 0) c0 += mod;
            if (i - j > 0) {
                res[i + 1][j + 1] = (res[i + 1][j + 1] + (ll)(i - j) * c0 % mod) % mod;
                res[i + 1][j + 2] = (res[i + 1][j + 2] + (ll)(i - j) * c1 % mod) % mod;
            }   
            if (y + j - 2 * i - 1 > 0)
                res[i + 1][j] = (res[i + 1][j] + (ll)(y + j - 2 * i - 1) * c0 % mod) % mod;
            if (y + j - 2 * i > 0)
                res[i + 1][j + 1] = (res[i + 1][j + 1] + (ll)(y + j - 2 * i) * c1 % mod) % mod;
        }
    int ans = 0;
    for (int j = 0; j <= x; j++)
        ans = (ans + (ll)res[x][j] * f[y - x]) % mod;
    printf ("%d\n", ans);
    return 0;
}