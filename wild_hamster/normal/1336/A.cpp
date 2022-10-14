
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
pii a[200500];
vector<ll> f;
void dfs(ll v, ll lvl = 0, ll p = -1) {
    w[v] = 1;
    lv[v] = lvl;
    for (auto to : g[v]) {
        if (to == p) {
            continue;
        }
        dfs(to, lvl + 1, v);
        w[v] += w[to];
    }
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    cin >> n >> k;
    for (int i = 0; i < n-1; i++) {
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    dfs(1);
    for (int i = 1; i <= n; i++) {
        f.push_back(lv[i] - w[i] + 1);
    }
    sort(f.begin(), f.end());
    reverse(f.begin(), f.end());
    ll ans = 0;
    for (int i = 0; i < k; i++) {
        ans += f[i];
    }
    cout << ans << "\n";
    return 0;
}