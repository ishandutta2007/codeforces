/**
 *    author:  otera    
**/
#include<bits/stdc++.h>
using namespace std;

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
    vector<int> a(n);
    rep(i, n) {
        cin >> a[i]; -- a[i];
    }
    vector<int> coma = a;
    sort(all(coma));
    coma.erase(unique(all(coma)), coma.end());
    int m = (int)coma.size();
    vector<int> mi(m, inf), ma(m, -inf);
    rep(i, n) {
        int val = lower_bound(all(coma), a[i]) - coma.begin();
        chmin(mi[val], i);
        chmax(ma[val], i);
    }
    vector<int> dp(m, 1);
    for(int i = 1; i < m; ++ i) {
        if(ma[i - 1] < mi[i]) {
            dp[i] = dp[i - 1] + 1;
        }
    }
    cout << m - *max_element(all(dp)) << "\n";
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//cout << fixed << setprecision(20);
	int t; cin >> t; rep(i, t)solve();
	// solve();
    return 0;
}