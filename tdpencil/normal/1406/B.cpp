#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define nl "\n"
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;



template <class T>
bool umin(T &x, T y) {
	if (x > y)
	{
		x = y;
		return 1;
	}
	return 0;
}
template <class T>
bool umax(T &x, T y) {
	if (x < y)
	{
		x = y;
		return 1;
	}
	return 0;
}
bool cmp(int a, int b) {
	return abs(a) > abs(b);
}
void solve() {
	int n; cin >> n;
	vector<ll> a(n);
	rep(i,0,n) {
		cin >> a[i];
	}
	if(n==5) {
		cout << a[0]*a[1]*a[2]*a[3]*a[4] << "\n";
	} else {
		// we claim that unless every integer in the array is negative, achieve a positive result is always possible
		bool allneg=1;
		for(auto &i : a) allneg&=i<0;

		if(allneg) {
			sort(all(a));
			reverse(all(a));
			cout << a[0]*a[1]*a[2]*a[3]*a[4] << nl;
			return;
		}
		vi non_negative;
		vi negative;

		for(int i=0;i<n;i++) {
			if(a[i]>=0) {
				non_negative.push_back(a[i]);
			} else {
				negative.push_back(a[i]);
			}
		}
		sort(non_negative.begin(),non_negative.end());
		sort(negative.begin(), negative.end());

		ll ans=0;
		// either we take 1 positive, and 4 negative
		if(negative.size()>=4) {
			ans=max(ans,1LL*negative[0]*negative[1]*negative[2]*negative[3]*non_negative.back());
		}
		// next we take 3 positive 2 negative
		if(non_negative.size()>=3&&negative.size()>=2) {
			ans=max(ans,1LL*negative[0]*negative[1]*non_negative[sz(non_negative)-3]*non_negative[sz(non_negative)-2]*non_negative.back());
		}
		// or we just take 5 positive
		if(non_negative.size()>=5) {
			ans=max(ans,1LL*non_negative[sz(non_negative)-1]*non_negative[sz(non_negative)-2]*non_negative[sz(non_negative)-3]*non_negative[sz(non_negative)-4]*non_negative[sz(non_negative)-5]);
		}

		cout << ans << "\n";
	}
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
    int t = 1;
	cin >> t;
    while(t--) {
        solve();
    }
}