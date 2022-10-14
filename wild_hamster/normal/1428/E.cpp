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
#define N 13
#define OFF 400001
#define MOD 1000000007
#define NN 1000000
ll n, m, k, w, r;
ll c[1005000], b[1005000], a[1005005], dp[1005000], maxdp[1005000];
ll t, x, y, z;
ll Abs(ll x) {
    return x > 0 ? x : -x;
}
vector<char> zal;
multiset<pii> f;
ll get_val(ll x, ll v) {
    if (v > x) {
        return x;
    }
    ll p = x / v;
    ll t = x % v;
    return p * p * (v - t) + (p + 1) * (p + 1) * t;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> n >> k;
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        ans += a[i] * a[i];
        b[i] = 1;
        f.insert(mp(get_val(a[i], b[i]) - get_val(a[i], b[i] + 1), i));
    }
    for (int i = 0; i < (k - n); i++) {
        auto it = f.end();
        it--;
        pii cur = *it;
        f.erase(it);
        ans -= cur.X;
        ll id = cur.Y;
        b[id]++;
        f.insert(mp(get_val(a[id], b[id]) - get_val(a[id], b[id] + 1), id));
    }
    cout << ans << "\n";
    return 0;
}