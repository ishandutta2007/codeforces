

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

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n; cin >> n;
    vi x(n), y(n);
    for(int i = 0; i < n; ++i) { cin >> x[i] >> y[i]; }
    for(int i = 1; i < n; ++i) x[i] -= x[0], y[i] -= y[0]; x[0] = y[0] = 0;

    int k = 1;
    for(;;) {
        int a[2] = { 0, 0 };
        for(int i = 0; i < n; ++i)
            a[(x[i]+y[i])&1]++;
        if(a[0] && a[1]) break;

        for(int i = 1; i < n; ++i) {
            int cx = x[i], cy = y[i];
            x[i] = (cx-x[0])+(cy-y[0]); x[i] >>= 1;
            y[i] = (cx-x[0])-(cy-y[0]); y[i] >>= 1;
        }
    }

    vi res;
    for(int i = 0; i < n; ++i)
        if((x[i]+y[i])&1) res.pb(i+1);
    cout << res.size() << endl;
    for(int i : res) cout << i << ' ';
}