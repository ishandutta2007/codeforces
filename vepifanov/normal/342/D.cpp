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
int m;
string s[3];
int res[10001][8];
int was[10001][8];
int ct;
vii w;

int calc (int i, int mask) {
    if (i == n) re int (mask == 0);
    for (int j = 0; j < 3; j++)
        if (s[j][i] != '.') {
            if (mask & (1 << j)) re 0;
            mask |= 1 << j;
        }
    if (was[i][mask] == ct) re res[i][mask];
    was[i][mask] = ct;
    int cur = 0;
    if ((mask & 3) == 0)
        if (mask & 4) cur = (cur + calc (i + 1, 0)) % mod; else cur = (cur + calc (i + 1, 4)) % mod;
    if ((mask & 6) == 0)
        if (mask & 1) cur = (cur + calc (i + 1, 0)) % mod; else cur = (cur + calc (i + 1, 1)) % mod;
    cur = (cur + calc (i + 1, mask ^ 7)) % mod;
    re res[i][mask] = cur;
}

int main () {
    cin >> n;
    for (int i = 0; i < 3; i++) cin >> s[i];
    int si, sj;
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < n; j++)
            if (s[i][j] == 'O') {
                si = i;
                sj = j;
            }
    for (int t = 0; t < 4; t++) {
        int di = int (t == 0) - int (t == 1);
        int dj = int (t == 2) - int (t == 3);
        int ok = 1;
        for (int k = 1; k <= 2; k++) {
            int i = si + di * k;
            int j = sj + dj * k;
            if (i < 0 || j < 0 || i >= 3 || j >= n || s[i][j] == 'X') ok = 0;
        }
        if (ok) w.pb (mp (di, dj));         
    }
    m = sz (w);
    int ans = 0;
    for (int i = 1; i < (1 << m); i++) {
        int q = 0;
        for (int j = 0; j < m; j++)
            if ((i >> j) & 1) {
                q ^= 1;
                s[si + w[j].fi][sj + w[j].se] = 'X';
                s[si + 2 * w[j].fi][sj + 2 * w[j].se] = 'X';
            }
        ct++;
        int cur = calc (0, 0);
        for (int j = 0; j < m; j++)
            if ((i >> j) & 1) {
                s[si + w[j].fi][sj + w[j].se] = '.';
                s[si + 2 * w[j].fi][sj + 2 * w[j].se] = '.';
            }
        if (q) ans = (ans + cur) % mod; else ans = (ans + mod - cur) % mod;
    }
    printf ("%d\n", ans);
    return 0;
}