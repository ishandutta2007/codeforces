#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define vi vector<int>
#define vb vector<bool>

#define ll long long
#define vl vector<ll>
#define EACH(x, y) for(auto &x: y)
#define pii pair<int, int>
#define pll pair<ll, ll>
#define ar array
#define F0R(x, y) rep(x,0,y)
#define all(x) x.begin(),x.end()
#define sz(x) (int)(x.size())
#define add push_back
#define V vector
#define P pair
#define tcT template<class T
#define tcTU tcT, class U
#define F first
#define S second
#define str string

#define FOR rep
const double eps = 1e-9;
int ni() {
	int tsadfsfd;
	cin >> tsadfsfd;
	return tsadfsfd;
}
ll nl() {
	ll tsadfsfd;
	cin >> tsadfsfd;
	return tsadfsfd;
}
string next() {
	string s;
	cin >> s;
	return s;
}

tcT> bool umin(T &x, T y) {
	if(x<y)
		return 1;
	else
		return x=y,0;
}
tcT> bool umax(T &x, T y) {
	if(x>y)
		return 1;
	else
		return x=y,0;
}
struct Tree {
	typedef int T;
	static constexpr T unit = INT_MIN;
	T f(T a, T b) { return max(a, b); } // (any associative fn)
	vector<T> s; int n;
	Tree(int n = 0, T def = unit) : s(2*n, def), n(n) {}
	void update(int pos, T val) {
		for (s[pos += n] = val; pos /= 2;)
			s[pos] = f(s[pos * 2], s[pos * 2 + 1]);
	}
	T query(int b, int e) { // query [b, e)
		T ra = unit, rb = unit;
		for (b += n, e += n; b < e; b /= 2, e /= 2) {
			if (b % 2) ra = f(ra, s[b++]);
			if (e % 2) rb = f(s[--e], rb);
		}
		return f(ra, rb);
	}
};


void solve() {
	int n, m;
	cin >> n >> m;
	int q; cin >> q;

	V<vi> g(n, vi(m));

	rep(i,0,n) {
		rep(j,0,m) {
			cin >> g[i][j];
		}
	}
	V<Tree> t(n, Tree(m));
	V<V<ll>> dp(n, V<ll>(m));
	rep(i,0,n) {
		ll c=0;
		rep(j,0,m) {
			if(j-1==-1) {
				dp[i][j]=1;
			} else if(g[i][j]==1&&g[i][j-1]==1) {
				dp[i][j]=dp[i][j-1]+1;
			} else {
				dp[i][j]=1;
			}
			t[i].update(j,dp[i][j]);
		}

	}

	while(q--) {
		int x, y;
		cin >> x >> y;
		--x, --y;
		g[x][y]^=1;
		int i=x;
		rep(j,0,m) {
			dp[i][j]=g[i][j];
			if(j-1==-1) {
				t[i].update(j,dp[i][j]);
				continue;
			} else if(g[i][j]==1&&g[i][j-1]==1) {
				dp[i][j] += dp[i][j-1];
			}
			t[i].update(j,dp[i][j]);

		}
		int ans=0;
		rep(i,0,n) {
			umax(ans,t[i].query(0,m));
		}
		cout << ans << "\n";
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int tt=1;
	// cin >> tt;

	rep(TT, 0, tt) {
		solve();
	}





}