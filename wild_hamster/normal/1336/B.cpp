
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
#include <fstream>

#define pii pair<ll,ll>
#define X first
#define Y second
#define mp make_pair

typedef long long ll;
using namespace std;
#define N 1000000
#define OFF 400001
#define MOD 1000000007
#define C 13000
#define NN 1000000
ll n, x, k, z, m, pos, q, ans_v, y, root;
vector<ll> g[200500];
ll w[200500], lv[200500];
vector<ll> a, b, c;
ll ans;
ll upd(ll x, ll y, ll z) {
    ans = min(ans, (x-y)*(x-y) + (x-z)*(x-z) + (y-z)*(y-z));
}
void mag(const vector<ll>& a, const vector<ll>& b, const vector<ll>& c) {
    n = a.size();
    m = b.size();
    k = c.size();
    for (int i = 0; i < n; i++) {
        ll x = i;
        ll y = upper_bound(b.begin(), b.end(), a[i]) - b.begin();
        for (int j = y-1; j <= y; j++) {
            if (j < 0 || j >= m) {
                continue;
            }
            ll z = upper_bound(c.begin(), c.end(), b[j]) - c.begin();
            if (z >= 0 && z < k) {
                upd(a[i], b[j], c[z]);
            }
            z--;
            if (z >= 0 && z < k) {
                upd(a[i], b[j], c[z]);
            }

            z = upper_bound(c.begin(), c.end(), a[i]) - c.begin();
            if (z >= 0 && z < k) {
                upd(a[i], b[j], c[z]);
            }
            z--;
            if (z >= 0 && z < k) {
                upd(a[i], b[j], c[z]);
            }
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    ll t;
    cin >> t;
    while (t--) {
        ans = 6LL * (ll)1e+18;
        cin >> n >> m >> k;
        a.clear();
        b.clear();
        c.clear();
        for (int i = 0; i < n; i++) {
            cin >> x;
            a.push_back(x);
        }

        for (int i = 0; i < m; i++) {
            cin >> x;
            b.push_back(x);
        }

        for (int i = 0; i < k; i++) {
            cin >> x;
            c.push_back(x);
        }
        sort(a.begin(), a.end());


        sort(b.begin(), b.end());

        sort(c.begin(), c.end());


        mag(a, b, c);
        mag(a, c, b);
        mag(b, a ,c);
        mag(b, c, a);
        mag(c, a, b);
        mag(c, b, a);
        cout << ans << "\n";
    }
    return 0;
}