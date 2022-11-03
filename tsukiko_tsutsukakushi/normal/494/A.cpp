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
    int cnt0 = 0, cnt1 = 0, cnt2 = 0;
    rep(i, n) {
        if(s[i] == '(') {
            ++ cnt0;
        } else if(s[i] == ')') {
            ++ cnt1;
        } else {
            ++ cnt2;
        }
    }
    if(cnt0 < cnt1 + cnt2) {
        cout << -1 << endl;
        return;
    }
    int cur = 0;
    int now = 0;
    vector<int> ans;
    rep(i, n) {
        if(s[i] == '(') {
            ++ cur;
        } else if(s[i] == ')') {
            -- cur;
        } else {
            ++ now;
            if(now != cnt2) {
                ans.push_back(1);
                -- cur;
            } else {
                ans.push_back(cnt0 - cnt1 - cnt2 + 1);
                cur -= cnt0 - cnt1 - cnt2 + 1;
            }
        }
        if(cur < 0) {
            cout << -1 << endl;
            return;
        }
    }
    for(int x: ans) {
        cout << x << endl;
    }
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//cout << fixed << setprecision(10);
	//int t; cin >> t; rep(i, t)solve();
	solve();
    return 0;
}