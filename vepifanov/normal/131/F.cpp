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
int m, k, ct;

char w[501][501];

int g[500][500], s[500][500], x[501];

int main () {
    scanf ("%d%d%d", &n, &m, &k);
    gets (w[0]);
    for (int i = 0; i < n; i++) gets (w[i]);
    n -= 2;
    m -= 2;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            g[i][j] = int (w[i + 1][j + 1] == '1' && w[i + 1][j] == '1' && w[i][j + 1] == '1' && w[i + 2][j + 1] == '1' && w[i + 1][j + 2] == '1');
    for (int i = 0; i < n; i++) {
        s[i][m] = 0;
        for (int j = m - 1; j >= 0; j--)
            s[i][j] = s[i][j + 1] + g[i][j];
    }
    ct = 0;
    ll ans = 0;
    for (int i = 0; i < m; i++)
        for (int j = i; j < m; j++) {
            x[n] = 0;
            for (int k = n - 1; k >= 0; k--) x[k] = x[k + 1] + s[k][i] - s[k][j + 1];
            int t = 0;
            for (int k = n - 1; k >= 0; k--) {
                while (x[k] - x[n - t - 1] >= ::k) t++;
                if (x[k] - x[n - t] >= ::k) ans += t + 1;
            }
        }
    printf ("%I64d\n", ans);
    return 0;
}