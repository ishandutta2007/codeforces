#include <string>
#include <time.h>
#include <vector>
#include <algorithm>
#include <bitset>
#include <utility>
#include <map>
#include <set>
#include <sstream>
#include <iostream>
#include <cmath>
#include <deque>

#define pii pair<ll,ll>
#define MOD 998244353
#define mp make_pair
#define X first
#define Y second
typedef int ll;
using namespace std;
ll n,m,k, y, z, l, i, j, x, r, x2, y2;
ll a[300500], pre[300500][25], dp[25][25], b[25];
bool good(ll x) {
    ll p = 0;
    for (int i = 0; i < n; i++) {
        if ((a[i] + x) % m < a[i] && (a[i] + x) % m >= p) {
            continue;
        }
        if (p <= a[i] + x && a[i] <= p) {
            continue;
        }
        if (a[i] > p) {
            p = a[i];
            continue;
        }
        return false;
    }
    return true;
}

ll tmp_arr[25];
int main() {
    string s;
    cin >> n;
    ll q;
    cin >> q;
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    for (int i = 0; i < 19; i++) {
        for (int j = 0; j < 19; j++) {
            dp[i][j] = n;
        }
    }
    for (int j = 0; j < n; j++) {
        for (int i = 0; i < 19; i++) {
            pre[j][i] = n;
        }
    }
    for (int i = n - 1; i >= 0; i--) {
        ll sz = 0;
        for (int j = 0; j < 19; j++) {
            if ((a[i] >> j) & 1) {
                tmp_arr[sz++] = j;
            }
        }
        for (int j = 0; j < sz; j++) {
            for (int k = 0; k < sz; k++) {
                dp[tmp_arr[j]][tmp_arr[k]] = i;
            }
        }

        for (int j = 0; j < 19; j++) {
            b[j] = n;
        }

        for (int j = 0; j < sz; j++) {
            for (int k = 0; k < 19; k++) {
                b[k] = min(b[k], dp[tmp_arr[j]][k]);
            }
        }
        for (int j = 0; j < sz; j++) {
            for (int k = 0; k < 19; k++) {
                dp[tmp_arr[j]][k] = min(dp[tmp_arr[j]][k], b[k]);
            }
        }

        for (int j = 0; j < sz; j++) {
            for (int k = 0; k < 19; k++) {
                pre[i][k] = min(pre[i][k], dp[tmp_arr[j]][k]);
            }
        }
    }
    for (int i = 0; i < q; i++) {
        scanf("%d %d", &x, &y);
        x--; y--;
        ll sz = 0;
        for (int j = 0; j < 19; j++) {
            if ((a[y] >> j) & 1) {
                tmp_arr[sz++] = j;
            }
        }
        bool ok = false;
        ll p = n;
        for (int j = 0; j < sz; j++) {
            ll k = tmp_arr[j];
            p = min(p, pre[x][k]);
            if (pre[x][k] <= y) {
                ok = true;
            }
        }
        if (ok) {
            printf("Shi\n");
        } else {
            printf("Fou\n");
        }
    }
    return 0;
}