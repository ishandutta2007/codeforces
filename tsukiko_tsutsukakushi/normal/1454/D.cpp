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
#define Rep(i,sta,n) for(int i=sta;i<n;i++)
typedef pair<int, int> P;
typedef pair<ll, ll> LP;
#define fr first
#define sc second
#define all(c) c.begin(),c.end()
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

void solve() {
    ll n; cin >> n;
    ll n_ = n;
    map<ll, int> cnt;
    for(ll i = 2; i * i <= n_; ++ i) {
        if(n_ % i == 0) {
            while(n_ % i == 0) {
                n_ /= i;
                cnt[i] ++;
            }
        }
    }
    if(n_ != 1) cnt[n_] ++;
    int q = -1, k = -1;
    for(auto pf: cnt) {
        ll p = pf.fr; 
        int co = pf.sc;
        if(chmax(k, co)) {
            q = p;
        }
    }
    cout << k << "\n";
    rep(i, k) {
        if(i != k - 1) cout << q << " ";
        else {
            rep(j, k - 1) n /= q;
            cout << n << "\n";
        }
    }
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//cout << fixed << setprecision(20);
	int t; cin >> t; rep(i, t)solve();
	// solve();
    return 0;
}