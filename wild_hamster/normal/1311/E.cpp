#include <time.h>
#include <sstream>
#include <algorithm>
#include <bitset>
#include <stack>
#include <vector>
#include <map>
#include <set>
#include <utility>
#include <iostream>
#include <cmath>
#include <deque>
#include <string>
#include <stdint.h>
#include <assert.h>

#define pii pair<ll,ll>
#define X first
#define Y second
#define mp make_pair

typedef long long ll;
using namespace std;
#define MAXN 200500
#define MOD 1000000000
#define OFF 2001
#define N 100000000
#define PI 3.14159265358979323846
ll n, x, k, z, m, pos, q, ans_v, y, mx;
ll x1, p1, x2;
ll a[200505];
set<ll> g[5050];
ll w[5050];
ll p[5050];
set<pii> leafs;

void dfs(ll v, ll lv) {
    w[v] = lv;
    for (auto to : g[v]) {
        p[to] = v;
        dfs(to, lv + 1);
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    ll t;
    cin >> t;
    while (t--) {
        ll d;
        cin >> n >> d;
        if (d > n * (n-1) / 2) {
            cout << "NO\n";
            continue;
        }
        if (n == 2) {
            if (d == 1) {
                cout << "YES\n1\n";
            } else {
                cout << "NO\n";
            }
        }
        for (int i = 1; i <= n; i++) {
            g[i].clear();
        }
        for (int i = 2; i <= n; i++) {
            g[i/2].insert(i);
        }
        dfs(1, 0);
        leafs.clear();
        for (int i = 2; i <= n; i++) {
            if (g[i].empty()) {
                leafs.insert(mp(-w[i], i));
            }
        }
        ll s = 0;
        for (int i = 2; i <= n; i++) {
            s += w[i];
        }
        if (s > d) {
            cout << "NO\n";
            continue;
        }
        cout << "YES\n";
        for (int ii = 0; ii < d - s; ii++) {
            auto it = next(leafs.begin());
            pii pa = *it;
            ll wi = -pa.X;
            ll v = pa.Y;
            w[v] = wi + 1;
            leafs.erase(it);
            leafs.insert(mp(-wi - 1, v));
            ll pr = p[v];
            g[pr].erase(v);
            if (g[pr].size() == 0) {
                leafs.insert(mp(-wi + 1, pr));
            }
            for (int j = 1; j <= n; j++) {
                if (g[j].size() < 2 && w[j] == wi) {
                    if (g[j].size() == 0) {
                        leafs.erase(mp(-w[j], j));
                    }
                    g[j].insert(v);
                    p[v] = j;
                    break;
                }
            }
        }
        for (int i = 1; i <= n; i++) {
            for (auto to : g[i]) {
                a[to] = i;
            }
        }
        for (int i = 2; i <= n; i++) {
            cout << a[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}