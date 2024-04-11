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
#define P 16
ll n, x, k, z, m, pos, q;

ll a[15][2005], ta[15][2005], na[15][2005], used[2005], ans;
ll dp[5050];
vector<pii> b;
vector<pair<ll, pii> > c;
vector<pii> d;
vector<ll> pr[4100];
ll g[20];
ll prec[15][5005];

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
    ll s = 0;
    for (int i = 0; i < b.size(); i++) {
        if (used[b[i].Y] == 0) {
            s++;
        }
        used[b[i].Y] = 1;
        if (s == n) {
            break;
        }
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

    for (int i = 0; i < (1<<n); i++) {
        dp[i] = 0;
    }
    for (int j = 0; j < m; j++) {
        for (int k = 0; k < (1<<n); k++) {
            prec[j][k] = 0;
        }
    }
    for (int j = 0; j < m; j++) {
        for (int k = 0; k < (1<<n); k++) {
            for (int i = 0; i < n; i++) {
                ll sum = 0;
                for (int l = 0; l < n; l++) {
                    if ((k >> l) & 1) {
                        sum += a[(i+l)%n][j];
                    }
                }
                prec[j][k] = max(prec[j][k], sum);
            }
        }
    }

    for (int j = 0; j < m; j++) {
        for (int k = (1<<n) - 1; k >= 0; k--) {
            for (auto v : pr[k]) {
                if (v >= (1<<n)) {
                    break;
                }
                dp[k | v] = max(dp[k|v], dp[k] + prec[j][v]);
            }
        }
    }
    //solve2();

    cout << dp[(1<<n)-1] << endl;
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    ll p = 0;
    for (int i = 0; i < 4096; i++) {
        for (int j = 0; j < 4096; j++) {
            if ((i & j) == 0) {
                pr[i].push_back(j);
            }
        }
    }
    //cout << p << endl;
    ll t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}