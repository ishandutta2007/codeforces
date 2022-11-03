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
    int n, x; cin >> n >> x;
    vector<int> a(n);
    rep(i, n) {
        cin >> a[i];
    }
    auto b = a;
    sort(all(b));
    if(a == b) {
        cout << 0 << "\n";
        return;
    }
    int cnt = 0;
    rep(i, n) {
        if(x >= a[i]) continue;
        else if(x < a[i]) {
            swap(x, a[i]);
            ++ cnt;
            bool ok = 1;
            rep(j, n - 1) {
                if(a[j] > a[j + 1]) ok = 0;
            }
            if(ok) {
                cout << cnt << "\n";
                return;
            }
        }
    }
    cout << -1 << "\n";
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//cout << fixed << setprecision(20);
	int t; cin >> t; rep(i, t)solve();
	// solve();
    return 0;
}