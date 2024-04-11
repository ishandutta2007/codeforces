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
#define debug(x)  cout << #x << " = " << (x) << endl;
using Graph = vector<vector<int> >;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
#define int long long

int nth_bit(ll num, int k) {
	return ((num >> k) & 1);
}

void solve() {
	int n, m; string s; cin >> n >> m >> s;
	int times[22][22];
	rep(i, m) {
		rep(j, m) {
			times[i][j] = 0;
		}
	}
	rep(i, n - 1) {
		int a = s[i] - 'a', b = s[i + 1] - 'a';
		times[a][b] ++;
		times[b][a] ++;
	}

	ll cost[(1<<21)];
	int msb = 0;
	cost[0] = 0;
	for(int bit = 1; bit < (1<<m); ++bit) {
		if(bit == (1<<(msb+1))) msb++;
		cost[bit] = cost[bit - (1<<msb)];
		rep(i, m) {
			if(i == msb) continue;
			if(nth_bit(bit, i)) {
				cost[bit] -= times[msb][i];
			} else {
				cost[bit] += times[msb][i];
			}
		}
	}

	vector<ll> dp(1<<m, INF);
	dp[0] = 0;
	rep(i, (1<<m)) {
		rep(j, m) {
			if(!nth_bit(i, j)) chmin(dp[i + (1<<j)], dp[i] + cost[i]);
		}
	}
	cout << dp[(1<<m) - 1] << endl;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//cout << fixed << setprecision(10);
	//init();
	solve();
	//cout << "finish" << endl;
    return 0;
}