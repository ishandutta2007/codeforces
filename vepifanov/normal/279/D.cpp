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

const int N = 1 << 23;

int n;
int m;
int x[23];
bitset<N> res[24];
int can[N];
int g[23][23];

int main () {
    scanf ("%d", &n);
    for (int i = 0; i < n; i++) scanf ("%d", &x[i]);
    for (int i = 0; i < n; i++)
        for (int j = i; j < n; j++) {
            g[i][j] = -1;
            for (int k = 0; k < n; k++)
                if (x[i] + x[j] == x[k])
                    g[i][j] = k;
        }
    for (int i = 0; i < (1 << n); i++)
        for (int j = 0; j < n; j++)
            if ((i >> j) & 1) {
                for (int k = j; k < n; k++)
                    if ((i >> k) & 1)
                        if (g[j][k] != -1)
                            can[i] |= 1 << g[j][k];
                can[i] |= can[i - (1 << j)];
                break;
            }
    memset (res, 0, sizeof (res));
    res[1][1] = 1;
    for (int i = 1; i < n; i++)
        for (int j = 0; j < (1 << n); j++)
            if (res[i][j] && ((can[j] >> i) & 1)) {
                res[i + 1][j + (1 << i)] = 1;
                for (int t = 0; t < i; t++)
                    if ((j >> t) & 1)
                        res[i + 1][j - (1 << t) + (1 << i)] = 1;
            }
    int ans = -1;
    for (int i = 0; i < (1 << n); i++)              
        if (res[n][i]) {
            int cur = 0;
            for (int j = 0; j < n; j++)
                cur += (i >> j) & 1;
            if (ans > cur || ans == -1) ans = cur;
        }
    printf ("%d\n", ans);
    return 0;
}