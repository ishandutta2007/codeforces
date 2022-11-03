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
	int x; cin >> x;
    const string MAX = "99999999999";
    string ans = MAX;
    for(int bit = 1; bit < (1<<9); ++ bit) {
        int cnt = 0;
        string res = "";
        rep(i, 9) {
            if(bit & (1<<i)) {
                cnt += (1 + i);
                res += (char)('1' + i);
            }
        }
        if(cnt == x) {
            if(ans.size() > res.size()) ans = res;
            else if(ans.size() == res.size()) {
                chmin(ans, res);
            }
        }
    }
    if(ans == MAX) ans = "-1";
    cout << ans << "\n";
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//cout << fixed << setprecision(20);
	int t; cin >> t; rep(i, t)solve();
	// solve();
    return 0;
}