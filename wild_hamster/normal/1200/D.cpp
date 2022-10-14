#include <vector>
#include <map>
#include <set>
#include <sstream>
#include <algorithm>
#include <bitset>
#include <utility>
#include <iostream>
#include <cmath>
#include <deque>
#include <string>
#include <time.h>
#include <stack>

#define pii pair<ll,ll>
#define X first
#define Y second
#define mp make_pair

typedef int ll;
using namespace std;
#define N 3005
#define MOD 998244353
ll n, x, k, z, m, pos, q;

ll a[100500], b[100500];
ll rmin[N], rmax[N], cmin[N], cmax[N];
ll ans[N][N];
char c[2005];
ll gcd(ll a, ll b) {
    return b == 0? a : gcd(b,a%b);
}
int main() {
    //ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        rmin[i] = cmin[i] = MOD;
    }
    for (int i = 0; i < n; i++) {
        scanf("%s", c);
        for (int j = 0; j < n; j++) {
            if (c[j] == 'B') {
                rmin[i] = min(rmin[i], j);
                cmin[j] = min(cmin[j], i);
                rmax[i] = max(rmax[i], j);
                cmax[j] = max(cmax[j], i);
            }
        }
    }

    ll wl = 0;
    for (int i = 0; i < n; i++) {
        if (rmin[i] == MOD) {
            wl++;
        }
        if (cmin[i] == MOD) {
            wl++;
        }
    }

    for (int i = 0; i + k <= n; i++) {
        for (int j = 0; j < n; j++) {
            if (cmin[j] == MOD) {
                a[j] = 0;
            } else if (cmin[j] >= i && cmax[j] < i + k) {
                a[j] = 1;
            } else {
                a[j] = 0;
            }
        }
        ll sum = 0;
        for (int j = 0; j < k; j++) {
            sum += a[j];
        }
        for (int j = k; j < n; j++) {
            ans[i][j-k] += sum;
            sum += a[j] - a[j-k];
        }
        ans[i][n-k] += sum;

        for (int j = 0; j < n; j++) {
            if (rmin[j] == MOD) {
                a[j] = 0;
            } else if (rmin[j] >= i && rmax[j] < i + k) {
                a[j] = 1;
            } else {
                a[j] = 0;
            }
        }
        sum = 0;
        for (int j = 0; j < k; j++) {
            sum += a[j];
        }
        for (int j = k; j < n; j++) {
            ans[j-k][i] += sum;
            sum += a[j] - a[j-k];
        }
        ans[n-k][i] += sum;
    }
    ll p = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            p = max(p, ans[i][j]);
        }
    }
    cout << p + wl << endl;
    return 0;
}