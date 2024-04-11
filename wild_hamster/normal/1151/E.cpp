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
#define MOD 1000000007
#define mp make_pair
#define X first
#define Y second
typedef long long ll;
using namespace std;
ll n,m,k, y, z, l, i, j, x, r;
set<ll> f;
ll a[100500], b[100500];
int main() {
    srand(time(0));
    //freopen("input.txt", "r", stdin);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        b[a[i]] = 1;
    }
    f.insert(0);
    f.insert(n+1);
    ll ans = 0;
    for (int i = n-1; i >= 1; i--) {
        ll x = a[i];
        ll y = a[i-1];
        if (x == y)
            continue;
        ll r = *(f.upper_bound(y));
        ll l = *(prev(f.upper_bound(y)));
        ll tl = 0, tr = n+1;
        if (x < y) {
            tl = x;
        } else {
            tr = x;
        }
        r = min(r, tr);
        l = max(l, tl);
        ans += (tr - y) * (y - tl) - (r - y) * (y - l);
        f.insert(a[i]);
    }
    ans += n * (n + 1) / 2;
    ll t = 0;
    for (int i = 1; i <= n; i++) {
        if (b[i] == 1) {
            ans -= t * (t + 1) / 2;
            t = 0;
        } else {
            t++;
        }
    }
    ans -= t * (t+1) / 2;
    cout << ans << endl;
    return 0;
}