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
ll n,m,k, y, z, l, i, j, x, r, x2, y2;
ll a[3000500], c[300050], d[300500];
vector<pii> f;
pii b[300500];
int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i + 1];
    }
    ll q;
    cin >> q;
    for (int i = 1; i <= n; i++) {
        b[i] = {-1, -1};
    }
    f.push_back(mp(-1, 0));
    for (int i = 0 ;i < q; i++) {
        ll x;
        cin >> x;
        if (x == 2) {
            cin >> y;
            f.push_back(mp(i, y));
        } else {
            ll y, z;
            cin >> y >> z;
            b[y] = mp(i, z);
        }
    }
    f.push_back(mp(q+5, 0));
    ll sz = f.size();
    for (int i = sz-1; i > 0; i--) {
        f[i-1].Y = max(f[i-1].Y, f[i].Y);
    }
    for (int i = 1; i <= n; i++) {
        if (b[i] == mp(-1LL, -1LL)) {
            cout << max(a[i], f[0].Y) << " ";
        } else {
            ll pos = upper_bound(f.begin(), f.end(), mp(b[i].X, 1LL * MOD)) - f.begin();
            cout << max(b[i].Y, f[pos].Y) << " ";
        }
    }
    return 0;
 
}