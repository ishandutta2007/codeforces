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
	int n; ll t; cin >> n >> t;
    string s; cin >> s;
    vector<int> num(n);
    rep(i, n) {
        num[i] = s[i] - 'a';
    }
    ll now = -(1<<num[n - 2]) + (1<<num[n - 1]);
    t -= now;
    vector<int> cnt(26, 0);
    rep(i, n - 2) {
        cnt[num[i]] ++;
    }
    per(i, 26) {
        rep(j, cnt[i]) {
            if(t < 0) t += (1<<i);
            else t -= (1<<i);
        }
    }
    cout << (t == 0 ? "Yes" : "No") << "\n";
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//cout << fixed << setprecision(20);
	//int t; cin >> t; rep(i, t)solve();
	solve();
    return 0;
}