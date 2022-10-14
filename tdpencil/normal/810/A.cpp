#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define prm(x, y) (2 * x + 2 * y)

ll a(ll x, ll y) {
	if(x % y >= (y+1) / 2) {
		return (x+y-1)/y;
	}
	return x/y;
}
int main() {
	int n;
	cin >> n;

	int k;
	cin >> k;

	vector<int> nums(n);

	for(auto &num: nums)
		cin >> num;

	ll s =0;
	for(auto &num: nums)
		s += num;

	ll avg = a(s, n);

	int ans = 0;
	while(avg != k) {
		++ans;
		s += k;
		avg = a(s, n + ans);
	}

	cout << ans;
}