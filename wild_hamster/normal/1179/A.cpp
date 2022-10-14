#include <string>
#include <time.h>
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

#define pii pair<ll,ll>
#define X first
#define Y second
#define mp make_pair

typedef long long ll;
using namespace std;
#define MAXN 228228
#define MOD 1000000007
ll x, y, n, m, k, R, C, q;
deque<ll> a;
vector<pii> ans;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    cin >> n >> q;
    ll mx = 0;
    R = MOD;
    for (int i = 0; i < n; i++) {
        cin >> x;
        mx = max(mx, x);
        a.push_back(x);
    }
    for (int i = 0; i <= 3*n; i++) {
        ll x = a.front(); a.pop_front();
        ll y = a.front(); a.pop_front();
        if (x == mx) {
            R = min(R, 1LL * i);
        }
        ans.push_back(mp(x, y));
        if (x > y) {
            swap(x, y);
        }
        a.push_front(y);
        a.push_back(x);
    }
    for (int i = 0; i < q; i++) {
        cin >> x;
        x--;
        if (x <= R) {
            cout << ans[x].X << " " << ans[x].Y << "\n";
        } else {
            ll p = (x-R)%(n-1) + R;
            cout << ans[p].X << " " << ans[p].Y << "\n";
        }
    }

    return 0;
}