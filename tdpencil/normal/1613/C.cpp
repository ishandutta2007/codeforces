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
	ll n, h;
	cin >> n >> h;

	vi a(n);
	for(int i=0;i<n;i++) {
		cin >> a[i];
	}
	// cout << n << "\n";

	ll lb=1,rb=h;


	while(lb<rb) {
		ll mid=(lb+rb)/2;
		assert(mid>0);
		ll end=0;
		ll dmg=0;
		for(int i=0;i<n;i++) {
			// cout << i +1 << " " << end << "\n";
			if(a[i]<=end) {
				end=mid+a[i];
				dmg+=(a[i]-a[i-1]);
			} else {
				if(i) {
					dmg+=end-a[i-1];
				}
				end=mid+a[i];
			}
		}

		// cout << dmg << "\n";
		dmg+=end-a[n-1];
		// cout << dmg << "\n";
		if(dmg>=h) {
			rb=mid;
		} else lb=mid+1;
	}

	cout << lb << nl;

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