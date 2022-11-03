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

map<pair<ll, ll>, ll> dp;

ll f(ll a, ll b) {
    if(dp.count({a, b})) return dp[{a, b}];
    if(a < 0 or b < 0) return 0;
    if(a == 0) return b + 1;
    if(b == 0) return a + 1;
    ll ret = 0;
    //(0, 0)
    ret += f(a / 2, b / 2);
    //(0, 1)
    if(b % 2 == 0) ret += f(a / 2, b / 2 - 1);
    else ret += f(a / 2, b / 2);
    //(1, 0)
    if(a % 2 == 0) ret += f(a / 2 - 1, b / 2);
    else ret += f(a / 2, b / 2);
    return dp[{a, b}] = ret;
}

void solve() {
	int l, r; cin >> l >> r;
    cout << f(r, r) - f(l - 1, r) - f(r, l - 1) + f(l - 1, l - 1) << endl;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//cout << fixed << setprecision(10);
	int t; cin >> t; rep(i, t)solve();
	//solve();
    return 0;
}