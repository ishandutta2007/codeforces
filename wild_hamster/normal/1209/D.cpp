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

ll a[200500], b[200500], d[150], used[MAXN], w[MAXN];

vector<ll> g[100500];
vector<ll> comp;
void dfs(ll v) {
    used[v] = 1;
    comp.push_back(v);
    for (auto to : g[v]) {
        if (!used[to]) {
            dfs(to);
        }
    }
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        ll x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
        w[x]++;
        w[y]++;
    }
    ll ans = 0;
    for (int i = 1; i <= n; i++) {
        if (!used[i]) {
            comp.clear();
            dfs(i);
            ll l = comp.size();
            ll x = 0;
            for (auto v : comp) {
                x += w[v];
            }
            ans += x / 2 - (l - 1);
        }
    }
    cout << ans << endl;



    return 0;
}