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
    vector<int> cnt(n, 0);
    rep(i, n) {
        cin >> a[i];
        -- a[i];
        ++ cnt[a[i]];
    }
    if(*max_element(all(cnt)) > (n + 1) / 2) {
        cout << -1 << "\n";
        return;
    }
    vector<int> num(n, 0);
    num[a[0]] ++, num[a[1]] ++;
    int k = 1;
    rep(i, n - 1) {
        if(a[i] == a[i + 1]) {
            num[a[i]] ++;
            num[a[i + 1]] ++;
            ++ k;
        }
    }
    int x = max_element(all(num)) - num.begin();
    int co = 0;
    if(a[0] == x) ++ co;
    if(a[n - 1] == x) ++ co;
    rep(i, n - 1) {
        if(a[i] == x and a[i + 1] == x) {
            co += 2;
        }
    }
    // cerr << k << " " << x << " " << co << "\n";
    cout << k - 1 + max(0, co - k - 1) << "\n";
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//cout << fixed << setprecision(20);
	int t; cin >> t; rep(i, t)solve();
	// solve();
    return 0;
}