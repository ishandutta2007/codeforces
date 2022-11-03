/**
 *    author:  otera    
**/
#include<iostream>
#include<string>
#include<cstdio>
#include<cstring>
#include<vector>
#include<cmath>
#include<algorithm>
#include<functional>
#include<iomanip>
#include<queue>
#include<deque>
#include<ciso646>
#include<random>
#include<map>
#include<set>
#include<complex>
#include<bitset>
#include<stack>
#include<unordered_map>
#include<utility>
#include<cassert>
using namespace std;

#define int long long
typedef long long ll;
typedef unsigned long long ul;
typedef unsigned int ui;
typedef long double ld;
const int inf=1e9+7;
const ll INF=1LL<<60 ;
const ll mod=1e9+7 ;
#define rep(i,n) for(int i=0;i<n;i++)
#define per(i,n) for(int i=n-1;i>=0;i--)
#define Rep(i,sta,n) for(int i=sta;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)
#define per1(i,n) for(int i=n;i>=1;i--)
#define Rep1(i,sta,n) for(int i=sta;i<=n;i++)
typedef complex<ld> Point;
const ld eps = 1e-8;
const ld pi = acos(-1.0);
typedef pair<int, int> P;
typedef pair<ld, ld> LDP;
typedef pair<ll, ll> LP;
#define fr first
#define sc second
#define all(c) c.begin(),c.end()
#define pb push_back
#define debug(x)  cerr << #x << " = " << (x) << endl;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

void solve() {
	int n; cin >> n;
    vector<int> a(n);
    rep(i, n) {
        cin >> a[i];
    }
    int ans = 0;
    for(int bit = 30; bit >= 0; --bit) {
        int mask = (1LL << bit);
        int cnt = 0;
        rep(i, n) {
            a[i] %= (2 * mask);
        }
        sort(all(a));
        // rep(i, n) {
        //     cerr << a[i] << " ";
        // }
        // cerr << endl;
        rep(i, n) {
            if(a[i] <= mask) {
                cnt += lower_bound(all(a), 2 * mask - a[i]) - lower_bound(all(a), mask - a[i]);
            } else {
                cnt += lower_bound(all(a), 2 * mask - a[i]) - a.begin();
                cnt += a.end() - lower_bound(all(a), 3 * mask - a[i]);
            }
            if(2 * a[i] % (2 * mask) >= mask && 2 * a[i] % (2 * mask) < 2 * mask) --cnt;
        }
        cnt /= 2;
        //cerr << cnt << endl;
        if(cnt % 2 != 0) {
            ans |= mask;
        }
    }
    cout << ans << endl;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//cout << fixed << setprecision(10);
	//int t; cin >> t; rep(i, t)solve();
	solve();
    return 0;
}