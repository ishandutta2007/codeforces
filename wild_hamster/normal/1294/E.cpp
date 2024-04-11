#include <time.h>
#include <sstream>
#include <algorithm>
#include <bitset>
#include <stack>
#include <vector>
#include <map>
#include <set>
#include <utility>
#include <iostream>
#include <cmath>
#include <deque>
#include <string>
#include <stdint.h>

#define pii pair<ll,ll>
#define X first
#define Y second
#define mp make_pair

typedef long long ll;
using namespace std;
#define MAXN 200500
#define MOD 998244353
#define OFF 2001
ll n, x, k, z, m, pos, q, ans_v, y, mx;
ll x1, p1, x2;
ll a[400500];
vector<vector<ll> > f;
int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    f.resize(n);
    for (int i = 0; i < n; i++) {
        f[i].resize(m);
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> f[i][j];
        }
    }

    ll ans = 0;
    for (int j = 0; j < m; j++) {
        for (int i = 0; i < n; i++) {
            a[i] = 0;
        }
        for (int i = 0; i < n; i++) {
            if (f[i][j] % m == (j + 1) % m && f[i][j] <= n * m ) {
                ll x = (f[i][j] - 1) / m;
                ll p = (i - x + n) % n;
                a[p]++;
            }
        }
        ll s = 2 * n * m + 500;
        for (int i = 0; i < n; i++) {
            s = min(s, i + n - a[i]);
        }
        ans += s;
    }
    cout << ans << "\n";


    return 0;
}