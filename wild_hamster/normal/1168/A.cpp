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
ll a[300500], b[100500];
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
int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    ll l = 0, r = m - 1;
    while (l < r) {
        ll mid = (l + r) / 2;
        if (good(mid)) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }
    cout << l << endl;
    return 0;
}