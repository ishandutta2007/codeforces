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

ll I = 99999;
int main() {
	

	int tt=1;
	//cin >> tt;

	rep(TT, 0, tt) {
		// bool ch = 1;
		int n; cin >> n;
		vi a(n), b(n);
		rep(i, 0, n-1) cin >> a[i];
		rep(i, 0, n-1) cin >> b[i];
		vi ans(n, I);
		rep(t, 0, 4) {
			ans[0]=t;
			rep(i, 0, n-1) {
				rep(j, 0, 4) {
					if((ans[i]|j)==a[i]&&(ans[i]&j)==b[i]) {
						ans[i+1]=j;
						break;
					}
				}
			}
			bool br=count(all(ans), I);
			if(br)
				continue;
			break;
		}
		if(count(all(ans), I))
		{
			cout << "NO\n";
			continue;
		}
		cout << "YES\n";
		rep(i, 0, n) {
			cout << ans[i] << " ";
		}
		cout << "\n";
		
		
		
	}

}