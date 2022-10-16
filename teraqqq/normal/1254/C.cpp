#include <bits/stdc++.h>

#define F first
#define S second
#define rsz resize
#define pb push_back

using namespace std;
using ll = long long;
using ld = long double;
using pi = pair<int, int>;
using vi = vector<int>;
using vpi = vector<pi>;
using vl = vector<ll>;

const int INF = 1e9;
const ll LINF = 6e18;
const ld PI = 4*atan((ld)1);

mt19937 rng;

ll ask(int t, int i, int j, int k) {
    cout << t << ' ' << i << ' ' << j << ' ' << k << endl;
    ll s; cin >> s;
    return s;
}

void solve() {
    int n; cin >> n;
    int t = 2;

    for(int i = 3; i <= n; ++i)
        if(ask(2, 1, t, i) < 0) t = i;
    vector<pair<ll, int>> v;
    for(int i = 2; i <= n; ++i) {
        if(i == t) continue;
        v.pb({ask(1, 1, t, i), i});
    }

    sort(v.begin(), v.end());
    vi vl, vr(1, t);
    for(int i = 0; i < v.size() - 1; ++i)
        if(ask(2, 1, v.back().S, v[i].S) < 0) vr.pb(v[i].S); else vl.pb(v[i].S);
    cout << 0 << ' ' << 1;
    for(int x : vr) cout << ' ' << x;
    cout << ' ' << v.back().S; reverse(vl.begin(), vl.end());
    for(int x : vl) cout << ' ' << x;
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    rng.seed(chrono::steady_clock::now().time_since_epoch().count());
    solve();
}