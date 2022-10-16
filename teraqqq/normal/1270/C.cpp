#include <bits/stdc++.h>

#define F first
#define S second
#define pb push_back
#define rsz resize

using namespace std;
using vi = vector<int>;
using ll = long long;
using pi = pair<int, int>;
using vpi = vector<pi>;
using vl = vector<ll>;

const ll LINF = 1e18;
const int INF = 1e9;

void solve() {
    int n; cin >> n;
    ll sum = 0; int y = 0;
    vi v(n); for(int& x : v) { cin >> x; sum += x, y ^= x; }
    cout << 2 << endl;
    cout << y << ' '  << y+sum << endl;

}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    //solve();
    int q; cin >> q; while(q--) solve();
}