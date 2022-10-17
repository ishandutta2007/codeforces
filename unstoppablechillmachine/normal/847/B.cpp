//GLEBAS
#include <bits/stdc++.h>

using namespace std;

#define TASK "cifrul"

typedef long long ll;
typedef pair<ll, ll> par;

#define F first
#define S second
#define all(x) (x).begin(), (x).end()
#define pw(x) (1ll << (x))

const ll INF = ll(1e18);
const ll MOD = ll(1e9) + 7;

int source() {
    ll n;
    cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    vector<vector<ll>> g;
    for (int i = 0; i < n; ++i) {
        ll l = -1, r = g.size();
        while (r - l > 1) {
            ll m = (l + r) / 2;
            if (g[m].back() > a[i]) {
                l = m;
            } else {
                r = m;
            }
        }
        if (r != g.size()) {
            g[r].push_back(a[i]);
        } else {
            g.push_back(vector<ll>());
            g[g.size() - 1].push_back(a[i]);
            continue;
        }
    }
    for (int i = 0; i < g.size(); ++i) {
        for (int j = 0; j < g[i].size(); ++j) {
            cout << g[i][j] << ' ';
        }
        cout << '\n';
    }
    return 0;
}

int main() {
#ifdef OLYMP
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#else
    //freopen(TASK".in", "r", stdin);
    //freopen(TASK".out", "w", stdout);
#endif
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    source();

    return 0;
}