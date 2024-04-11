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
#define pi pii
#define nl '\n'
#define pl pll
#define ar array
#define F0R(x, y) rep(x,0,y)
#define all(x) x.begin(),x.end()
#define sz(x) (int)(x.size())
#define add push_back
#define V vector
#define P pair
#define tcT template<class T
#define tcTU tcT, class U
#define f first
#define s second
#define str string

#define FOR rep
const double eps = 1e-12;

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
using C = ll;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#define uid(a, b) uniform_int_distribution<int>(a, b)(rng)
void solve() {
	int n; cin >> n;
	int cnt[2]={};
	int p[2]={};
	int a[n];
	rep(i,0,n) {
		cin >> a[i];
		++cnt[a[i]&1];
		p[a[i]&1]=i+1;
	}
	if(cnt[0]>cnt[1]) {
		cout << p[1] << "\n";
	} else if(cnt[1]>cnt[0]) {
		cout << p[0] << "\n";
	}

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
//	sieve();
	// return 0;
	int tt=1;
	// cin >> tt;
	
	
	rep(TT, 0, tt) {
		solve();
	}





}