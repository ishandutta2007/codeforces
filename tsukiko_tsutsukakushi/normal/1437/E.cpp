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
#include<unordered_set>
#include<utility>
#include<cassert>
#include<array>
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
#define rep1(i,n) for(int i=1;i<=n;i++)
#define per1(i,n) for(int i=n;i>=1;i--)
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
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int LIS(vector<int> a) {
    int sz = (int)a.size();
    vector<int> dp(sz, INF);
    rep(i, sz) {
        *upper_bound(all(dp), a[i]) = a[i];
    }
    return (int)(lower_bound(all(dp), INF) - dp.begin());
}

void solve() {
	int n, k; cin >> n >> k;
    vector<ll> a(n + 2);
    a[0] = -INF, a[n + 1] = INF;
    rep(i, n) {
        cin >> a[i + 1];
    }
    rep(i, n + 2) {
        a[i] -= i;
    }
    vector<int> b(k + 2);
    b[0] = 0, b[k + 1] = n + 1;
    rep(i, k) {
        cin >> b[i + 1];
    }
    int ans = 0;
    rep(i, k + 1) {
        if(a[b[i]] > a[b[i + 1]]) {
            cout << -1 << endl;
            return;
        }
        vector<int> x;
        for(int j = b[i]; j <= b[i + 1]; ++ j) {
            if(a[j] < a[b[i]] or a[b[i + 1]] < a[j]) ++ ans;
            else {
                x.push_back(a[j]);
            }
        }
        ans += (int)x.size() - LIS(x);
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