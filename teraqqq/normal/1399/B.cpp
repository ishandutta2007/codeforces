#include <bits/stdc++.h>

#define F first
#define S second
#define pb push_back
#define eb emplace_back
#define mp make_pair

using namespace std;
using ll = long long;
using vi = vector<int>;
using pi = pair<int, int>;
using vpi = vector<pi>;

const int INF = 1e9;
const ll LINF = 1e18;

void solve() {
    int n; cin >> n;
    int ma = INF, mb = INF;
    vi a(n); for(int& x : a) cin >> x, ma = min(ma, x);
    vi b(n); for(int& x : b) cin >> x, mb = min(mb, x);
    ll res = 0;
    for(int i = 0; i < n; ++i)
        res += max(a[i] - ma, b[i] - mb);
    cout << res << '\n';
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t; while(t--) solve();
}