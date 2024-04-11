#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define vi vector<int>
#define ll long long
#define vl vector<ll>
#define EACH(x, y) for(auto &x: y)
#define pii pair<int, int>
#define pll pair<ll, ll>
#define ar array
#define add push_back

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

template<class T> bool umin(T &x, T y) {
	if(x<y)
		return 1;
	else
		return x=y,0;
}
template<class T> bool umax(T &x, T y) {
	if(x>y)
		return 1;
	else
		return x=y,0;
}
double abs(double x, double y) {
	double dif = x - y;
	if(dif < 0)
		return -dif;
	return dif;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int tt=1;
	// cin >> tt;

	rep(TT, 0, tt) {
		vector<bool> pos(5000);
		
		ar<int, 3> k;
		rep(i, 0, 3)
			cin >> k[i];
		int cnt[2000] = {};
		rep(i, 0, 3)
			++cnt[k[i]];
		
		if(cnt[1]>=1 || cnt[2] >= 2 || cnt[3] == 3 || (cnt[2]==1&&cnt[4]==2)) {
			cout << "YES\n";
		} else cout << "NO\n";
	}
}