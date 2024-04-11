#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxN=2e5;
int n;
vector<int> v;
ar<int, 2> a[mxN];
ll ans;

struct ft {
	ll a[mxN+1];
	void upd(int i, ll x) {
		for(++i; i<=n; i+=i&-i)
			a[i]+=x;
	}
	ll qry(int i) {
		ll r=0;
		for(; i; i-=i&-i)
			r+=a[i];
		return r;
	}
} f0, f1;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for(int i=0; i<n; ++i)
		cin >> a[i][0];
	for(int i=0; i<n; ++i) {
		cin >> a[i][1];
		v.push_back(a[i][1]);
	}
	sort(v.begin(), v.end());
	sort(a, a+n);
	for(int i=0; i<n; ++i) {
		int p=lower_bound(v.begin(), v.end(), a[i][1])-v.begin();
		ans+=f0.qry(p+1)*a[i][0]-f1.qry(p+1);
		f0.upd(p, 1);
		f1.upd(p, a[i][0]);
	}
	cout << ans;
}