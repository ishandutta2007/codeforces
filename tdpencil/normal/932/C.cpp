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

void solve() {
	bool can[1000001]={};
	int n, a, b;
	cin >> n >> a >> b;
	can[0]=true;
	rep(i,0,n+1) {
		if(!can[i])
			continue;
		if(i+a<=n)
			can[i+a]=true;
		if(i+b<=n)
			can[i+b]=true;
	}


	if(!can[n]) {
		cout << "-1\n";
		return;
	}
	vi dec;

	int cur=n;

	while(cur > 0) {
		if(a <= cur && can[cur - a]) {
			dec.add(a);
			cur -= a;
		} else if(b <= cur && can[cur - b]) {
			dec.add(b);
			cur -= b;
		}
	}
	assert(cur==0);
	vector<vector<int>> used;
	vector<int> current;
	for(ll i = 1; i <= n; ++i) {
		if(dec.back() > 0) {
			current.add(i);
			--dec.back();
		} else {
			dec.pop_back();
			used.add(current);
			current.clear();
			current.add(i);
			--dec.back();
		}
	}
	if(current.size())
		used.add(current);
	for(auto &j : used) {
		rotate(j.begin(), j.begin()+1, j.end());
		for(auto i : j) {
			cout << i << " ";
		}

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