#include <utility>
#include <iostream>
#include <cmath>
#include <deque>
#include <string>
#include <time.h>
#include <stack>
#include <vector>
#include <map>
#include <set>
#include <sstream>
#include <algorithm>
#include <bitset>

#define pii pair<ll,ll>
#define X first
#define Y second
#define mp make_pair

typedef long long ll;
using namespace std;
#define MAXN 200500
#define MOD 998244353
#define OFF 200001
ll N;
ll n, x, k, z, m, pos, q, ans_v, y;
ll x1, p1, x2;
ll a[300500], b[300500];
vector<ll> f;
ll c[300500], d[300500];
string str;

void solve() {
    cin >> n;
    for (int i = 0; i < 2*n; i++) {
        cin >> a[i];

    }
    for (int i = OFF - n - 1; i <= OFF + n + 1; i++) {
        c[i] = d[i] = MOD;
    }
    ll sum = 0, sum2 = 0;
    c[OFF] = 0;
    d[OFF] = 2*n-1;
    ll ans = 2 * n;
    for (int i = 0; i < n; i++) {
        if (a[i] == 1) {
            sum ++;
        } else {
            sum--;
        }
        if (a[2*n-i-1] == 1) {
            sum2++;
        } else {
            sum2--;
        }
        c[sum+OFF] = i + 1;
        d[sum2+OFF] = 2*n-i-2;
    }
    for (int i = -n - 1; i <= n + 1; i++) {
        if (c[OFF+i] != MOD && d[OFF-i] != MOD) {
            ans = min(ans, d[OFF-i] - c[OFF+i] + 1);
        }
    }
    cout << ans << "\n";
    return;
}
int main() {
    ll t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;

}