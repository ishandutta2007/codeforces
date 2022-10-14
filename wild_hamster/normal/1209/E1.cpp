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

typedef long long ll;
using namespace std;
#define MAXN 300500
#define MOD 998244353
ll n, x, k, z, m, pos, q;

ll a[15][2005], ta[15][2005], na[15][2005], used[2005];
vector<pii> b;

void solve() {
    cin >> n >> m;
    b.clear();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
            b.push_back(mp(a[i][j], j));
        }
    }
    sort(b.begin(), b.end());
    reverse(b.begin(), b.end());
    for (int i = 0; i < m; i++) {
        used[i] = 0;
    }
    for (int i = 0; i < min((int)b.size(), 8); i++) {
        used[b[i].Y] = 1;
    }
    ll pos = 0;
    for (int i = 0; i < m; i++) {
        if (used[i]) {
            for (int j = 0; j < n; j++) {
                ta[j][pos] = a[j][i];
            }
            pos++;
        }
    }
    m = pos;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            a[i][j] = ta[i][j];
        }
    }
        ll x = 1;
        for (int i = 0; i < m; i++) {
            x *= n;
        }
        vector<ll> f;
        ll ans = 0;
        for (int i = 0; i < x; i++) {
            f.clear();
            ll k = i;
            for (int j = 0; j < m; j++) {
                f.push_back(k % n);
                k /= n;
            }
            for (int j = 0; j < n; j++) {
                for (int k = 0; k < m; k++) {
                    na[j][k] = a[(j+f[k])%n][k];
                }
            }
            ll sum = 0;
            for (int i = 0; i < n; i++) {
                ll cur = 0;
                for (int j = 0; j < m; j++) {
                    cur = max(cur, na[i][j]);
                }
                sum += cur;
            }
            ans = max(ans, sum);
        }
        cout << ans << endl;
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    ll t;
    cin >> t;
    while (t--) {
        solve();
    }



    return 0;
}