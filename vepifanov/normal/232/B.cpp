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

const int mod = 1000000000 + 7;

int n;
ll m;
int k;
int res[101][10001];
int g[101][101];
int c[101][101];

int power (int a, ll b) {
    int c = 1;
    while (b) {
        if (b & 1) c = ((ll)c * a) % mod;
        b /= 2;
        a = ((ll)a * a) % mod;
    }
    re c;
}

int main () {
    for (int i = 0; i <= 100; i++)
        for (int j = 0; j <= i; j++)
            if (i == 0 || j % i == 0)
                c[i][j] = 1;
            else
                c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % mod;
    cin >> n >> m >> k;
    for (int i = 0; i < n; i++)
        for (int j = 0; j <= n; j++)
            g[i][j] = power (c[n][j], (m - i - 1) / n + 1);
    memset (res, 0, sizeof (res));
    res[0][0] = 1;
    for (int i = 0; i < n; i++)
        for (int j = 0; j <= i * n && j <= k; j++)
            for (int t = 0; t <= n && j + t <= k; t++)
                res[i + 1][j + t] = (res[i + 1][j + t] + (ll)res[i][j] * g[i][t]) % mod;
    printf ("%d\n", res[n][k]);
    return 0;
}