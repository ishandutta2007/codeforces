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
#define MAXN 30000
#define MOD 1000000007
#define N 1048576
ll n, x, k, z, m, pos, q, ans_v;


ll b[200500];
vector<ll> g[200500];
ll a[200500];
ll ans;
ll used[200500], w[200500], in_cycle[200500];
vector<ll> comp;

void dfs_s(ll v) {
    if (used[v]) {
        return;
    }
    comp.push_back(v);
    used[v] = 1;
    for (auto to : g[v]) {
        dfs_s(to);
    }
}

set<pii> f;
vector<ll> cycle, pshe;

void dfs(ll v, ll val) {
    used[v] = 1;
    ans = max(ans, val);
    for (auto to : g[v]) {
        if (!used[to]) {
            dfs(to, val + a[to]);
        }
    }
}

void dfs_v(ll v, ll val, ll p) {
    if (used[v]) {
        ans_v = val;
        for (auto tt : pshe) {
            a[tt] = 0;
        }
        return;
    }
    pshe.push_back(v);
    for (auto to : g[v]) {
        if (to == p) {
            continue;
        }
        dfs_v(to, val + a[v], v);
    }
    pshe.pop_back();
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < m; i++) {
        ll x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    ll s;
    cin >> s;
    dfs_s(s);
    for (int i = 1; i <= n; i++) {
        used[i] = 1;
    }
    for (auto v : comp) {
        used[v] = 0;
        w[v] = g[v].size();
        f.insert(mp(w[v], v));
    }

    while (!f.empty()) {
        auto it = f.begin();
        ll deg = it->X;
        ll v = it->Y;
        if (deg >= 2) {
            break;
        }
        used[v] = 1;
        f.erase(it);
        for (auto to : g[v]) {
            if (!used[to]) {
                f.erase(mp(w[to], to));
                w[to]--;
                f.insert(mp(w[to], to));
            }
        }
    }

    for (auto kv : f) {
        cycle.push_back(kv.second);
    }

    for (auto v : comp) {
        used[v] = 0;
    }
    if (cycle.empty()) {
       ans = 0;
       dfs(s, 0);
       cout << ans + a[s] << endl;
       return 0;
    } else {
        ll cur_ans = 0;
        for (auto v : cycle) {
            cur_ans += a[v];
            used[v] = 1;
            in_cycle[v] = 1;
        }
        if (!in_cycle[s]) {
            dfs_v(s, 0, s);
        }
        for (auto v : cycle) {
            dfs(v, 0);
        }
        cout << cur_ans + ans + ans_v << endl;
        return 0;
    }

    return 0;
}