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
    vi v(n); for(int& x : v) cin >> x;
    for(int i = 1; i < n; ++i) {
        if(abs(v[i] - v[i-1]) >= 2) {
            cout << "YES" << endl;
            cout << i << ' ' << i+1 << endl;
            return;
        }
    }

    cout << "NO" << endl;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    //solve();
    int q; cin >> q; while(q--) solve();
}