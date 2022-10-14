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
ll n, x, k, z, m, pos, q, ans_v, y;
ll x1, p1, x2;
set<pii> f;
ll a[200500];
void solve() {
    cin >> n >> m;
    ll sum = 0, max2 = 0, maxi = 0;
    ll ans = -1;
    for (int i = 0; i <n; i++) {
        cin >> a[i];
        if (a[i] > max2) {
            max2 = a[i];
            maxi = i;
        }
        sum += a[i];
        if (sum - max2 <= m) {
            ans = maxi;
        }
    }
    if (sum <= m) {
        cout << "0\n";
    } else {
        cout << ans + 1 << "\n";
    }
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    ll t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}