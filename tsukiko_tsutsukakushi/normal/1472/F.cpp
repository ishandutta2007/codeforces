/**
 *    author:  otera    
**/
#include<bits/stdc++.h>
using namespace std;

#define int long long
typedef long long ll;
typedef long double ld;
const int inf=1e9+7;
const ll INF=1LL<<60;
#define rep(i, n) for(int i = 0; i < n; ++ i)
#define per(i,n) for(int i=n-1;i>=0;i--)
#define Rep(i,sta,n) for(int i=sta;i<n;i++)
typedef pair<int, int> P;
typedef pair<ll, ll> LP;
#define fr first
#define sc second
#define all(c) c.begin(),c.end()
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

void solve() {
    int n, m; cin >> n >> m;
    vector<int> r(m), c(m);
    rep(i, m) {
        cin >> r[i] >> c[i]; -- r[i], -- c[i];
    }
    vector<int> ids(m); 
    iota(all(ids), 0);
    sort(all(ids), [&](int i, int j){ 
        if(c[i] != c[j]) return c[i] < c[j];
        else return r[i] < r[j]; 
    });
    int prev = -1, bit = 3;
    rep(i, m) {
        int id = ids[i];
        if(bit == 3) {
            if(prev == c[id]) {
                cout << "NO\n";
                return;
            }
            prev = c[id];
            bit = (1<<r[id]);
        } else {
            if((bit | (1<<r[id])) == 3) {
                if((c[id] - prev) % 2 == 1) {
                    cout << "NO\n";
                    return;
                }
                prev = c[id];
                bit = 3;
            } else {
                if((c[id] - prev) % 2 == 0) {
                    cout << "NO\n";
                    return;
                }
                prev = c[id];
                bit = 3;
            }
        }
    }
    if(bit != 3) {
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//cout << fixed << setprecision(20);
	int t; cin >> t; rep(i, t)solve();
	// solve();
    return 0;
}