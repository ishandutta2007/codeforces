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
 
int dp[6030][6030];
vector<vector<int>> nxt;
 
int calc(int l, int r) {
    if(dp[l][r] != -1) return dp[l][r];
    if(l > r) return dp[l][r] = 0;
    int res = 0;
    int add = count(all(nxt[l]), r);
    chmax(res, add + calc(l + 1, r));
    for(int nr: nxt[l]) {
        if(nr >= r) continue;
        chmax(res, add + calc(l, nr) + calc(nr, r));
    }
    return dp[l][r] = res;
}
 
void solve() {
	int n; cin >> n;
    vector<int> l(n), r(n);
    vector<int> comp;
    rep(i, n) {
        cin >> l[i] >> r[i];
        ++ r[i];
        comp.push_back(l[i]);
        comp.push_back(r[i]);
    }
    sort(all(comp));
    comp.erase(unique(all(comp)), comp.end());
    rep(i, n) {
        l[i] = lower_bound(all(comp), l[i]) - comp.begin();
        r[i] = lower_bound(all(comp), r[i]) - comp.begin();
    }
    int sz = comp.size();
    rep(i, sz + 1) {
        rep(j, sz + 1) dp[i][j] = -1;
    }
    nxt.assign(sz + 1, vector<int>());
    rep(i, n) {
        nxt[l[i]].push_back(r[i]);
    }
    cout << calc(0, sz) << endl;
}
 
signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//cout << fixed << setprecision(10);
	int t; cin >> t; rep(i, t)solve();
	//solve();
    return 0;
}