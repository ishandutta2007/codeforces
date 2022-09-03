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
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<string> vs;
typedef vector<vi> vvi;

template<class T> T abs(T x) { re x > 0 ? x : -x; }

const int M = 320;
const int mod = 1000000000 + 7;
const int N = 100000;

int n;
int m;
int d;
int res[2][M][M];

int main () {
    scanf ("%d%d%d", &m, &n, &d); d--;
    if (m > n) {
        printf ("0\n");
        re 0;
    }
    res[n & 1][m][0] = 1;
    for (int i = n - 1; i >= 0; i--) {
            int ci = i & 1;
            int ni = 1 - ci;
        for (int j = 0; j <= m; j++)
            for (int k = 0; k <= m; k++) {
                unsigned int cur = 0;
                if (i != d) {
                    cur += res[ni][j][k];
                    if (k > 0) cur += res[ni][j][k - 1];
                }
                cur += res[ni][j + 1][k + 1] + res[ni][j + 1][k];
                res[ci][j][k] = cur % mod;
            }
    }
    int ans = res[0][0][0];
    for (int i = 2; i <= m; i++) ans = ((ll)ans * i) % mod;
    cout << ans << endl;
    return 0;
}