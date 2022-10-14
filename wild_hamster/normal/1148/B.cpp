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
typedef long long ll;
using namespace std;
ll n,m,k, y, z, l, i, j, x, r, x2, y2;
ll a[200500], b[200500];
ll Abs(ll x) {
    return (x > 0 ? x : -x);
}
int main() {
    cin >> n >> m >> l >> r >> k;
    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        a[i] = x;
    }
    for (int i = 0; i < m; i++) {
        int x;
        scanf("%d", &x);
        b[i] = x;
    }
    if (n <= k || m <= k) {
        cout << -1 << endl;
        return 0;
    }
    ll ans = 0;
    ll pos = 0;
    for (int i = 0; i <= k; i++) {
        while (pos < m && b[pos] < a[i] + l) {
            pos++;
        }
        ans = max(ans, pos + k - i);
    }
    if (ans >= m) {
        cout << -1 << endl;
    } else {
        cout << b[ans] + r << endl;
    }
    return 0;
}