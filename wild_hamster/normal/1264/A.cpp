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
#define MAXN 200500
#define MOD 998244353
#define OFF 2001
ll n, x, k, z, m, pos, q, ans_v, y;
ll x1, p1, x2;
ll a[MAXN], b[MAXN];
vector<ll> f;

void solve() {
    ll n;
    cin >> n;
    f.clear();
    ll cur = -1;
    ll y = 0;
    for (int i = 0; i < n; i++) {
        cin >> x;
        if (i == 0) {
            cur = x;
            y = 1;
        } else
        if (x != cur) {
            f.push_back(y);
            y = 1;
        } else {
            y++;
        }
        cur = x;
    }
    f.push_back(y);

    ll min1 = f[0];
    ll i = 1;
    ll sum1 = 0, sum2 = 0;
    while (i < f.size() && sum1 <= min1) {
        sum1 += f[i++];
    }

    while (i < f.size() && sum2 <= min1) {
        sum2 += f[i++];
    }

    while (i < f.size() && (sum1 + sum2 + min1 + f[i]) * 2 <= n) {
        sum2 += f[i++];
    }
    if (sum1 <= min1 || sum2 <= min1 || (sum1 + sum2 + min1) * 2 > n) {
        cout << "0 0 0\n";
    } else {
        cout << min1 << " " << sum1 << " " << sum2 << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    ll t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}