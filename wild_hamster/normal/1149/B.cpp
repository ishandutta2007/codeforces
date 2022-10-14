#include <algorithm>
#include <string>
#include <time.h>
#include <iostream>
#include <vector>
#include <utility>
#include <bitset>
#include <cmath>
#include <map>
#include <set>

#define mp make_pair
#define X first
#define Y second
#define pii pair<ll,ll>
#define x1 dlfjl
#define x2 dkfj
#define x3 dflgkg
#define y1 dskgj
#define y2 dskfj
#define y3 dfhgdh
#define SQ 320
#define PI 3.14159265359
#define MOD 1000003
typedef int ll;
using namespace std;

ll a[300500], x, y, z, n, m, q, dp[255][255][255];

ll Abs(ll x) {
    return (x > 0 ? x : -x);
}
vector<ll> g[26];
ll sz[4];
ll nxt[27][100005];
ll cur[27][100005];
vector<char> curp[5];

void update(ll x, ll y, ll z) {
    if (x > sz[1] || y > sz[2] || z > sz[3]) {
        return;
    }
    if (x > 0) {
        dp[x][y][z] = min(dp[x][y][z], nxt[curp[1][x-1] - 'a'][dp[x-1][y][z] + 1]);
    }
    if (y > 0) {
        dp[x][y][z] = min(dp[x][y][z], nxt[curp[2][y-1] - 'a'][dp[x][y-1][z] + 1]);
    }
    if (z > 0) {
        dp[x][y][z] = min(dp[x][y][z], nxt[curp[3][z-1] - 'a'][dp[x][y][z-1] + 1]);
    }
}
int main() {
    string s;
    cin >> n >> q;
    cin >> s;
    for (int i = 0; i < s.size(); i++) {
        cur[s[i]-'a'][i] = 1;
    }
    for (int i = 0; i < 26; i++) {
        nxt[i][n] = nxt[i][n+1] = n;
        for (int j = n-1; j >= 0; j--) {
            if (cur[i][j]) {
                nxt[i][j] = j;
            } else {
                nxt[i][j] = nxt[i][j+1];
            }
        }
    }
    for (int i = 0; i <= 250; i++) {
        for (int j = 0; j <= 250; j++) {
            for (int k = 0; k <= 250; k++) {
                dp[i][j][k] = MOD;
            }
        }
    }
    dp[0][0][0] = -1;
    for (int i = 0; i < q; i++) {
        ll t;
        char c1, c2;
        cin >> c1 >> t;

        if (c1 == '-') {
            curp[t].pop_back();
           for (int i = 0; i <= 250; i++) {
               for (int j = 0; j <= 250; j++) {
                   if (t == 1) {
                       dp[sz[t]][i][j] = MOD;
                   }

                   if (t == 2) {
                       dp[i][sz[t]][j] = MOD;
                   }


                   if (t == 3) {
                       dp[i][j][sz[t]] = MOD;
                   }
               }
           }
           sz[t]--;
        } else {
            cin >> c2;
            curp[t].push_back(c2);

            sz[t]++;

            for (int i = 0; i <= 250; i++) {
                for (int j = 0; j <= 250; j++) {
                    if (t == 1) {
                        update(sz[t], i, j);
                    }
                    if (t == 2) {
                        update(i, sz[t], j);
                    }
                    if (t == 3) {
                        update(i, j, sz[t]);
                    }
                }
            }
        }
        if (dp[sz[1]][sz[2]][sz[3]] < n) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}