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

#define MOD 998244353
#define pii pair<ll,ll>
#define X first
#define Y second
#define mp make_pair

typedef long long ll;
using namespace std;
#define MAXN 1488228
ll x, y, n, m, k;
ll a[500005], tin[505], timer, ans, d[205];
vector<ll> g[205];
void dfs(ll v, ll p = -1) {
    tin[v] = timer++;
    for (auto to : g[v]) {
        if (to == p) {
            continue;
        }
        if (tin[to]) {
            if (tin[v] > tin[to]) {
                ans = min(ans, tin[v] + 1 - tin[to]);
            }
        } else {
            dfs(to, v);
        }
    }
}
int main() {
    cin >> m;
    for (int i = 0; i < m; i++) {
        ll x;
        cin >> x;
        if (x != 0) {
            a[n++] = x;
        }
    }

    if (n > 200) {
        cout << 3 << endl;
        return 0;
    }
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (a[i] & a[j]) {
                g[i].push_back(j);
                g[j].push_back(i);
            }
        }
    }
    timer = 1;
    ans = MOD;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            d[j] = MOD;
        }
        d[i] = 0;
        vector<ll> bfs;
        bfs.push_back(i);
        ll pos = 0;
        ll flag = 0;
        while (pos < bfs.size()) {
            ll v = bfs[pos++];
            for (auto to : g[v]) {
                if (to != i) {
                    if (d[to] == MOD) {
                        d[to] = d[v] + 1;
                        bfs.push_back(to);
                    } else {
                        if (d[to] >= d[v]) {
                            ans = min(ans, d[to] + d[v] + 1);
                            flag = 1;
                        }
                    }
                }
            }
            if (flag) {
                break;
            }
        }
    }
    if (ans == MOD) {
        ans = -1;
    }
    cout << ans << endl;
    return 0;
}