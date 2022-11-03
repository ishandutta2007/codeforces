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

int n, k; 
vector<vector<int>> s;

int ma;

bool check(int l, int r) {
	cerr << l << " " << r << endl;
	vector<int> S;
	for(int i = l; i < r; ++ i) {
		rep(j, (int)s[i].size()) {
			S.pb(s[i][j]);
		}
	}
	cout << "? " << (int)S.size();
	rep(i, (int)S.size()) {
		cout << " " << S[i] + 1;
	}
	cout << endl;
	fflush(stdout);
	int res;
	cin >> res;
	if(res == -1) exit(0);
	if(res == ma) return true;
	return false; 
}

void solve() {
	cin >> n >> k;
    s.assign(k, vector<int>());
	int cnt = 0;
	rep(i, k) {
		int c; cin >> c;
		cnt += c;
		s[i].resize(c);
		rep(j, c) {
			cin >> s[i][j];
			-- s[i][j];
		}
	}
	cout << "? " << n;
	rep(i, n) {
		cout << " " << i + 1;
	}
	cout << endl;
	fflush(stdout);
	cin >> ma;
	if(ma == -1) exit(0);
	int l = 0, r = k;
	// bool only = 1;
	while(r - l > 1) {
		int mid = (r + l) / 2;
		int r_ = r, l_ = l;
		if(check(l, mid)) {
			r = mid;
		}
		else {
			l = mid;
		}
	}
	int mi = ma;
	if(n - (int)s[l].size() != 0) {
		cout << "? " << n - (int)s[l].size();
		rep(i, n) {
			bool c = 1;
			rep(j, (int)s[l].size()) {
				if(i == s[l][j]) c = 0;
			}
			if(c) cout << " " << i + 1;
		}
		cout << endl;
		fflush(stdout);
		cin >> mi;
		if(mi == -1) exit(0);
    }
	cout << "! ";
	rep(i, k) {
		if(i == l) {
			cout << mi << " ";
		} else {
			cout << ma << " ";
		}
	}
	cout << endl;
	fflush(stdout);
	string ans;
	cin >> ans;
	if(ans == "Correct") {
		return;
	} else {
		exit(0);
	}
}

signed main() {
	// ios::sync_with_stdio(false);
	// cin.tie(0);
	//cout << fixed << setprecision(10);
	int t; cin >> t; rep(i, t)solve();
	//solve();
    return 0;
}