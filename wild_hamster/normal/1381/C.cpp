
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
#define mp make_pair
#define X first
#define Y second

typedef int ll;
using namespace std;
#define N 10000000
#define OFF 400001
#define C 13000
#define NN 1000000
ll n, x, k, z, m, pos, q, ans_v, y, root, xx;
ll ii;
ll a[200500], b[200500], c[200500], dp[2005000], used[200500];
vector<ll> g[100500], pshe;
set<pii> f;
multiset<ll> za, zb;

bool check() {
    ll xx0 = 0, y0 = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] == b[i]) {
            xx0++;
        }
    }
    for (int i = 0; i < n; i++) {
        za.insert(a[i]);
    }
    for (int i = 0; i < n; i++) {
        if (za.find(b[i]) != za.end()) {
            za.erase(za.find(b[i]));
            y0++;
        }
    }
    return (xx == xx0 && y == y0);

}
void solve() {
    cin >> n >> xx >> y;
    for (int i = 1; i <= n + 1; i++) {
        g[i].clear();
        used[i] = 0;
    }
    ll uc = -1;
    for (int i = 0; i < n; i++) {
        b[i] = 0;
    }
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        used[a[i]] = 1;
        g[a[i]].push_back(i);
    }
    for (int i = 1; i <= n+1; i++) {
        if (!used[i]) {
            uc = i;
        }
    }
    f.clear();
    for (int i = 1; i <= n + 1; i++) {
        f.insert(mp(-static_cast<int>(g[i].size()), i));
    }
    for (int i = 0; i < xx; i++) {
        auto it = f.begin();
        auto x = *it;
        x.X++;
        b[g[x.Y].back()] = a[g[x.Y].back()];
        g[x.Y].pop_back();
        f.erase(it);
        f.insert(x);
    }
    ll fr = n - xx;
    ll need = y - xx;
    if (fr == 0) {
        cout << "YES\n";
        for (int i = 0; i < n; i++) {
            cout << b[i] << " ";
        }
        cout << "\n";
        return;
    }
    ll mx = 0, id = 0;
    for (int i = 1; i <= n + 1; i++) {
        if (g[i].size() > mx) {
            id = i;
            mx = g[i].size();
        }
    }
    if ((fr - mx) * 2 < need) {
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
    pshe.clear();
    for (auto x : g[id]) {
        pshe.push_back(x);
    }
    for (int i = 1; i <= n+1; i++) {
        if (i != id) {
            for (auto x : g[i]) {
                pshe.push_back(x);
            }
        }
    }
    ll psz = pshe.size();
    for (int i = 0; i < psz; i++) {
        ll x = pshe[i];
        ll y = pshe[(i+mx) % psz];
        if (a[x] != a[y] && need > 0) {
            b[x] = a[y];
            need--;
        } else {
            b[x] = uc;
        }
    }
    for (int i = 0; i < n; i++) {
        cout << b[i] << " " ;
    }
    cout << "\n";
    /*if (!check()) {
        cout << "CHLEN\n";
    }*/
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    ll t;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}