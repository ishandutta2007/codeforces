#include <cstring>
#include <cstdio>
#include <cmath>
#include <queue>
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#define LL long long
#define pii pair <int, int>
#define piii pair <pii, int>
using namespace std;

const int N = 30100;

short dp[N][2200];
short num[N], sum[N];

struct data {
    short x, l, res;
    data () {}
    data (short x, short l, short res) : x (x), l (l), res (res) {}
};

int main () {
//    freopen ("in.txt", "r", stdin);
    short n, d;
    int a;
    cin >> n >> d;
    for (int i = 1; i <= n; i++) {
        scanf ("%d", &a);
        num[a]++;
    }
    if (d <= 2000) {
        memset (dp, -1, sizeof dp);
        dp[d][d] = num[d];
        short res = 0;
        for (int i = 1; i <= 30000; i++) {
            for (int j = 1; j <= 2100; j++) if (dp[i][j] != -1) {
                res = max (res, dp[i][j]);
                if (i + j - 1 > 30000) continue;
                if (j) dp[i + j - 1][j - 1] = max (dp[i + j - 1][j - 1], (short)(dp[i][j] + num[i + j - 1]));
                dp[i + j][j] = max (dp[i + j][j], (short)(dp[i][j] + num[i + j]));
                dp[i + j + 1][j + 1] = max (dp[i + j + 1][j + 1], (short)(dp[i][j] + num[i + j + 1]));
            }
        }
        cout << res << endl;
    } else {
        queue <data> q;
        q.push (data (d, d, num[d]));
        int mx = 0;
        while (!q.empty ()) {
            data u = q.front (); q.pop();
            int x = u.x, l = u.l, res = u.res;
            mx = max (mx, res);
            for (int i = -1; i <= 1; i++) if (l + i && x + l + i <= 30000) {
                q.push (data (x + l + i, l + i, res + num[x + l + i]));
            }
        }
        cout << mx << endl;
    }
}