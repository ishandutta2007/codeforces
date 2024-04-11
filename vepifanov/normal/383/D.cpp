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

const int N = 10000;
const int mod = 1000000000 + 7;

int n;
int m;
int x[1000];
int res[1001][2 * N + 1];

int main () {
    scanf ("%d", &n);
    for (int i = 0; i < n; i++) scanf ("%d", &x[i]);
    memset (res, 0, sizeof (res));
    res[0][N] = 1;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= 2 * N; j++) {
            if (j - x[i] >= 0) res[i + 1][j] += res[i][j - x[i]];
            if (j + x[i] <= 2 * N) res[i + 1][j] += res[i][j + x[i]];
            res[i + 1][j] %= mod;
        }
        ans = (ans + res[i + 1][N]) % mod;
        res[i + 1][N] = (res[i + 1][N] + 1) % mod;
    }
    printf ("%d\n", ans);
    return 0;
}