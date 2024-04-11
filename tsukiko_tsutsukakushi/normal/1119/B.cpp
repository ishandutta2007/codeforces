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
    int n; ll h; cin >> n >> h;
    vector<ll> a(n);
    rep(i, n) {
        cin >> a[i];
    }
    int ok = 0, ng = n + 1;
    while(ng - ok > 1) {
        int mid = (ok + ng) / 2;
        vector<int> b(mid);
        rep(i, mid) b[i] = a[i];
        sort(all(b));
        reverse(all(b));
        ll sum = 0;
        for(int i = 0; i < mid; i += 2) {
            sum += b[i];
        }
        if(sum <= h) ok = mid;
        else ng = mid;
    }
    cout << ok << endl;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//cout << fixed << setprecision(10);
	//int t; cin >> t; rep(i, t)solve();
	solve();
    return 0;
}