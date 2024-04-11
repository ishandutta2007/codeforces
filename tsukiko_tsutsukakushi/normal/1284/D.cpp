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
#define int long long

int n;

bool check(vector<P> a, vector<P> b) {
	multiset<int> left, right;
	vector<pair<int, pair<int, int>>> vec;
	rep(i, n) {
		vec.push_back( {a[i].fr, { 0, i} } );
		vec.push_back( {a[i].sc, { 1, i} } );
	}
	sort(all(vec));
	for(auto& x: vec) {
		int i = x.sc.sc;
		if(x.sc.fr == 0) {
			left.insert(b[i].fr);
			right.insert(b[i].sc);
		} else {
			int mi = *right.begin();
			int ma = *left.rbegin();
			if(mi < b[i].fr || b[i].sc < ma) {
				cout << "NO" << endl;
				exit(0);
				return false;
			}
			auto ite = right.lower_bound(b[i].sc);
			right.erase(ite);
			ite = left.lower_bound(b[i].fr);
			left.erase(ite);
		}
	}
	return true;
}

void solve() {
	cin >> n;
    vector<P> a(n), b(n);
	rep(i, n) {
		int sa, ea, sb, eb;
		cin >> sa >> ea >> sb >> eb;
		a[i] = {sa, ea};
		b[i] = {sb, eb};
	}
	if(check(a, b) && check(b, a)) {
		cout << "YES" << endl;
	} else {
		cout << "NO" << endl;
	}
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//cout << fixed << setprecision(10);
	//init();
	//int t; cin >> t; rep(i, t)solve();
	solve();
	//cout << "finish" << endl;
    return 0;
}