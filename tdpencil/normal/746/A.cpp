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
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int tt=1;
	 //cin >> tt;

	rep(TT, 0, tt) {
		int x, y, z;
		cin >> x >> y >> z;
		x /= 1;
		y /= 2;
		z /= 4;
		cout << 7 * min({x, y, z}) << "\n";
	}

	



}