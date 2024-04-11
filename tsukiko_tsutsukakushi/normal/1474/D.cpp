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
    ll sum = 0;
    rep(i, n) {
        cin >> a[i];
        sum += a[i];
    }
    if(sum % 2 == 1) {
        cout << "NO\n";
        return;
    }
    vector<int> left(n - 1, -1), right(n - 1, -1);
    left[0] = (a[0] <= a[1] ? a[1] - a[0] : -1);
    bool ok = (a[0] <= a[1]);
    vector<int> b = a;
    b[1] -= b[0];
    for(int i = 1; i < n - 1; ++ i) {
        if(!ok) break;
        left[i] = (b[i] <= b[i + 1] ? b[i + 1] - b[i] : -1);
        ok = (b[i] <= b[i + 1]);
        b[i + 1] -= b[i];
    }
    if(ok and b[n - 1] == 0) {
        cout << "YES\n";
        return;
    }
    b = a;
    right[0] = (a[n - 1] <= a[n - 2] ? a[n - 2] - a[n - 1] : -1);
    ok = (a[n - 1] <= a[n - 2]);
    b[n - 2] -= b[n - 1];
    for(int i = 1; i < n - 1; ++ i) {
        if(!ok) break;
        right[i] = (b[n - 1 - i] <= b[n - 2 - i] ? b[n - 2 - i] - b[n - 1 - i] : -1);
        ok = (b[n - 1 - i] <= b[n - 2 - i]);
        b[n - 2 - i] -= b[n - 1 - i];
    }
    rep(i, n - 1) {
        //swap(a[i], a[i + 1]);
        int l = (i == 0 ? 0 : i == 1 ? a[0] : left[i - 2]);
        int r = (i + 1 == n - 1 ? 0 : i + 1 == n - 2 ? a[n - 1] : right[n - 4 - i]);
        if(l == -1 or r == -1) continue;
        //cerr << l << " " << r << "\n";
        if(a[i + 1] - l == a[i] - r and a[i] - r >= 0) {
            cout << "YES\n";
            return;
        } 
    }
    cout << "NO\n";
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//cout << fixed << setprecision(20);
	int t; cin >> t; rep(i, t)solve();
	// solve();
    return 0;
}