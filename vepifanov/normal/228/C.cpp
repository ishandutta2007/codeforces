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
int can[500][500];
int FILL[500][500];
int ncan[500][500];
int nFILL[500][500];
string s[500];

int main () {
    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> s[i];
    int ans = 0;
    for (int mask = 0; mask < 16; mask++) {
        memset (can, 0, sizeof (can));
        memset (FILL, 0, sizeof (FILL));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if (s[i][j] == '.')
                    can[i][j] = 1;
                else
                    FILL[i][j] = 1;
        for (int l = 1; 2 * l <= min (n, m); l *= 2) {
            memset (ncan, 0, sizeof (ncan));
            memset (nFILL, 0, sizeof (nFILL));
            for (int i = 0; i + 2 * l <= n; i++)
                for (int j = 0; j + 2 * l <= m; j++) {
                    int ccan = 1, cFILL = 1;
                    for (int p = 0; p < 2; p++)
                        for (int q = 0; q < 2; q++) {
                            cFILL &= FILL[i + p * l][j + q * l];
                            if ((mask >> (p * 2 + q)) & 1) ccan &= FILL[i + p * l][j + q * l]; else ccan &= can[i + p * l][j + q * l];
                        }
                    ncan[i][j] = ccan;
                    nFILL[i][j] = cFILL;
                    if (l >= 2 && ccan) ans += ccan;
                }   
            for (int i = 0; i + 2 * l <= n; i++)
                for (int j = 0; j + 2 * l <= m; j++) {
                    can[i][j] = ncan[i][j];
                    FILL[i][j] = nFILL[i][j];
                }   
        }   
    }   
    printf ("%d\n", ans);
    return 0;
}