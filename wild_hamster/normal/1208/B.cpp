#include <iostream>
#include <cmath>
#include <deque>
#include <string>
#include <time.h>
#include <vector>
#include <map>
#include <set>
#include <sstream>
#include <algorithm>
#include <bitset>
#include <utility>

#define X first
#define Y second
#define mp make_pair
#define MOD 998244353
#define pii pair<ll,ll>

typedef int ll;
using namespace std;
#define MAXN 400228
#define SQ 700
ll x, y, n, m, k, i, j, q;
ll a[MAXN], b[MAXN];
map<ll, ll> f;

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        f[a[i]]++;
        if (f[a[i]] == 2) {
            k++;
        }
    }
    if (k == 0) {
        cout << 0 << endl;
        return 0;
    }
    ll ans = n;
    for (int i = 0; i < n; i++) {
        ll p = k;
        for (int j = i; j < n; j++) {
            f[a[j]]--;
            if (f[a[j]] == 1) {
                p--;
            }
            if (p == 0) {
                ans = min(ans, j - i + 1);
            }
        }
        for (int j = i; j < n; j++) {
            f[a[j]]++;
        }
    }
    cout << ans << endl;
    return 0;
}