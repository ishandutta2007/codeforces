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
 
int query(int x) {
    cout << x << endl;
    fflush(stdout);
    int res; cin >> res;
    if(res == 0) exit(0);
    assert(res != -2);
    return res;
}
 
void solve() {
    int m, n; cin >> m >> n;
    vector<int> check(n);
    rep(i, n) {
        check[i] = query(1);
    }
    int le = 1, ri = m + 1;
    int i = 0;
    while(ri - le > 1) {
        int mid = (le + ri) / 2;
        int res = query(mid);
        if(check[i] == 1) {
            if(res == 1) le = mid;
            else ri = mid;
        } else {
            if(res == 1) ri = mid;
            else le = mid;
        }
        i = (i + 1) % n;
    }
    query(le);
    assert(false);
}
 
signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//cout << fixed << setprecision(20);
	//int t; cin >> t; rep(i, t)solve();
	solve();
    return 0;
}