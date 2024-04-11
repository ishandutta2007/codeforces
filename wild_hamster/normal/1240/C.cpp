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
ll dp[500500][2];
vector<pii> g[500500];
ll f[500500];
void dfs(ll v, ll p = -1) {
    for (auto kv : g[v]) {
        ll to = kv.X;
        if (to == p) {
            continue;
        }
        dfs(to, v);
    }
    ll pos = 0;
    ll sum = 0;
    ll sum0 = 0, sum1 = 0;
    for (auto kv : g[v]) {
        ll to = kv.X;
        ll val = kv.Y;
        if (to == p) {
            continue;
        }
        if (dp[to][0] < dp[to][1] + val) {
            f[pos++] = dp[to][1] + val - dp[to][0];
        }
        sum += dp[to][0];
    }
    sort(f, f+pos);
    reverse(f, f+pos);
    sum0 = sum;
    sum1 = sum;
    for (int i = 0; i < pos; i++) {
        if (i < k-1) {
            sum0 += f[i];
            sum1 += f[i];
        }
        if (i == k-1) {
            sum0 += f[i];
        }
    }
    dp[v][0] = sum0;
    dp[v][1] = sum1;
}
void solve() {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        g[i].clear();
    }
    for (int i = 0; i < n-1; i++) {
        ll x, y;
        cin >> x >> y >> z;
        g[x].push_back(mp(y, z));
        g[y].push_back(mp(x, z));
    }
    dfs(1);
    cout << max(dp[1][0], dp[1][1]) << "\n";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    ll t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}