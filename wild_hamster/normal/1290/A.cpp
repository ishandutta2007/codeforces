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
#define N 1000000
#define OFF 200001
#define MOD 1000000007
#define C 13000
#define NN 1000000
ll n, x, k, z, m, pos, q, ans_v, y, root;
vector<ll> g[N + 5];
ll a[200500];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    ll t;
    cin >> t;
    while (t--) {
        cin >> n >> m >> k;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        ll ans = 0;
        if (k + 1 >= m) {
            for (int i = 0; i < m; i++) {
                ans = max(ans, a[i]);
                ans = max(ans, a[n-1-i]);
            }
            cout << ans << "\n";
            continue;
        }

        for (int i = 0; i <= k; i++) {
            ll l = i;
            ll r = n - 1 - (k - i);
            ll x = m - k - 1;
            ll mn = MOD;
            for (int j = 0; j <= x; j++) {
                mn = min(mn, max(a[l + j], a[r - (x - j)]));
            }
            ans = max(ans, mn);
        }
        cout << ans << "\n";
    }
    return 0;

}