/**
 *    author:  otera    
**/
#include<bits/stdc++.h>
using namespace std;

#define int long long
typedef long long ll;
typedef long double ld;
#define rep(i, n) for(int i = 0; i < n; ++ i)
#define per(i,n) for(int i=n-1;i>=0;i--)
typedef pair<int, int> P;
typedef pair<ll, ll> LP;
#define fr first
#define sc second
#define all(c) c.begin(),c.end()
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

void solve() {
    string s; cin >> s;
    int n = (int)s.size();
    int a = 0, b = 0;
    int ans = 0;
    rep(i, n) {
        if(s[i] == '(') ++ a;
        else if(s[i] == '[') ++ b;
        else if(s[i] == ')') {
            if(a > 0) {
                -- a; ++ ans;
            }
        } else if(s[i] == ']') {
            if(b > 0) {
                -- b, ++ ans;
            }
        }
    }
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