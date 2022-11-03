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
	ll n; cin >> n;
    int m = 1;
    int cur = 1;
    while(cur * 4 - 1 < n) {
        cur *= 4LL;
        ++ m;
    } 
    ll ans = 0;
    auto f = [&](int i) {
        if(i == 0) return P{0, 0};
        else if(i == 1) {
            if(n % 3 == 1) return P{0, 1};
            else if(n % 3 == 2) return P{1, 0};
            else return P{1, 1};
        } else if(i == 2) {
            if(n % 3 == 1) return P{1, 0};
            else if(n % 3 == 2) return P{1, 1};
            else return P{0, 1};
        } else {
            if(n % 3 == 1) return P{1, 1};
            else if(n % 3 == 2) return P{0, 1};
            else return P{1, 0};
        }
    };
    if(n % 3 == 1) {
        // a
        ans += (1LL<<(2 * m - 2));
    } else if(n % 3 == 2) {
        // b
        ans += (1LL<<(2 * m - 1));
    } else {
        // c
        ans += (1LL<<(2 * m - 1)) + (1LL<<(2 * m - 2));
    }
    int n_ = n;
    n_ -= cur;
    n_ /= 3;
    for(int i = 0; i <= 2 * m - 4; i += 2) {
        int j = n_ % 4;
        n_ /= 4;
        ans += f(j).sc * (1LL<<i) + f(j).fr * (1LL<<(i + 1));
    }
    cout << ans << endl;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//cout << fixed << setprecision(10);
	int t; cin >> t; rep(i, t)solve();
	// solve();
    return 0;
}