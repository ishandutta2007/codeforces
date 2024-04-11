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
#define MAXN (1<<20)
#define MOD 1000000007
#define N 1048576
ll n, x, k, z, m, pos, q, ans_v;
ll x1, p1, x2, p2;
map<ll, ll> g[600500];
ll f[500500], a[600500], sb[600500], b[600500], p[600500];

void solve() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    ll cur = 0;
    ll prv = -1;
    for (int i = 0; i <= 2 * n; i++) {
        g[i].clear();
        p[i] = sb[i] = b[i] = 0;
    }
    ll ans = 0;
    ll sz = 0;
    b[0] = 0;
    for (int i = 0; i < n; i++) {
        if (sb[cur] == a[i]) {
            b[cur]++;
            prv = p[cur];
            cur = prv;
            ans += b[cur];
        } else {
            if (g[cur].find(a[i]) == g[cur].end()) {
                b[cur]++;
                sb[++sz] = a[i];
                p[sz] = cur;
                g[cur][a[i]] = sz;
                cur = sz;
            } else {
                b[cur]++;
                cur = g[cur][a[i]];
                ans += b[cur];
            }
        }
        //cout << ans << endl;
    }
    //cout << "HYU" << endl;
    cout << ans << "\n";
}

/*
3
5
2 1 1 2 2
6
1 2 1 1 3 2
9
3 1 2 2 1 6 6 3 3

 */

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    ll t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}