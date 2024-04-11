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
    int n; cin >> n;
    vector<ll> a(n);
    vector<ll> sum(n + 1, 0);
    rep(i, n) {
        cin >> a[i];
        sum[i + 1] = sum[i] ^ a[i];
    }
    if(n >= 100) {
        cout << 1 << endl;
        return;
    }
    ll ans = inf;
    rep(i, n + 1) {
        for(int j = i + 1; j < n + 1; ++ j) {
            for(int k = j + 1; k < n + 1; ++ k) {
                ll left = sum[j] ^ sum[i], right = sum[k] ^ sum[j];
                if(left > right) {
                    chmin(ans, k - i - 2);
                }
            }
        }
    }
    if(ans == inf) ans = -1;
    cout << ans << "\n";
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//cout << fixed << setprecision(20);
	//int t; cin >> t; rep(i, t)solve();
	solve();
    return 0;
}