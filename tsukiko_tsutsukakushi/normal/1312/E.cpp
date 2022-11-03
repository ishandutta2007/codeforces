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

//#define int long long
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

int n;
vector<int> a;

pair<int, int> dp[510][510];

//dp
pair<int, int> rec(int l, int r) {
    if(l >= r) return {0, inf};
    if(r - l == 1) return {1, a[l]};
    if(dp[l][r].fr != inf) return dp[l][r];
    pair<int, int> res = {r - l, inf};
    for(int i = l + 1; i < r; ++i) {
        chmin(res, {rec(l, i).fr + rec(i, r).fr, inf});
        if(rec(l, i).fr == 1 && rec(i, r).fr == 1 && rec(l, i).sc == rec(i, r).sc) {
            return dp[l][r] = {1, rec(l, i).sc + 1};
        }
    }
    return dp[l][r] = res;
}

void solve() {
	cin >> n;
    a.resize(n);
    rep(i, n) {
        // cin >> a[i];
        scanf("%d", &a[i]);
    }
    rep(i, 510) {
        rep(j, 510) {
            dp[i][j] = {inf, inf};
        }
    }
    cout << rec(0, n).fr << endl;
}

signed main() {
	// ios::sync_with_stdio(false);
	// cin.tie(0);
	//cout << fixed << setprecision(10);
	//int t; cin >> t; rep(i, t)solve();
	solve();
    return 0;
}