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
#include <string>
#include <time.h>
#include <stack>

#define pii pair<ll,ll>
#define X first
#define Y second
#define mp make_pair

typedef long long ll;
using namespace std;
#define MAXN 300500
#define MOD 998244353
ll n, x, k, z, m, pos, q;

ll a[MAXN], mx[MAXN], mn[MAXN];
vector<pii> b;
vector<ll> f;
map<ll, ll> g;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> q;
    for (int i = 1; i < MAXN; i++) {
        mx[i] = -1;
        mn[i] = MOD;
    }
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        mn[a[i]] = min(mn[a[i]], 1LL * i);
        mx[a[i]] = max(mx[a[i]], 1LL * i);
    }
    ll cur = 0;
    ll i = 0;
    while (i < n) {
        ll r = i;
        while (i <= r) {
            r = max(r, mx[a[i]]);
            i++;
        }
        f.push_back(i);
    }

    ll l = 0;
    ll ans = 0;
    for (int i = 0; i < f.size(); i++) {
        g.clear();
        for (int j = l; j < f[i]; j++) {
            g[a[j]]++;
        }
        ll cur = f[i] - l;
        ll m = 0;
        for (auto x : g) {
            m = max(m, x.Y);
        }
        ans += cur - m;
        l = f[i];
    }
    cout << ans << endl;
    return 0;
}